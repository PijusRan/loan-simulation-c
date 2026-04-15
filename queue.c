#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "loan.h"

typedef struct { 
    Loan* items;
    unsigned int size, count;
} queue;

queue* CreateQueue(unsigned int queueSize){
    queue* ret = malloc(sizeof(queue));
    ret->items = malloc(queueSize * sizeof(Loan));
    ret->size = queueSize;
    ret->count = 0;

    return ret;
}
void DoneQueue(queue* Q){
    free(Q);
}

queue* CloneQueue(queue* from){
    queue* new = malloc(sizeof(queue));

    for(int i = 0; i < from->size; i++){
        new->items[i] = from->items[i];
    }
    new->size = from->size;
    new->count = from->count;

    return new;
}

unsigned int CountQueue(queue* Q){
    return Q->count;
}

unsigned int isEmptyQueue(queue* Q){
    return (Q->count == 0) ? 1 : 0;
}

unsigned int isFullQueue(queue* Q){
    return (Q->count == (*Q).size) ? 1 : 0;
}

Loan peekQueue(queue* Q){
    return Q->items[0];
}

char* toStringQueue(queue* Q) {
    size_t bufferSize = Q->count * 200 + 1;
    char* result = (char*)malloc(bufferSize);

    result[0] = '\0';
    char temp[132];

    for (int i = 0; i < Q->count; i++) {
        snprintf(temp, sizeof(temp),
                 "Skola:\n"
                 "    Paskola: %.2f\n"
                 "    Laikotarpis: %d\n"
                 "    Palūkanos: %.2f\n"
                 "    Delspinigiai: %.2f\n",
                 Q->items[i].sum, 
                 Q->items[i].time, 
                 Q->items[i].interest, 
                 Q->items[i].lateFees);
        strcat(result, temp);
    }

    return result;
}

void enqueue(queue* Q, Loan item){
    if(isFull(Q)){
        printf("Klaida: eilė pilna.\n");
        return;
    }

    Q->items[Q->count] = item;
    Q->count++;
}

void dequeue(queue* Q){
    if(isEmpty(Q)){
        printf("Klaida: eilė jau tuščia.\n");
        return;
    }

    for(int i = 0; i < Q->count; i++){
        Q->items[i] = Q->items[i+1];
    }

    Q->count--;
}

void makeEmptyQueue(queue* Q){
    while(!isEmptyQueue(Q)){
        dequeue(Q);
    }
}