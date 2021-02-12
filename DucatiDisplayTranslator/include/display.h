#ifndef DISPLAY_H_INCLUDED
#define DISPLAY_H_INCLUDED

#include <Arduino.h>

extern char textspeed[];
extern char textodo[];

void DisplaySetBaudRate(long baudrate);
void DisplayTerminateMsg();
void DisplaySymbolWrench(byte visible);
void DisplaySymbolAM(byte visible);
void DisplaySymbolPM(byte visible);
void DisplaySymbolKmh(byte visible);
void DisplaySymbolMph(byte visible);
void DisplaySymbolDtc(byte visible);
void DisplaySymbolDda(byte visible);
void DisplaySymbolError(byte visible);
void DisplaySymbolLap(byte visible);
void DisplaySymbolTair(byte visible);
void DisplaySymbolTrip(byte visible);
void DisplaySymbolFuel(byte visible);
void DisplaySymbolTot(byte visible);
void DisplaySymbolRev(byte visible);
void DisplaySymbolTemp(byte visible);
void DisplayAllSymbolsOff();
void DisplaySendSpeed();
void DisplaySendOdo();
void DisplaySendRev(int rev);
void DisplaySendTemp(int temp);

#endif