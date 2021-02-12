#include <Arduino.h>
#include <display.h>
#include <lookup.h>
#include <myWire.h>
#include <parsedata.h>
#include <main.h>

#define WAIT 200

//display
long rev = 0;
int temp = 0;
int speed = 0;
long dist = 0;
char textspeed[5] = {' ',' ',' ',' ',' '};
char textodo[8] = {' ',' ',' ',' ',' ',' ',' ',' '};

//I2C
#define SDA_PIN 4
#define SCL_PIN 5
#define IIC_ADRESS 0x38
#define IIC_ARRAYSIZE 33
#define IIC_FIXEDDATA 9 // first 9 bytes are fixed

uint8_t IicArray[IIC_ARRAYSIZE] = {0};
int i = 0;
int newData = 0;

// function that executes whenever data is receivced from master
void receiveEvent(int numBytes) {
  if (numBytes == IIC_ARRAYSIZE) {
    i = 0;
    // number of bytes correct
    //Serial.print("IIC: Start ");
    while(Wire.available()) {
      IicArray[i] = Wire.read();
      //Serial.print(0xFF & IicArray[i], HEX);
      //Serial.print(";");
      i++;
    }
    newData ++;
  }
  else {
    /*
    Serial.println("IIC: Wrong number of bytes received");
    Serial.print("IIC: Received ");
    Serial.print(numBytes);
    Serial.println(" bytes");
    */
    while(Wire.available()) {
      Wire.read();
    }
  }
  //Serial.println(" End");
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  
  // set higher baudrate for display
  DisplaySetBaudRate(115200);

  // Clear Display
  DisplayAllSymbolsOff();
  DisplaySendSpeed();
  DisplaySendOdo();
  DisplaySendRev(0);
  DisplaySendTemp(0);

  //
  Wire.begin(IIC_ADRESS);
  /*
  Serial.print("IIC: Wire Slave Adress: ");
  Serial.println(IIC_ADRESS, HEX);
  */
  Wire.onReceive(receiveEvent); //register receive handler
}

void loop() {
  // check if new data is available
  if (newData) {
    while (newData) {
      //Serial.print("newData: ");
      //Serial.println(newData);
      newData --;
    }
    // parse data
    parseData();
    // parse chars
    parseTextOdo();
    parseTextSpeed();

    // send data to display
    DisplaySendTemp(TempBars * 14);
    DisplaySendRev(RevBars * 2);

    DisplaySymbolTemp(TempSymbol);
    DisplaySymbolRev(RevSymbol);
    
    DisplaySendOdo();
    DisplaySendSpeed();
    DisplaySymbolDda(SymbolDDA);
    DisplaySymbolDtc(SymbolDTC);
    DisplaySymbolError(SymbolError);
    DisplaySymbolFuel(SymbolFuel);
    DisplaySymbolKmh(SymbolKmh);
    DisplaySymbolLap(SymbolLap);
    DisplaySymbolMph(SymbolMph);
    DisplaySymbolTair(SymbolTAir);
    DisplaySymbolTot(SymbolTot);
    DisplaySymbolTrip(SymbolTrip);
    DisplaySymbolWrench(SymbolWrench);
    DisplaySymbolPM(SymbolPM);
    DisplaySymbolAM(SymbolAM);
  }
}
