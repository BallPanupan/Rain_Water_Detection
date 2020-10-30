int inPin = 2;    
int rain_val;      
int relay_pin = 15; 

int led_pin1 = 7;
int led_pin2 = 8;
int led_pin3 = 9;

int buttonPin1 = 4;
int buttonPin2 = 5;
int buttonPin3 = 6;
int buttonState1 = 0;
int buttonState2 = 0;
int buttonState3 = 0;

void setup() {
  Serial.begin(9600);
  pinMode(inPin, INPUT);   
   
  pinMode(buttonPin1, INPUT);
  pinMode(buttonPin2, INPUT);
  pinMode(buttonPin3, INPUT);
  
  pinMode(relay_pin, OUTPUT);

  pinMode(led_pin1, OUTPUT);
  pinMode(led_pin2, OUTPUT);
  pinMode(led_pin3, OUTPUT);

  
}

void loop() {
  buttonState1 = digitalRead(buttonPin1);
  buttonState2 = digitalRead(buttonPin2);
  buttonState3 = digitalRead(buttonPin3);

  
  //เช็คฝน 1 = ไม่มีฝน | 0 = มีฝน
  rain_val = digitalRead(inPin);   
  Serial.println(rain_val);

  if (buttonState1 == HIGH) {
    // turn LED on:
    Serial.println("_________ on 1");
    digitalWrite(led_pin1, HIGH);
    pinMode(relay_pin, HIGH);
    delay(10000);
  }else{
    digitalWrite(led_pin1, LOW);
    pinMode(relay_pin, LOW);
    }
  if (buttonState2 == HIGH) {
    // turn LED on:
    Serial.println("_________ on 2");
    digitalWrite(led_pin2, HIGH);
  }else{
    digitalWrite(led_pin2, LOW);
    }
  if (buttonState3 == HIGH) {
    // turn LED on:
    Serial.println("_________ on 3");
    digitalWrite(led_pin3, HIGH);
  }else{
    digitalWrite(led_pin3, LOW);
    }

  if(rain_val == 1){
    pinMode(relay_pin, LOW);
    }
  else{
    pinMode(relay_pin, HIGH);
    }
    
  delay(200);
}
  
