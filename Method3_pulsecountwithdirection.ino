/* Inthis method a single IR line detecting Module and a little circuitry to detect the direction of rotation are 
combined to either increment or decrement the pulse count which gives the position of the Robotic Arm*/

volatile long ticks = 0;
volatile int val1=0;
void setup()
{
  Serial.begin(9600);
  pinMode(2,INPUT);//Digital Pin2 is defined as Input
  attachInterrupt(0,countTicks,RISING); //Here number Zero means Interrupt INT0 is seen at Digital Pin2 
  //All the pulses will be seen as interrupts so as to not miss any pulses
}

void loop()
{
  Serial.println(ticks);//Gives current position
  delay(10);
}
void countTicks()
{
  val1=analogRead(A0);
  if (val1>100)
  {
  ticks++;//Motor is Moving forward,Increment Count
  }
  else
  {
    ticks--;//Motor is Moving backward,Decrement Count
  }
}
  
