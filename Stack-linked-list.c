#include <stdio.h>
#include <stdlib.h>

// Define a structure for the nodes of the linked list
struct node {
  int data;
  struct node *next;
};

// Function to push a new node onto the stack
void push(struct node** head_ref, int new_data) {
  struct node* new_node = (struct node*) malloc(sizeof(struct node));
  new_node->data = new_data;
  new_node->next = (*head_ref);
  (*head_ref) = new_node;
}

// Function to pop a node off the stack
int pop(struct node** head_ref) {
  int retval = -1;
  struct node* top;
  if (*head_ref == NULL) {
    return retval;
  }
  top = *head_ref;
  retval = top->data;
  *head_ref = top->next;
  free(top);
  return retval;
}

// Function to print the stack
void printStack(struct node *node) {
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
  printf("Stack Linked List: ");
  printStack(head);
  printf("\nPopped item: %d\n", pop(&head));
   printf("\nPopped item: %d\n", pop(&head));
    printf("\nPopped item: %d\n", pop(&head));
  printf("Stack after pop: ");
  printStack(head);
  return 0;
}
