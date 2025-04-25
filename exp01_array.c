#include <stdio.h>

void insertElement(int array[], int *size, int element, int position) {
  if (*size >= 100 || position < 1 || position > *size + 1)
    return;
  for (int i = *size; i >= position; i--)
    array[i] = array[i - 1];
  array[position - 1] = element;
  (*size)++;
}

void deleteElement(int array[], int *size, int position) {
  if (*size == 0 || position < 1 || position > *size)
    return;
  for (int i = position - 1; i < *size - 1; i++)
    array[i] = array[i + 1];
  (*size)--;
}

void displayArray(int array[], int size) {
  printf("Array: ");
  for (int i = 0; i < size; i++)
    printf("%d ", array[i]);
  printf(size ? "\n" : "Array is empty.\n");
}

int main() {
  int array[100], size = 0, choice, element, position;
  while (1) {
    printf("\n1.Insert 2.Delete 3.Display 4.Exit\nChoose: ");
    scanf("%d", &choice);
    if (choice == 4)
      break;
    if (choice == 1) {
      printf("Value: ");
      scanf("%d", &element);
      printf("Position: ");
      scanf("%d", &position);
      insertElement(array, &size, element, position);
    } else if (choice == 2) {
      printf("Position: ");
      scanf("%d", &position);
      deleteElement(array, &size, position);
    } else if (choice == 3) {
      displayArray(array, size);
    }
  }
  return 0;
}
