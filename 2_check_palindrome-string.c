#include<stdio.h>
#include<string.h>
//palindrome string//
int main(){
char stringy[100];
    printf("Enter a string: ");
    scanf("%[^\n]", stringy);
    
    int start = 0, end = strlen(stringy) - 1, counter = 0;
    int len = strlen(stringy);
    while (start <= end){
        if(stringy[start] == stringy[end]){
            counter++;
        }
        start++;
        end--;
    }
    
    if(counter == ((len + 1) / 2)){
        printf("%s is a palindrome", stringy);
    } else {
        printf("%s is not a palindrome", stringy);
    }
    
    return 0;
}