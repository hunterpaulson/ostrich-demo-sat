#include <wiringSerial.h>
#include <stdio.h>
#include <ir_key_codes.h>

int fd = serialOpen('/dev/ttyACM0', 9600);    //open the port w/ baud rate 9600

int main(){
    if(fd > 0){
        serialFlush(fd); //flush any data in buffer
        printf("[IR-TEST] begin pressing buttons\n");
        if(serialDataAvail(fd) > 0){
            printf("%d", (char) serialGetchar(fd));
        }

    }else{
        printf("[ERROR] unable to open port '/dev/ttyACM0'\n");
    }

    serialClose(fd);
}