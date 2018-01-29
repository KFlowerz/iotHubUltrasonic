

#define trigPin 12
#define echoPin 13
#define ledPin 4


void setup()
{
	Serial.begin(9600);
	pinMode(trigPin, OUTPUT);
	pinMode(echoPin, INPUT);
	pinMode(ledPin, OUTPUT);
}

void loop()
{
	int duration, distance;
	char unit[2] = { 'c','m' };
	/*char result[15];
	char unit[3];*/
	char data[200];
	digitalWrite(ledPin, LOW);
	digitalWrite(trigPin, HIGH);
	delayMicroseconds(100);
	digitalWrite(trigPin, LOW);
	duration = pulseIn(echoPin, HIGH);
	distance = (duration / 2) / 29.1;
	if (distance >= 200 || distance <= 0) {
		Serial.println("Out of range");
		digitalWrite(ledPin, LOW);
	}
	else {
		Serial.print(distance);
		Serial.println(" cm");
		digitalWrite(ledPin, HIGH);
	}
	sprintf(data, "{\"duration\": \"%d\", \"dist\": \"%d\", \"unit\": \"%s\"}", duration, distance, unit);
	Serial.println(data);
	delay(500);
}
