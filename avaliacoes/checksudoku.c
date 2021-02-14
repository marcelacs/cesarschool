// SPDX-License-Identifier: GLP-3.0
#include <stdio.h>
#include <stdlib.h>

int checklines(int arr1[10]);

int main(int argc, char  *argv[])
{
	int mat[9][9];
	FILE *fpt;

	fpt = fopen(argv[1], "r");

	if (!fpt) {
		printf("Error ao abrir arquivo");
		return 0;
	}
	char n;
	int na;

	do {
		for (int i = 0; i < 9; i++) {
			int x = 0;

			for (int j = 0; j < 18; j++) {
				n = fgetc(fpt);
				if (n == ',' || n == '\n' || n == EOF) {
				} else {
					na = n - '0';
					mat[i][x] = na;
					x++;
				}
			}
		}
	} while (n != EOF);

	fclose(fpt);
	int arr1[9];
	int sumln = 0;
	int pass;
	int sumpass = 0;

	// check Lines

	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++)
			arr1[j] = mat[i][j];

		pass = checklines(arr1);
		sumln += pass;
	}
	if (sumln != 9) {
		printf("False\n");
		return 0;
	}

	sumpass++;

	// check columns

	int sumcl = 0;

	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++)
			arr1[j] = mat[j][i];

		pass = checklines(arr1);
		sumcl += pass;
	}

	if (sumcl != 9) {
		printf("False\n");
		return 0;
	}

	sumpass++;

	//check square
	//012
	int p1[9];
	int p2[9];
	int p3[9];
	int p;
	int i1 = 0;
	int i2 = 0;
	int i3 = 0;
	int sumsq = 0;

	for (int i = 0; i <= 2; ++i) {
		for (int j = 0; j < 9; ++j) {
			p = mat[i][j];
			if (j < 3) {
				p1[i1] = p;
				i1++;
			}
			if (j > 2 && j < 6) {
				p2[i2] = p;
				i2++;
			}
			if (j > 5 && j < 9) {
				p3[i3] = p;
				i3++;
			}
		}
	}

	pass = checklines(p1);
	sumsq += pass;
	pass = checklines(p2);
	sumsq += pass;
	pass = checklines(p3);
	sumsq += pass;

	//345

	i1 = 0;
	i2 = 0;
	i3 = 0;

	for (int i = 3; i <= 5; ++i) {
		for (int j = 0; j < 9; ++j) {
			p = mat[i][j];
			if (j < 3) {
				p1[i1] = p;
				i1++;
			}
			if (j > 2 && j < 6) {
				p2[i2] = p;
				i2++;
			}
			if (j > 5 && j < 9) {
				p3[i3] = p;
				i3++;
			}
		}
	}

	pass = checklines(p1);
	sumsq += pass;
	pass = checklines(p2);
	sumsq += pass;
	pass = checklines(p3);
	sumsq += pass;

	//678

	i1 = 0;
	i2 = 0;
	i3 = 0;

	for (int i = 6; i <= 8; ++i) {
		for (int j = 0; j < 9; ++j) {
			p = mat[i][j];
			if (j < 3) {
				p1[i1] = p;
				i1++;
			}
			if (j > 2 && j < 6) {
				p2[i2] = p;
				i2++;
			}
			if (j > 5 && j < 9) {
				p3[i3] = p;
				i3++;
			}
		}
	}

	pass = checklines(p1);
	sumsq += pass;
	pass = checklines(p2);
	sumsq += pass;
	pass = checklines(p3);
	sumsq += pass;

	if (sumsq == 9) {
		sumpass++;
	} else {
		printf("False\n");
		return 0;
	}

	if (sumpass  == 3) {
		printf("True\n");
	} else {
		printf("False\n");
		return 0;
	}

	return 0;
}

int checklines(int arr1[10])
{
	int arr2[10];

	for (int i = 0; i < 10; i++)
		arr2[i] = 0;

	int n;

	for (int i = 0; i < 9; i++) {
		n = arr1[i];
		arr2[n] += 1;
	}
	int pass = 0;

	for (int i = 1; i < 10; i++) {
		if (arr2[i] == 1) {
			pass = 1;
		} else {
			pass = 0;
			return pass;
		}
	}
	return pass;
}