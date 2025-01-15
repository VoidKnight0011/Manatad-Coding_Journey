/*
Project Name: RPS Mk. III
Coded by: Geoseffe Vincent B. Manatad
Programmer’s Note:
    - I coded this all while I was going home after the day where I had my Pre-Finals Examination. This is probably my first “First Major Code.”
*/

#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<unistd.h>
#include<time.h>

//___________________________________________________________________________

        void intro();
    int option();
        void loading();
    void choicesPrint();
    void player1(char a[]);
    void player2(char a[]);
        void lowercase(char a[]);
    void game(char a[], char b[]);
        void pauseSec();
        int end();
        void slowType();
        void exclamationMarks();
        void clearScreen();

int pts1 = 0, pts2 = 0;

//___________________________________________________________________________
//___________________________________________________________________________
//___________________________________________________________________________

int main(){
    option();
return 0;
}

//___________________________________________________________________________
//___________________________________________________________________________
//___________________________________________________________________________

void intro(){
    slowType("Welcome to ");
    loading();
    clearScreen();
    slowType("Rock");
    printf("-");
        pauseSec();
    slowType("Paper");
        pauseSec();
    printf("-");
    slowType("Scissors ");
        exclamationMarks();
        pauseSec();
}

int option(){
    char p1[10] , p2[10];
    int choice;
    intro();
        do{
            slowType("\n[1] Start\n[0] End\n");
            scanf("%d", &choice);
                if(choice == 1){
                clearScreen();
                    slowType("\nLet the Games ");
                        loading();
                    slowType("Begin");
                    exclamationMarks();
                    pauseSec();
                    clearScreen();
                        choicesPrint();
                        player1(p1);\
                        clearScreen();
                    slowType("\nPlayer 1 chose: ");
                        pauseSec();
                    printf("'%c%s'\n", toupper(p1[0]), p1 + 1);
                        player2(p2);
                        pauseSec();
                    slowType("Player 2 chose: ");
                        pauseSec();  
                    printf("'%c%s'\n", toupper(p2[0]), p2 + 1);
                        game(p1, p2);
                        pauseSec();
                        clearScreen();
            
        do{
            if(pts1 == 3) {
                slowType("The Winner is Player 1!\n");
                printf("%d—%d\n", pts1, pts2);
                slowType("\nThank You For Playing!\n");
                    loading();
                return 0;
            } else if(pts2 == 3) {
                slowType("The Winner is Player 2 wins!\n");
                printf("%d—%d\n", pts1, pts2);
                slowType("\nThank You For Playing!\n");
                    loading();
                return 0;
            }
                    pauseSec();
                    clearScreen();
                slowType("\nDo you wish to continue?\n[0] Score\n[1] Yes\n[2] No\n");
                    if(scanf("%d", &choice) !=1){
                        slowType("\nChoices must be:\n[0] Score [1] Yes or [2] No\n");
                        while(getchar() != '\n');
                        continue;
                    }
                
                    if(choice == 0){
                        slowType("\nScore:\nPlayer 1: ");
                        printf("%d\n");
                        slowType("Player 2: ");
                        printf("%d\n", pts1, pts2);
                    } else if(choice == 1){
                        clearScreen();
                        slowType("\nGame Retart!\n");
                            pauseSec();
                            player1(p1);
                        slowType("\nPlayer 1 chose: ");
                            pauseSec();
                        printf("'%s'\n", p1);
                            player2(p2);
                            pauseSec();
                        slowType("Player 2 chose: ");
                            pauseSec(); 
                        printf("'%s'\n", p2);
                            game(p1, p2);
                        } else if(choice == 2){
                            end();
}
        } while(1);

            if(pts1==3){
            break;
            } else if(pts2==3){
            break;
            }
            if(choice==2){
            break;
            }
                    } else if(choice == 0){
                        clearScreen();
                        end();
                    } else {
                        slowType("\nInvalid input!\n\n");
                        pauseSec();
                        clearScreen();
                        while(getchar() != '\n');
                    }
        } while(pts1 < 3 || pts2 < 3);

}

