/*************************************
****** Ambient Light Sensor **********
****** MStronik.blog *****************/
#define ALS_pin  A0
/*#define Led_pinB 2
#define Led_pinG 3
#define Led_pinR 4*/
int Led_pinB = 2;
int Led_pinG = 3;
int Led_pinR = 4;
int dark_AL = 20; // change this value according with your ALS reading, when it is dark in the room
int normal_AL = 100;// change this value according with your ALS reading, when there is normal light in the room
int  bright_AL = 600;// change this value according with your ALS reading, when it is too bright
void setup() {
  pinMode(ALS_pin, INPUT);
  pinMode(Led_pinB, OUTPUT);
  pinMode(Led_pinG, OUTPUT);
  pinMode(Led_pinR, OUTPUT);
  Serial.begin(9600);
  digitalWrite(Led_pinB, LOW);
  digitalWrite(Led_pinG, LOW);
  digitalWrite(Led_pinR, LOW);
}

void loop() {
  float valueSensor = analogRead(ALS_pin);//read the ALS value
  Serial.print("ALS wert: ");
  Serial.println(valueSensor);
  delay(500);
  if((valueSensor < dark_AL )&&(valueSensor >0 ))
  {
    digitalWrite(Led_pinB,HIGH);
    digitalWrite(Led_pinG,HIGH);
    digitalWrite(Led_pinR,HIGH);
    }
  else if((valueSensor >= dark_AL)&&(valueSensor < normal_AL))
  {
    digitalWrite(Led_pinB,LOW);
    digitalWrite(Led_pinG,HIGH);
    digitalWrite(Led_pinR,LOW);
    }
  else  
    {
      digitalWrite(Led_pinB,LOW);
      digitalWrite(Led_pinG,LOW);
      digitalWrite(Led_pinR,HIGH);
      }
}
