const int sensorPin = A0;  // assuming the sensor is connected to analog pin A0

void setup() {

  Serial.begin(15200);

  pinMode(sensorPin, INPUT);
}

void loop() {

  int sensorValue = analogRead(sensorPin);

  Serial.println(sensorValue);

  delay(1000);
}
