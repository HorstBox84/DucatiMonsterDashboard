#ifndef PARSEDATA_H_INCLUDED
#define PARSEDATA_H_INCLUDED

#include <Arduino.h>
#include <lookup.h>

extern uint8_t IicArray[];

extern uint8_t TempSymbol;
extern uint8_t TempBars;

extern uint8_t RevSymbol;
extern uint8_t RevBars;

extern uint16_t OdoChar1;
extern uint8_t OdoColon1;
extern uint16_t OdoChar2;
extern uint16_t OdoChar3;
extern uint8_t OdoColon2;
extern uint8_t OdoDegree;
extern uint16_t OdoChar4;
extern uint8_t OdoDP;
extern uint16_t OdoChar5;

extern uint16_t SpeedChar1;
extern uint8_t SpeedDP1;
extern uint16_t SpeedChar2;
extern uint8_t SpeedDP2;
extern uint16_t SpeedChar3;

extern uint8_t SymbolKmh;
extern uint8_t SymbolWrench;
extern uint8_t SymbolTAir;
extern uint8_t SymbolDTC;
extern uint8_t SymbolDDA;
extern uint8_t SymbolError;
extern uint8_t SymbolTot;
extern uint8_t SymbolMph;
extern uint8_t SymbolFuel;
extern uint8_t SymbolTrip;
extern uint8_t SymbolPM;
extern uint8_t SymbolAM;
extern uint8_t SymbolLap;

extern char textspeed[];
extern char textodo[];

void parseData();
void clearData();

char parseChar(uint16_t Symbol);
void parseTextOdo();
void parseTextSpeed();

#endif