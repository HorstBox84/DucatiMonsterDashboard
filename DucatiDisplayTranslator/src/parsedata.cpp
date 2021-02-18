#include <parsedata.h>

void parseData() {
  //Serial.println("Parsing Data");
  clearData();
  // Symbols
  SymbolKmh     = (IicArray[10] >> 0) & 0x01;
  SymbolWrench  = (IicArray[10] >> 1) & 0x01;
  SymbolTAir    = (IicArray[11] >> 7) & 0x01;
  SymbolDTC     = (IicArray[12] >> 3) & 0x01;
  SymbolDDA     = (IicArray[16] >> 3) & 0x01;
  SymbolError   = (IicArray[18] >> 7) & 0x01;
  SymbolTot     = (IicArray[19] >> 3) & 0x01;
  SymbolMph     = (IicArray[10] >> 2) & 0x01;
  SymbolFuel    = (IicArray[23] >> 3) & 0x01;
  SymbolTrip    = (IicArray[24] >> 7) & 0x01;
  SymbolPM      = (IicArray[25] >> 3) & 0x01;
  SymbolAM      = (IicArray[27] >> 3) & 0x01;
  SymbolLap     = (IicArray[14] >> 3) & 0x01;

  // Temp
  TempSymbol    = (IicArray[17] >> 0) & 0x01;
  TempBars      = ((IicArray[17] >> 4) & 0x01) +
                  ((IicArray[17] >> 6) & 0x01) +
                  ((IicArray[17] >> 5) & 0x01) +
                  ((IicArray[17] >> 7) & 0x01) +
                  ((IicArray[17] >> 3) & 0x01) +
                  ((IicArray[17] >> 1) & 0x01) +
                  ((IicArray[17] >> 2) & 0x01);

  // Rev
  RevSymbol    = (IicArray[ 9] >> 4) & 0x01;
  RevBars      = ((IicArray[ 9] >> 5) & 0x01) +
                  ((IicArray[ 9] >> 6) & 0x01) +
                  ((IicArray[32] >> 0) & 0x01) +
                  ((IicArray[32] >> 2) & 0x01) +
                  ((IicArray[32] >> 1) & 0x01) +
                  ((IicArray[32] >> 3) & 0x01) +
                  ((IicArray[32] >> 7) & 0x01) +
                  ((IicArray[32] >> 5) & 0x01) +
                  ((IicArray[32] >> 6) & 0x01) +
                  ((IicArray[32] >> 4) & 0x01) +
                  ((IicArray[31] >> 0) & 0x01) +
                  ((IicArray[31] >> 2) & 0x01) +
                  ((IicArray[31] >> 1) & 0x01) +
                  ((IicArray[31] >> 3) & 0x01) +
                  ((IicArray[31] >> 7) & 0x01) +
                  ((IicArray[31] >> 5) & 0x01) +
                  ((IicArray[31] >> 6) & 0x01) +
                  ((IicArray[31] >> 4) & 0x01) +
                  ((IicArray[30] >> 0) & 0x01) +
                  ((IicArray[30] >> 2) & 0x01) +
                  ((IicArray[30] >> 1) & 0x01) +
                  ((IicArray[30] >> 3) & 0x01) +
                  ((IicArray[30] >> 7) & 0x01) +
                  ((IicArray[30] >> 5) & 0x01) +
                  ((IicArray[30] >> 6) & 0x01) +
                  ((IicArray[30] >> 4) & 0x01) +
                  ((IicArray[29] >> 0) & 0x01) +
                  ((IicArray[29] >> 2) & 0x01) +
                  ((IicArray[29] >> 1) & 0x01) +
                  ((IicArray[29] >> 3) & 0x01) +
                  ((IicArray[29] >> 7) & 0x01) +
                  ((IicArray[29] >> 5) & 0x01) +
                  ((IicArray[29] >> 6) & 0x01) +
                  ((IicArray[29] >> 4) & 0x01) +
                  ((IicArray[28] >> 0) & 0x01) +
                  ((IicArray[28] >> 2) & 0x01) +
                  ((IicArray[28] >> 1) & 0x01) +
                  ((IicArray[28] >> 3) & 0x01) +
                  ((IicArray[28] >> 7) & 0x01) +
                  ((IicArray[28] >> 5) & 0x01) +
                  ((IicArray[28] >> 6) & 0x01) +
                  ((IicArray[28] >> 4) & 0x01) +
                  ((IicArray[ 9] >> 0) & 0x01) +
                  ((IicArray[ 9] >> 2) & 0x01) +
                  ((IicArray[ 9] >> 1) & 0x01) +
                  ((IicArray[ 9] >> 3) & 0x01) +
                  ((IicArray[10] >> 5) & 0x01) +
                  ((IicArray[10] >> 6) & 0x01) +
                  ((IicArray[10] >> 4) & 0x01);

  // character decoding odo
  OdoChar1 = (((IicArray[27] & 0xF7) << 8) | (IicArray[26] & 0x7F));
  OdoColon1 =     (IicArray[26] >> 7) & 0x01;
  OdoChar2 = (((IicArray[25] & 0xF7) << 8) | (IicArray[24] & 0x7F));
  OdoChar3 = (((IicArray[23] & 0xF7) << 8) | (IicArray[22] & 0x7F));
  OdoColon1 =     (IicArray[22] >> 7) & 0x01;
  OdoChar4 = (((IicArray[21] & 0xF7) << 8) | (IicArray[20] & 0x7F));
  OdoDegree =     (IicArray[21] >> 3) & 0x01;
  OdoDP =         (IicArray[20] >> 7) & 0x01;
  OdoChar5 = (((IicArray[19] & 0xF7) << 8) | (IicArray[18] & 0x7F));

  // character decoding speed
  SpeedChar1 = (((IicArray[16] & 0xF7) << 8) | (IicArray[15] & 0x7F));
  SpeedDP1 =     (IicArray[15] >> 7) & 0x01;
  SpeedChar2 = (((IicArray[14] & 0xF7) << 8) | (IicArray[13] & 0x7F));
  SpeedDP2 =     (IicArray[13] >> 7) & 0x01;
  SpeedChar3 = (((IicArray[12] & 0xF7) << 8) | (IicArray[11] & 0x7F));
}

