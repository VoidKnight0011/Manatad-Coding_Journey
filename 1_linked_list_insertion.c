// Online C compiler to run C program online
#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int value;
    struct Node *next;
} Node;

Node *createNode(int);
void insertAtStart(Node**, int);
void insertAtEnd(Node**, int);
void insertAtPosition(Node**, int, int);
void displayList(Node*);
void promptValue(int*);
void freeList(Node**);

int main() {
    Node *head = NULL;
    
    printf("Linked Lists:\n");
    do{
        int choice;
        printf("1. Display List\n2. Insert At Position\n0. End Program\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
            displayList(head);
            break;
            case 2:
                int reChoice;
                int value;
                 printf("\nWhere to insert?\n");
                 printf("1. Start\n2. End\n3. Position\n0. Clear List\n");
                 printf("Enter choice: ");
                scanf("%d", &reChoice);
                 switch(reChoice){
                     case 1:
                     promptValue(&value);
                     insertAtStart(&head, value);
                     break;
                     
                     case 2:
                     promptValue(&value);
                     insertAtEnd(&head, value);
                     break;
                     
                     case 3:
                     promptValue(&value);
                     int position;
                     printf("What position to insert: ");
                     scanf("%d", &position);
                     if(position == 1) insertAtStart(&head, value);
                     else if(position < 1) {
                         printf("Invalid Position!\n\n");
                         break;
                     }
                     else insertAtPosition(&head, value, position);
                     break;
                     
                     case 0:
                     freeList(&head);
                     break;
                 }
                 break;
                 
            case 0:
            exit(0);
            break;
        }
    }while(1);

    return 0;
}

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
    scanf("%d", &(*value));
}

void insertAtStart(Node **head, int value){
    Node *newNode = createNode(value);
    
    newNode->next = *head;
    *head = newNode;
    
    printf("Inserted %d at the beginning\n\n", value);
}

void insertAtEnd(Node **head, int value){
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
    
    printf("Inserted %d at the end\n\n", value);
}

void insertAtPosition(Node **head, int value, int position){
    Node *newNode = createNode(value);
    
    Node* current = *head;
    int cpos = 1;
    while (current != NULL && cpos < position - 1){
        if(current->next == NULL){
            current->next = newNode;
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
    
    printf("Inserted %d at position %d\n\n", value, position);
}

void displayList(Node *head){
    if(head == NULL){
        printf("The List is empty!\n\n");
        return;
    }
    
    Node *current = head;
    
    while(current != NULL){
        printf("%d -> ", current->value);
        current = current->next;
    } printf("NULL\n\n");
}

void freeList(Node **head){
    Node *current = *head;
    while(current != NULL){
        Node *temp = current;
        current = current->next;
        free(temp);
    }
    *head = NULL;
}
