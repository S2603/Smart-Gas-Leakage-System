#define buz 5
void setup()

{
  pinMode(buz,OUTPUT);
  Serial.begin(9600);      // Start Serial Communication/ Baud Rate

}
void loop()

{

  float sensorVoltage;                                      // Initialize Variable for Sensor Voltage

  float sensorValue;                                                // Initialize Variable for Sensor Value

  sensorValue = analogRead(A0);                  // Read the Sensor Values from Analog Pin A0

  sensorVoltage = sensorValue/1024*5.0;      // Calculate the Sensor Voltage
  if(sensorVoltage < 5)
  {
     Serial.println("Gas Detected");
     digitalWrite(buz,HIGH);
 }
 else
 {
  Serial.println("NO Gas");
  digitalWrite(buz,LOW);
 }
 delay(100);                        // wait 100ms for next reading
}
