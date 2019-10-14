#include <wiringSerial.h>
#include <stdio.h>
#include <wiringPi.h>
#include <errno.h>
#include <string>
#include <iostream>


int fd = serialOpen("/dev/ttyACM0", 9600);
int bytesToRead;

using namespace std;

int main(){
    wiringPiSetup();
    
    string toString;

    if(fd > 0){
        serialFlush(fd); //flush any data in buffer
        printf("[IR-TEST] begin pressing buttons\n");

	    while(1){
                bytesToRead = serialDataAvail(fd);
            
	        if(bytesToRead > 0){
                 //char * serialData = new char[bytesToRead];
	            
                for(int i = 0; i < bytesToRead; i++){
		            //serialData[i] = serialGetchar(fd);
                    //printf("%c", serialData[i]);
                    toString = serialGetchar(fd);
                }

                cout << toString << endl;

                //delete serialData;
	        serialFlush(fd);
            }
           delay(150);
        } 
    }else{
        printf("[ERROR] unable to open port '/dev/ttyACM0'\n");
    }

    serialClose(fd);
}
