#define trigPin 12
#define echoPin 11
int Buzzer = 8;
int duration, distance;

void setup() {
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);  
  pinMode(Buzzer, OUTPUT);
}

void loop() {
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(1000);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2)/ 29.1;
  String msg = "";
  int BuzzerDelay = 0;
  int BuzzerIntencity = 0;
  if (distance > 100){
    msg = "No Obstacle!";
    BuzzerIntencity = 0;
    BuzzerDelay = 0;
  }else if (distance >= 70){
    msg = "Obstacle Detected - Far!";
    BuzzerIntencity = 200;
    BuzzerDelay = 10;
  }else if (distance >= 50){
    msg = "Obstacle Detected - Little Far!";
    BuzzerIntencity = 170;
    BuzzerDelay = 10;
  }else if (distance >= 40){
    msg = "Obstacle Detected - Little Near!";
    BuzzerIntencity = 140;
    BuzzerDelay = 10;
  }else if (distance >= 10){
    msg = "Obstacle Detected - Near!";
    BuzzerIntencity = 110;
    BuzzerDelay = 10;
  }else {
    msg = "Obstacle Detected - Too Close!";
    BuzzerIntencity = 250;
    BuzzerDelay = 10;
  }
  Serial.println("-------------------------------------------");
  Serial.println(msg);
  Serial.print("distance = " ); Serial.print(distance);
  Serial.println();
  analogWrite(Buzzer, BuzzerIntencity);
  delay(BuzzerDelay);
}
