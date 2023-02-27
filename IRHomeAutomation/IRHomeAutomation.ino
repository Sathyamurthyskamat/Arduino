/* 
 * Please Goto https://github.com/cyborg5/IRLib download the .zip file.
 * Goto Sketch => Include Library => Add .zip Library => Select the downloaded Zip file
 * Before Using this Program Please use Test.ino Program get the HeXa codes ex.948321234 
 * 
*/

#include <IRLib.h>
#include <IRLibMatch.h>
#include <IRLibRData.h>
#include <IRLibTimer.h>

//Create a receiver object to listen on pin 11

IRrecv My_Receiver(11);

//Create a decoder object
IRdecode My_Decoder;

int a = 0; 
int b = 0;
int c = 0;
int d = 0;
int e = 0;
int f = 0;

void setup()
{
  Serial.begin(9600);
  My_Receiver.enableIRIn(); // Start the receiver
  pinMode(A0, OUTPUT);
  pinMode(A1, OUTPUT);
  pinMode(A2, OUTPUT);
  pinMode(A4, OUTPUT);
  pinMode(13, OUTPUT);    
 }

void loop() {
  
  //Continuously look for results. When you have them pass them to the decoder
  if ( My_Receiver.GetResults(&My_Decoder)) {
    
    My_Decoder.decode();  //Decode the data
    
    if( My_Decoder.value != 0 ){
      
      My_Decoder.DumpResults();
      Serial.println( My_Decoder.value, DEC );
      
      if( My_Decoder.value == 948321234 ){/*Power*/
        digitalWrite(A0,LOW);
        digitalWrite(A1,LOW);
        digitalWrite(A2,LOW);
        digitalWrite(A4,LOW);
        digitalWrite(13,LOW);
        a=b=c=d=e=0;
        }
        
        else if( My_Decoder.value == 948321248 ){/*1*/
          if(a==0){
            digitalWrite(A4,LOW);
            digitalWrite(A0,HIGH);
            a++;
            }else if(a==1){
              digitalWrite(A0,LOW);
              a--;
              }
            }
            
        else if(My_Decoder.value==948321232){/*2*/
          if(b==0){
            digitalWrite(A1,HIGH);
            b++;
          }else if(b==1){ 
            digitalWrite(A1,LOW);
            digitalWrite(A5,LOW);
            b--;
            }
          }
        else if(My_Decoder.value==948321264){/*3*/
          if(c==0){
            digitalWrite(A4,LOW);
            digitalWrite(A2,HIGH);
            c++;
            }else if(c==1){
              digitalWrite(A2,LOW);
              c--;
              }
            }
         else if(My_Decoder.value==948321224){/*4*/
          if(d==0){
            digitalWrite(A0,LOW);
            digitalWrite(A2,LOW);
            digitalWrite(A4,HIGH);
            d++;
            }else if(d==1){
              digitalWrite(A4,LOW);
              d--;
              }
            }
            
         else if(My_Decoder.value==948321256){/*5*/
          if(e==0){
            digitalWrite(13,HIGH);
            e++;
            }else if(e==1){
              digitalWrite(13,LOW);
              e--;
              }
            }
          }
          /*Show the results on serial monitor*/
          My_Receiver.resume(); 
          /*Restart the receiver*/
      }
}
