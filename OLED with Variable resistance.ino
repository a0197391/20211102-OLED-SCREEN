#include <Wire.h>
#include "SSD1306Wire.h"
SSD1306Wire  display(0x3c, 21, 22);

void setup() {
    Serial.begin(115200);
    // Initialising the UI will init the display too.
    display.init();
    display.flipScreenVertically(); //畫面上下顛倒顯示
    display.clear(); //清空畫面
    display.setFont(ArialMT_Plain_16);   //設定字型與大小
    pinMode(12,INPUT);
    
}

void loop() {
  display.clear();  
  int input=analogRead(12);
  String myString=String(input);
  display.drawString(0,5,myString);
  display.display(); //顯示畫面
  Serial.println(input);
}

