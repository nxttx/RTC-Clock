///////////////////////////////////////////////////////////////////////////////////////////
//Clock made with segment display                                                        //
//Made by: Robert Boudewijn                                                              //
//Date: 17/03/2020 17:14:00                                                              //
///////////////////////////////////////////////////////////////////////////////////////////

boolean checkButtonPressed(){
    if (digitalRead(BUTTON) == 1 ){
        return true;
    }else{
      return false;
    }
}
