struct node {
  int i;
  struct node *next;
};
void print_list(struct node * x);
struct node * insert_front(struct node * new, int i);
struct node * free_list(struct node * current);
struct node * node_remove(struct node *front, int data);
