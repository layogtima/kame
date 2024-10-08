#include <Servo.h>

int _ABVAR_1_distance = 0 ;
int ardublockUltrasonicSensorCodeAutoGeneratedReturnCM(int trigPin, int echoPin)
{
  long duration;
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(20);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  duration = duration / 59;
  if ((duration < 2) || (duration > 300)) return false;
  return duration;
}

void __ardublockDigitalWrite(int pinNumber, boolean status)
{
  pinMode(pinNumber, OUTPUT);
  digitalWrite(pinNumber, status);
}

int _ABVAR_2_a;
int _ABVAR_3_a;
Servo servo_pin_4;
Servo servo_pin_7;
Servo servo_pin_6;
Servo servo_pin_2;
Servo servo_pin_9;
Servo servo_pin_5;
Servo servo_pin_8;
Servo servo_pin_3;

void turnR();
void backwards();
void walk();
void home();

void setup()
{
  digitalWrite( 12 , LOW );
  Serial.begin(115200);
  servo_pin_2.attach(2);
  servo_pin_3.attach(3);
  servo_pin_4.attach(4);
  servo_pin_5.attach(5);
  servo_pin_6.attach(6);
  servo_pin_7.attach(7);
  servo_pin_8.attach(8);
  servo_pin_9.attach(9);
  home();

  delay(2000);

}

void loop() {
  servo_pin_3.write(0);
  Serial.print("0");
  delay(3000);
  servo_pin_3.write(60); // 0 to 80
  Serial.print("60");
  delay(1000);
  Serial.println("pin 3");

  servo_pin_4.write(0);
  Serial.print("0");
  delay(3000);
  servo_pin_3.write(60); // 0 to 80
  Serial.print("60");
  delay(1000);
  Serial.println("pin 4");

  servo_pin_5.write(0);
  Serial.print("0");
  delay(3000);
  servo_pin_3.write(60); // 0 to 80
  Serial.print("60");
  delay(1000);
  Serial.println("pin 5");

  servo_pin_6.write(0);
  Serial.print("0");
  delay(3000);
  servo_pin_3.write(60); // 0 to 80
  Serial.print("60");
  delay(1000);
  Serial.println("pin 6");

  servo_pin_7.write(0);
  Serial.print("0");
  delay(3000);
  servo_pin_3.write(60); // 0 to 80
  Serial.print("60");
  delay(1000);
  Serial.println("pin 7");

  servo_pin_8.write(0);
  Serial.print("0");
  delay(3000);
  servo_pin_3.write(60); // 0 to 80
  Serial.print("60");
  delay(1000);
  Serial.println("pin 8");

  servo_pin_9.write(0);
  Serial.print("0");
  delay(3000);
  servo_pin_3.write(60); // 0 to 80
  Serial.print("60");
  delay(1000);
  Serial.println("pin 9");
}

void boop()
{
  _ABVAR_1_distance = 	ardublockUltrasonicSensorCodeAutoGeneratedReturnCM( 12 , 13 ) ;
  walk();
  if (( ( _ABVAR_1_distance ) < ( 25 ) ))
  {
    delay( 200 );
    __ardublockDigitalWrite(10, HIGH);
    tone(11, 440, 1000);
    delay( 1400 );
    for (_ABVAR_2_a=1; _ABVAR_2_a<= ( 3 ); ++_ABVAR_2_a )
    {
      backwards();
    }
    for (_ABVAR_3_a=1; _ABVAR_3_a<= ( 4 ); ++_ABVAR_3_a )
    {
      turnR();
    }
    __ardublockDigitalWrite(10, LOW);
  }
  else
  {
    walk();
  }
}

void walk()
{
  servo_pin_4.write( 80 );
  servo_pin_7.write( 40 );
  delay( 75 );
  servo_pin_7.write( 40 );
  delay( 75 );
  servo_pin_6.write( 80 );
  servo_pin_2.write( 80 );
  delay( 150 );
  servo_pin_4.write( 50 );
  servo_pin_7.write( 70 );
  servo_pin_9.write( 100 );
  servo_pin_5.write( 140 );
  delay( 75 );
  servo_pin_6.write( 125 );
  servo_pin_2.write( 125 );
  delay( 150 );
  servo_pin_8.write( 110 );
  servo_pin_3.write( 110 );
  delay( 75 );
  servo_pin_4.write( 80 );
  servo_pin_7.write( 40 );
  servo_pin_9.write( 140 );
  servo_pin_5.write( 100 );
  delay( 75 );
  servo_pin_8.write( 55 );
  servo_pin_3.write( 55 );
  delay( 100 );
}

void home()
{
  servo_pin_9.write( 120 );
  servo_pin_5.write( 120 );
  servo_pin_4.write( 60 );
  servo_pin_7.write( 60 );
  servo_pin_2.write( 125 );
  servo_pin_6.write( 125 );
  servo_pin_8.write( 55 );
  servo_pin_3.write( 55 );
}

void backwards()
{
  servo_pin_4.write( 40 );
  servo_pin_7.write( 80 );
  delay( 75 );
  servo_pin_6.write( 80 );
  servo_pin_2.write( 80 );
  delay( 150 );
  servo_pin_4.write( 70 );
  servo_pin_7.write( 50 );
  servo_pin_9.write( 140 );
  servo_pin_5.write( 100 );
  delay( 75 );
  servo_pin_6.write( 125 );
  servo_pin_2.write( 125 );
  delay( 150 );
  servo_pin_8.write( 110 );
  servo_pin_3.write( 110 );
  delay( 75 );
  servo_pin_4.write( 40 );
  servo_pin_7.write( 80 );
  servo_pin_9.write( 100 );
  servo_pin_5.write( 140 );
  delay( 75 );
  servo_pin_8.write( 55 );
  servo_pin_3.write( 55 );
  delay( 100 );
}

void turnR()
{
  servo_pin_8.write( 110 );
  servo_pin_3.write( 110 );
  delay( 150 );
  servo_pin_4.write( 40 );
  servo_pin_7.write( 40 );
  servo_pin_9.write( 100 );
  servo_pin_5.write( 100 );
  delay( 150 );
  servo_pin_8.write( 55 );
  servo_pin_3.write( 55 );
  servo_pin_6.write( 80 );
  servo_pin_2.write( 80 );
  delay( 150 );
  servo_pin_4.write( 80 );
  servo_pin_7.write( 80 );
  servo_pin_9.write( 100 );
  servo_pin_5.write( 100 );
  delay( 150 );
  servo_pin_6.write( 125 );
  servo_pin_2.write( 125 );
  delay( 150 );
  servo_pin_4.write( 60 );
  servo_pin_7.write( 60 );
  servo_pin_9.write( 120 );
  servo_pin_5.write( 120 );
}
