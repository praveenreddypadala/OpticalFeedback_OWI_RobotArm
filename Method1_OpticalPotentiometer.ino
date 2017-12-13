Simple Analog Read to read the voltage across the IR Receiver based on the amount of light falling

int sensorPin1 = A0;    // select the input pin for the potentiometer

int sval = 0;  // variable to store the value coming from the sensor

void setup() {

  Serial.begin(9600);
}

void loop() {
  // read the value from the sensor:
  sval = analogRead(A0);   

  Serial.println(sval);

  delay(5);  
}
