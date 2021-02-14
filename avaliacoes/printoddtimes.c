// SPDX-License-Identifier: GLP-3.0
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char  *argv[])
{
	int qtd = argc - 1;
	int arr1[qtd];
	int arr2[qtd + 1];

	for (int x = 0; x < qtd; x++)
		arr2[x] = 0;

	for (int x = 0; x < qtd; x++)
		arr1[x] = atoi(argv[x + 1]);

	for (int x = 0; x < qtd; x++) {
		int n = arr1[x];

		arr2[n] += 1;
	}

	for (int x = qtd; x >= 0; x--) {
		int n = arr2[x];

		if (n % 2 == 1)
			printf("%d ", x);
	}
	printf("\n");
	return 0;
}