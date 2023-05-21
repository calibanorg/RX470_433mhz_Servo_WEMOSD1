#include <RCSwitch.h>
#include <Servo.h>

#define BUTTON1_CODE    8750898 //use read out from your SonOff 4-Key Sender
#define BUTTON2_CODE    8750904 ////use read out from your SonOff 4-Key Sender
#define SERVO_PIN       2 //WEMOS D1 Mini Pro D4

RCSwitch mySwitch = RCSwitch();
Servo myservo;

void setup() {
  Serial.begin(115200);
  mySwitch.enableReceive(digitalPinToInterrupt(4)); //connect the module pin to GPIO4 / D2
  myservo.attach(SERVO_PIN);
  myservo.write(0); // Initialize the servo to 0 Degrees
}

void loop() {
  if (mySwitch.available()) {
    
    int value = mySwitch.getReceivedValue();
    
    if (value == BUTTON1_CODE) {
      Serial.print("Button Open");
      myservo.write(180); // Turn the servo 180 Degrees
    } else if (value == BUTTON2_CODE) {
      Serial.print("Button Closed");
      myservo.write(-180); // Turn the servo 180 Degrees back
    }

    mySwitch.resetAvailable();
  }
}
