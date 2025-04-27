#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node *prev;
  struct Node *next;
};

struct Node *head = NULL;

int isEmpty() { return head == NULL; }

void insertFront(int value) {
  struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
  newNode->data = value;
  newNode->prev = NULL;
  newNode->next = head;
  if (head != NULL) {
    head->prev = newNode;
  }
  head = newNode;
}

void insertRear(int value) {
  struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
  newNode->data = value;
  newNode->next = NULL;
  if (isEmpty()) {
    newNode->prev = NULL;
    head = newNode;
    return;
  }
  struct Node *temp = head;
  while (temp->next != NULL) {
    temp = temp->next;
  }
  temp->next = newNode;
  newNode->prev = temp;
}

int deleteFront() {
  struct Node *temp = head;
  int value = temp->data;
  head = head->next;
  if (head != NULL) {
    head->prev = NULL;
  }
  free(temp);
  return value;
}

int deleteRear() {
  struct Node *temp = head;
  while (temp->next != NULL) {
    temp = temp->next;
  }
  int value = temp->data;
  if (temp->prev != NULL) {
    temp->prev->next = NULL;
  } else {
    head = NULL;
  }
  free(temp);
  return value;
}

void display() {
  if (isEmpty()) {
    printf("List is empty\n");
    return;
  }
  struct Node *temp = head;
  printf("List elements: ");
  while (temp != NULL) {
    printf("%d", temp->data);
    temp = temp->next;
    if (temp != NULL) {
      printf("<-->");
    }
  }
  printf("\n");
}

int main() {
  int choice, value;
  do {
    printf("1.Insert Front 2.Insert Rear 3.Delete Front 4.Delete Rear 5.is "
           "List empty 6.display 7.Exit\n");
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
        printf("List is empty\n");
      } else {
        printf("Deleted value: %d\n", deleteFront());
      }
      break;
    case 4:
      if (isEmpty()) {
        printf("List is empty\n");
      } else {
        printf("Deleted value: %d\n", deleteRear());
      }
      break;
    case 5:
      printf(isEmpty() ? "List is empty\n" : "List is not empty\n");
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
