#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct Node {
    char value;
    struct Node* next;
} Node;

void initStack(Node** top);

void push(Node** top, char value);

char pop(Node** top);

int isEmpty(Node* top);

int isBalanced(char* expression);

int main() {
    char expression[MAX_SIZE];
    printf("Digite uma expressão: ");
    scanf("%[^\n]", expression);
    if (isBalanced(expression)) {
        printf("A expressão está correta.\n");
    } else {
        printf("A expressão  está incorreta.\n");
    }
    return 0;
}

void initStack(Node** top) {
    *top = NULL;
}

void push(Node** top, char value) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->value = value;
    newNode->next = *top;
    *top = newNode;
}

char pop(Node** top) {
    if (*top == NULL) {
        printf("ERRO: pilha vazia\n");
        exit(1);
    }
    char value = (*top)->value;
    Node* temp = *top;
    *top = (*top)->next;
    free(temp);
    return value;
}

int isEmpty(Node* top) {
    return top == NULL;
}

int isBalanced(char* expression) {
    Node* stack;
    initStack(&stack);
    char c;
    for (int i = 0; expression[i] != '\0'; i++) {
        c = expression[i];
        if (c == '(' || c == '[' || c == '{') {
            push(&stack, c);
        } else if (c == ')' || c == ']' || c == '}') {
            if (isEmpty(stack)) {
                return 0;
            }
            char top = pop(&stack);
            if ((c == ')' && top != '(') || (c == ']' && top != '[') || (c == '}' && top != '{')) {
                return 0;
            }
        }
    }
    return isEmpty(stack);
}


