#include<stdio.h>
#include<string.h>

#define Max_Len 50

void strRev(char str[]);

int main(){
int num = 5;
char string[Max_Len];
    printf("Input String: ", string);
    scanf("%[^\n]", string);
    
    printf("%s\n", string);
    strRev(string);
    
    printf("%s", string);
    return 0;
}

void strRev(char str[]){
    for(int i = 0, j = strlen(str) - 1; i!=j; i++, j--){
    char temp = str[i];
    str[i] = str[j];
    str[j] = temp;
    }

}
