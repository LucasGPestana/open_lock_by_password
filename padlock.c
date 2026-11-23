#include "padlock.h"
#include <stdio.h>


void extractDataPadlockFromPassword(const unsigned int password, struct dataPadlock* dLock) {
	
	// União que associa a senha as campos de bits que representam os dados do cadeado
	// Como os membros compartilham a mesma área de memória, cada campo recebe os bits da senha em binário correspondente ao tamanho que ela ocupa
	union {
		unsigned int password;
		struct dataPadlock dLockDecoded;
	} passwordDecoder;

	passwordDecoder.password = password;
 	
	// Campos de bits de ordem ocupam dois bits
	dLock->firstNumberSort = passwordDecoder.dLockDecoded.firstNumberSort;
	dLock->secondNumberSort = passwordDecoder.dLockDecoded.secondNumberSort;
	dLock->thirdNumberSort = passwordDecoder.dLockDecoded.thirdNumberSort;
	dLock->forthNumberSort = passwordDecoder.dLockDecoded.forthNumberSort;

	// Campos de bits de número ocupam quatro bits
	dLock->firstNumber = passwordDecoder.dLockDecoded.firstNumber;
	dLock->secondNumber = passwordDecoder.dLockDecoded.secondNumber;
	dLock->thirdNumber = passwordDecoder.dLockDecoded.thirdNumber;
	dLock->forthNumber = passwordDecoder.dLockDecoded.forthNumber;

	// Campo de bit de estado do cadeado ocupa um bit
	dLock->opened = 0;

}

_Bool isDataPadlockSortRepeated(struct dataPadlock* dLock) {

	// Vetor com a contagem de cada valor (indíce do vetor) que pode ser representado por dois bits (0 a 3)
	unsigned short counts[4] = {0, 0, 0, 0};

	counts[dLock->firstNumberSort] += 1;
	counts[dLock->secondNumberSort] += 1;
	counts[dLock->thirdNumberSort] += 1;
	counts[dLock->forthNumberSort] += 1;

	for (int i = 0; i < 4; ++i) {
	
		if (counts[i] > 1)
			return 0;

	}

	return 1;

}

void getStoredNumbersFromDataPadlock(struct dataPadlock* dLock, int* ptrStoredNumbers) {

	*(ptrStoredNumbers + dLock->firstNumberSort) = dLock->firstNumber;
	*(ptrStoredNumbers + dLock->secondNumberSort) = dLock->secondNumber;
	*(ptrStoredNumbers + dLock->thirdNumberSort) = dLock->thirdNumber;
	*(ptrStoredNumbers + dLock->forthNumberSort) = dLock->forthNumber;

}

void openPadlock(struct dataPadlock* dLock, int* ptrStoredNumbers, int* ptrEntryNumbers) {

	_Bool opened = 1;

	if (dLock->opened) {

		puts("O cadeado já está destrancado!");

	} else {

		for (int i = 0; i < 4; ++i) {

			if (*(ptrStoredNumbers + i) != *(ptrEntryNumbers + i)) {
				
				opened = 0;
				break;

			}
		}

		dLock->opened = opened;

	}
}
