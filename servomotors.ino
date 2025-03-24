#include <Servo.h>

Servo lr_servo;
Servo ud_servo;

int x;
int y;
int SWstate = 1;
int pos = 0;

void setup()
{
    lr_servo.attach(3);
    ud_servo.attach(5);
}
void loop()
{
    x = analogRead(0);
    x = map(x, 0, 1023, 0, 180);
    y = analogRead(1);
    y = map(y, 0, 1023, 0, 180);
    SWstate = digitalRead(12);

    if (SWstate == LOW)
    {
        for (pos = 40; pos <= 140; pos += 1)
        {
            lr_servo.write(pos);
            ud_servo.write(pos);
            delay(15);
        }

        for (pos = 140; pos >= 40; pos -= 1)
        {
            lr_servo.write(pos);
            ud_servo.write(pos);
            delay(15);
        }
    }
    else
    {
        lr_servo.write(x);
        ud_servo.write(y);
        delay(15);
    }
}
