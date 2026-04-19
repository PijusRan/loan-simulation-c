#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "loan.h"

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

Loan* peek_pq(PQueue *p){
  return &(p->elements[0].value);
}

// If a is more important than b
int moreImportant(Loan* a, Loan* b){
  if(a->sum > b->sum)
    return 1;
  else if(a->sum < b->sum)
    return 0;
  
  if(a->interest > b->interest)
    return 1;
  else if(a->interest < b->interest)
    return 0;

  if(a->lateFees > b->lateFees)
    return 1;
  else if(a->lateFees < b->lateFees)
    return 0;
  
  return 0;
}

PQueue *create_pq() {
  PQueue *p = (PQueue *)malloc(sizeof(PQueue));
  p->size = 2;
  p->length = 0;
  p->elements = (Node *)malloc(p->size * sizeof(Node));
  return p;
}

int count_pq(PQueue *p){
  return p->length;
}

void increase_size_pq(PQueue *p) {
  p->size *= 2;
  p->elements = realloc(p->elements, p->size * sizeof(Node));
}

int is_empty_pq(PQueue *p) { return p->length == 0; }

void insert_pq(PQueue *p, Loan value) {
  if (p->length >= p->size)
    increase_size_pq(p);
  Node n = {.value = value};
  insert_node_pq(p, n);
}

void insert_node_pq(PQueue *p, Node n) {
  int idx = 0;
  while (moreImportant(&(p->elements[idx].value), &(n.value)) && idx < p->length) {
    idx++;
  }
  p->length++;
  for (int i = p->length - 1; i > idx; i--) {
    p->elements[i] = p->elements[i - 1];
  }
  p->elements[idx] = n;
}

void remove_pq(PQueue *p) {
  if (p->length <= 0) return;
  Loan* value = &(p->elements[p->length - 1].value);
  p->length--;
}

// !!!
void print_pq(PQueue *p) {
  for (int i = 0; i < p->length; i++) {
    printf("%d ", p->elements[i].value);
  }
  printf("\n");
}

PQueue *join_pq(PQueue *p1, PQueue *p2) {
  while (!is_empty_pq(p2)) {
    insert_pq(p1, p2->elements[p2->length - 1].value);
    remove_pq(p2);
  }
  return p1;
}

void delete_pq(PQueue *p) {
  free(p->elements);
  free(p);
  p = NULL;
}
