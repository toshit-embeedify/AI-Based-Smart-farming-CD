//Arduino Code - Water Level
 
int Lvl = A0; //Define the Analog pin# on the Arduino for the level sensor signal

void setup() {
Serial.begin(9600); // Start the serial communication
}

void loop() {
int water_lvl=analogRead(Lvl);
Serial.print("Water level: ");
Serial.println(water_lvl);
delay(200);
}