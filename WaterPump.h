int relay_pin2 = 14;


void water_on() {
  Serial.println("2 Hours");
  Serial.println("water punp [ ON ]");
  digitalWrite(relay_pin2, LOW);
  delay(300000); // 5 นาที 300000 ms
  Serial.println("water punp [ OFF ]");
  digitalWrite(relay_pin2, HIGH);
  delay(1000);
}
