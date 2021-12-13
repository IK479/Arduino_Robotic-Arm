#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

// called this way, it uses the default address 0x40
Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();// motor 0
Adafruit_PWMServoDriver pwm1 = Adafruit_PWMServoDriver();// motor 1
Adafruit_PWMServoDriver pwm2 = Adafruit_PWMServoDriver();// motor 2
Adafruit_PWMServoDriver pwm3 = Adafruit_PWMServoDriver();// motor 3
Adafruit_PWMServoDriver pwm4 = Adafruit_PWMServoDriver();// motor 4
Adafruit_PWMServoDriver pwm5 = Adafruit_PWMServoDriver();// motor 5

int degrees;
int servoAngleArray[6] = {"NULL"};
int potentiometerArray[6] = {"NULL"};
int pulselenArray[6] = {"NULL"};

    
long unsigned int time;
int servosLocation[3][6]={"NULL"};
bool whileRecording= true, theRecordingHasFinished;
int stopLoop,timeForRestoreTheMovement, stuckInTheRestoring=0;

const byte PIN_ANALOG_X = 6;
const byte PIN_ANALOG_Y = 7;
int x_position;
int y_position;

#define ledPin 6
#define switchPin 9
long unsigned int currentTime; 


void setup() {

  //motor 0:
  pwm.begin();
  pwm.setOscillatorFrequency(27000000);
  pwm.setPWMFreq(50);  // Analog servos run at ~50 Hz updates

  //motor 1:
  pwm1.begin();
  pwm1.setOscillatorFrequency(27000000);
  pwm1.setPWMFreq(50);  // Analog servos run at ~50 Hz updates

  //motor 2:
  pwm2.begin();
  pwm2.setOscillatorFrequency(27000000);
  pwm2.setPWMFreq(50);  // Analog servos run at ~50 Hz updates

  //motor 3:
  pwm3.begin();
  pwm3.setOscillatorFrequency(27000000);
  pwm3.setPWMFreq(50);  // Analog servos run at ~50 Hz updates

  //motor 4:
  pwm4.begin();
  pwm4.setOscillatorFrequency(27000000);
  pwm4.setPWMFreq(50);  // Analog servos run at ~50 Hz updates

  //motor 5:
  pwm5.begin();
  pwm5.setOscillatorFrequency(27000000);
  pwm5.setPWMFreq(50);  // Analog servos run at ~50 Hz updates

  pinMode(2,OUTPUT);
  Serial.begin(115200);
  potentiometerArray[0]= analogRead(A0);// motor 0
  potentiometerArray[1]= analogRead(A1);// motor 1
  potentiometerArray[2]= analogRead(A2);// motor 2
  potentiometerArray[3]= analogRead(A3);// motor 3
  potentiometerArray[4]= analogRead(A6);// motor 4
  potentiometerArray[5]= analogRead(A7);// motor 5

  stopLoop= 0;
  theRecordingHasFinished= false;

  pinMode(switchPin, INPUT);
  pinMode(ledPin, OUTPUT);
}

void loop() {
    armControllerMovement(); //Enble arm movement  
}


void armControllerMovement(){
  
  //those lines control on motor 0:
  potentiometerArray[0]= analogRead(A0);
  servoAngleArray[0] = map(potentiometerArray[0], 0, 1023, 0, 180);

  degrees = servoAngleArray[0];
  pulselenArray[0] = map(degrees, 0, 180, 800, 2200);
  pwm.writeMicroseconds(0, pulselenArray[0]); 


  
  //those lines control on motor 1:
  potentiometerArray[1]= analogRead(A1);
  servoAngleArray[1]= map( potentiometerArray[1], 0, 1023, 0, 180);

  degrees = servoAngleArray[1];
  pulselenArray[1] = map(degrees, 0, 180, 800, 2200);
  pwm1.writeMicroseconds(1, pulselenArray[1]); 



  //those lines control on motor 2:
  potentiometerArray[2]= analogRead(A2);
  servoAngleArray[2]= map( potentiometerArray[2], 0, 1023, 0, 180);
  
  degrees = servoAngleArray[2];
  pulselenArray[2] = map(degrees, 0, 180, 800, 2000);
  pwm2.writeMicroseconds(2, pulselenArray[2]); 



  //those lines control on motor 3:
  potentiometerArray[3]= analogRead(A3);
  servoAngleArray[3]= map( potentiometerArray[3], 0, 1023, 0, 180);

  degrees = servoAngleArray[3];
  pulselenArray[3] = map(degrees, 0, 180, 800, 2200);
  pwm3.writeMicroseconds(3, pulselenArray[3]); 



  //those lines control on motor 4:
  potentiometerArray[4]= analogRead(PIN_ANALOG_X);
  servoAngleArray[4]= map( potentiometerArray[4], 0, 1023, 0, 180);

  degrees = servoAngleArray[4];
  pulselenArray[4] = map(degrees, 0, 180, 800, 2200);
  pwm4.writeMicroseconds(4, pulselenArray[4]); 



  
  //those lines control on motor 5:
  potentiometerArray[5]= analogRead(PIN_ANALOG_Y);
  servoAngleArray[5]= map( potentiometerArray[5], 0, 1023, 0, 180);

  degrees = servoAngleArray[5];
  pulselenArray[5] = map(degrees, 0, 180, 800, 2200);
  pwm5.writeMicroseconds(5, pulselenArray[5]); 
  
}


  

 
