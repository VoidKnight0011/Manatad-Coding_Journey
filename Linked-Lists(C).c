#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int value;
   struct Node *next;
}Node;

void displayList(Node *);
Node* createNode(int);
void insertAtBeginning(Node**, int)V8,  ;
void insertAtEnd(Node**, int);

int main(){
int choice;
Node* head = NULL;
    printf("Linked Listers!\n");
    int subChoice, value, pos;
    do{
    printf("1. Display List\n2. Insert Node\n");
    printf("Pick a Choice: ");
    scanf("%d", &choice);
    
        switch(choice){
            case 0:
            printf("Exiting Program");
            exit(0);
            break;
            
            case 1:
            displayList(head);
            break;
            
            case 2:
            printf("Where to Insert?\n");
            printf("1. Beginning\n2. At Position\n3. Last\n");
            printf("Enter Your Choice: ");
            scanf("%d", &subChoice);
            
            printf("\nEnter value to be inserted: ");
            scanf("%d", &value);
                switch(subChoice){
                case 1:
                insertAtBeginning(&head, value);
                break;
                
                case 2:
                printf("Enter position to insert: ");
                scanf("%d", &pos);
                // Insert at Position func
                break;
                
                case 3:
                insertAtEnd(&head, value);
                break;
                }
            break;    
            
            default:
            printf("Unknown");
            break;
        }
    
    }while(1);
    return 0;
}

void displayList(Node *head){
    Node *temp = head;
    
    if(temp == NULL){
        printf("The List is Empty\n\n");
        return;
    }
    
    while(temp != NULL){
    printf("%d -> ", temp->value);
    temp = temp->next;
    } printf("NULL\n\n");
}

Node* createNode(int value){
    Node *newNode = (Node*)malloc(sizeof(Node));
    if(newNode == NULL){
    printf("Memory Allocation Failed!");
    exit(1);
    }
    
    newNode->value = value;
    newNode->next = NULL;
    
    return newNode;
}

void insertAtBeginning(Node **head, int value){
    Node *newNode = createNode(value);
    newNode->next = *head;
    *head = newNode;
    printf("Node inserted at the Beginning\n\n");
}

void insertAtEnd(Node **head, int value){
    Node *newNode = createNode(value);
    
    if(*head == NULL) *head = newNode;
    else{
    Node *temp = *head;
        while(temp->next != NULL){
        temp = temp->next;
        } temp->next = newNode;
        
        printf("Node inserted at end\n\n");
    } 
}