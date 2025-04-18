#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int value;
    struct Node *next;
} Node;

// __________ Function Prototypes __________ //

void insertAtStart(Node**, int);
void insertAtEnd(Node**, int);
void insertAtPosition(Node**, int, int);
void deleteAtStart(Node**);
void deleteAtEnd(Node**);
void deleteAtPosition(Node**, int);
    Node *createNode(int);
    void displayList(Node*);
    void freeList(Node**);
        void promptValue(int*);
        void clearScreen();
        void clearBuffer();





// __________ Main Function __________ //

int main() {
    Node *head = NULL;
    
    do{
        int choice, reChoice, value, rereChoice, rePosition, position;
        printf("Linked Lists:\n");
        printf("1. Display List\n2. Insert to List\n3. Delete Node\n0. End Program\n");
        printf("Enter your choice: ");
        while(scanf("%d", &choice) != 1){
            clearBuffer();
            printf("Invalid input!\nEnter a Valid Choice: ");
        }
        clearScreen();
        switch(choice){
            case 1:
            displayList(head);
            break;
            case 2:
                 printf("\nWhere to insert?\n");
                 printf("1. Start\n2. Position\n3. End\n");
                 printf("Enter choice: ");
                scanf("%d", &reChoice);
                 switch(reChoice){
                     case 1:
                     promptValue(&value);
                     insertAtStart(&head, value);
                     break;
                     
                     case 2:
                     promptValue(&value);
                     int position;
                     printf("What position to insert: ");
                     while(scanf("%d", &position) != 1 || position < 1){
                         printf("Invalid input!\nEnter a Valid Position: ");
                         clearBuffer();
                     }
                     if(position == 1) insertAtStart(&head, value);
                     else insertAtPosition(&head, value, position);
                     break;
                     
                     case 3:
                     promptValue(&value);
                     insertAtEnd(&head, value);
                     break;
                     
                     default:
                     printf("Invalid choice!\n\n");
                 }
                 break;
            case 3:
            if(head == NULL){
                clearScreen();
                printf("The List is Empty!\n");
                break;
            }
            printf("Where to delete?\n1. Start\n2. At Position\n3. End\n0. Free List\n");
            printf("Enter your choice: ");
            scanf("%d", &rereChoice);
                switch(rereChoice){
                    case 1:
                    deleteAtStart(&head);
                    break;
                    case 2:
                    printf("Enter position to delete at: ");
                     while(scanf("%d", &position) != 1 || position < 1){
                         printf("Invalid input!\nEnter a Valid Position: ");
                         clearBuffer();
                     }
                     if(position == 1) deleteAtStart(&head);
                     else deleteAtPosition(&head, position);
                    break;
                    case 3:
                    deleteAtEnd(&head);
                    break;
                    case 0:
                    freeList(&head);
                    break;
                }
            break;
            
            case 0:
            exit(0);
            break;
            
            default:
            printf("Invalid choice!\n\n");
        }
    }while(1);

    return 0;
}

// __________________________________________ //
    
    
    
    
// __________ Function Definitions __________ //

    Node *createNode(int value){
        Node *newNode = (Node*)malloc(sizeof(Node));
            if(newNode == NULL){
                printf("Memory Allocation Failed!");
                exit(1);
            }
            
        newNode->value = value;
        newNode->next = NULL;
        
        return newNode;
    }
    
    void promptValue(int *value){
        printf("Enter value to be inserted: ");
        while(scanf("%d", &(*value)) != 1){
            printf("Invalid Input!\nEnter a Valid Value: ");
            clearBuffer();
        }
    }
    
    void insertAtStart(Node **head, int value){
        Node *newNode = createNode(value);
        
        newNode->next = *head;
        *head = newNode;
        
        clearScreen();
        printf("Inserted %d at the beginning\n\n", value);
    }
    
    void insertAtEnd(Node **head, int value){
        clearScreen();
        if(*head == NULL){
            insertAtStart(head, value);
            return;
        }
        Node *newNode = createNode(value);
            Node *current = *head;
        while(current->next != NULL){
            current = current->next;
        }
        
        current->next = newNode;
        
        clearScreen();
        printf("Inserted %d at the end\n\n", value);
    }
    
    void insertAtPosition(Node **head, int value, int position){
        Node *newNode = createNode(value);
        
        Node* current = *head;
        int cpos = 1;
        while (current != NULL && cpos < position - 1){
            if(current->next == NULL){
                current->next = newNode;
                clearScreen();
                printf("Inserted %d at the end\n\n", value);
                return;
            }
            current = current->next;
            cpos++;
        }
        
        if(current == NULL){
            printf("Position not found\n\n");
            return;
        }
        
        newNode->next = current->next;
        current->next = newNode;
        clearScreen();
        printf("Inserted %d at position %d\n\n", value, position);
    }
    
    void displayList(Node *head){
        clearScreen();
        if(head == NULL){
            printf("The List is empty!\n\n");
            return;
        } else {
            Node *current = head;
            
            while(current != NULL){
                printf("%d -> ", current->value);
                current = current->next;
            } printf("NULL\n\n");
        }
    }
    
    void deleteAtStart(Node **head){
        
        Node *temp = *head;
        *head = (*head)->next;
        free(temp);
        
        clearScreen();
        printf("Deleted Node at the Start of the List\n\n");
    }
    
    void deleteAtEnd(Node **head){
        if(*head == NULL){
            printf("The List is empty!!\n\n");
            return;
        } else if ((*head)->next == NULL){
            free(*head);
            *head = NULL;
            return;
        } else {
            Node *current = *head;
            while(current->next->next != NULL){
                current = current->next;
            }
            free(current->next);
            current->next = NULL;
            
            clearScreen();
            printf("Deleted Node at the End of the List\n\n");
        }
    }
    
    void deleteAtPosition(Node **head, int position){
        Node *current = *head;
        int cpos = 1;
        while(current != NULL && cpos < position - 1){
            current = current->next;
            cpos++;
        }
        Node *deletion = current->next;
        current->next = current->next->next;
        free(deletion);
        
        clearScreen();
        printf("Deleted Node at position %d of the List\n\n", position);
    }
    
    void freeList(Node **head){
        if(*head == NULL){
            clearScreen();
            printf("The List is Empty!\n\n");
            return;
        }
        Node *current = *head;
        int nodeCount = 0;
        while(current != NULL){
            Node *temp = current;
            current = current->next;
            free(temp);
            nodeCount++;
        }
        *head = NULL;
        clearScreen();
        printf("Freed %d Node", nodeCount);
        if(nodeCount > 1) printf("s");
        printf(" in the Linked List!\n\n");
    }
    
    void clearScreen(){
        printf("\033[H\033[J");
        fflush(stdout);
    }
    
    void clearBuffer(){
        while(getchar() != '\n');
    }
