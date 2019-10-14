#include <wiringPi.h>
#include <wiringSerial.h>
#include <errno.h>
#include <lcd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string>
#include <iostream>


//USE WIRINGPI PIN NUMBERS
#define LCD_RS  25               //Register select pin
#define LCD_E   24               //Enable Pin
#define LCD_D4  23               //Data pin 4
#define LCD_D5  22               //Data pin 5
#define LCD_D6  21               //Data pin 6
#define LCD_D7  14               //Data pin 7
#define MAXTIMINGS 85
#define DHTPIN 7

//KEY CODE DEFINITIONS FOR 'KEYES' IR REMOTE
#define KEY_1       0xFF6897
#define KEY_2       0xFF9876
#define KEY_3       0xFFB04F
#define KEY_4       0xFF30CF
#define KEY_5       0xFF18E7
#define KEY_6       0xFF7A85
#define KEY_7       0xFF10EF
#define KEY_8       0xFF38C7
#define KEY_9       0xFF5AA5
#define KEY_0       0xFF4AB5
#define KEY_UP      0xFF6290
#define KEY_DOWN    0xFFA857
#define KEY_RIGHT   0xFFC23D
#define KEY_LEFT    0xFF22DD
#define KEY_OK      0xFF02FD
#define KEY_STAR    0xFF42BD
#define KEY_POUND   0xFF52AD

//OUTPUT MODES
#define TEMP 1
#define HUMID 2
#define IR 3


using namespace std;

//LCD AND TEMP/HUMID INIT
int lcd;
int dht11_dat[5] = {0, 0, 0, 0, 0};
int currentState; 

//IR RECEIVER INIT
int fd = serialOpen("/dev/ttyACM0", 9600);   //open serial port with baud rate 9600
int bytesToRead;    


/* Checks if the key extracted by read_ir_dat() is valid or not
*   
*   @RETURNS -1 if invalid, else returns the valid key
*/
int check_valid_key(int key){

    switch(key){
        case KEY_0:
            return KEY_0;
            break;
        case KEY_1:
            return KEY_1;
            break;
        case KEY_2:
            return KEY_2;
            break;
        case KEY_3:
            return KEY_3;
            break;
        case KEY_4:
            return KEY_4;
            break;
        case KEY_5:
            return KEY_5;
            break;
        case KEY_6:
            return KEY_6;
            break;
        case KEY_7:
            return KEY_7;
            break;
        case KEY_8:
            return KEY_8;
            break;
        case KEY_9:
            return KEY_9;
            break;
        case KEY_UP:
            return KEY_UP;
            break;
        case KEY_DOWN:
            return KEY_DOWN;
            break;
        case KEY_RIGHT:
            return KEY_RIGHT;
            break;
        case KEY_LEFT:
            return KEY_LEFT;
            break;
        case KEY_OK:
            return KEY_OK;
            break;
        case KEY_STAR:
            return KEY_STAR;
            break;
        case KEY_POUND:
            return KEY_POUND;
            break;
        default:
            return -1;
    }
}


/* Uses WiringPi library to gather serial data into a char array, then parses
*  the array into a valid, manipulatable int value
*   
*  @RETURNS -1 if invalid key/unable to open port, else returns valid checked key
*/
int read_ir_dat(){
    int irKey = -1;             //final key
    string dataToString;   //intermidiate key string
    
    if(fd > 0){
            bytesToRead = serialDataAvail(fd);
            
	        if(bytesToRead > 0){
                char * serialData = new char[bytesToRead];
	            
                //get ir signal into data array
                for(int i = 0; i < bytesToRead; i++){
		            serialData[i] = serialGetchar(fd);
                }
                
                //change that data into a string so it can be manipulated easier
                for(int i = 0; i < bytesToRead; i++){
		            dataToString = dataToString + serialData[i];
                }

                //get int value for key
                irKey = stoi(dataToString, nullptr, 16);

                //garbage collecting
                delete serialData;
                
                //flush extra data
	            serialFlush(fd);
            }
            
            //allow serial buffer to fill
           delay(100);

           return check_valid_key(irKey);

    }else{
        printf("[ERROR] unable to open port '/dev/ttyACM0'\n");
        return -1;
    }
}



