#ifndef PADLOCK_H
#define PADLOCK_H

struct dataPadlock {
        unsigned int firstNumberSort : 2;
        unsigned int secondNumberSort : 2;
        unsigned int thirdNumberSort : 2;
        unsigned int forthNumberSort : 2;
        unsigned int firstNumber : 4; 
        unsigned int secondNumber : 4;
        unsigned int thirdNumber : 4;
        unsigned int forthNumber : 4;
        unsigned int opened : 1;
};

void extractDataPadlockFromPassword(const unsigned int password, struct dataPadlock* dLock);
_Bool isDataPadlockSortRepeated(struct dataPadlock* dLock);
void getStoredNumbersFromDataPadlock(struct dataPadlock* dLock, int* ptrStoredNumbers);
void openPadlock(struct dataPadlock* dLock, int* ptrStoredNumbers, int* ptrEntryNumbers);

#endif
