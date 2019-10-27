/*
QuickSort:
>Regard the last element as a pivot element.
>go through the whole sequence and compare each element with pivot element.
>divide the whole sequence into two subsequences, one of which is smaller than pivot element while the other is bigger.
>these 3 steps processed above seems like having put the pivot element at the right position already.
>do this on both subsequences and complete a recursion.
*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<iostream>

using namespace std;
int partition(int* A, int p, int r);
void quick_sort(int* A, int p, int r);
int* random_generate(int size);

int* random_generate(int size)
{
	int* A = (int*)malloc(size*sizeof(int));
	unsigned int seed = 5;
	srand(seed);
	for (int i = 0; i < size; i++)
		A[i] = rand() % 50;
	return A;
}

int partition(int* A, int p, int r)
{
	int primary = A[r];
	int i = p - 1;
	for (int j = p; j < r; j++)
	{
		if (A[j] <= primary)
		{
			//swap A[i+1]  A[j]
			int temp = A[j];
			A[j] = A[i + 1];
			A[++i] = temp;  
			//-----------------
		}
	}
	int temp = A[i + 1];
	A[i + 1] = A[r];
	A[r] = temp;
	return i + 1;
}

void quick_sort(int* A, int p, int r)
{
	if (p < r)
	{
		int q = -1;
		q = partition(A, p, r);
		quick_sort(A, p, q-1);
		quick_sort(A, q+1, r);
	}
}

int main(int argc, char** argv)
{
	int* A = random_generate(10);
	for (int i = 0; i < 10; i++)
		printf("%d ", A[i]);
	cout << endl;
	quick_sort(A, 0, 9);
	for (int i = 0; i < 10; i++)
		printf("%d ", A[i]);
	return 0;
}