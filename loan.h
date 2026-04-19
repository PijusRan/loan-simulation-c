#ifndef LOAN_H
#define LOAN_H

typedef struct {
    double sum;
    double interest;
    double lateFees;
    int time;
    double interestRate;
    double lateFeeRate;
} Loan;

#endif