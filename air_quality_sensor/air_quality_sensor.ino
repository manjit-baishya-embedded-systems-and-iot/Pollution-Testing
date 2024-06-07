// define the pin for the ZP07-MP503 sensor
const int sensorPin = A0;  // assuming the sensor is connected to analog pin A0

void setup() {
  // initialize the serial communication
  Serial.begin(9600);
  // configure the sensor pin as input
  pinMode(sensorPin, INPUT);
}

void loop() {
  // read the value from the sensor
  int sensorValue = analogRead(sensorPin);
  // print the sensor value to the serial monitor
  Serial.print("Sensor Value: ");
  Serial.println(sensorValue);
  // wait for 1 second before the next reading
  delay(1000);
}
