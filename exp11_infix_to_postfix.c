#include <stdio.h>
#include <string.h>
#define MAX 20

char stack[MAX];
int top = -1;

int isFull() { return top == MAX - 1; }

int isEmpty() { return top == -1; }

void push(char value) { stack[++top] = value; }

char pop() { return stack[top--]; }

int precedence(char op) {
  if (op == '+' || op == '-')
    return 1;
  if (op == '*' || op == '/')
    return 2;
  return 0;
}

void infixToPostfix(char infix[], char postfix[]) {
  int i = 0, j = 0;
  char ch;
  while (infix[i] != '\0') {
    ch = infix[i++];
    if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z')) {
      postfix[j++] = ch;
    } else if (ch == '(') {
      push(ch);
    } else if (ch == ')') {
      while (top != -1 && stack[top] != '(') {
        postfix[j++] = pop();
      }
      if (top != -1)
        pop(); // Discard '('
    } else {
      while (top != -1 && precedence(stack[top]) >= precedence(ch)) {
        postfix[j++] = pop();
      }
      push(ch);
    }
  }
  while (top != -1) {
    postfix[j++] = pop();
  }
  postfix[j] = '\0';
}

int main() {
  char infix[MAX], postfix[MAX];
  int choice;
  do {
    printf("1.Infix to Postfix 2.Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    switch (choice) {
    case 1:
      printf("Enter the Infix expression: ");
      scanf("%s", infix);
      infixToPostfix(infix, postfix);
      printf("Postfix expression: %s\n", postfix);
      break;
    case 2:
      printf("Thank you for using my program\n");
      break;
    }
  } while (choice != 2);
  return 0;
}
