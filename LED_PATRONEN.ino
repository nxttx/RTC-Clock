///////////////////////////////////////////////////////////////////////////////////////////
//Clock made with segment display                                                        //
//Made by: Robert Boudewijn                                                              //
//Date: 17/03/2020 17:14:00                                                              //
///////////////////////////////////////////////////////////////////////////////////////////

byte number(int i) {
  const byte NUMBERS [] = {
    B11111100, //0
    B01100000, //1
    B11011010, //2
    B11110010, //3
    B01100110, //4
    B10110110, //5
    B10111110, //6
    B11100100, //7
    B11111110, //8
    B11110110, //9
    B11101110, //A
    B00111110, //B
    B10011100, //C
    B01111010, //D
    B10011110, //E
    B10001110  //F
  };
  return NUMBERS[i];
}

byte numberWithDot(int i) {
  const byte NUMBERS [] = {
    B11111101, //0.
    B01100001, //1.
    B11011011, //2.
    B11110011, //3.
    B01100111, //4
    B10110111, //5
    B10111111, //6
    B11100101, //7
    B11111111, //8
    B11110111, //9
    B11101111, //A
    B00111111, //B
    B10011101, //C
    B01111011, //D
    B10011111, //E
    B10001111  //F
  };
  return NUMBERS[i];
}

boolean isBitSet(byte pattern, int index) {
  byte check = B00000001 << index;
  return  ((pattern & check)  == check);
}

void displayBinair(byte patroon) {
  for ( int i = 0; i < 8; i++) {
    if ( isBitSet(patroon, i) == true) {
      digitalWrite(DS, HIGH);
    }
    else {
      digitalWrite(DS, LOW);
    }
    digitalWrite(SH_CP, HIGH);
    digitalWrite(SH_CP, LOW);
  }
  digitalWrite(ST_CP, HIGH);
  digitalWrite(ST_CP, LOW);
}
