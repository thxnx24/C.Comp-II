#include <iostream>
using namespace std;

void swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void cocktail_sort(int* ini, int* fin)
{
	bool verifica = true;
	while (verifica) 
	{
		verifica = false;
		for (int *ptr = ini; ptr < fin; ++ptr)
		{
			if (*ptr > *(ptr + 1))
			{
				swap(ptr, ptr + 1);
				verifica = true;
			}
		}
		if (!verifica) break;
		fin--;
		for (int* ptr = fin; ptr > ini; --ptr)
		{
			if (*ptr < *(ptr - 1)) 
			{
				swap(ptr, ptr - 1);
				verifica = true;
			}
		}
		ini++;
	}
}

int main()
{
	int array[] = { 1,9,2,8,3,7,4,6,5,0 };
	int n = sizeof(array) / sizeof(array[0]);

	cocktail_sort(array, array + n - 1);
	
	for (int i = 0; i < n; i++)
	{
		cout << array[i] << " ";
	}
	return 0;
}