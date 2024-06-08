void setup() {
  Serial.begin(115200);
}
void loop() {
  if(Serial.available())                                   // if there is data comming
  {
    String data = Serial.readStringUntil('\n');
    Serial.println(data);
  }
}