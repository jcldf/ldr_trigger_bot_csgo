#include <Mouse.h>
//Pinos de conexao do modulo
const int s0 = 3;
const int s1 = 2;
const int s2 = 1;
const int s3 = 0;
const int out = 6;
 
//Pinos do led RGB
//int pinoledverm = 2;
//int pinoledverd = 3;
//int pinoledazul = 4;
 
//Variaveis cores
int red = 0;
int green = 0;
int blue = 0;
 
void setup()
{
  pinMode(s0, OUTPUT);
  pinMode(s1, OUTPUT);
  pinMode(s2, OUTPUT);
  pinMode(s3, OUTPUT);
  pinMode(out, INPUT);
  //pinMode(pinoledverm, OUTPUT);
  //pinMode(pinoledverd, OUTPUT);
  //pinMode(pinoledazul, OUTPUT);
  Serial.begin(9600);
  digitalWrite(s0, HIGH);
  digitalWrite(s1, LOW);
  Mouse.begin();
}
 
void loop()
{
  //Detecta a cor
  color();
  //Mostra valores no serial monitor
  Serial.print("Vermelho :");
  Serial.print(red, DEC);
  Serial.print(" Verde : ");
  Serial.print(green, DEC);
  Serial.print(" Azul : ");
  Serial.print(blue, DEC);
  Serial.println();

  if (red > 9000 && blue > 8000 && green > 8000){

    Mouse.click();
    delay(100);
    
  }

 
}
 
void color()
{
  //Rotina que le o valor das cores
  digitalWrite(s2, LOW);
  digitalWrite(s3, LOW);
  //count OUT, pRed, RED
  red = pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH);
  digitalWrite(s3, HIGH);
  //count OUT, pBLUE, BLUE
  blue = pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH);
  digitalWrite(s2, HIGH);
  //count OUT, pGreen, GREEN
  green = pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH);
}
