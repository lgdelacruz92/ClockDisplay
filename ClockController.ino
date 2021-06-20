#include <PololuLedStrip.h>
#include "digit.h"

// Create an ledStrip object and specify the pin it will use.
PololuLedStrip<12> ledStrip;

// Create a buffer for holding the colors (3 bytes per color).
#define LED_COUNT 84 
#define DIGIT_NUM_LED = 21;


rgb_color colors[LED_COUNT];
rgb_color on = rgb_color(255,0,0);
rgb_color off = rgb_color(0,0,0);


Digit first;
Digit second;
Digit third;
Digit fourth;

int lastClockTime[] = {0,0,0,0};
String currentMessage = "";

unsigned long lastUpdatedDisplay = millis();
bool initialOn = false;

void convertDigit(Digit one, Digit two, Digit three, Digit four) {
  if (one._a){
    colors[0] = on;
    colors[1] = on;
    colors[2] = on;
  } else {
    colors[0] = off;
    colors[1] = off;
    colors[2] = off;
  }
  if (one._b){
    colors[3] = on;
    colors[4] = on;
    colors[5] = on;
  } else {
    colors[3] = off;
    colors[4] = off;
    colors[5] = off;
  }
  if (one._c){
    colors[6] = on;
    colors[7] = on;
    colors[8] = on;
  } else {
    colors[6] = off;
    colors[7] = off;
    colors[8] = off;
  }
  if (one._d){
    colors[9] = on;
    colors[10] = on;
    colors[11] = on;
  } else {
    colors[9] = off;
    colors[10] = off;
    colors[11] = off;
  }
  if (one._e){
    colors[12] = on;
    colors[13] = on;
    colors[14] = on;
  } else {
    colors[12] = off;
    colors[13] = off;
    colors[14] = off;
  }
  if (one._f){
    colors[15] = on;
    colors[16] = on;
    colors[17] = on;
  } else {
    colors[15] = off;
    colors[16] = off;
    colors[17] = off;
  }
  if (one._g){
    colors[18] = on;
    colors[19] = on;
    colors[20] = on;
  } else {
    colors[18] = off;
    colors[19] = off;
    colors[20] = off;
  }
  if (two._a){
    colors[21] = on;
    colors[22] = on;
    colors[23] = on;
  } else {
    colors[21] = off;
    colors[22] = off;
    colors[23] = off;
  }
  if (two._b){
    colors[24] = on;
    colors[25] = on;
    colors[26] = on;
  } else {
    colors[24] = off;
    colors[25] = off;
    colors[26] = off;
  }
  if (two._c){
    colors[27] = on;
    colors[28] = on;
    colors[29] = on;
  } else {
    colors[27] = off;
    colors[28] = off;
    colors[29] = off;
  }
  if (two._d){
    colors[30] = on;
    colors[31] = on;
    colors[32] = on;
  } else {
    colors[30] = off;
    colors[31] = off;
    colors[32] = off;
  }
  if (two._e){
    colors[33] = on;
    colors[34] = on;
    colors[35] = on;
  } else {
    colors[33] = off;
    colors[34] = off;
    colors[35] = off;
  }
  if (two._f){
    colors[36] = on;
    colors[37] = on;
    colors[38] = on;
  } else {
    colors[36] = off;
    colors[37] = off;
    colors[38] = off;
  }
  if (two._g){
    colors[39] = on;
    colors[40] = on;
    colors[41] = on;
  } else {
    colors[39] = off;
    colors[40] = off;
    colors[41] = off;
  }
  if (three._a){
    colors[42] = on;
    colors[43] = on;
    colors[44] = on;
  } else {
    colors[42] = off;
    colors[43] = off;
    colors[44] = off;
  }
  if (three._b){
    colors[45] = on;
    colors[46] = on;
    colors[47] = on;
  } else {
    colors[45] = off;
    colors[46] = off;
    colors[47] = off;
  }
  if (three._c){
    colors[48] = on;
    colors[49] = on;
    colors[50] = on;
  } else {
    colors[48] = off;
    colors[49] = off;
    colors[50] = off;
  }
  if (three._d){
    colors[51] = on;
    colors[52] = on;
    colors[53] = on;
  } else {
    colors[51] = off;
    colors[52] = off;
    colors[53] = off;
  }
  if (three._e){
    colors[54] = on;
    colors[55] = on;
    colors[56] = on;
  } else {
    colors[54] = off;
    colors[55] = off;
    colors[56] = off;
  }
  if (three._f){
    colors[57] = on;
    colors[58] = on;
    colors[59] = on;
  } else {
    colors[57] = off;
    colors[58] = off;
    colors[59] = off;
  }
  if (three._g){
    colors[60] = on;
    colors[61] = on;
    colors[62] = on;
  } else {
    colors[60] = off;
    colors[61] = off;
    colors[62] = off;
  }
  if (four._a){
    colors[63] = on;
    colors[64] = on;
    colors[65] = on;
  } else {
    colors[63] = off;
    colors[64] = off;
    colors[65] = off;
  }
  if (four._b){
    colors[66] = on;
    colors[67] = on;
    colors[68] = on;
  } else {
    colors[66] = off;
    colors[67] = off;
    colors[68] = off;
  }
  if (four._c){
    colors[69] = on;
    colors[70] = on;
    colors[71] = on;
  } else {
    colors[69] = off;
    colors[70] = off;
    colors[71] = off;
  }
  if (four._d){
    colors[72] = on;
    colors[73] = on;
    colors[74] = on;
  } else {
    colors[72] = off;
    colors[73] = off;
    colors[74] = off;
  }
  if (four._e){
    colors[75] = on;
    colors[76] = on;
    colors[77] = on;
  } else {
    colors[75] = off;
    colors[76] = off;
    colors[77] = off;
  }
  if (four._f){
    colors[78] = on;
    colors[79] = on;
    colors[80] = on;
  } else {
    colors[78] = off;
    colors[79] = off;
    colors[80] = off;
  }
  if (four._g){
    colors[81] = on;
    colors[82] = on;
    colors[83] = on;
  } else {
    colors[81] = off;
    colors[82] = off;
    colors[83] = off;
  }

}

