// define the pin for the ZP07-MP503 sensor
const int terminal_A = A0;  // terminal A is connected to analog pin A0
const int terminal_B = A1;  // terminal B is connected to analog pin A0

void setup() {
  // initialize the serial communication
  Serial.begin(9600);
  // configure the sensor pin as input
  pinMode(terminal_A, INPUT);
  pinMode(terminal_B, INPUT);
}

void loop() {
  // read the value from the sensor
  int value_A = analogRead(terminal_A);
  int value_B = analogRead(terminal_B);
  
  // print the sensor value to the serial monitor
  Serial.print("Sensor Value: ");
  Serial.println(value_A);
  Serial.println(value_B);
  
  // wait for 1 second before the next reading
  delay(1000);
}
