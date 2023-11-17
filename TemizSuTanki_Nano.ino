#include <LiquidCrystal_I2C.h>
#include<Wire.h>

#define Sens_Input A7



LiquidCrystal_I2C lcd( 0x27, 16 , 2);


float analog_pressure;

int role_1 = 2;
int role_2 =3;
float yuzde_deger;



void setup() {
Serial.begin(9600);

pinMode(Sens_Input,INPUT);  
pinMode(role_1,OUTPUT);
pinMode(role_2,OUTPUT);
lcd.begin();
digitalWrite(role_1,LOW);
digitalWrite(role_2,LOW); 


}

void loop() {
 
 analog_pressure = analogRead(Sens_Input);
 yuzde_deger = map(analog_pressure,176,420,0,100);
 analog_pressure = analogRead(Sens_Input);
 if(analog_pressure >184) {
         digitalWrite(role_1,HIGH);
         digitalWrite(role_2,HIGH);
          lcd.setCursor(0,0);
          lcd.print(" Temiz Su Tanki ");
          lcd.setCursor(0,1);
          lcd.print("Su Seviyesi:");
          lcd.setCursor(13,1);
          lcd.print("%");
          lcd.setCursor(14,1);
          lcd.print(yuzde_deger);
          Serial.print("Basınç Degeri : ");
          Serial.println(analog_pressure);
          delay(1000);
          
 }
 else{
        digitalWrite(role_1,LOW);
        digitalWrite(role_2,LOW);
        lcd.setCursor(0,0);
        lcd.print("Temiz Su Bitti ");
        lcd.setCursor(0,1);
        lcd.print("Su Seviyesi:");
        lcd.setCursor(13,1);
        lcd.print("%");
        lcd.setCursor(14,1);
        lcd.print("0");
        delay(500);
        lcd.setCursor(0,0);
        lcd.print("                ");
        lcd.setCursor(0,1);
        lcd.print("                ");
        Serial.print("Basınç Degeri : ");
        Serial.println(analog_pressure);
        delay(500);

}

 }