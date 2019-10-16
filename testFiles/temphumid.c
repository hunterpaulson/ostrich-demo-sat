#include <wiringPi.h>
#include <lcd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

//USE WIRINGPI PIN NUMBERS
#define LCD_RS  25               //Register select pin
#define LCD_E   24               //Enable Pin
#define LCD_D4  23               //Data pin 4
#define LCD_D5  22               //Data pin 5
#define LCD_D6  21               //Data pin 6
#define LCD_D7  14               //Data pin 7
#define MAXTIMINGS 85
#define DHTPIN 7

int lcd;
int dht11_dat[5] = {0, 0, 0, 0, 0};
int lastTest; 


void read_dht11_dat()
{
        uint8_t laststate = HIGH;
        uint8_t counter = 0;
        uint8_t j = 0, i;
        float f; 
        char displayStr[16];                                    //pointer to char string
        char* setupStr;                                         //set up string for sprintf        

        dht11_dat[0] = dht11_dat[1] = dht11_dat[2] = dht11_dat[3] = dht11_dat[4] = 0;

        pinMode(DHTPIN, OUTPUT);
        digitalWrite(DHTPIN, LOW);
        delay(18);
        
        digitalWrite(DHTPIN, HIGH);
        delayMicroseconds(40);
        
        pinMode(DHTPIN, INPUT);

        for (i = 0; i < MAXTIMINGS; i++)
        {
                counter = 0;
                lastTest = digitalRead(DHTPIN);
                while (lastTest == laststate)
                {
                        //printf("%d", lastTest); //this shouldnt work but it does
                        counter++;
                        delayMicroseconds(2); // is 2 because 1 is too fast
                        if (counter == 255)
                        {
                                break;
                        }

                        lastTest = digitalRead(DHTPIN);
                }
                laststate = digitalRead(DHTPIN);

                printf("\n");
                if (counter == 255)
                        break;

                if ((i >= 4) && (i % 2 == 0))
                {
                        dht11_dat[j / 8] <<= 1;
                        if (counter > 16)
                                dht11_dat[j / 8] |= 1;
                        j++;
                }
         }

        if ((j >= 40) && (dht11_dat[4] == ((dht11_dat[0] + dht11_dat[1] + dht11_dat[2] + dht11_dat[3]) & 0xFF)))
        {
                f = dht11_dat[2] * 9. / 5. + 32;        //F calculation 

                //humidity
                setupStr = "Humidity: %d.%d %%";
                sprintf(displayStr, setupStr, dht11_dat[0], dht11_dat[1]);
                lcdPosition(lcd, 0, 0);                 //print in the first row
                lcdPuts(lcd, displayStr);

                //temp
                setupStr = "Temp: %d.%d C\0";
                sprintf(displayStr, setupStr, dht11_dat[2], dht11_dat[3]);
                lcdPosition(lcd, 0, 1);                 //print in the second row
                lcdPuts(lcd, displayStr);
                /*
                lcdPosition(lcd, 0, 0);
                lcdPrintf(lcd, "H: %d.%d %%\n", dht11_dat[0], dht11_dat[1]);

                lcdPosition(lcd, 0, 1);
                //lcdPrintf(lcd, "Temp: %d.0 C", dht11_dat[2]); //Uncomment for Celsius
                lcdPrintf(lcd, "T: %.1f F", f); //Comment out for Celsius
                */
        }
}

int main(void)
{
        int lcd;
        wiringPiSetup();
        lcd = lcdInit (2, 16, 4, LCD_RS, LCD_E, LCD_D4, LCD_D5, LCD_D6, LCD_D7, 0, 0, 0, 0);
        
        while (1)
        {
                read_dht11_dat();
                delay(1000); 
        }

        return(0);
}