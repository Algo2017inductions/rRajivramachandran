#include<stdio.h>
#include<string.h>
#include<iostream>
using namespace std;

int main()
{
	int count = 0,counter,n,i,j,k,rel;
	char A[50],B[50],c;
	bool C[6];
	cout<<"Enter number of test cases:";
	cin>>n;
	for(k = 0; k < n; k++)
	{   
	    fflus
		cout<<"Enter name 1:";
		gets(A);
		cout<<"Enter name 2:";
		gets(B);
		
		for(i = 0; i < strlen(A); i++)
		{
			c = A[i];
			for(j = 0; j < strlen(B); j++)
			{
				if( c == B[j])    // eliminate common letters
				{
					B[j] = '_';
					A[i] = '_';
					count -= 2;
					break;
				}
			}
		}
		
		count = strlen(A) + strlen(B) + count; //total letters remaining
		counter = count % 6;   //result is same for 1,7,13 number of letters
		
		for(i = 0; i < 6; i++)
		C[i] = 1;
		j = 0;
		for(i = 1; i <= 5; i++)       //checking the flames
		{
			count = 0;
			while(count != counter)
			{
				if(C[j] != 0)
				    count++;
				j++;
				if(j == 6)       //cyclic manner
				j = 0;
			}
			if(j == 0)
			    j = 5;
			else
			    j -= 1;
			C[j] = 0;     // eliminated letters are zeroed
			
			//get to the previously scratched letter and continue
			if(j == 5)
			    j = 0;
			else
			    j++;	    
		}
		
		for(i = 0; i < 6; i++)
		    if(C[i] == 1)
		        {
				    rel = i + 1;
					break;
			    }
		cout<<"Relationship:";	    
		switch(rel)
		{
			case 1: cout<<"Friends\n";
			        break;
			case 2: cout<<"Love\n";
			        break;
			case 3: cout<<"Adore\n";
			        break;
			case 4: cout<<"Marriage\n";
			        break;
			case 5: cout<<"Enemies\n";
			        break;
			case 6: cout<<"Sister\n";
			        break;								        
		}	    
	}
}
