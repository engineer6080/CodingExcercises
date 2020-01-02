#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int isunique(char *str){
        int checker = 0;
        for(int i = 0; i < strlen(str); i++) {
                int val = str[i] - 'a'; //Assumming letters a through z
                if((checker & (1 << val))) {
                        return 0;
                }
                checker |= (1<<val);
        }
        return 1;
}

int main(){

        char in[100];
        printf("Enter Input: ");
        scanf("%s",in);

        printf("is unique = %s\n", isunique(in) ? "true" : "false");

}
