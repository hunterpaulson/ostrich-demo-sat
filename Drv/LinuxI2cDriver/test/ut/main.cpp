#include <Tester.hpp>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

TEST(TestNominal,Nominal) {

    Drv::Tester tester;

}

const char* help = "[-h] -d <I2C device> -a <I2C address> <byte 0> <byte1> ... <byteN>";

int main(int argc, char* argv[]) {

    int c;

    U32 addr = 0;
    char device[80];
    device[0] = 0;

    while ((c = getopt (argc, argv, "hd:a:")) != -1) {
        switch (c) {
            case 'h':
                printf("test_ut %s\n",argv[0],help);
                return 0;
            case 'a':
                addr = strtoul(optarg,0,0);
                break;
            case 'd':
                strcpy(device,optarg);
                break;
            default:
                printf("test_ut %s\n",argv[0],help);
                return -1;
        }
    }

    printf("Address: %d (0x%02X) Device: %s\n",addr,addr,device);

    for (int i = optind; i < argc; i++) {
        printf("Data: %s\n",argv[i]);
    }

    return 0;

    Drv::Tester tester;

    U8 data[12];

    tester.sendData(0x40,data,sizeof(data));

    return 0;
}


