// SPDX-License-Identifier: GPL-3.0
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
	int valor;
	struct node *prox;
};

int main(void)
{

	char entrada[12];
	int elem;
	struct node *top = NULL;

	while (strcmp(entrada, "Finalizar") != 0) {
		scanf("%s", entrada);

		if ((strcmp(entrada, "Empilhar") == 0)) {
			scanf("%d", &elem);
			struct node *new_node;

			new_node =  (struct node *)malloc(sizeof(struct node));
			new_node->valor = elem;
			new_node->prox = top;
			top = new_node;
		}

		else if ((strcmp(entrada, "Desempilhar") == 0)) {
			struct node *tmp;

			tmp = top;
			free(top);
			top = tmp->prox;

		} else if ((strcmp(entrada, "Imprimir") == 0)) {
			struct node *temp;

			if (top == 0) {
				printf("pilhar vazia");
			} else {
				temp = top;
				printf("\n%d", temp->valor);
				temp = temp->prox;
				while (temp != 0) {
					printf(" %d", temp->valor);
					temp = temp->prox;
				}
			}
		}
	}
	return 0;
}
