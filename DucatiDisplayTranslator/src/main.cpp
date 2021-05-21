#include <Arduino.h>
#include <display.h>
#include <lookup.h>
#include <myWire.h>
#include <parsedata.h>
#include <main.h>
#include <CAN.h>

#define WAIT 200

//CAN
#define MSG_ID_TPS 0x81
#define MSG_ID_SPEED 0x100
#define MSG_ID_TEMP 0x211
#define CAN_PACKETSIZE 8

uint8_t CanArray[CAN_PACKETSIZE] = {0};

//display
long rev = 0;
long revBak = 0;
int tps = 0;
int tpsBak = 0;
int clutch = 0;
int clutchBak = 0;
int temp = 0;
int tempBak = 0;
int gear = 0;
int gearBak = 0;
//int speed = 0;
//long dist = 0;
char textspeed[5] = {' ',' ',' ',' ',' '};
char textspeedBak[5] = {' ',' ',' ',' ',' '};
char textodo[8] = {' ',' ',' ',' ',' ',' ',' ',' '};
char textodoBak[8] = {' ',' ',' ',' ',' ',' ',' ',' '};

//I2C
#define SDA_PIN 4
#define SCL_PIN 5
#define IIC_ADRESS 0x38
#define IIC_ARRAYSIZE 33
#define IIC_FIXEDDATA 9 // first 9 bytes are fixed

uint8_t IicArray[IIC_ARRAYSIZE] = {0};
int i = 0;
int newData = 0;

// function that executes with new CAN data
void onCanReceive(int packetSize) {
  // received a packet
  int pos = 0;
  if ((CAN.packetId() == MSG_ID_SPEED) | (CAN.packetId() == MSG_ID_TEMP) | (CAN.packetId() == MSG_ID_TPS)) {
    while (CAN.available()) {
      CanArray[pos] = (char)CAN.read() & 0xFF;
      pos++;
    }
  }

  switch (CAN.packetId()) {
    case MSG_ID_TPS:
    tps = CanArray[0] >> 1;
    clutch = CanArray[0] & 0x01;
    newData ++;
    break;

    case MSG_ID_SPEED:
    gear = (CanArray[0] >> 4) & 0x0F;
    rev = (CanArray[3] << 8) | CanArray[4];
    SymbolStand = (CanArray[5] >> 1) & 0x01;
    newData ++;
    break;

    case MSG_ID_TEMP:
    TempText = CanArray[0] - 40;
    newData ++;
    break;

    default:
    //Serial.println("CAN: unknown message ID");
    break;
  }
}

// function that executes with new IIC data
void onIicReceive(int numBytes) {
  if (numBytes == IIC_ARRAYSIZE) {
    i = 0;
    while(Wire.available()) {
      IicArray[i] = Wire.read();
      i++;
    }
    newData ++;
  }
  else {
    while(Wire.available()) {
      Wire.read();
    }
  }
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  
  // set higher baudrate for display
  DisplaySetBaudRate(115200);
  Serial.println();

  // Clear Display
  DisplayAllSymbolsOff();
  DisplaySendSpeed();
  DisplaySendOdo();
  DisplaySendRev(0);
  DisplaySendTemp(0);
  DisplaySendGear(0);
  DisplaySendTps(0);

  // start wire
  Wire.begin(IIC_ADRESS);
  Wire.onReceive(onIicReceive); //register receive handler

  //Serial.println("CAN: Receiver");

  // start the CAN bus at 500 kbps
  if (!CAN.begin(500E3)) {
    //Serial.println("CAN: Starting failed!");
    while (1);
  }

  // register the receive callback
  CAN.onReceive(onCanReceive);
  //Serial.println("CAN: receive callback registered");
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
    DisplaySendOdo();
    DisplaySendSpeed();

    if (TempBars != TempBarsBak) {
      DisplaySendTemp(TempBars * 14);
      TempBarsBak = TempBars;
    }

    if (RevBars != RevBarsBak) {
      DisplaySendRev(RevBars * 2);
      RevBarsBak = RevBars;
    }

    if (TempSymbol != TempSymbolBak) {
      DisplaySymbolTemp(TempSymbol);
      TempSymbolBak = TempSymbol;
    }

    if (RevSymbol != RevSymbolBak) {
      DisplaySymbolRev(RevSymbol);
      RevSymbolBak = RevSymbol;
    }
    
    if (SymbolDDA != SymbolDDABak) {
      DisplaySymbolDda(SymbolDDA);
      SymbolDDABak = SymbolDDA;
    }
    
    if (SymbolDTC != SymbolDTCBak) {
      DisplaySymbolDtc(SymbolDTC);
      SymbolDTCBak = SymbolDTC;
    }

    if (SymbolError != SymbolErrorBak) {
      DisplaySymbolError(SymbolError);
      SymbolErrorBak = SymbolError;
    }    
    
    if (SymbolFuel != SymbolFuelBak) {
      DisplaySymbolFuel(SymbolFuel);
      SymbolFuelBak = SymbolFuel;
    }
    
    if (SymbolKmh != SymbolKmhBak) {
      DisplaySymbolKmh(SymbolKmh);
      SymbolKmhBak = SymbolKmh;
    }
    
    if (SymbolLap != SymbolLapBak) {
      DisplaySymbolLap(SymbolLap);
      SymbolLapBak = SymbolLap;
    }
    
    if (SymbolMph != SymbolMphBak) {
      DisplaySymbolMph(SymbolMph);
      SymbolMphBak = SymbolMph;
    }

    if (SymbolTAir != SymbolTAirBak) {
      DisplaySymbolTair(SymbolTAir);
      SymbolTAirBak = SymbolTAir;
    }   
    
    if (SymbolTot != SymbolTotBak) {
      DisplaySymbolTot(SymbolTot);
      SymbolTotBak = SymbolTot;
    }
    
    if (SymbolTrip != SymbolTripBak) {
      DisplaySymbolTrip(SymbolTrip);
      SymbolTripBak = SymbolTrip;
    }

    if (SymbolWrench != SymbolWrenchBak) {
      DisplaySymbolWrench(SymbolWrench);
      SymbolWrenchBak = SymbolWrench;
    }    
    
    if (SymbolPM != SymbolPMBak) {
      DisplaySymbolPM(SymbolPM);
      SymbolPMBak = SymbolPM;  
    }

    if (SymbolAM != SymbolAMBak) {
      DisplaySymbolAM(SymbolAM);
      SymbolAMBak = SymbolAM;  
    }    
    
    if (gear != gearBak) {
      DisplaySendGear(gear);
      gearBak = gear;
    }
    
    if (tps != tpsBak) {
      DisplaySendTps(tps);
      tpsBak = tps;
    }
    
    if (clutch != clutchBak) {
      DisplaySymbolClutch(clutch);
      clutchBak = clutch;
    }
    
    if (SymbolStand != SymbolStandBak) {
      DisplaySymbolStand(SymbolStand);
      SymbolStandBak = SymbolStand;
    }

    if (TempText != TempTextBak) {
      DisplaySendTempText(TempText);
      TempTextBak = TempText;
    }
  }
}
