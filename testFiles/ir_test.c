#include <wiringSerial.h>
#include <stdio.h>
#include <wiringPi.h>
#include <errno.h>

int main(){
    wiringPiSetup();
    int fd = serialOpen("/dev/ttyACM0", 9600);
    char bullshit;
   int test;

    if(fd > 0){
        serialFlush(fd); //flush any data in buffer
        printf("[IR-TEST] begin pressing buttons\n");

	while(1){
          //bullshit = (char) serialGetchar(fd);
          test = serialDataAvail(fd);
	  bullshit = (char) serialGetchar(fd);
	 // printf("%d", test);
	 
	  if(test > 0){
	      printf("%c", bullshit); 
          }
      }
    }else{
        printf("[ERROR] unable to open port '/dev/ttyACM0'\n");
    }

    serialClose(fd);
}
