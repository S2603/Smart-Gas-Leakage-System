#include<ESP8266WiFi.h>
#include"Adafruit_MQTT_Client.h"
#define wifi "Shuvo"
#define password "Suvo2662"
#define server "io.Adafruit.com"
#define port 1883`
#define username "Suvo_2662"
#define key "aio_PJOA222d7NzRvVFor1iqLNrMlRN3"
WiFiClient esp;
Adafruit_MQTT_Client mqtt(&esp,server,port,username,key);
Adafruit_MQTT_Publish feed=Adafruit_MQTT_Publish(&mqtt,username"/feeds/GAS");
void setup()
{Serial.begin(9600);
delay(10);
Serial.println("Adafruit MQTT demo");
Serial.println("Connecting to");
Serial.println(wifi);
WiFi.begin(wifi,password);
while(WiFi.status()!=WL_CONNECTED)
{delay(500);
Serial.println(".");
}
Serial.println("wifi connected");
Serial.println("ip adress");
Serial.println(WiFi.localIP());
Serial.println("connecting to mqtt");
while(mqtt.connect())
{
  Serial.println(".");
}
}
void loop()
{
  float sensorVoltage;                                      // Initialize Variable for Sensor Voltage

  float sensorValue;                                                // Initialize Variable for Sensor Value

  sensorValue = analogRead(A0);                  // Read the Sensor Values from Analog Pin A0

  sensorVoltage = sensorValue/1024*5.0;          // Calculate the Sensor Voltage
  if(mqtt.connected())
{
Serial.println("sending data");
Serial.println(sensorVoltage);
Serial.println("....");
if(feed.publish(sensorVoltage));
{
  Serial.println("success");
}
}
else
{
  Serial.println("fail");
}
delay(2200);
}
