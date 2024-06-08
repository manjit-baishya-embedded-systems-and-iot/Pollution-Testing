// defining the sensor input ports
const int zp07 = A0;
const int pm25 = A1;

// setting up the device
void setup() {

  // starting serial port
  Serial.begin(115200);

  // sedininf the pin modes
  pinMode(zp07, INPUT);
  pinMode(pm25, INPUT);
}

void loop() {

  // send data over serial port
  Serial.println(zp07());
  Serial.println(pm25());

  // delay
  delay(1000);
}

// get the value of ZP07 Sensor
int zp07(){

  // reading analog value
  int level = analogRead(zp07)/256;
  return level;
}

// get the value of PM2.5 Sensor
int pm25(){

  // reading analog value
  int level = analogRead(pm25)/256;
  return level;
}