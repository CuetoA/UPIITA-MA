#include <stdio.h>
#include <stdlib.h>

int var = 1;
int flag = 0;
char* binaryVar;

char* toBinary(int n){
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

int main(){
    
    while(var <= 128 && var >= 0){
        
        if (flag == 0)
            var *= 2;
        else
            var /= 2;

        binaryVar = toBinary(var);
        printf("var %s\n", binaryVar);

        if (var == 128)
            flag = 1;
        else if (var == 1)
            flag = 0;
    }

    return 0;
}


