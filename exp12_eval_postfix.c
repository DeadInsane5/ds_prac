#include <stdio.h>
#define MAX 20

int stack[MAX];
int top = -1;

void push(int value) { stack[++top] = value; }

int pop() { return stack[top--]; }

int evaluatePostfix(char postfix[]) {
  int i = 0;
  char ch;
  while (postfix[i] != '\0') {
    ch = postfix[i++];
    if (ch >= '0' && ch <= '9') {
      push(ch - '0');
    } else {
      int op2 = pop();
      int op1 = pop();
      switch (ch) {
      case '+':
        push(op1 + op2);
        break;
      case '-':
        push(op1 - op2);
        break;
      case '*':
        push(op1 * op2);
        break;
      case '/':
        push(op1 / op2);
        break;
      }
    }
  }
  return pop();
}

int main() {
  char postfix[MAX];
  int choice;
  do {
    printf("1.Evaluate Postfix 2.Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    switch (choice) {
    case 1:
      printf("Enter the Postfix expression: ");
      scanf("%s", postfix);
      int result = evaluatePostfix(postfix);
      printf("Result: %d\n", result);
      break;
    case 2:
      printf("Thank you for using my program\n");
      break;
    }
  } while (choice != 2);
  return 0;
}
