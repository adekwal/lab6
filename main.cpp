#include <iostream>
#include <cstdlib>
#include <math.h>
#include "gauss.h"

void HilbertMatrix(int N, double** H);
void displayMatrix(int N, double** H);
void computeVec(int N, double** H, double* b);
void plotVec(int N, double* b);

int main()
{
	int N; double** H; double* x; double* b; printf("N="); scanf_s("%d", &N);
	H = (double**)malloc(N * sizeof(double*));
	for (int i = 0; i < N; i++)
	{
		H[i] = (double*)malloc(N * sizeof(double));
	}//dynamiczna alokacja pamieci na tablice(macierz) H o wymiarach NxN
	x = (double*)malloc(N * sizeof(double));//macierz niewiadomych
	b = (double*)malloc(N * sizeof(double));//macierz prawych stron

	HilbertMatrix(N, H);
	displayMatrix(N, H);
	computeVec(N, H, b);
	plotVec(N, b);
	gauss(N, H, x, b);

	for (int i = 0; i < N; i++)
	{
		printf("%lf\n", x[i]);
	}

	free(H); free(x); free(b);
}

void HilbertMatrix(int N, double** H)//tworzenie macierzy H
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			H[i][j] = (1. / (1 + i + j));
		}
	}
}
void displayMatrix(int N, double** H)//wypisywanie macierzy H na ekran
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			printf("%lf\t", H[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}
void computeVec(int N, double** H, double* b)//obliczanie wektora b
{
	for (int i = 0; i < N; i++)
	{
		b[i] = 0;
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			b[i] += H[i][j];
		}
	}
}
void plotVec(int N, double* b)//wypisywanie wektora b na ekran
{
	for (int i = 0; i < N; i++)
	{
		printf("%lf\n", b[i]);
	}
	printf("\n");
}