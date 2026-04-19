#ifndef QUEUE_INT
#define QUEUE_INT

#include "loan.h"

typedef struct { 
    Loan* items;
    unsigned int size, count;
} queue;

// Create: sukuria eilę
// Precondition: Nėra
// Postcondition: grąžinamas eilės adresas
queue* CreateQueue(unsigned int queueSize);

// Done: ištrina eilę
// Precondition: Q nėra nullptr
// Postcondition: Eilė yra ištrinta
void DoneQueue(queue* Q);

// Clone: nukopijuoja eilę
// Precondition: Q nėra nullptr
// Postcondition: grąžinamas ptr į naują eilę
queue* CloneQueue(queue* from);

// Count: grąžina elementų kiekį
// Precondition: Q nėra nullptr
// Postcondition: grąžinamas int
unsigned int CountQueue(queue* Q);

// isEmpty: grąžina ar eilė tuščia
// Precondition: Q nėra nullptr
// Postcondition: grąžina 1 arba 0
unsigned int isEmptyQueue(queue* Q);

// isFull: grąžina ar eilė pilna
// Precondition: Q nėra nullptr
// Postcondition: grąžina 1 arba 0
unsigned int isFullQueue(queue* Q);

// Peek: grąžina patį viršutinį elementą eilėje
// Precondition: Q nėra nullptr, Q turi mažiausiai 1 elementą
// Postcondition: grąžina pirmąjį elementą eilėje (int)
Loan* PeekQueue(queue* Q);

// toString: paverčia eilę į teksto eilutę ir grąžina
// Precondition: Q nėra nullptr
// Postcondition: grąžinamas char* eilutė
char* toStringQueue(queue* Q);

// enqueue: prideda item prie eilės
// Precondition: eilė Q nėra perpildyta
// Postcondition: elementas yra pridėtas į eilę ir count padidėja 1 arba klaida konsolėje
void enqueue(queue* Q, Loan item);

// dequeue: išima pirmutinį elementą iš eilės
// Precondition: Eilė nėra tuščia ir jos dydis nėra 0
// Postcondition: Elementas išimtas, eilė sumažėja 1
void dequeue(queue* Q);

// makeEmpty: išima visus elementus iš eilės
// Precondition: Nėra
// Postcondition: Visi elementai yra panaikinti, count = 0
void makeEmptyQueue(queue* Q);

#endif