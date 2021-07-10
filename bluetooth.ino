#include <Servo.h>

Servo servohorizontal;
int servoh = 0;
int servohMax = 130;
int servohMin = 50;

Servo servovertical;
int servov = 0;
int servovMax = 150;
int servovMin = 80;

int ldrtopl = 0; 
int ldrtopr = 2; 
int ldrbotl = 1; 
int ldrbotr = 3; 

void setup ()
{
  servohorizontal.attach(10);
  servohorizontal.write(90);
  servovertical.attach(9);
  servovertical.write(115);

  pinMode(8, INPUT_PULLUP);

  delay(500);
}

void loop()
{

while (digitalRead(8) == HIGH)
{
  servoh = servohorizontal.read();
  servov = servovertical.read();

  int topl = analogRead(ldrtopl);
  int topr = analogRead(ldrtopr);
  int botl = analogRead(ldrbotl);
  int botr = analogRead(ldrbotr);

  int top = (topl + topr) ;
  int bot = (botl + botr) ;
  int left = (topl + botl) ;
  int right = (topr + botr) ;

  if (top < bot)
  {
    if (servov >= servovMax)
    {
      servov = servovMax;
    }
    servovertical.write(servov + 1);
    delay(10);
  }
  else if (bot < top)
  {
    if (servov <= servovMin)
    {
      servov = servovMin;
    }
    servovertical.write(servov - 1);
    delay(10);
  }
  else
  {
    servovertical.write(servov);
  }

  if (right > left)
  {
    if (servoh >= servohMax)
    {
      servoh = servohMax;
    }
    servohorizontal.write(servoh + 1);
    delay(10);
  }
  else if (left > right)
  {
    if (servoh <= servohMin)
    {
      servoh = servohMin;
    }
    servohorizontal.write(servoh - 1);
    delay(10);
  }
    else
  {
    servohorizontal.write(servoh);
  }
  delay(50);
}
  delay(50);
}
