#include "FlexHand.h"
#include <Servo.h>

Servo ringS, thumbS, pinkyS, middleS, indexS;

int servoPin1 = 5; // ring
int servoPin2 = 2; // thumb
int servoPin3 = 9;// pinky
int servoPin4 = 11; // middle
int servoPin5 = 3; // index

int maxRing = 700;
int maxThumb = 650;
int maxPinky = 700;
int maxMiddle = 640;
int maxIndex = 700;

int minRing = 450;
int minThumb = 380;
int minPinky = 450;
int minMiddle = 480;
int minIndex = 450;

FlexHand ring(A0, minRing, maxRing, 12, AVG);
FlexHand thumb(A1, minThumb, maxThumb, 12, AVG);
FlexHand pinky(A2, minPinky, maxPinky, 12, AVG);
FlexHand middle(A3, minMiddle, maxMiddle, 12, AVG);
FlexHand index(A4, minIndex, maxIndex, 12, AVG);

void setup(){
  ringS.attach(servoPin1);
  thumbS.attach(servoPin2);
  pinkyS.attach(servoPin3);
  middleS.attach(servoPin4);
  indexS.attach(servoPin5);
  
  ringS.turn(90);
  thumbS.turn(90);
  pinkyS.turn(90);
  middleS.turn(90);
  indexS.turn(90);

  for(int i = 0; i < 3000; i++){
    ring.Calibrate();
    thumb.Calibrate();
    pinky.Calibrate();
    middle.Calibrate();
    index.Calibrate();
  }
}

void loop(){
  ring.updateVal();
  thumb.updateVal();
  pinky.updateVal();
  middle.updateVal();
  index.updateVal();

  int ringPos = map(ring.getSensorValue(), minRing, maxRing, 180, 0);
  ringPos = constrain(ringPos, 0, 180);
  int thumbPos = map(thumb.getSensorValue(), minThumb, maxThumb, 180, 0);
  thumbPos = constrain(thumbPos, 0, 180);
  int pinkyPos = map(pinky.getSensorValue(), minPinky, maxPinky, 0, 180);
  pinkyPos = constrain(pinkyPos, 0, 180);
  int middlePos = map(middle.getSensorValue(), minMiddle, maxMiddle, 0, 180);
  middlePos = constrain(middlePos, 0, 180);
  int indexPos = map(index.getSensorValue(), minIndex, maxIndex, 0, 180);
  indexPos = constrain(indexPos, 0, 180);

  
  //Tells servos to move by the amount specified in the "pos" variables
  ringS.write(ringPos);
  thumbS.write(thumbPos);
  pinkyS.write(pinkyPos);
  middleS.write(middlePos);
  indexS.write(indexPos);


}
