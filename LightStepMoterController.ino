#include <Stepper.h>
 
const int STEPS = 2048;
Stepper stepper(STEPS, 8,10,9,11);
 
void setup()
{
  stepper.setSpeed(14);
  Serial.begin(9600);
  pinMode(6, INPUT); 
}
 

bool pos = false; //false => No light, true => Yes light 
void loop()
{

  
   if (digitalRead(6) == HIGH && pos == true) {
    
    Serial.println("CDS off");  // 빛이차단되면 출력됩니다
    int val = 180;
    val=map(val,0,360,0,2048); //회전각 스템 수
    stepper.step(val);
    Serial.println(val);
    delay(10);
    pos = false;

  }
 if (digitalRead(6) == LOW && pos == false) {
    
    Serial.println("CDS ON");  // 빛이감지되면 출력됩니다
    int val = -180;
    val=map(val,0,360,0,2048); //회전각 스템 수
    stepper.step(val);
    Serial.println(val);
    delay(10);
    pos = true;

  }

  if(Serial.available()) {
    int val=Serial.parseInt(); //회전각 int형으로 읽기
     
    val=map(val,0,360,0,2048); //회전각 스템 수
    stepper.step(val);
    Serial.println(val);
    delay(10);
  }
}