//Rajiv 108116067
// insertion sort done in ascending order
#include<stdio.h>
#include<iostream>
using namespace std;
int main()
{
	int A[200],n,i,j,temp;
	cout<<"Enter the number of numbers:";
	cin>>n;
	cout<< "Enter the numbers:";
	
	for(i = 0; i < n;i++)
	    cin>>A[i];
	
	for(i = 1; i < n; i++)
	{
		temp = A[i];
		j = i - 1;
		while(j >= 0 && temp < A[j])
		{
		    A[j + 1] = A[j];
		    j--;
		}

        A[j + 1] = temp;
	}
	
	cout<<"The sorted array is:\n";
	for(i = 0; i < n; i++)
        cout<<A[i]<<"\t";
	return 0; 
}

