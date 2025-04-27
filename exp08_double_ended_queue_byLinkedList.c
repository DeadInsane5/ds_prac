#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node *next;
};

struct Node *front = NULL;
struct Node *rear = NULL;

int isEmpty() { return front == NULL; }

void insertFront(int value) {
  struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
  newNode->data = value;
  newNode->next = front;
  if (isEmpty()) {
    rear = newNode;
  }
  front = newNode;
}

void insertRear(int value) {
  struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
  newNode->data = value;
  newNode->next = NULL;
  if (isEmpty()) {
    front = newNode;
    rear = newNode;
  } else {
    rear->next = newNode;
    rear = newNode;
  }
}

int deleteFront() {
  struct Node *temp = front;
  int value = temp->data;
  front = front->next;
  if (front == NULL) {
    rear = NULL;
  }
  free(temp);
  return value;
}

int deleteRear() {
  int value;
  if (front == rear) {
    value = front->data;
    free(front);
    front = NULL;
    rear = NULL;
    return value;
  }
  struct Node *temp = front;
  while (temp->next != rear) {
    temp = temp->next;
  }
  value = rear->data;
  free(rear);
  rear = temp;
  rear->next = NULL;
  return value;
}

void display() {
  if (isEmpty()) {
    printf("Queue is empty\n");
    return;
  }
  struct Node *temp = front;
  printf("Queue elements: ");
  while (temp != NULL) {
    printf("%d", temp->data);
    temp = temp->next;
    if (temp != NULL) {
      printf(" ");
    }
  }
  printf("\n");
}

int main() {
  int choice, value;
  do {
    printf("1.Insert Front 2.Insert Rear 3.Delete Front 4.Delete Rear 5.is "
           "Queue empty 6.display 7.Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    switch (choice) {
    case 1:
      printf("Enter the value to insert: ");
      scanf("%d", &value);
      insertFront(value);
      break;
    case 2:
      printf("Enter the value to insert: ");
      scanf("%d", &value);
      insertRear(value);
      break;
    case 3:
      if (isEmpty()) {
        printf("Queue is empty\n");
      } else {
        printf("Deleted value: %d\n", deleteFront());
      }
      break;
    case 4:
      if (isEmpty()) {
        printf("Queue is empty\n");
      } else {
        printf("Deleted value: %d\n", deleteRear());
      }
      break;
    case 5:
      printf(isEmpty() ? "Queue is empty\n" : "Queue is not empty\n");
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