string read_dht11_dat(int mode)
{
        uint8_t laststate = HIGH;
        uint8_t counter = 0;
        uint8_t j = 0, i;
        float f; 
        char TempDisplayStr[16];                                    //pointer to char string
        char HumDisplayStr[16]; 
        string setupStr;                                         //set up string for sprintf        

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
                currentState = digitalRead(DHTPIN);
                while (currentState == laststate)
                {
                        //printf("%d", currentState); //this shouldnt work but it does
                        counter++;
                        delayMicroseconds(2); // is 2 because 1 is too fast
                        if (counter == 255)
                        {
                                break;
                        }

                        currentState = digitalRead(DHTPIN);
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
                sprintf(HumDisplayStr, setupStr, dht11_dat[0], dht11_dat[1]);
        
                //temp
                setupStr = "Temp: %d.%d C\0";
                sprintf(TempDisplayStr, setupStr, dht11_dat[2], dht11_dat[3]);
                
               if(mode == 1){
                   return HumDisplayStr;
               }else if(mode == 2){
                   return TempDisplayStr;
               }else{
                   return "[ERROR] invalid temp/hum mode\n";
               }

        }

        return "invalidData";
}

void lcd_output(string toPrint, int line){
    
    if(toPrint.length() > 16){

        //if string greater than screen length, split the string 
       // lcdPosition(lcd, 0, 0);
       // lcdPuts(lcd, toPrint.substr(0, 16));
       // lcdPosition(lcd, 0, 1);
       // lcdPuts(lcd, toPrint.substr(16, toPrint.length()-1));
    }else{
        lcdPosition(lcd, 0, line);           
        lcdPuts(lcd,toPrint.c_str());
    }

   
}


int main(void)
{   
    wiringPiSetup();
    string returnedString;
    int count = 0;
    int currentIrKey = KEY_1;
    int lastIrKey = KEY_1;

    lcd = lcdInit (2, 16, 4, LCD_RS, LCD_E, LCD_D4, LCD_D5, LCD_D6, LCD_D7, 0, 0, 0, 0);

    while(currentIrKey != KEY_POUND)
    {
        switch(currentIrKey){
            case KEY_1:             //print temperature
                returnedString = read_dht11_dat(2);

                while(returnedString.compare("invalidData") == 0 && count < 50){    //get a valid piece of data
                    returnedString = read_dht11_dat(2);
                    count++;
                }
                

                lcd_output(returnedString, 0);
                delay(1000);
                break;

            case KEY_2:
                returnedString = read_dht11_dat(1);

                while(returnedString.compare("invalidData") == 0 && count < 50){    //get a valid piece of data
                    returnedString = read_dht11_dat(1);
                    count++;
                }

                lcd_output(returnedString, 0);
                delay(1000);
                break;

            case KEY_3:
                lcd_output("SATELLITE NAME:", 0);
                lcd_output("Ostrich", 1);
                break;

            case KEY_4:
                //quote from the famous song 'Faucet Failure' by Ski Mask the Slump God
                lcd_output("IM FLYER THAN A", 0);
                lcd_output("FUCKIN OSTRICH", 1);
                break;
            case KEY_5:
                lcd_output("HEAD OF PI OPS", 0);
                lcd_output("Zach Hoffmann", 1);
                break;
            case KEY_6:
                lcd_output("LEET HACKERMANZ", 0);
                lcd_output("Hunter Paulson", 1);
                break;
            case KEY_7:
                lcd_output("Kill me now", 0);
                break;
            default:
                cout << "[ERROR] press the right buttons come on" << endl;
        }
        
        lastIrKey = currentIrKey;
        currentIrKey = read_ir_dat(); 
    }

    lcd_output("Goodbye", 0);

    serialClose(fd);
    return(0);


}
