#include<stdio.h>

int binaryChecker(int);

int main(){
    int binary;

    do {
    printf("Enter a binary number: ");
    scanf("%d", &binary);
        if(binaryChecker(binary) == 1) break;
        else printf("%d is not a binary number! Please try again.\n", binary);
    } while (1);

    printf("Hi");

    return 0;
}

int binaryChecker(int a){
    while(a != 0){
        int rem = a % 10;
        if(rem != 0 && rem != 1) return 0;
        
        a /= 10;
    }
    return 1;
}
