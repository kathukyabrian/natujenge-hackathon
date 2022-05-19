#include <stdlib.h>
#include <stdio.h>
#include <string.h>
typedef unsigned char BYTE;

void marker()
{
    printf("===========================================\n");
}

int utf8strlen2(char *s)
{
    int cnt = 0;
    while (*s)
    {
        cnt++;
        if ((*s++ & 0xc0) == 0x0c0)
        {                               /* binary is 11xxxxxx */
            while ((*s & 0xc0) == 0x80) /* binary code is 10xxxxxx */
                s++;
        }
    }
    return cnt;
}

void string2ByteArray(char *input, BYTE *output)
{
    int loop;
    int i;

    loop = 0;
    i = 0;

    while (input[loop] != '\0')
    {
        output[i++] = input[loop++];
    }
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
        0x00

    };

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
    unsigned int tag = 0x0424;

    char *value = "Hello Natujenge#";

    printf("The tag in bytes is %x\n", tag);

    int size = utf8strlen2(value);
    printf("The size is %d\n", size);

    printf("The length in 2 bytes is %x\n", size);

    int combined = 0x0 & 0xff;

    int len = strlen(value);
    BYTE arr[len];
    int i;
    string2ByteArray(value, arr);

    // printing
    printf("utf8 string: %s\n", value);
    printf("byte array is...\n");
    for (i = 0; i < len; i++)
    {
        printf("%c - %d\n", value[i], arr[i]);
    }
    printf("\n");

    // end of question 2

    return 1;
}