#define TouchPin 9
#define Led 10

void setup() {
    // initialize digital pin TouchPin as an Input.
    pinMode(TouchPin,INPUT);
    // initialize digital pin LED_BUILTIN as an output.
    pinMode(LED_BUILTIN, OUTPUT);//You can use Led insted if LED_BUILTIN. = 13 pin
  }

void loop() {
  int sensorValue=digitalRead(TouchPin);
  
    if (sensorValue==1)//You can Use true or 1
        { 
          //turn the LED on (HIGH is the voltage level)
          digitalWrite (LED_BUILTIN,HIGH);
    }
    else
        {
          //turn the LED off by making the voltage LOW
          digitalWrite (LED_BUILTIN,LOW);
        }
}
