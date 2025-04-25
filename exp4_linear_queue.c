#include <stdio.h>
#define MAX_SIZE 5

int queue[MAX_SIZE];
int front = 0;
int rear = -1;

int isFull() { return rear == MAX_SIZE - 1; }

int isEmpty() { return front > rear || rear == -1; }

void enqueue(int value) {
  if (isFull()) {
    printf("Queue is full\n");
    return;
  }
  queue[++rear] = value;
}

int dequeue() { return queue[front++]; }

int getFront() { return queue[front]; }

int getRear() { return queue[rear]; }

void display() {
  if (isEmpty()) {
    printf("Queue is empty\n");
    return;
  }
  for (int i = front; i <= rear; i++)
    printf("%d\n", queue[i]);
}

int main() {
  int choice, value;
  do {
    printf("1.Enqueue 2.Dequeue 3.Qfront 4.Qrear 5.is Queue full 6.is Queue "
           "empty 7.display 8.Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    switch (choice) {
    case 1:
      printf("Enter the value to Enqueue into the Queue\n");
      scanf("%d", &value);
      enqueue(value);
      break;
    case 2:
      if (isEmpty())
        printf("Queue is empty\n");
      else
        printf("Dequeue val is = %d\n", dequeue());
      break;
    case 3:
      if (isEmpty())
        printf("Queue is empty\n");
      else
        printf("Front val of the Queue is = %d\n", getFront());
      break;
    case 4:
      if (isEmpty())
        printf("Queue is empty\n");
      else
        printf("Rear val of the Queue is = %d\n", getRear());
      break;
    case 5:
      printf(isFull() ? "Queue is full\n" : "Queue is not full\n");
      break;
    case 6:
      printf(isEmpty() ? "Queue is empty\n" : "Queue is not empty\n");
      break;
    case 7:
      display();
      break;
    case 8:
      printf("Thank you for using my program\n");
      break;
    }
  } while (choice != 8);
  return 0;
}
