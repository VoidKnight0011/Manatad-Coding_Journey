#include<stdio.h>
#include<stdlib.h>

// Bubble Sort

int main() {
int length;
    printf("Enter array length: ");
    scanf("%d",&length);
    
    int *array = (int*)malloc(length * sizeof(int));
    printf("Enter the elements of the array:\n");
    for(int i = 0; i < length; i++){
    scanf("%d", &array[i]);
    }
    
    
    for(int i = 0; i < length; i++){
        for (int j = 0; j < length - 1; j++){
            if(array[j+1] < array[j]){
                int temp = array[j + 1];
                array[j + 1] = array[j];
                array[j] = temp;
            }
        }
    }
    
    for(int i = 0; i < length; i++){
        printf("%d ", array[i]);
    }
    
    free(array);
    
    return 0;
}