/* Inthis method a single IR line detecting Module and a little circuitry to detect the direction of rotation are 
combined to either increment or decrement the pulse count which gives the position of the Robotic Arm*/
const int in_pin =2;
volatile long ticks = 0;
volatile int val1=0;
void setup()
{
  Serial.begin(9600);
  pinMode(in_pin,INPUT);
  attachInterrupt(0,countTicks,RISING);
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
  ticks++;
  }
  else
  {
    ticks--;
  }
}
  
