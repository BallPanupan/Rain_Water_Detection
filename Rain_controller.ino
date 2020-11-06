int inPin = 2;  

int analogPin = A0;  
int val2 = 0;

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

int water_Detection = 28800000;// 480 minute | 8 hourst = 28800000
int time_btn1 = 3000; // 3 ms
int time_btn2 = 3600000; // 60 minute = 3600000
int time_btn3 = 28800000;// 480 minute | 8 hourst = 28800000

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
  val2 = analogRead(analogPin);
  Serial.print("val = "); // พิมพ์ข้อมความส่งเข้าคอมพิวเตอร์ "val = "
  Serial.println(val2); // พิมพ์ค่าของตัวแปร val
  
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
    Serial.println("3 ms");
    delay(time_btn1); // is 'time_btn1'
  }else{
    digitalWrite(led_pin1, LOW);
    pinMode(relay_pin, LOW);
    }
  if (buttonState2 == HIGH) {
    // turn LED on:
    Serial.println("_________ on 2");
    digitalWrite(led_pin2, HIGH);
    pinMode(relay_pin, HIGH);
    Serial.println("60 minute");
    delay(time_btn2); // is 'time_btn2'
    
  }else{
    digitalWrite(led_pin2, LOW);
    pinMode(relay_pin, LOW);
    }
  if (buttonState3 == HIGH) {
    // turn LED on:
    Serial.println("_________ on 3");
    digitalWrite(led_pin3, HIGH);
    pinMode(relay_pin, HIGH);
    Serial.println("3 Hours");
    delay(time_btn3);// is 'time_btn3'
  }else{
    digitalWrite(led_pin3, LOW);
    pinMode(relay_pin, LOW);
    }

  if(rain_val == 1){ //is water_Detection
    pinMode(relay_pin, LOW);
    }
  else{
    pinMode(relay_pin, HIGH);
    delay(water_Detection);
    }
    
  delay(200);
}
  
