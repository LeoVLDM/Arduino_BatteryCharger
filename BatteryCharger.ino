
// 1. Считывание напряжения
/*
4.88
170 = 4.14
*/

// Voltage Sensor 1
#define vs1_pin A0
float vs1_in = 0.0;
float vs1_out = 0.0;
float vs1_R1 = 30000.0;
float vs1_R2 = 7500.0;

int value;


void setup()
{
	pinMode(vs1_pin, INPUT);

	Serial.begin(9600);
	Serial.println("Start Charger");

}

void loop()
{
	value = analogRead(vs1_pin);
	vs1_out= (value * 5.0) / 1024.0;
	vs1_in = vs1_out / (vs1_R2 / (vs1_R1 + vs1_R2));

	Serial.print("INPUT V= ");
	Serial.println(vs1_in,2);

	delay(250);
}
