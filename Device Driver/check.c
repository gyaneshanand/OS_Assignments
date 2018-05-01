#include <stdio.h>
#include <memory.h>
#include <stdlib.h>

#define LENGTH 16
int main()
{
    char const plainone[LENGTH] = "PlainOne";//message
    char const plaintwo[LENGTH] = "PlainTwo";//key
    char xor[LENGTH];//cyphertext
    char final[LENGTH];//recovered message
    int i;

    for(i=0; i<LENGTH; ++i)
        xor[i] = (char)(plainone[i] ^ plaintwo[i]);
    printf("PlainText One: %s\nPlainText Two: %s\n\none^two: ", plainone, plaintwo);
    for(i=0; i<LENGTH; ++i){
        final[i]=(char)(xor[i]^plaintwo[i]);
        printf("%02X \n", xor[i]);}
    printf(" first string recovered : %s \n",final );
    printf("\n");
    return 0;
}