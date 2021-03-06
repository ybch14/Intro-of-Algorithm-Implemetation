#include <iostream>
#include <algorithm>

void counting_sort(int* A, int length, int upbound)
{
	int *C = new int[upbound + 1];
	int *B = new int[length];
	std::fill(C, C + upbound + 1, 0);
	for (int i = 0; i < length; i++)
		C[A[i]]++;
	// C[i]: number of elements equal to i
	for (int i = 1; i <= upbound; i++)
		C[i] = C[i] + C[i - 1];
	// C[i]: number of elements <= i
	for (int i = length-1; i >= 0; i--)
	{
		B[C[A[i]]-1] = A[i];
		C[A[i]]--;
	}
	std::copy(B, B + length, A);
}

void insert_sort(int* A, int length)
{
	int* result = new int[length];
	std::copy(A, A + length, result);
	for (int i = 0; i < length; i++)
	{
		int j = i - 1;
		while ((j >= 0) && (A[j] > result[i]))
		{
			A[j + 1] = A[j];
			j--;
		}
		A[j + 1] = result[i];
	}
	delete[]result;
}

bool test_sort(int* A, int length)
{
	for (int i = 0; i < length - 1; i++)
	{
		if (A[i] > A[i + 1])
		{
			std::cout << "Wrong at " << i << std::endl;
			return false;
		}
	}
	return true;
}

void quick_sort(int* A, int low, int high)
{
	int partition(int* A, int low, int high);
	void insert_sort(int* A, int length);
	if (high - low + 1 <= 50)
		insert_sort(A + low, high - low + 1);
	else
	{
		int mid = partition(A, low, high);
		if (mid - 1 > low)
			quick_sort(A, low, mid - 1);
		if (high > mid + 1)
			quick_sort(A, mid + 1, high);
	}
}

int partition(int* A, int low, int high)
{
	int x = A[high], tmp = 0;
	int i = low - 1;
	for (int j = low; j < high; j++)
	{
		if (A[j] <= x)
		{
			i++;
			tmp = A[i];
			A[i] = A[j];
			A[j] = tmp;
		}
	}
	tmp = A[i + 1];
	A[i + 1] = A[high];
	A[high] = tmp;
	return i + 1;
}
