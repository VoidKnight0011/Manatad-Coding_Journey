#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node *prev;
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
    int choice;

    do {
        clearScreen();
        printf("Doubly Linked List:\n");
        printf("1. Display List\n");
        printf("2. Insert Node\n");
        printf("3. Delete Node\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        while (scanf("%d", &choice) != 1) {
            clearBuffer();
            printf("Invalid input! Enter a valid choice: ");
        }

        switch (choice) {
            case 1:
                displayList(head);
                break;

            case 2: {
                int where, value, pos;
                printf("\nWhere to insert?\n");
                printf("1. Start\n2. Position\n3. End\n");
                printf("Enter choice: ");
                scanf("%d", &where);
                promptValue(&value);

                if (where == 1) {
                    insertAtStart(&head, value);
                } else if (where == 2) {
                    printf("Enter position: ");
                    while (scanf("%d", &pos) != 1 || pos < 1) {
                        clearBuffer();
                        printf("Invalid! Enter a valid position: ");
                    }
                    insertAtPosition(&head, value, pos);
                } else if (where == 3) {
                    insertAtEnd(&head, value);
                } else {
                    printf("Invalid choice!\n");
                }
                break;
            }

            case 3: {
                int where, pos;
                if (head == NULL) {
                    printf("List is empty!\n");
                    break;
                }
                printf("\nWhere to delete?\n");
                printf("1. Start\n2. Position\n3. End\n0. Free Entire List\n");
                printf("Enter choice: ");
                scanf("%d", &where);

                if (where == 1) {
                    deleteAtStart(&head);
                } else if (where == 2) {
                    printf("Enter position: ");
                    while (scanf("%d", &pos) != 1 || pos < 1) {
                        clearBuffer();
                        printf("Invalid! Enter a valid position: ");
                    }
                    deleteAtPosition(&head, pos);
                } else if (where == 3) {
                    deleteAtEnd(&head);
                } else if (where == 0) {
                    freeList(&head);
                } else {
                    printf("Invalid choice!\n");
                }
                break;
            }

            case 0:
                freeList(&head);
                exit(0);

            default:
                printf("Invalid choice!\n");
        }

        printf("\nPress Enter to continue...");
        clearBuffer();
        getchar();
    } while (1);

    return 0;
}

// __________ Function Definitions __________ //

Node *createNode(int value) {
    Node *newNode = malloc(sizeof(Node));
    if (!newNode) {
        fprintf(stderr, "Memory allocation failed!\n");
        exit(1);
    }
    newNode->value = value;
    newNode->prev = newNode->next = NULL;
    return newNode;
}

void insertAtStart(Node **head, int value) {
    // TODO: implement for doubly linked list
}

void insertAtEnd(Node **head, int value) {
    // TODO: implement for doubly linked list
}

void insertAtPosition(Node **head, int value, int pos) {
    // TODO: implement for doubly linked list
}

void deleteAtStart(Node **head) {
    // TODO: implement for doubly linked list
}

void deleteAtEnd(Node **head) {
    // TODO: implement for doubly linked list
}

void deleteAtPosition(Node **head, int pos) {
    // TODO: implement for doubly linked list
}

void displayList(Node *head) {
    clearScreen();
    if (!head) {
        printf("List is empty!\n");
        return;
    }
    Node *cur = head;
    printf("NULL <-> ");
    while (cur) {
        printf("%d <-> ", cur->value);
        cur = cur->next;
    }
    printf("NULL\n");
}

void freeList(Node **head) {
    Node *cur = *head;
    int count = 0;
    while (cur) {
        Node *t = cur;
        cur = cur->next;
        free(t);
        count++;
    }
    *head = NULL;
    clearScreen();
    printf("Freed %d node%s\n", count, count > 1 ? "s" : "");
}

void promptValue(int *value) {
    printf("Enter value: ");
    while (scanf("%d", value) != 1) {
        clearBuffer();
        printf("Invalid! Enter an integer: ");
    }
}

void clearScreen() {
    printf("\033[H\033[J");
    fflush(stdout);
}

void clearBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}
