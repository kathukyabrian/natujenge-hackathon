#include <stdlib.h>
#include <stdio.h>
#include <string.h>
typedef unsigned char BYTE;

void marker()
{
    printf("===========================================\n");
}

int getUtf8StringLength(char *s)
{
    int i = 0, j = 0;
    while (s[i])
    {
        // 0xco is 1100 0000 - anding means that we are interested in the first 2 bits
        // 0x80 is 1000 0000 - 
        if ((s[i] & 0xc0) != 0x80)
        {
            printf("%x is counting 1\n", s[i]);
            j++;
        }
        else
        {
            printf("%c is counting 2\n", s[i]);
            j+=2;
        }

        i++;
    }
    return j;
}

int main()
{

    // start question 1
    int hexInput[50] = {
        0x13,
        0x55,
        0xb6,
        0x76,
        0x79,
        0x88,
        0x29,
        0x5e,
        0x00,
        0x00,
        0x00,
        0x00,
        0x00,
        0x03,
        0x00,
        0x34,
        0x7e,
        0x58,
        0x1e,
        0x36,
        0x00,
        0x00,
        0x00,
        0x00,
        0x00,
        0x00,
        0x00,
        0x00};

    int sourcePort = 0x0 & 0xff;
    sourcePort |= hexInput[0] & 0xff;
    sourcePort <<= 8;
    sourcePort |= hexInput[1] & 0xff;
    printf("Source port is %d\n", sourcePort);

    int destinationPort = 0x0 & 0xff;
    destinationPort |= hexInput[2] & 0xff;
    destinationPort <<= 8;
    destinationPort |= hexInput[3] & 0xff;
    printf("Destination port is %d\n", destinationPort);

    int verificationTag = 0x0 & 0xff;
    verificationTag |= hexInput[4] << 24;
    verificationTag |= hexInput[5] << 16;
    verificationTag |= hexInput[6] << 8;
    verificationTag |= hexInput[7];
    printf("Verification tag is %d\n", verificationTag);

    int type = 0x0 & 0xff;
    type |= hexInput[12];
    printf("Type is %d\n", type);

    int bflag = hexInput[13] & 0b00000010;
    char *bFlagStr = "false";
    if (bflag != 0)
    {
        bFlagStr = "true";
    }
    printf("B Flag is %s\n", bFlagStr);

    int length = 0x0 & 0xff;
    length |= hexInput[14];
    length <<= 8;
    length |= hexInput[15];
    printf("Length is %d\n", length);
    marker();
    // end of question 1

    // start question 2

    // tag = 0x0424
    // value = Hello Natujenge Σ!

    unsigned int tag = 0x0424;
    printf("The tag is %x\n", tag);

    char *value = "Hello Natujenge Σ!";

    int characterCount = getUtf8StringLength(value);
    printf("The number of characters is %d\n", characterCount);

    short characterCountIn2Bytes = characterCount;
    printf("The number of characters as 2 bytes is %x\n", characterCountIn2Bytes);

    char valueByteArray[19] = {};

    for (int i = 0; i <= characterCount; i++)
    {
        printf("Character is %c\n", value[i]);
    }

    // end of question 2

    return 1;
}