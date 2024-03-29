#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

int main(){
  struct node * list = (struct node*)malloc(sizeof(struct node));
  list = NULL;
  printf("Testing empty lists\n");
  print_list(list);

  printf("Populating list with # from 0 - 9\n");
  int i = 0;
  for(;i <10;i++){
    list = insert_front(list, i);
  }

  printf("Printing List\n");
  print_list(list);

  printf("Removing 9:\n");
  list = node_remove(list,9);
  print_list(list);
  printf("Removing 4:\n");
  list = node_remove(list,4);
  print_list(list);
  printf("Removing 0:\n");
  list = node_remove(list,0);
  print_list(list);
  printf("Removing -1:\n");
  list = node_remove(list, -1);
  print_list(list);

  printf("Freeing List\n");
  list = free_list(list);
  print_list(list);

}
