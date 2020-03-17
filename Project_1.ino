///////////////////////////////////////////////////////////////////////////////////////////
//Clock made with segment display                                                        //
//Made by: Robert Boudewijn                                                              //
//Date: 17/03/2020 17:14:00                                                              //
///////////////////////////////////////////////////////////////////////////////////////////

// RTC --------------
#include <RTClib.h>
RTC_DS1307 rtc;

//Button -------------
const int BUTTON = 2;

//switch case --------
const int QUARTERS = 0;
const int HOURS = 1;
const int DAYS = 2;
const int MONTHS = 3;
int currentMode = 0;

//software timer ------
unsigned long int currentMillis;
const int INTERVAL = 150;
unsigned long int previousMillis = 0 - INTERVAL;

//shift register------
const int DS = 8;     // Hiermee geef je door hoeveel ledjes aan moeten staan
const int SH_CP = 10; // clock
const int ST_CP = 9;  // latch pin/ einde van send.


void setup() {

  Serial.begin(9600);
  startShiftRegsister();
  rtc.begin();

}
void loop() {
  DateTime now = rtc.now();
  currentMillis = millis();
  switch (currentMode) {
    case QUARTERS:
    int minutes = now.minute();
    int quarter =15;
    if(minutes >= 7+ (quarter*3) || minutes <= 7){
      displayBinair(numberWithDot(0));
    }else if(minutes >= 7 && minutes <= 7+ (quarter*1)){
      displayBinair(numberWithDot(1));
    }else if(minutes >= 7+ (quarter*1) && minutes <=7+ (quarter*2)){
      displayBinair(numberWithDot(2));
    } else if (minutes >= 7+ (quarter*2) && minutes  <= 7+ (quarter*3)){
      displayBinair(numberWithDot(3));
    }
      Serial.println("display QUARTERS");
      break;

    case HOURS:
      Serial.println("display HOURS");
      if(now.hour() < 12){
        displayBinair(number(now.hour()));
      }else{
        int hours= now.hour() - 12;
        displayBinair(numberWithDot(hours));
      }
      break;

    case DAYS:  //moet nog gecontroleerd worden. 
      Serial.println("display DAYS");
            if(now.day() < 15){
        displayBinair(number(now.day()));
      }else{
        int days= now.day() - 15;
        displayBinair(numberWithDot(days));
      }
      break;

    case MONTHS:  //moet nog gecontroleerd worden.
      Serial.println("display MONTHS");
      displayBinair(number(now.month()));
      break;

  }
  if (currentMillis - previousMillis >= INTERVAL) {
    previousMillis = currentMillis;
    if (checkButtonPressed()) {
      currentMode++;
      if (currentMode >= 4) {
        currentMode = 0;
      }

    }
  }
}
