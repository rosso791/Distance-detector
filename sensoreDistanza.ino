int trigPort = 9;
int echoPort = 10;
int ledRosso = 4;
int ledVerde = 5;
long durata, distanza;

void setup() {
  Serial.begin(9600);
  Serial.print("Sensore ultrasuoni");
  pinMode(trigPort, OUTPUT);
  pinMode(echoPort, INPUT);
  pinMode(ledRosso, OUTPUT);
  pinMode(ledVerde, OUTPUT);
}

void loop() {
  digitalWrite(trigPort, LOW);
  digitalWrite(trigPort, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPort, HIGH);
  durata = pulseIn(echoPort, HIGH);
  distanza = 0.034*durata /2;
  Serial.println(distanza);
  delay(750);
  if (distanza > 10){
    digitalWrite(ledVerde, HIGH);
    digitalWrite(ledRosso, LOW);
  }
  else{
    digitalWrite(ledRosso,HIGH);
    digitalWrite(ledVerde, LOW);
  }

 
}
