#include<iostream>
using namespace std;

int partition(int *input, int si, int ei)
{
    int pivot = input[si];
    int count = 0;
    for(int i = si + 1; i <= ei; i++)
    {
        if(input[i] <= pivot)
        {
            count++;
        }
    }
    int temp = input[si];
    input[si] = input[si + count];
    input[si + count] = temp;
    int i = si;
    int j = ei;
    while(i <= count + si && j >= count + si)
    {
        if(input[i] <= pivot)
        {
            i++;
        }
        else if(input[j] > pivot)
        {
            j--;
        }
        else
        {
         	temp = input[i];
            input[i] = input[j];
            input[j] = temp;
            i++;
            j--;
        }
    }
    return count + si;
}

void quicksort(int *input, int si, int ei)
{
    if(si >= ei)
    {
        return;
    }
    int c = partition(input, si, ei);
    quicksort(input, si, c - 1);
    quicksort(input, c + 1, ei);
}

int main()
{
	int size;
	cin >> size;
	int *arr = new int[size];
	for(int i = 0; i < size; i++)
	{
		cin >> arr[i];
	}
	quicksort(arr, 0, size - 1);
	for(int i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}
	return 0;
}