void convertIntToDigit(int i, Digit& digit) {
  digit.reset();
  if (i == 0) {
    digit.zero();
  }
  if (i == 1) {
    digit.one();
  }
  if (i == 2) {
    digit.two();
  }
  if (i == 3) {
    digit.three();
  }
  if (i == 4) {
    digit.four();
  }
  if (i == 5) {
    digit.five();
  }
  if (i == 6) {
    digit.six();
  }
  if (i == 7) {
    digit.seven();
  }
  if (i == 8) {
    digit.eight();
  }
  if (i == 9) {
    digit.nine();
  }
}


void updateClockTime(String theReadValue) {
  Serial.println("Buffer read: " + theReadValue);

  if (theReadValue.indexOf("failed") == -1) {
    // Read the digits
    int startIndex = 0;
    while (theReadValue[startIndex] == ' ' || theReadValue[startIndex] == '\n') {
      startIndex++;
    }
    char firstDigit = theReadValue[startIndex];
    char secondDigit = theReadValue[startIndex+1];
    char thirdDigit = theReadValue[startIndex+3];
    char fourthDigit = theReadValue[startIndex+4];

    int fDigit = firstDigit - '0';
    int sDigit = secondDigit - '0';
    int tDigit = thirdDigit - '0';
    int frDigit = fourthDigit - '0';
    
    if (fDigit < 0 || fDigit > 9) {
      Serial.println("Error in fDigit: "  + String(fDigit));
      return;
    }

    if (sDigit < 0 || sDigit > 9) {
      Serial.println("Error in sDigit: " + String(sDigit));
      return;
    }

    if (tDigit < 0 || tDigit > 9) {
      Serial.println("Error in tDigit: "  + String(sDigit));
      return;
    }

    if (frDigit < 0 || frDigit > 9) {
      Serial.println("Error in frDigit: "  + String(sDigit));
      return;
    }
    
    // Update last clock time
    lastClockTime[0] = fDigit;
    lastClockTime[1] = sDigit;

    int hour = lastClockTime[0]*10+lastClockTime[1];
    if ( hour > 12) {
      lastClockTime[0] = 0;
      lastClockTime[1] = hour % 12;
    }
    

    lastClockTime[2] = tDigit;
    lastClockTime[3] = frDigit;

    Serial.println("Read " + String(lastClockTime[0]) + String(lastClockTime[1]) + ":" + String(lastClockTime[2]) + String(lastClockTime[3]));
  }
}


void setup() {
  // put your setup code here, to run once:

  Serial.begin(115200);
}

void loop() {
  

  
  if (Serial.available() > 0) {
    char c = Serial.read();
    if (c == '\n') {
      Serial.println("The read value " + currentMessage);
      updateClockTime(currentMessage);
      currentMessage = "";
    } else {
      currentMessage += String(c);
    }
  }
  convertIntToDigit(lastClockTime[0], first);
  convertIntToDigit(lastClockTime[1], second);
  convertIntToDigit(lastClockTime[2], third);
  convertIntToDigit(lastClockTime[3], fourth); 

  convertDigit(first, second, third, fourth);

  if (initialOn == false) {
    ledStrip.write(colors, LED_COUNT);
    initialOn = true;
  } else {
    if (millis() - lastUpdatedDisplay > 2000) {
      ledStrip.write(colors, LED_COUNT);
      lastUpdatedDisplay = millis();
    }
    
  }

  
}
