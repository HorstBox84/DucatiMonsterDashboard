#ifndef MAIN_H_INCLUDED
#define MAIN_H_INCLUDED

#include <Arduino.h>

uint8_t TempSymbol = 0;
uint8_t TempBars = 0;

uint8_t RevSymbol = 0;
uint8_t RevBars = 0;

uint16_t OdoChar1 = 0;
uint8_t OdoColon1 = 0;
uint16_t OdoChar2 = 0;
uint16_t OdoChar3 = 0;
uint8_t OdoColon2 = 0;
uint8_t OdoDegree = 0;
uint16_t OdoChar4 = 0;
uint8_t OdoDP = 0;
uint16_t OdoChar5 = 0;

uint16_t SpeedChar1 = 0;
uint8_t SpeedDP1 = 0;
uint16_t SpeedChar2 = 0;
uint8_t SpeedDP2 = 0;
uint16_t SpeedChar3 = 0;

uint8_t SymbolKmh = 0;
uint8_t SymbolWrench = 0;
uint8_t SymbolTAir = 0;
uint8_t SymbolDTC = 0;
uint8_t SymbolDDA = 0;
uint8_t SymbolError = 0;
uint8_t SymbolTot = 0;
uint8_t SymbolMph = 0;
uint8_t SymbolFuel = 0;
uint8_t SymbolTrip = 0;
uint8_t SymbolPM = 0;
uint8_t SymbolAM = 0;
uint8_t SymbolLap = 0;

#endif