#include <IRremote.h>
 
int RECV_PIN = 3; 
 
IRrecv irrecv(RECV_PIN); 
 
decode_results results; 
 
void setup(){
  Serial.begin(9600);
  irrecv.enableIRIn(); 
}
 
void loop(){

  if (irrecv.decode(&results)) {
    Serial.print("Código HEX: ");
    Serial.println(results.value, HEX); 
    Serial.print("Código DEC: "); 
    Serial.println(results.value); 
    Serial.println(""); 
    irrecv.resume(); 
  }
  delay(100); 
}
