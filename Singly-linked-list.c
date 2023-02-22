#include <stdio.h>
#include <stdlib.h>

// Define a structure for the nodes of the linked list
struct node {
  int data;
  struct node *next;
};

// Function to insert a node at the beginning of the linked list
void push(struct node** head_ref, int new_data) {
  struct node* new_node = (struct node*) malloc(sizeof(struct node));
  new_node->data = new_data;
  new_node->next = (*head_ref);
  (*head_ref) = new_node;
}

// Function to print the linked list
void printList(struct node *node) {
  while (node != NULL) {
    printf(" %d ", node->data);
    node = node->next;
  }
}

int main() {
  struct node* head = NULL;
  push(&head, 1);
  push(&head, 2);
  push(&head, 3);
  push(&head, 4);
  printf("Created Linked List: ");
  printList(head);
  return 0;
}
