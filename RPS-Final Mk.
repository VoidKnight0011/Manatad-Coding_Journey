#include <stdio.h>
#include <unistd.h>

void introGreet();
void delay(int);
void Tx(char[]);
void clearScreen();

int main() {
	introGreet();
    return 0;
}



void introGreet(){
	Tx("Welcome to...");
	delay(1);
	clearScreen();
	Tx("Rock, ");
	delay(1);
	Tx("Paper, ");
	delay(1);
	Tx("Scissors ! ! !");
	delay(3);
}

void delay(int a){
	sleep(a);
}

void Tx(char a[]){
	for(int i = 0; a[i] != '\0'; i++){
		putchar(a[i]);
		fflush(stdout);
		usleep(50 * 1000);
	}
}

void clearScreen(){
    printf("\033[H\033[J");
    fflush(stdout);
}
