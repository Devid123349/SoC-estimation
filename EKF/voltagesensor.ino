const int voltageSensorPin = A0;          // sensor pin
float vIn;                                // measured voltage (3.3V = max. 16.5V, 5V = max 25V)
float vOut;
float voltageSensorVal;                   // value on pin A3 (0 - 1023)
const float factor = 5.128;               // reduction factor of the Voltage Sensor shield
const float vCC = 5.00;                   // Arduino input voltage (measurable by voltmeter)

void setup() {
  Serial.begin(9600);
}

void loop() {

  voltageSensorVal = analogRead(voltageSensorPin);    // read the current sensor value (0 - 1023) 
  vOut = (voltageSensorVal / 1024) * vCC;             // convert the value to the real voltage on the a nalog pin
  vIn =  vOut * factor;                               // convert the voltage on the source by multiplying with the factor

  Serial.println(vOut);

  Serial.print("Voltage = ");             
  Serial.print(vIn);
  Serial.println("V");

  delay(1000);
}
