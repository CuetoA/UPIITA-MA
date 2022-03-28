#include <stdio.h>
#include <stdlib.h>
 
char* toBinary(int n)
{
    int len = 8;
    int k = 0;
    int i;

    char* binary = (char*)malloc(sizeof(char) * len);
    
    for (i = (1 << len - 1); i > 0; i = i / 2) {
        binary[k++] = (n & i) ? '1' : '0';
    }
    binary[k] = '\0';
    return binary;
}
 
int main(void)
{
    int n = 20;
    int len = 8;
 
    char* binary = toBinary(n);
    printf("The binary representation of %d is %s", n, binary);
    free(binary);
 
    return 0;
}