char parseChar(uint16_t Symbol) {
    switch (Symbol) {
        case A_LFA:
        return('A');
        case B_RAVO:
        return('B');
        case C_HARLIE:
        return('C');
        case D_ELTA:
        return('D');
        case E_CHO:
        return('E');
        case F_OXTROT:
        return('F');
        case G_OLF:
        return('G');
        case H_OTEL:
        return('H');
        case I_NDIA:
        return('I');
        case J_ULIETT:
        return('J');
        case K_ILO:
        return('K');
        case L_IMA:
        return('L');
        case M_IKE:
        return('M');
        case N_OVEMBER:
        return('N');
        case N_OVEMBER_SMALL:
        return('n');
        case O_SCAR:
        return('O');
        case P_APA:
        return('P');
        case Q_UEBEC:
        return('Q');
        case R_OMEO:
        return('R');
        case S_IERRA:
        return('S');
        case T_ANGO:
        return('T');
        case U_NIFORM:
        return('U');
        case V_ICTOR:
        return('V');
        case W_HISKEY:
        return('W');
        case X_RAY:
        return('X');
        case Y_ANKEE:
        return('Y');
        case Z_ULU:
        return('Z');

        case ZERO:
        return('0');
        case ONE:
        return('1');
        case TWO:
        return('2');
        case THREE:
        return('3');
        case FOUR:
        return('4');
        case FIVE:
        return('5');
        case SIX:
        return('6');
        case SEVEN:
        return('7');
        case EIGHT:
        return('8');
        case NINE:
        return('9');
        
        case ALL_ON:
        return('0');

        default:
        return(' ');
        break;
    }
}

void clearData() {
    TempSymbol = 0;
    TempBars = 0;
    
    RevSymbol = 0;
    RevBars = 0;

    OdoChar1 = 0;
    OdoColon1 = 0;
    OdoChar2 = 0;
    OdoChar3 = 0;
    OdoColon2 = 0;
    OdoDegree = 0;
    OdoChar4 = 0;
    OdoDP = 0;
    OdoChar5 = 0;

    SpeedChar1 = 0;
    SpeedDP1 = 0;
    SpeedChar2 = 0;
    SpeedDP2 = 0;
    SpeedChar3 = 0;

    SymbolKmh = 0;
    SymbolWrench = 0;
    SymbolTAir = 0;
    SymbolDTC = 0;
    SymbolDDA = 0;
    SymbolError = 0;
    SymbolTot = 0;
    SymbolMph = 0;
    SymbolFuel = 0;
    SymbolTrip = 0;
    SymbolPM = 0;
    SymbolAM = 0;
    SymbolLap = 0;
}

void parseTextOdo() {
    textodo [0] = parseChar(OdoChar1);
    if (OdoColon1) {
      textodo[1] = ':';
    } 
    else {
      textodo[1] = ' ';
    }
    textodo [2] = parseChar(OdoChar2);
    textodo [3] = parseChar(OdoChar3);
    if (OdoColon2) {
      textodo[4] = ':';
    }
    else if (OdoDegree) {
      textodo[4] = '\°';
    }
    else {
      textodo[4] = ' ';
    }
    textodo [5] = parseChar(OdoChar4);
    if (OdoDP) {
      textodo[6] = '.';
    } 
    else {
      textodo[6] = ' ';
    }
    textodo [7] = parseChar(OdoChar5);

    // shift right
    int j = 6;
    int k = 0;
    while (j > 0) {
      if (textodo[j] == ' '){
        while (j - k > 0) {
          textodo[j - k] = textodo[j - k - 1];
          textodo[j - k - 1] = ' ';
          k++;
        }
        k = 0;
      }
      j--;
    }
}

void parseTextSpeed() {
    textspeed [0] = parseChar(SpeedChar1);
    if (SpeedDP1) {
      textspeed[1] = '.';
    } 
    else {
      textspeed[1] = ' ';
    }
    textspeed [2] = parseChar(SpeedChar2);
    if (SpeedDP2) {
      textspeed[3] = '.';
    }
    else {
      textspeed[3] = ' ';
    }
    textspeed [4] = parseChar(SpeedChar3);

    // shift right
    int j = 3;
    int k = 0;
    while (j > 0) {
      if (textspeed[j] == ' '){
        while (j - k > 0) {
          textspeed[j - k] = textspeed[j - k - 1];
          textspeed[j - k - 1] = ' ';
          k++;
        }
        k = 0;
      }
      j--;
    }
}