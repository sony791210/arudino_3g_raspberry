void setup() {
  Serial.begin(9600);
  if(DEBUG) Serial.begin(serialBaudrate);                   // initialize serial
  while (!Serial);
}

