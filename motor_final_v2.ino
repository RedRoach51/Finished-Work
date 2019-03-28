#include <Servo.h>
#include <WemosInit.h>

#define motor1pin 2
#define motor2pin 14

// 377 ms is 3 inches away
// DO NOT use Turn functions, robot is being finnicky
Servo motor1; // Motor 1 is Left Wheel
Servo motor2; // Motor 2 is Right Wheel


boolean sensor_test = false;
boolean check = false;

void setup() {
  // put your setup code here, to run once:
  motor1.attach(motor1pin);
  motor2.attach(motor2pin);
  delay(3000);
  
  Serial.begin(115200);
  //Sensor Front
  pinMode(D4,OUTPUT); 
  pinMode(D3,INPUT);
  //Sensor Left
  pinMode(D6,OUTPUT);
  pinMode(D7,INPUT);
  //Sensor Right
  pinMode(D8, OUTPUT);
  pinMode(D2, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

  //right turn
  motor1.write(80);
  motor2.write(110);
  delay(640);
  pause();
  //correction for slight drift left
  motor1.write(72);
  motor2.write(74);
  delay(1400);
  //left turn
  motor1.write(100);
  motor2.write(82);
  delay(900);
  pause();
  backward();
  delay(1000);
  //correction for slight drift right
  motor1.write(72);
  motor2.write(74);
  delay(200);
  forward();
  delay(3000);
  backward();
  delay(1600);
  //right turn
  motor1.write(80);
  motor2.write(110);
  delay(400);
  pause();
  forward();
  delay(2450);
  //left turn
  motor1.write(100);
  motor2.write(82);
  delay(755);
  pause();
  forward();
  delay(2000);
  backward();
  delay(2900);
  forward();
  delay(500);
  //left turn
  motor1.write(100);
  motor2.write(82);
  delay(980);
  motor1.write(72);
  motor2.write(74);
  delay(3300);
    //forward();
  //delay(400);
  pause();xd
  delay(1010101010101);
}

void right_turn(){
  motor1.write(90);
  motor2.write(90);
  delay(400);
  motor1.write(83);
  motor2.write(100);
  //delay(950);
  delay(880);
  motor1.write(90);
  motor2.write(90);
  delay(500);
}

void left_turn(){
  motor1.write(90);
  motor2.write(90);
  delay(400);
  motor1.write(100);
  motor2.write(82);
  //delay(900);
  delay(830);
  motor1.write(90);
  motor2.write(90);
  delay(500);
}

void forward(){
  motor1.write(72);
  motor2.write(73);
}

void backward(){
  motor1.write(110);
  motor2.write(111);
}

void pause() {
  motor1.write(90);
  motor2.write(90);
  delay(200);
}
