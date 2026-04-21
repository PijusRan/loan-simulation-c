#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "loan.h"
#include "../queue-types/queue.h"
#include "../queue-types/priority_queue.h"

void pay(double* from, double* to){
    if(*to > 0){
        *to -= *from;
        *from = 0;
        
        if(*to < 0){
            *from -= *to;
            *to = 0;
        }
    }
}

void payLoan(double *payback, Loan* loan){
        // Pirma delspinigiai
        pay(payback, &(loan->sum));
        if(*payback == 0) return;

        // Po to palūkanos
        pay(payback, &(loan->interest));
        if(*payback == 0) return;

        // Po to suma
        pay(payback, &(loan->lateFees));
        if(*payback == 0) return;
}

double simulateQueue(queue* loanQueue, unsigned int randomSeed) {
    srand(randomSeed != -1 ? randomSeed : time(0));
    
    double totalPaid = 0.0;
    int currentMonth = 0;
    
    // Mėnesiai - sukas kol nebėr skolų
    while (!isEmptyQueue(loanQueue)) {
        currentMonth++;
        
        // 1. Sugeneruojama apmokėjimo suma 
        // Generuojame atsitiktinę sumą, pavyzdžiui, nuo 50 iki 549 (galima keisti ribas)
        double monthlyPayment = (double)((rand() % 500) + 200);
        totalPaid += monthlyPayment;
        
        double remainingPayment = monthlyPayment;
        
        // 2. Sumokama visa suma (dengiamos seniausios skolos)
        while (remainingPayment > 0) {
            Loan* oldestLoan = PeekQueue(loanQueue);
            payLoan(&remainingPayment, oldestLoan);
            if(oldestLoan->sum + oldestLoan->interest + oldestLoan->lateFees == 0){
                dequeue(loanQueue);
            }
            if(isEmptyQueue(loanQueue)){
                break;
            }
        }
        
        // 3. Apskaičiuojama visų kitų paskolų delspinigiai ir palūkanos
        int elementsCount = CountQueue(loanQueue);
        
        // Pereiname per visą eilę (rotuojame) jos nesugadindami
        for (int i = 0; i < elementsCount; i++) {
            // Paimame elementą iš priekio ir jį ištriname (dequeue)
            Loan* currentLoan = &(loanQueue->items[i]);
            currentLoan->interest += currentLoan->sum * (currentLoan->interestRate * 30/360);
            
            // Jei veluoja delspinigiai
            if(currentLoan->time < currentMonth){
                currentLoan->lateFees += currentLoan->sum * currentLoan->lateFeeRate;
            }
        }
    }
    
    // Grąžiname iš viso sumokėtų pinigų kiekį
    return totalPaid;
}

double simulatePQueue(PQueue* loanQueue, unsigned int randomSeed){
    srand(randomSeed != -1 ? randomSeed : time(0));
    
    double totalPaid = 0.0;
    int currentMonth = 0;
    
    // Mėnesiai - sukas kol nebėr skolų
    while (!is_empty_pq(loanQueue)) {
        currentMonth++;
        
        // 1. Sugeneruojama apmokėjimo suma 
        // Generuojame atsitiktinę sumą, pavyzdžiui, nuo 50 iki 549 (galima keisti ribas)
        double monthlyPayment = (double)((rand() % 500) + 200);
        totalPaid += monthlyPayment;
        
        double remainingPayment = monthlyPayment;
        
        // 2. Sumokama visa suma (dengiamos seniausios skolos)
        while (remainingPayment > 0) {
            Loan* oldestLoan = peek_pq(loanQueue);
            payLoan(&remainingPayment, oldestLoan);
            if(oldestLoan->sum + oldestLoan->interest + oldestLoan->lateFees == 0){
                remove_pq(loanQueue);
            }
            if(is_empty_pq(loanQueue)){
                break;
            }
        }
        
        // 3. Apskaičiuojama visų kitų paskolų delspinigiai ir palūkanos
        int elementsCount = count_pq(loanQueue);
        
        // Pereiname per visą eilę (rotuojame) jos nesugadindami
        for (int i = 0; i < elementsCount; i++) {
            // Paimame elementą iš priekio ir jį ištriname (dequeue)
            Loan* currentLoan = &(loanQueue->elements[i].value);
            currentLoan->interest += currentLoan->sum * (currentLoan->interestRate * 30/360);
            
            // Jei veluoja delspinigiai
            if(currentLoan->time < currentMonth){
                currentLoan->lateFees += currentLoan->sum * currentLoan->lateFeeRate;
            }
        }
    }
    
    // Grąžiname iš viso sumokėtų pinigų kiekį
    return totalPaid;
}