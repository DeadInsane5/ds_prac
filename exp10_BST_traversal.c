#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node *left;
  struct Node *right;
};

struct Node *root = NULL;

int isEmpty() { return root == NULL; }

void insert(int value) {
  struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
  newNode->data = value;
  newNode->left = NULL;
  newNode->right = NULL;
  if (isEmpty()) {
    root = newNode;
    return;
  }
  struct Node *temp = root;
  struct Node *parent = NULL;
  while (temp != NULL) {
    parent = temp;
    temp = value < temp->data ? temp->left : temp->right;
  }
  if (value < parent->data) {
    parent->left = newNode;
  } else {
    parent->right = newNode;
  }
}

struct Node *findMin(struct Node *node) {
  while (node->left != NULL) {
    node = node->left;
  }
  return node;
}

struct Node *deleteNode(struct Node *node, int value) {
  if (node == NULL) {
    return node;
  }
  if (value < node->data) {
    node->left = deleteNode(node->left, value);
  } else if (value > node->data) {
    node->right = deleteNode(node->right, value);
  } else {
    if (node->left == NULL) {
      struct Node *temp = node->right;
      free(node);
      return temp;
    }
    if (node->right == NULL) {
      struct Node *temp = node->left;
      free(node);
      return temp;
    }
    struct Node *temp = findMin(node->right);
    node->data = temp->data;
    node->right = deleteNode(node->right, temp->data);
  }
  return node;
}

void inorder(struct Node *node) {
  if (node != NULL) {
    inorder(node->left);
    printf("%d ", node->data);
    inorder(node->right);
  }
}

void preorder(struct Node *node) {
  if (node != NULL) {
    printf("%d ", node->data);
    preorder(node->left);
    preorder(node->right);
  }
}

void postorder(struct Node *node) {
  if (node != NULL) {
    postorder(node->left);
    postorder(node->right);
    printf("%d ", node->data);
  }
}

void displayInorder() {
  if (isEmpty()) {
    printf("Tree is empty\n");
    return;
  }
  printf("Inorder traversal: ");
  inorder(root);
  printf("\n");
}

void displayPreorder() {
  if (isEmpty()) {
    printf("Tree is empty\n");
    return;
  }
  printf("Preorder traversal: ");
  preorder(root);
  printf("\n");
}

void displayPostorder() {
  if (isEmpty()) {
    printf("Tree is empty\n");
    return;
  }
  printf("Postorder traversal: ");
  postorder(root);
  printf("\n");
}

int main() {
  int choice, value;
  do {
    printf("1.Insert 2.Delete 3.Inorder 4.Preorder 5.Postorder 6.Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    switch (choice) {
    case 1:
      printf("Enter the value to insert: ");
      scanf("%d", &value);
      insert(value);
      break;
    case 2:
      printf("Enter the value to delete: ");
      scanf("%d", &value);
      if (isEmpty()) {
        printf("Tree is empty\n");
      } else {
        root = deleteNode(root, value);
        printf("Value deleted\n");
      }
      break;
    case 3:
      displayInorder();
      break;
    case 4:
      displayPreorder();
      break;
    case 5:
      displayPostorder();
      break;
    case 6:
      printf("Thank you for using my program\n");
      break;
    }
  } while (choice != 6);
  return 0;
}
