#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct node { int i; struct node *next; };

void print_list(struct node * linkedlist){
  printf("data of linkedlist: [");
  while(linkedlist){
    printf("%d," , linkedlist->i);
    linkedlist = linkedlist -> next;
  }
  printf("]");
}

struct node * insert_front(struct node * linkedlist , int data){
  struct node *new = (struct node *)malloc(sizeof(struct node));
  new->i = data;
  new->next = linkedlist;
  return new;
}

struct node * free_list(struct node* linkedlist){
  struct node *first = linkedlist;
  struct node *temp;
  while(linkedlist){
    temp= linkedlist->next;
    free(linkedlist);
    linkedlist = temp;
  }
  return first;
}

void main(){
  struct node *first = (struct node *)malloc(sizeof(struct node));
  struct node *second = (struct node *)malloc(sizeof(struct node));
  struct node *third = (struct node *)malloc(sizeof(struct node));

  first -> i = 1;
  first -> next = second;
  second -> i = 2;
  second -> next = third;
  third -> i = 3;
  print_list(first);
  printf("adding 0\n");
  first = insert_front(first , 0);
  print_list(first);
  printf("Free tyler1\n");
  free_list(first);


}


