#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include <string.h>

#define MAX 100

int stack[MAX];
int top = -1;

void push(int item) {
    if (top == MAX - 1) {
        printf("Stack overflow...\n");
    } 
    else {
        stack[++top] = item;
    }
}

int pop() {
    if (top == -1) {
        printf("Stack underflow...\n");
        return -1;
    }
    return stack[top--];
}

int evalpostfix(char *exp) {
    for (int i = 0; exp[i] != '\0'; i++) {
        char ch = exp[i];

        if (ch == ' ' || ch == '\t')
            continue;

        else if (isdigit(ch)) {
            int num = 0;
            while (isdigit(exp[i])) {
                num = num * 10 + (exp[i] - '0');
                i++;
            }
            i--;
            push(num);
        } 
        else {
            if (top < 1) {
                printf("Invalid postfix expression...\n");
                return -1;
            }
            int val2 = pop();
            int val1 = pop();
            int res;

            switch (ch) {
                case '+':
                    res = val1 + val2;
                    break;
                case '-':
                    res = val1 - val2;
                    break;
                case '*':
                    res = val1 * val2;
                    break;
                case '/':
                    if (val2 == 0) {
                        printf("Division by zero error...\n");
                        return -1;
                    }
                    res = val1 / val2;
                    break;
                case '^':
                    res = (int)pow(val1, val2);
                    break;
                default:
                    printf("Invalid operator: %c\n", ch);
                    return -1;
            }
            push(res);
        }
    }

    int result = pop();
    if (top != -1) {
        printf("Warning: Extra operands in expression...\n");
    }
    return result;
}

int main() {
    char exp[MAX];
    printf("Enter a postfix expression: ");
    fgets(exp, MAX, stdin);
    exp[strcspn(exp, "\n")] = '\0'; 
    int result = evalpostfix(exp);
    if (result != -1) {
        printf("Result of postfix expression: %d\n", result);
    } 
    return 0;
}
