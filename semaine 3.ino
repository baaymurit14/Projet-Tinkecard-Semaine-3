// C++ code
//
// Définition des broches  
const int trigPin = 9;
const int echoPin = 10;
const int ledPin = 13;
const int buzzerPin = 11;
const int seuil = 100; // initialisation du seuil en (cm)

void setup() {
  
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  Serial.begin(9600); // pour permettre les sorties affichage
}

void loop() {
  //impulsion du capteur
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
	
  //lecture de la durée de retour de l'echo
  long duration = pulseIn(echoPin, HIGH);
  //calcul de la distance
  int distance = duration * 0.034 / 2;

  Serial.print("Distance : ");
  Serial.print(distance);
  Serial.println(" cm");

  //condition selon la distance alerte lorsque la distance est inferieur au seuil
  if (distance < seuil) {
    digitalWrite(ledPin, HIGH);
    tone(buzzerPin, 1000); //on utilise ici tone pour emettre un son en 1kHz
  } else {
    digitalWrite(ledPin, LOW);
    noTone(buzzerPin);// sinon pas de son 
    digitalWrite(buzzerPin, LOW);
  }

  delay(500); //une petite pause 
}
