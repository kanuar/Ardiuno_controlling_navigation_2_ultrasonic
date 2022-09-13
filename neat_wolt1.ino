// C++ code
//
int dist_front = 0;

int dist_back = 0;

long readUltrasonicDistance(int triggerPin, int echoPin)
{
  pinMode(triggerPin, OUTPUT);  // Clear the trigger
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  // Sets the trigger pin to HIGH state for 10 microseconds
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT);
  // Reads the echo pin, and returns the sound wave travel time in microseconds
  return pulseIn(echoPin, HIGH);
}

void setup()
{
  Serial.begin(9600);
  pinMode(7, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(8, OUTPUT);
}

void loop()
{
  dist_back = 0.01723 * readUltrasonicDistance(2, 3);
  dist_front = 0.01723 * readUltrasonicDistance(4, 5);
  Serial.println(dist_back);
  Serial.println(dist_front);
  Serial.println("");
  digitalWrite(7, HIGH);
  digitalWrite(6, HIGH);
  digitalWrite(10, HIGH);
  digitalWrite(11, LOW);
  digitalWrite(9, HIGH);
  digitalWrite(8, LOW);
  delay(1000); // Wait for 1000 millisecond(s)
  if (dist_front < 40) {
    digitalWrite(10, LOW);
    digitalWrite(11, HIGH);
    digitalWrite(9, HIGH);
    digitalWrite(8, LOW);
    delay(5000); // Wait for 5000 millisecond(s)
  }
  if (dist_back < 40) {
    digitalWrite(10, HIGH);
    digitalWrite(11, LOW);
    digitalWrite(9, LOW);
    digitalWrite(8, HIGH);
    delay(5000); // Wait for 5000 millisecond(s)
  }
}