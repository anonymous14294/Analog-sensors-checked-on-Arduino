#include <dht11.h>

int tempraturepin= A2;
int lightpin= A3;
int humiditypin= A4;

float temprature;

float light;

float humidity;

dht11 DHT11;

void setup() {
  Serial.begin(9600);

  Serial.println("Data from all the Analog Sensors are");

}

void loop() {
  temprature = gettemprature();
  light = getlight();
  humidity = gethumidity();

  Serial.println("Temprature");
  Serial.print(temprature);

  Serial.println("**********");

  Serial.println("Light");
  Serial.print(light);

  Serial.println("**********");

  Serial.println("Humidity");
  Serial.print(humidity);

  delay(5000);

}

float gettemprature()
{

int sensorValue = analogRead(tempraturepin);

 float milliVoltstemprature = sensorValue*(5.0/1023.0)*1000;

 return milliVoltstemprature/10;
}

float getlight()
{
  int sensorValue = analogRead(lightpin);

  float milliVoltslight =sensorValue*(5.0/1023.0)*1000;

  return milliVoltslight/10;
}

float gethumidity()
{
  DHT11.read(humiditypin);
  return(float)DHT11.humidity;
}

