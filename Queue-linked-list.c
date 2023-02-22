#include <stdio.h>
#include <stdlib.h>

// Define a structure for the nodes of the linked list
struct node {
  int data;
  struct node *next;
};

// Function to enqueue a new node into the queue
void enqueue(struct node** head_ref, struct node** tail_ref, int new_data) {
  struct node* new_node = (struct node*) malloc(sizeof(struct node));
  new_node->data = new_data;
  new_node->next = NULL;
  if (*tail_ref != NULL)
    (*tail_ref)->next = new_node;
  *tail_ref = new_node;
  if (*head_ref == NULL)
    *head_ref = new_node;
}

// Function to dequeue a node from the queue
int dequeue(struct node** head_ref, struct node** tail_ref) {
  int retval = -1;
  struct node *temp;
  if (*head_ref == NULL)
    return retval;
  temp = *head_ref;
  retval = temp->data;
  *head_ref = temp->next;
  if (*head_ref == NULL)
    *tail_ref = NULL;
  free(temp);
  return retval;
}

// Function to print the queue
void printQueue(struct node *node) {
  while (node != NULL) {
    printf(" %d ", node->data);
    node = node->next;
  }
}

int main() {
  struct node *head = NULL;
  struct node *tail = NULL;
  enqueue(&head, &tail, 1);
  enqueue(&head, &tail, 2);
  enqueue(&head, &tail, 3);
  enqueue(&head, &tail, 4);
  printf("Queue Linked List: ");
  printQueue(head);
  printf("\nDequeued item: %d\n", dequeue(&head, &tail));
  printf("\nDequeued item: %d\n", dequeue(&head, &tail));
  printf("\nDequeued item: %d\n", dequeue(&head, &tail));
  printf("Queue after dequeue: ");
  printQueue(head);
  return 0;
}
