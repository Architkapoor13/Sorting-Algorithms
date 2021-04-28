#include<iostream>
using namespace std;

void mergearray(int input[], int si, int ei)
{
    int arr[100000];
    int k = si;
    int i = si;
    int mid = (si+ei)/2;
    int j=mid+1;
    while(i <= mid && j <= ei)
    {
        if(input[i] <= input[j])
        {
            arr[k++] = input[i++];
          
        }
        else
        {
            arr[k++] = input[j++];
          
        }
    }
    
    while(i <= mid)
    {
        arr[k++] = input[i++];
        
    }

    while(j <= ei)
    {
        arr[k++] = input[j++];
       
    }
    
   
    for(int i = si; i <= ei; i++)
    {
        input[i] = arr[i];
        
    }
}

void devidemerge(int input[], int si, int ei)
{
    if(si >= ei)
    {
        return;
    }
	int mid = (si + ei)/2;    
    devidemerge(input, si, mid);
    devidemerge(input, mid+1, ei);
    mergearray(input, si, ei);
}

int main()
{
	int size;
	cin >> size;
	int *arr = new int [size];
	for(int i = 0; i < size; i++)
	{
		cin >> arr[i];
	}
	devidemerge(arr, 0, size - 1);
	for(int i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}
	return 0;
}
