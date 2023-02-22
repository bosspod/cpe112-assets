#include <stdio.h>
#include <stdlib.h>

// Define a structure for the nodes of the linked list
struct node {
  int data;
  struct node *next;
  struct node *prev;
};

// Function to insert a node at the beginning of the linked list
void insertAtBeginning(struct node** head_ref, int new_data) {
  struct node* new_node = (struct node*) malloc(sizeof(struct node));
  new_node->data = new_data;
  new_node->next = (*head_ref);
  new_node->prev = NULL;
  if ((*head_ref) != NULL)
    (*head_ref)->prev = new_node;
  (*head_ref) = new_node;
}
//Reverse linked list

void reverse(struct node** head_ref)
{
    struct node* prev = NULL;
    struct node* current = *head_ref;
    struct node* next = NULL;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head_ref = prev;
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
  insertAtBeginning(&head, 1);
  insertAtBeginning(&head, 2);
  insertAtBeginning(&head, 3);
  insertAtBeginning(&head, 4);
  printf("Created Doubly Linked List: ");
  printList(head);
  reverse(&head);
  printList(head);
  return 0;
}
