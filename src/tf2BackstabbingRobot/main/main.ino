String InBytes;
int LED = 2;
int micPin=5;
boolean val= 0;

void setup(){
  Serial.begin(9600);
  pinMode(LED, OUTPUT);
  pinMode(micPin, INPUT);
}

void loop(){

  val = digitalRead(micPin);
  Serial.println(val);

  if(val==HIGH){
    digitalWrite(LED, HIGH);
    Serial.println("on");
  }else{
    digitalWrite(LED, LOW);
    Serial.println("off");
  }
  /*
  if(Serial.available() > 0){
    InBytes = Serial.readStringUntil('\n');
    if(InBytes == "on"){
      digitalWrite(LED, HIGH);
      Serial.write("LED ON");
    }else if(InBytes == "off"){
      digitalWrite(LED, LOW);
      Serial.write("LED OFF");
    }else{
      Serial.write("invalid information");
    }
  }
  */
}