void loading(){
    for(int i=3;i>0;i--){
        printf(". ");
        fflush(stdout);
            pauseSec();
    }
}

void exclamationMarks(){
for(int i=3;i>0;i--){
printf(" !");
fflush(stdout);
usleep(250*1000);
}
}

void choicesPrint(){
    for(int i=1;i>0;i--){
        slowType("(Choices) ");
            pauseSec();
        slowType("Rock, ");
            pauseSec();
        slowType("Paper, ");
            pauseSec();
    slowType("Scissors\n");
            pauseSec();
    }
}

void player1(char a[]){
    do{
        slowType("Enter player 1: ");
        scanf("%s", a);
            lowercase(a);
            if(strcmp(a, "rock") == 0 ||  strcmp(a, "paper") == 0 || strcmp(a, "scissors") == 0){
            break;
            } else {
                slowType("Invalid Choice!\n\n");
            }
    }while(1);
}

void player2(char a[]){
    srand(time(NULL));
    int dice = rand()%3;

    if(pts1 > pts2){
        switch(dice){
            case 0:
                strcpy(a, "scissors");
            break;
            case 1:
                strcpy(a, "paper");
            break;
            case 2:
                strcpy(a, "rock");
            break;
        }
    } else {
        switch(dice){
            case 0:
                strcpy(a, "rock");
            break;
            case 1:
                strcpy(a, "paper");
            break;
            case 2:
                strcpy(a, "scissors");
            break;
        }
    }
}

void lowercase(char a[]){
    for(int i = 0;a[i] != '\0'; i++ ){
        a[i] = tolower(a[i]);
    }
}

void game(char a[], char b[]){
    if(strcmp(a, b) == 0){
        slowType("It's a tie!\n");
    } else if (strcmp(a, "rock") == 0 && strcmp(b, "scissors") == 0 || strcmp(a, "paper") == 0 && strcmp(b, "rock") == 0 || strcmp(a, "scissors") == 0 && strcmp(b, "paper") == 0){
        slowType("Player 1 wins!\n");
        pts1++;
    } else {
        slowType("Player 2 wins!\n");
        pts2++;
    }
}

void pauseSec(){
    sleep(1);
}

void clearScreen(){
printf("\033[H\033[J");
}

int end(){
    if(pts1 > pts2){
                                slowType("\nThe Winner is");
                                    pauseSec();
                                slowType(" Player 1!\n");
                                printf("%d—%d\n", pts1, pts2);
                                    pauseSec();
                                slowType("\nThank You For Playing!\n");
                            loading();
                                exit(0);
                            } else if(pts2 > pts1){
                                slowType("\nThe Winner is");
                                    pauseSec();
                                printf(" Player 2!\n");
                                printf("%d—%d\n", pts1, pts2);
                                    pauseSec();
                                slowType("\nThank You For Playing!\n");
                                    loading();
                                exit(0);
                            } else if(pts1 == pts2){
                                slowType("\nIt's a Tie!\n");
                                printf("%d—%d\n", pts1, pts2);
                                    pauseSec();
                                slowType("\nThank You For Playing!\n");
                                    loading();
                                exit(0);
                            }
                            slowType("\nThank You For Playing!\n");
                                loading();
                            exit(0);
                        }
                        
void slowType(char a[]){
for(int i=0; a[i] != '\0'; i++){
putchar(a[i]);
fflush(stdout);
usleep(50 * 1000);
}
}

//___________________________________________________________________________

/*
Code History: 
    I.) RPS Mark I: (University of San Carlos) BSIT-1, Block E: Programming 1, Assignment
    II.) RPS Mark II: RPS (Rock-Paper-Scissors) - Manual Edition
    III.) RPS Mark III: —--
*/ 



