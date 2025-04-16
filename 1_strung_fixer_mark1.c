#include<stdio.h>
#include<string.h>
#include<ctype.h>

#define Max_Len 50

void strRev(char str[]);
void toLower(char str[]);

int main(){
int num = 5;
char string[Max_Len];
    printf("Input String: ", string);
    fgets(string, sizeof(string), stdin);
        string[strcspn(string, "\n")] = '\0';
    
    printf("Normal: %s\n", string);
    toLower(string);
    printf("Fixed: %s\n", string);
    strRev(string);
    printf("Reversed: %s", string);
    return 0;
}

void strRev(char str[]){
    for(int i = 0, j = strlen(str); i!=j; i++, j--){
    char temp = str[i];
    str[i] = str[j];
    str[j] = temp;
    }

}

void toLower(char str[]){
    for(int i=0; i<strlen(str); i++){
    str[i] = tolower(str[i]);
    }
}
    