#include <Mouse.h>

#include <SoftwareSerial.h>

int isObstaclePin = 2;
int isObstaclePin2 = 3;
int right = LOW; //HIGH MEANS NO OBSTACLE
int left = LOW;


void setup() {

  //mouse setup
  
  
  //IR setup
  Serial.begin(9600);
  Serial.println("IR SETUP");
  pinMode(isObstaclePin, INPUT);

  
  
    
}

void loop() {

  right = digitalRead(isObstaclePin);
  left = digitalRead(isObstaclePin);

  if(right == LOW || left == LOW){
    //simulate mouse click through python script
    Serial.println("HOLA AMIGOS");
  }
}
