#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<time.h>

int miniDecimalConverter(int *reBinary) {
    int decimal = 0, place = 0;

    while (*reBinary > 0) {
        int rem = *reBinary % 10;
        if (rem == 1) decimal += pow(2, place);
        *reBinary /= 10;
        place++;
    }

    return decimal;
}

void outputChecker(int *binary, int decimal){
    int decimalEquiv = *binary;
    decimalEquiv = miniDecimalConverter(&decimalEquiv);
    
    if(decimal == decimalEquiv){
    printf("Correct\n\n");
    *binary = 0;
    }else{
    printf("False! The value of %d was %d NOT %d\n\n", *binary, decimalEquiv, decimal);
    *binary = 0;
    }
}

int randomBinaryGenerator(int *binary){
    *binary = 0;
    for(int i = 0; i<8; i++){
    int bit = rand() % 2;
    *binary = (*binary) * 10 + bit;
    }

    return *binary;
}

void printProgram(){
    int binary, decimal;
    do{
    randomBinaryGenerator(&binary);
        printf("Convert %d into Decimal\n", binary);
        printf("Your Answer: ", decimal);
        scanf("%d", &decimal);
            if(decimal == 0) exit(0);
            
        outputChecker(&binary, decimal);
        
    } while(1);    
}

// -----

int main(){
    srand(time(NULL));
    printf("--- Binary Conversion Practice ---\n");    
    printProgram();
    return 0;
}