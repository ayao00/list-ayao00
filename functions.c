#include <stdio.h>
#include <stdlib.h>

#include "functions.h"

void print_list(struct node * x){
  if(x == NULL){
    printf("Empty list: []\n");
  }else{
    printf("List:[");
    while(x->next != NULL){
      printf("%d, ", x->i);
      x = x->next;
    }
    printf("%d]\n", x->i);
  }
}

struct node * insert_front(struct node * new, int i){
  struct node * new_node = (struct node *)malloc(sizeof(struct node));
  new_node->i= i;
  new_node->next = new;
  return new_node;
}

struct node * free_list(struct node * current){
  struct node* next_node = (struct node *)malloc(sizeof(struct node));
  if(current->next != NULL){
    next_node = current->next;
    printf("Freeing node: %d\n", current->i);
    free(current);
    free_list(next_node);
  }else{
    printf("List freed\n");
  }
  return NULL;
}

struct node * node_remove(struct node *front, int data){
  if(front == NULL){
    printf("Empty list\n");
    return front;
  }else{
    if(front->i == data){
      return front->next;
    }else{
      struct node * previous = front;
      struct node * finder = front->next;
      while(finder != NULL){
        if(finder->i == data){
          previous->next = finder->next;
          free(finder);
          return front;
        }
        previous = finder;
        finder = finder->next;
      }
      return front;
    }
  }
}
