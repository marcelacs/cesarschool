// SPDX-License-Identifier: GPL-3.0
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100000

int main(void)
{

	char arr_1[MAX];
	char *N[MAX];
	int i = 0;
	int nn[MAX];

	fgets(arr_1, MAX, stdin);
	char *token;
	char *temp;
	int com;

	token = strtok(arr_1, " ");
	while (token != NULL) {
		N[i] = token;
		com = atoi(token);
		nn[i] = com;
		token = strtok(NULL, " ");
		i++;
	}

	printf("\n");


	char arr_2[MAX];
	char *M[MAX];
	int j = 0;
	int mm[MAX];

	fgets(arr_2, MAX, stdin);
	char *token2;
	char *temp2;

	token2 = strtok(arr_2, " ");
	while (token2 != NULL) {
		M[j] = token2;
		com = atoi(token2);
		mm[j] = com;
		token2 = strtok(NULL, " ");
		j++;
	}

	if (j > i) {
		printf("Fila de saida maior que a de entrada");
		return 0;
	}

	int cont = 0;

	for (int y = 0; y < j; y++) {
		for (int x = 0; x < i; x++) {
			if (mm[y] == nn[x])
				cont++;
		}
	}

	if (cont < j) {
		printf("Impossivel tirar pessoa inexistente da fila");
		return 0;
	}

	int arr_fin[MAX];
	int pass = 0;
	int z = 0;

	for (int x = 0; x < i; x++) {
		for (int y = 0; y < j; y++) {
			if (mm[y] == nn[x])
				pass = 1;
		}

		if (pass == 0) {
			arr_fin[z] = nn[x];
			z++;
		}
		pass = 0;
	}

	int tam = i - j;

	for (int x = 0; x < tam; x++)
		printf(" %d", arr_fin[x]);

	return 0;
}