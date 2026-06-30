#include <stdio.h>
#include <ctype.h>
#define STACK_MAX_SIZE 20

int stack[STACK_MAX_SIZE];
int top = -1;

void push(int x) {
    if (top == STACK_MAX_SIZE - 1) {
        printf("Stack overflow.\n");
        return;
    }
    stack[++top] = x;
}

int isEmpty() {
    return top == -1;
}

int pop() {
    if (isEmpty()) return -1;
    return stack[top--];
}

void evaluatePostfix(char *e) {
    int a, b, result;

    while (*e != '\0') {
        if (isdigit(*e)) {
            push(*e - '0');
        } else {
            a = pop();
            b = pop();

            if (a == -1 || b == -1) {
                printf("Invalid postfix expression.\n");
                return;
            }

            switch (*e) {
                case '+': result = b + a; break;
                case '-': result = b - a; break;
                case '*': result = b * a; break;
                case '/':
                    if (a == 0) {
                        printf("Division by zero error.\n");
                        return;
                    }
                    result = b / a;
                    break;
                default:
                    printf("Invalid operator in expression.\n");
                    return;
            }
            push(result);
        }
        e++;
    }

    if (top == 0) {
        int finalResult = pop();
        printf("Result: %d\n", finalResult);
    } else {
        printf("Invalid postfix expression.\n");
    }
}

int main() {
    char exp[100];
    printf("Enter the postfix expression: ");
    scanf("%s", exp);
    evaluatePostfix(exp);
    return 0;
}
