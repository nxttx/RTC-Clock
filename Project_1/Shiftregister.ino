///////////////////////////////////////////////////////////////////////////////////////////
//Clock made with segment display                                                        //
//Made by: Robert Boudewijn                                                              //
//Date: 17/03/2020 17:14:00                                                              //
///////////////////////////////////////////////////////////////////////////////////////////

void startShiftRegsister(){
  pinMode(DS, OUTPUT);
  pinMode(SH_CP, OUTPUT);
  pinMode(ST_CP, OUTPUT);

  digitalWrite(DS, LOW);
  digitalWrite(SH_CP, LOW);
  digitalWrite(ST_CP, LOW);

  // every thing off
  digitalWrite(DS, LOW);
  for ( int i = 0; i < 8; i++) {
    digitalWrite(SH_CP, HIGH);
    digitalWrite(SH_CP, LOW);
  }
  digitalWrite(ST_CP, HIGH);
  digitalWrite(ST_CP, LOW);

}
