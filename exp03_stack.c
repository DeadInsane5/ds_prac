#include <stdio.h>
#define MAX_SIZE 5

int stack[MAX_SIZE];
int top = 0;

int isFull() { return top == MAX_SIZE - 1; }

int isEmpty() { return top == 0; }

void push(int value) {
  if (isFull()) {
    printf("Stack is full\n");
    return;
  }
  stack[++top] = value;
}

int pop() { return stack[top--]; }

int peek() { return stack[top]; }

void display() {
  if (isEmpty()) {
    printf("Stack is empty\n");
    return;
  }
  for (int i = top; i >= 1; i--)
    printf("%d\n", stack[i]);
}

int main() {
  int choice, value;
  do {
    printf("1.push 2.pop 3.Stacktop 4.is Stack full 5.is Stack empty 6.display "
           "7. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    switch (choice) {
    case 1:
      printf("Enter the value to be pushed into the Stack: ");
      scanf("%d", &value);
      push(value);
      break;
    case 2:
      if (isEmpty())
        printf("Stack is empty\n");
      else
        printf("Pop val is = %d\n", pop());
      break;
    case 3:
      if (isEmpty())
        printf("Stack is empty\n");
      else
        printf("Top of stack val is = %d\n", peek());
      break;
    case 4:
      printf(isFull() ? "Stack is full\n" : "Stack is not full\n");
      break;
    case 5:
      printf(isEmpty() ? "Stack is empty\n" : "Stack is not empty\n");
      break;
    case 6:
      display();
      break;
    case 7:
      printf("Thank you for using my program\n");
      break;
    }
  } while (choice != 7);
  return 0;
}
