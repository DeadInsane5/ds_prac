#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node *next;
};

struct Node *head = NULL;

int isEmpty() { return head == NULL; }

void insertFront(int value) {
  struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
  newNode->data = value;
  newNode->next = head;
  head = newNode;
}

void insertEnd(int value) {
  struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
  newNode->data = value;
  newNode->next = NULL;
  if (isEmpty()) {
    head = newNode;
  } else {
    struct Node *temp = head;
    while (temp->next != NULL) {
      temp = temp->next;
    }
    temp->next = newNode;
  }
}

int deleteFront() {
  struct Node *temp = head;
  int value = temp->data;
  head = head->next;
  free(temp);
  return value;
}

int deleteEnd() {
  if (head->next == NULL) {
    int value = head->data;
    free(head);
    head = NULL;
    return value;
  }
  struct Node *temp = head;
  struct Node *prev = NULL;
  while (temp->next != NULL) {
    prev = temp;
    temp = temp->next;
  }
  int value = temp->data;
  prev->next = NULL;
  free(temp);
  return value;
}

void display() {
  if (isEmpty()) {
    printf("List is empty\n");
    return;
  }
  struct Node *temp = head;
  while (temp != NULL) {
    printf("%d\n", temp->data);
    temp = temp->next;
  }
}

int main() {
  int choice, value;
  do {
    printf("1.Insert at front 2.Insert at end 3.Delete from front 4.Delete "
           "from end 5.is List empty 6.display 7.Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    switch (choice) {
    case 1:
      printf("Enter the value to insert at front: ");
      scanf("%d", &value);
      insertFront(value);
      break;
    case 2:
      printf("Enter the value to insert at end: ");
      scanf("%d", &value);
      insertEnd(value);
      break;
    case 3:
      if (isEmpty())
        printf("List is empty\n");
      else
        printf("Deleted value from front is = %d\n", deleteFront());
      break;
    case 4:
      if (isEmpty())
        printf("List is empty\n");
      else
        printf("Deleted value from end is = %d\n", deleteEnd());
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
