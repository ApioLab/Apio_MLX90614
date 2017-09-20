#include <Wire.h> // I2C library, required for MLX90614
#include <Apio_MLX90614.h> 
IRTherm therm; // Create an IRTherm object 
const byte LED_PIN = 14; // led in Apio_DIN2

void setup() 
{
Serial.begin(115200); 
Serial.println("Demo Test MLX90614 V1.00");
therm.begin(); // Therm starting
therm.setUnit(TEMP_C); //  or TEMP_F if USA :-) or TEMP_K for KELVIN  
pinMode(LED_PIN, OUTPUT); // LED pin as output
digitalWrite(LED_PIN, LOW);
}

void loop() 
{
digitalWrite(LED_PIN, HIGH);  
  if (therm.read()) // On success, read() will return 1, on fail 0.
  {
 
    Serial.print("Object: " + String(therm.object(), 2));
    Serial.write("°"); // Degree Symbol
    Serial.println("F");
    Serial.print("Ambient: " + String(therm.ambient(), 2));
    Serial.print("°"); // Degree Symbol
    Serial.println("C");
    Serial.println();
  }

  if (therm.readID()) // Read from the ID registers
  { 
    Serial.println("ID: 0x" + String(therm.getIDH(), HEX) + String(therm.getIDL(), HEX));
  }
  digitalWrite(LED_PIN, LOW);
  delay(500);
}
