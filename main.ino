#include "Arduino.h"
#include "DFRobotDFPlayerMini.h"

DFRobotDFPlayerMini myDFPlayer;

unsigned long mytime;
unsigned long t0;
unsigned long t1;
unsigned long t2;
unsigned long t3;
unsigned long t4;

unsigned long tEnd      = 60000;
unsigned long tBg       = 300;
unsigned long tStrobo   = 200;
unsigned long tTirai    = 1000;
unsigned long tMaju     = 2000;
unsigned long tTangan   = 3500;
unsigned long tAxis1    = 400;
unsigned long tAxis2    = 500;
unsigned long tAxis3    = 300;

unsigned long delStart  = 0;
unsigned long delFire   = 5000;

#define trigPin  11
#define echoPin  12
#define lightPin 13

int state  = 0;
int state1 = 0;
int state2 = 0;
int dis = 100;

String arr[50] = {};
int i;
int o;

void setup() {
  Serial.begin(9600);
  Serial1.begin(9600);
  myDFPlayer.begin(Serial1);
  myDFPlayer.volume(30);
  myDFPlayer.play(1);
  delay(1000);
  myDFPlayer.stop();
  
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);

  pinMode(trigPin,  OUTPUT);
  pinMode(echoPin,  INPUT);
  pinMode(lightPin, INPUT);

  for (int i = 2;i<=7;i++){
    digitalWrite(i, HIGH);
  }

  mytime = 0;
  t0 = 0;
  t1 = 0;
  t2 = 0;
  t3 = 0;
  t4 = 0;
}

void loop() {

  int lig = digitalRead(lightPin);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  int dur = pulseIn(echoPin, HIGH);
  dis = 0.017 * dur;

//  if (lig == 0){
//    myDFPlayer.play(1);
//    for (int i = 2;i<=7;i++){
//      digitalWrite(i, HIGH);
//    }
//    delay(delFire);
//    state = 0;
//  }

  if (dis <=100 ){
    o = 1;
  } else {
    o = 0;
  }

  arr[i] = o;
  if (i == 49){
    i = 0;
  }
  i = i + 1;

  if (arr[1] == "1" && arr[17] == "1" && arr[35] == "1" && state == 0){
    state  = 1;
    state1 = 1;
    mytime = millis();
    Serial.print("A");
    delay(delStart);
    myDFPlayer.play(1);
    mytime = millis();
    t0 = millis();
    t1 = millis();
    t2 = millis();
    t3 = millis();
    t4 = millis();
  }else if (arr[1] == "1" && arr[17] == "1" && arr[35] == "1" && state == 1){
    if (millis() - mytime >= tEnd){
      state = 2;
    }
    digitalWrite(2, LOW);
    mode0(); 
    mode1(); 
    mode2(); 
    //mode3();
    Serial.print("B");
  }else if (arr[1] == "0" && arr[17] == "0" && arr[35] == "0" && state == 1){
    state = 0;
    Serial.print("C");
    delay(5000);
  }else if (arr[1] == "0" && arr[17] == "0" && arr[35] == "0" && state == 2){
    state = 0;
    Serial.print("C");
    delay(5000);
  }else {
    Serial.print("D");
    for (int i = 2;i<=7;i++){
      digitalWrite(i, HIGH);
    }
  }  

  delay(20);
  Serial.print(i);
  Serial.print("\t");
  Serial.print(dis);
  Serial.print("\t");
  Serial.print(arr[1]);
  Serial.print(arr[17]);
  Serial.print(arr[35]);
  Serial.print("\t");
  Serial.print(millis() - mytime);
  Serial.print("\t");
  Serial.println(state);

}
