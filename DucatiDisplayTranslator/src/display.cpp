#include <display.h>

void DisplaySetBaudRate(long baudrate) {
  Serial.print("baud=");
  Serial.print(baudrate);
  DisplayTerminateMsg();
  delay(100);
  Serial.end();
  delay(100);
  Serial.begin(baudrate);
}

void DisplayTerminateMsg() {
  Serial.write(0xFF);
  Serial.write(0xFF);
  Serial.write(0xFF);
}

void DisplaySymbolWrench(byte visible) {
  Serial.print("vis wrench,");
  Serial.print(visible);
  DisplayTerminateMsg();
}

void DisplaySymbolAM(byte visible) {
  Serial.print("vis am,");
  Serial.print(visible);
  DisplayTerminateMsg();
}

void DisplaySymbolPM(byte visible) {
  Serial.print("vis pm,");
  Serial.print(visible);
  DisplayTerminateMsg();
}

void DisplaySymbolKmh(byte visible) {
  Serial.print("vis kmh,");
  Serial.print(visible);
  DisplayTerminateMsg();
}

void DisplaySymbolMph(byte visible) {
  Serial.print("vis mph,");
  Serial.print(visible);
  DisplayTerminateMsg();
}

void DisplaySymbolDtc(byte visible) {
  Serial.print("vis dtc,");
  Serial.print(visible);
  DisplayTerminateMsg();
}

void DisplaySymbolDda(byte visible) {
  Serial.print("vis dda,");
  Serial.print(visible);
  DisplayTerminateMsg();
}

void DisplaySymbolError(byte visible) {
  Serial.print("vis error,");
  Serial.print(visible);
  DisplayTerminateMsg();
}

void DisplaySymbolLap(byte visible) {
  Serial.print("vis lap,");
  Serial.print(visible);
  DisplayTerminateMsg();
}

void DisplaySymbolTair(byte visible) {
  Serial.print("vis tair,");
  Serial.print(visible);
  DisplayTerminateMsg();
}

void DisplaySymbolTrip(byte visible) {
  Serial.print("vis trip,");
  Serial.print(visible);
  DisplayTerminateMsg();
}

void DisplaySymbolFuel(byte visible) {
  Serial.print("vis fuel,");
  Serial.print(visible);
  DisplayTerminateMsg();
}

void DisplaySymbolTot(byte visible) {
  Serial.print("vis tot,");
  Serial.print(visible);
  DisplayTerminateMsg();
}

void DisplaySymbolRev(byte visible) {
  Serial.print("vis rev,");
  Serial.print(visible);
  DisplayTerminateMsg();
}

void DisplaySymbolClutch(byte visible) {
  Serial.print("vis clutch,");
  Serial.print(visible);
  DisplayTerminateMsg();
}

void DisplaySymbolStand(byte visible) {
  Serial.print("vis stand,");
  Serial.print(visible);
  DisplayTerminateMsg();
}

void DisplaySymbolTemp(byte visible) {
  Serial.print("vis temp,");
  Serial.print(visible);
  DisplayTerminateMsg();
}

void DisplayAllSymbolsOff() {
  DisplaySymbolDda(0);
  DisplaySymbolDtc(0);
  DisplaySymbolWrench(0);
  DisplaySymbolMph(0);
  DisplaySymbolKmh(0);
  DisplaySymbolError(0);
  DisplaySymbolLap(0);
  DisplaySymbolTair(0);
  DisplaySymbolTrip(0);
  DisplaySymbolFuel(0);
  DisplaySymbolTot(0);
  DisplaySymbolClutch(0);
  DisplaySymbolTemp(0);
  DisplaySymbolPM(0);
  DisplaySymbolAM(0);
}

void DisplaySendGear(int gear) {
  Serial.print("textgear.txt=\"");
  if (gear > 0) {
    Serial.print(gear);
  }
  else {
    Serial.print("N");
  }
  Serial.print("\"");
  DisplayTerminateMsg();
}

void DisplaySendTempText(int temp) {
  Serial.print("texttemp.txt=\"");
  Serial.print(temp);
  Serial.print("\°C");
  Serial.print("\"");
  DisplayTerminateMsg();
}

void DisplaySendTps(int tps) {
  Serial.print("texttps.txt=\"");
  Serial.print(tps);
  Serial.print("\%");
  Serial.print("\"");
  DisplayTerminateMsg();
}

void DisplaySendSpeed() {
  Serial.print("textspeed.txt=\"");
  Serial.print(textspeed[0]);
  if (textspeed[1] != ' ') {
    Serial.print(textspeed[1]);
  }
  Serial.print(textspeed[2]);
  if (textspeed[3] != ' ') {
    Serial.print(textspeed[3]);
  }
  Serial.print(textspeed[4]);
  Serial.print("\"");
  DisplayTerminateMsg();
}

void DisplaySendOdo() {
  Serial.print("textodo.txt=\"");
  Serial.print(textodo[0]);
  if (textodo[1] != ' ') {
    Serial.print(textodo[1]);
  }
  Serial.print(textodo[2]);
  Serial.print(textodo[3]);
  if (textodo[4] != ' ') {
    Serial.print(textodo[4]);
  }
  Serial.print(textodo[5]);
  if (textodo[6] != ' ') {
    Serial.print(textodo[6]);
  }
  Serial.print(textodo[7]);
  Serial.print("\"");
  DisplayTerminateMsg();
}

void DisplaySendRev(int rev) {
  Serial.print("rev.val=");
  Serial.print(rev);
  DisplayTerminateMsg();
}

void DisplaySendTemp(int temp) {
  Serial.print("temp.val=");
  Serial.print(temp);
  DisplayTerminateMsg();
}