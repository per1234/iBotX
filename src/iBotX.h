/*iBotX.h - Simplified library for better understanding of basic programming*/

#ifndef iBotX_h
#define iBotX_h

#include "Arduino.h"
#include <Servo.h> 

#define SW1_PIN A0
#define SW2_PIN 2
#define SW3_PIN 3

#define LASER_PIN 5

#define SERVO_PIN 4

#define US_TRIG_PIN 13
#define US_ECHO_PIN 12
#define US_DIV 58.0

#define MEASURE_SAMPLE_DELAY 5
#define MEASURE_SAMPLES 25
#define MEASURE_DELAY 250

#define SENS_LEFT_OUTER_PIN A5
#define SENS_LEFT_INNER_PIN A4
#define SENS_MIDDLE_PIN A3
#define SENS_RIGHT_INNER_PIN A2
#define SENS_RIGHT_OUTER_PIN A1

#define IN1_PIN 7
#define IN2_PIN 6
#define ENA_PIN 11

#define IN3_PIN 8
#define IN4_PIN 9
#define ENB_PIN 10

Servo iServo;

void iBotX()
{
  pinMode(SW1_PIN, INPUT_PULLUP);
  pinMode(SW2_PIN, INPUT_PULLUP);
  pinMode(SW3_PIN, INPUT_PULLUP);

  pinMode(LASER_PIN, OUTPUT);
  
  pinMode(SERVO_PIN, OUTPUT);
  iServo.attach(SERVO_PIN);

  pinMode(US_TRIG_PIN, OUTPUT);
  pinMode(US_ECHO_PIN, INPUT);
  digitalWrite(US_TRIG_PIN, LOW);

  pinMode(IN1_PIN, OUTPUT);
  pinMode(IN2_PIN, OUTPUT);
  pinMode(ENA_PIN, OUTPUT);

  pinMode(IN3_PIN, OUTPUT);
  pinMode(IN4_PIN, OUTPUT);
  pinMode(ENB_PIN, OUTPUT);
  
  TCCR2A |= 0b00000011;
  TCCR2B |= 0b00000100;
  TIMSK2 |= 0b00000011;
  OCR2A = 0;
  TCCR2A |= 0b00000011;
  TCCR2B |= 0b00000100;
  TIMSK2 |= 0b00000111;
  OCR2B = 0;
}

void laser_on()
{
  digitalWrite(LASER_PIN, HIGH);
}

void laser_off()
{
  digitalWrite(LASER_PIN, LOW);
}

uint8_t sw1()
{
	return !digitalRead(SW1_PIN);
}

uint8_t sw2()
{
	return !digitalRead(SW2_PIN);
}

uint8_t sw3()
{
	return !digitalRead(SW3_PIN);
}

void SW1()
{
	while(digitalRead(SW1_PIN)) {;}
	delay(500);
}

void SW2()
{
	while(digitalRead(SW2_PIN)) {;}
	delay(500);
}

void SW3()
{
	while(digitalRead(SW3_PIN)) {;}
	delay(500);
}

uint8_t SW_Select()
{
  uint8_t sw_pressed;
  while(1) 
  {
    if(!digitalRead(SW1_PIN))
    {
      sw_pressed = 1;
      break;
    }
    if(!digitalRead(SW2_PIN))
    {
      sw_pressed = 2;
      break;
    }
    if(!digitalRead(SW3_PIN))
    {
      sw_pressed = 3;
      break;
    }
  }
  delay(500);
  return sw_pressed;
}

uint8_t sensor1()
{
	return analogRead(SENS_LEFT_OUTER_PIN);
}

uint8_t sensor2()
{
	return analogRead(SENS_LEFT_INNER_PIN);
}

uint8_t sensor3()
{
	return analogRead(SENS_MIDDLE_PIN);
}

uint8_t sensor4()
{
	return analogRead(SENS_RIGHT_INNER_PIN);
}

uint8_t sensor5()
{
	return analogRead(SENS_RIGHT_OUTER_PIN);
}

void motor(int spd_l, int spd_r)
{
  if (spd_l > 0)
  {
    digitalWrite(IN1_PIN, HIGH);
    digitalWrite(IN2_PIN, LOW);
  }
  else if (spd_l < 0)
  {
    digitalWrite(IN1_PIN, LOW);
    digitalWrite(IN2_PIN, HIGH);
    spd_l = -spd_l;
  }
  else
  {
    digitalWrite(IN1_PIN, LOW);
    digitalWrite(IN2_PIN, LOW);
    spd_l = 0;
  }
  if (spd_l > 255)
  {
    spd_l = 255;
  }

  if (spd_r > 0)
  {
    digitalWrite(IN3_PIN, HIGH);
    digitalWrite(IN4_PIN, LOW);
  }
  else if (spd_r < 0)
  {
    digitalWrite(IN3_PIN, LOW);
    digitalWrite(IN4_PIN, HIGH);
    spd_r = -spd_r;
  }
  else
  {
    digitalWrite(IN3_PIN, LOW);
    digitalWrite(IN4_PIN, LOW);
    spd_r = 0;
  }
  if (spd_r > 255)
  {
    spd_r = 255;
  }

  OCR2A = spd_l;
  OCR2B = spd_r;
}

void motor(int spd_l, int spd_r, unsigned long duration)
{
  motor(spd_l, spd_r);
  delay(duration);
  motor(0, 0);
}

void servo(int pos)
{
	iServo.write(pos);
}

void done(int pos)
{
	motor(0,0);
	servo(90);
	while(1) {;}
}

long us_single_cm()
{
  long duration = 0;
  digitalWrite(US_TRIG_PIN, HIGH);
  delayMicroseconds(11);
  digitalWrite(US_TRIG_PIN, LOW);
  duration = pulseIn(US_ECHO_PIN, HIGH);
  return (long) (((float) duration / US_DIV));
}

long sonar_cm()
{
  long measureSum = 0;
  for (int i = 0; i < MEASURE_SAMPLES; i++)
  {
    delay(MEASURE_SAMPLE_DELAY);
    measureSum += us_single_cm();
  }
  return measureSum / MEASURE_SAMPLES;
}

long us_single_mm()
{
  long duration = 0;
  digitalWrite(US_TRIG_PIN, HIGH);
  delayMicroseconds(11);
  digitalWrite(US_TRIG_PIN, LOW);
  duration = pulseIn(US_ECHO_PIN, HIGH);
  return (long) (((float) duration / US_DIV)*10);
}

long sonar_mm()
{
  long measureSum = 0;
  for (int i = 0; i < MEASURE_SAMPLES; i++)
  {
    delay(MEASURE_SAMPLE_DELAY);
    measureSum += us_single_mm();
  }
  return measureSum / MEASURE_SAMPLES;
}

ISR(TIMER2_COMPA_vect)
{
  digitalWrite(ENA_PIN, LOW);
}

ISR(TIMER2_COMPB_vect)
{
  digitalWrite(ENB_PIN, LOW);
}

ISR(TIMER2_OVF_vect)
{
  digitalWrite(ENA_PIN, HIGH);
  digitalWrite(ENB_PIN, HIGH);
}

#endif