#include <stdio.h>
#include <stdlib.h>

// Define a structure for the nodes of the linked list
struct node {
  int data;
  struct node *next;
};

// Function to insert a node at the end of the linked list
void insertAtEnd(struct node** head_ref, int new_data) {
  struct node* new_node = (struct node*) malloc(sizeof(struct node));
  struct node *last = *head_ref;
  new_node->data = new_data;
  new_node->next = *head_ref;
  if (*head_ref != NULL) {
    while (last->next != *head_ref)
      last = last->next;
    last->next = new_node;
  } else
    new_node->next = new_node;
  *head_ref = new_node;
}

// Function to print the linked list
void printList(struct node *node) {
  struct node *last = node;
  printf("%d\n", node->data);
  node = node->next;
  while (node != last) {
    printf("%d\n", node->data);
    node = node->next;
  }
}

int main() {
  struct node *head = NULL;
  insertAtEnd(&head, 1);
  insertAtEnd(&head, 2);
  insertAtEnd(&head, 3);
  insertAtEnd(&head, 4);
  printf("Circular Linked List: \n");
  printList(head);
  return 0;
}
