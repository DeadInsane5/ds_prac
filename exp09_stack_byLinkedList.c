#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node *next;
};

struct Node *top = NULL;

int isEmpty() { return top == NULL; }

void push(int value) {
  struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
  newNode->data = value;
  newNode->next = top;
  top = newNode;
}

int pop() {
  struct Node *temp = top;
  int value = temp->data;
  top = top->next;
  free(temp);
  return value;
}

int peek() { return top->data; }

void display() {
  if (isEmpty()) {
    printf("Stack is empty\n");
    return;
  }
  struct Node *temp = top;
  while (temp != NULL) {
    printf("%d", temp->data);
    temp = temp->next;
    if (temp != NULL) {
      printf("--->");
    }
  }
  printf("--->NULL\n");
}

int main() {
  int choice, value;
  do {
    printf("1.Push 2.Pop 3.display 4.Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    switch (choice) {
    case 1:
      printf("Enter the value to push into Stack: ");
      scanf("%d", &value);
      push(value);
      break;
    case 2:
      if (isEmpty())
        printf("Stack is empty\n");
      else
        printf("Popped value is = %d\n", pop());
      break;
    case 3:
      display();
      break;
    case 4:
      printf("Thank you for using my program\n");
      break;
    }
  } while (choice != 4);
  return 0;
}
