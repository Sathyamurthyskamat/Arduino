#define trigPin  10
#define echoPin 9
#define led 13

void setup() {
  
  Serial.begin(9600);
  // Set D10 as an OUTPUT
  pinMode(trigPin, OUTPUT);

  // Set D9 as an OUTPUT
  pinMode(echoPin, INPUT); 
  pinMode(led,OUTPUT);
}

void loop()
{
  long duration, inches, cm;
  digitalWrite(trigPin, LOW); // Turn the trigPin low if trigPin High
  delayMicroseconds(2); //wait 2 microsecond
  digitalWrite(trigPin, HIGH); // Turn the trigPin HIGH
  delayMicroseconds(5); //wait 5 microsecond
  digitalWrite(trigPin, LOW); // Turn the trigPin LOW

  duration = pulseIn(echoPin, HIGH); // Turn the echoPin HIGH for reciving Signal

  //get the readings from the functions below and print it
  inches = microsecondsToInches(duration);
  cm = microsecondsToCentimeters(duration);
  
  Serial.print(inches);
  Serial.print("in, ");
  Serial.print(cm);
  Serial.print("cm");
  Serial.println();

  //if condition for 'cm' you can use 'inches' also 
  /*if (cm>=10){
    digitalWrite(led,HIGH);
    
  }else{
    digitalWrite(led,LOW);
  }*/
  delay(200); //wait 20 milliseconds
}

//This is a function used to get the reading
long microsecondsToInches(long microseconds)
{
  return microseconds / 74 / 2;// send current reading
}

//This is a function used to get the reading
long microsecondsToCentimeters(long microseconds)
{
  return microseconds / 29 / 2;// send current reading
}
