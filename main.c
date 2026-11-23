#include "padlock.h"
#include <stdio.h>
#include <stdlib.h>

int main() {

	const unsigned int password = 15976339;

	struct dataPadlock dLock;

	int* ptrEntryNumbers = (int *)calloc(4, sizeof(int));
	int* ptrStoredNumbers = (int*)calloc(4, sizeof(int));
	_Bool validEntrys;

	extractDataPadlockFromPassword(password, &dLock);

	if (!isDataPadlockSortRepeated(&dLock)) {

		puts("Existem números repetidos na ordem!");
		return 1;

	}

	do {
		
		validEntrys = 1;
	
		puts("Digite os quatro números da senha, separados por espaço (Ex: 1 1 1 1)");
		scanf("%d %d %d %d", ptrEntryNumbers + 0, ptrEntryNumbers + 1, ptrEntryNumbers + 2, ptrEntryNumbers + 3);

		for (int i = 0; i < 4; ++i) {
			if (*(ptrEntryNumbers + i) < 0) {
				puts("Números não podem ser negativos!");
				validEntrys = 0;
				break;
			}
		}

	} while (!validEntrys);

	getStoredNumbersFromDataPadlock(&dLock, ptrStoredNumbers);

	openPadlock(&dLock, ptrStoredNumbers, ptrEntryNumbers);

	printf("Cadeado %s\n", (dLock.opened) ? "Aberto" : "Fechado");

	free(ptrStoredNumbers);
	free(ptrEntryNumbers);

	return 0;
}
