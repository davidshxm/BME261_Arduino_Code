void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int emg1 = analogRead(A0);
  int emg2 = analogRead(A1);
  int emg3 = analogRead(A2);

  Serial.print("A0: ");
  Serial.println(emg1);
  Serial.print("A1: ");
  Serial.println(emg2);
  Serial.print("A2: ");
  Serial.println(emg3);
  
  delay(500);
}
