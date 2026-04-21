#include "../simulation/loan.h"

typedef struct Node {
  Loan value;
} Node;

typedef struct PQueue {
  Node *elements;
  int size;
  int length;
} PQueue;

PQueue *create_pq();
void increase_size_pq(PQueue *p);
int is_empty_pq(PQueue *p);
void insert_node_pq(PQueue *p, Node n);
void remove_pq(PQueue *p);
void insert_pq(PQueue *p, Loan value);
void print_pq(PQueue *p);
PQueue *join_pq(PQueue *p1, PQueue *p2);
void delete_pq(PQueue *p);

Loan* peek_pq(PQueue *p);
int count_pq(PQueue *p);