/* I made minor changes to the code used by 
Dejan Nedelkovski who used a rotary encoderattached to a gear wheel to get positional and directional Feedback.
In my case instead of the Output A and B coming from Rotary encoder we have Out 1 and Output 2 coming from two IR modules whose value will be logic zero or High based on the pattern seen by module  
The two outputs of IR Modules are connected to Digital pins configured as Digital Inputs
Outputs. 
 */
 
 #define outputA 6
 #define outputB 7
 int counter = 0; 
 int aState;
 int aLastState;  
 void setup() { 
   pinMode (outputA,INPUT);
   pinMode (outputB,INPUT);
   
   Serial.begin (9600);
   // Reads the initial state of the outputA
   aLastState = digitalRead(outputA);   
 } 
 void loop() { 
   aState = digitalRead(outputA); // Reads the "current" state of the outputA
   // If the previous and the current state of the outputA are different, that means a Pulse has occured
   if (aState != aLastState){     
     // If the outputB state is different to the outputA state, that means the encoder is rotating clockwise
     if (digitalRead(outputB) != aState) { 
       counter ++;
     } else {
       counter --;
     }
     Serial.print("Current Position: ");
     Serial.println(counter);
   } 
   aLastState = aState; // Updates the previous state of the outputA with the current state
 }
