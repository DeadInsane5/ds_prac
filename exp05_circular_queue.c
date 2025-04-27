#include <stdio.h>
#define MAX 5

int queue[MAX];
int front = -1, rear = -1;

int isFull() { return (front == 0 && rear == MAX - 1) || (front == rear + 1); }

int isEmpty() { return front == -1; }

void enqueue(int value) {
  if (isFull()) {
    printf("Queue is full\n");
    return;
  }
  if (isEmpty()) {
    front = 0;
  }
  rear = (rear + 1) % MAX;
  queue[rear] = value;
}

int dequeue() {
  int value = queue[front];
  if (front == rear) {
    front = -1;
    rear = -1;
  } else {
    front = (front + 1) % MAX;
  }
  return value;
}

void display() {
  if (isEmpty()) {
    printf("Queue is empty\n");
    return;
  }
  printf("Queue elements: ");
  if (rear >= front) {
    for (int i = front; i <= rear; i++) {
      printf("%d", queue[i]);
      if (i < rear)
        printf(" ");
    }
  } else {
    for (int i = front; i < MAX; i++) {
      printf("%d", queue[i]);
      if (i < MAX - 1 || rear > 0)
        printf("->");
    }
    for (int i = 0; i <= rear; i++) {
      printf("%d", queue[i]);
      if (i < rear)
        printf(" ");
    }
  }
  printf("\n");
}

int main() {
  int choice, value;
  do {
    printf("1.Enqueue 2.Dequeue 3.is Queue full 4.is Queue empty 5.display "
           "6.Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    switch (choice) {
    case 1:
      printf("Enter the value to enqueue: ");
      scanf("%d", &value);
      enqueue(value);
      break;
    case 2:
      if (isEmpty())
        printf("Queue is empty\n");
      else
        printf("Dequeued value: %d\n", dequeue());
      break;
    case 3:
      printf(isFull() ? "Queue is full\n" : "Queue is not full\n");
      break;
    case 4:
      printf(isEmpty() ? "Queue is empty\n" : "Queue is not empty\n");
      break;
    case 5:
      display();
      break;
    case 6:
      printf("Thank you for using my program\n");
      break;
    }
  } while (choice != 6);
  return 0;
}
