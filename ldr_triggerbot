int LDR_Pin = A2; //analog pin 0
#include <Mouse.h>
void setup(){
Serial.begin(115200);
Mouse.begin();

}

void loop(){
int LDRReading = analogRead(LDR_Pin);

Serial.println(LDRReading);
//delay(2); //just here to slow down the output for easier reading

if (LDRReading >= 390 && LDRReading <= 420){
  //Mouse.click();
  delay(20);
}

}
