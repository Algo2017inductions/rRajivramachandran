#include<stdio.h>
#include<iostream>
using namespace std;
void simulator1(int A[50], int n)
{
	int i,j,flag,q,m;
	cout<<"Enter number of queries for sim1:";
	cin>>m;
	for(i = 1; i <= m; i++)
	{
		j = 0, flag = -1;
		cout<<"Enter query:";
		cin>>q;
		cout<<"\n";
		while( j < n)
		{
			if(A[j] > q && flag == -1)   // cut and serve
			{
				A[j] -= q;
				flag = 1;
			}
			
			else if(A[j] == q && flag == -1)   // give completely
			{
				A[j] = 0;
				flag = 1;
			}
			
			if(A[j] != 0)
			cout<<A[j]<<" ";
			j++;
		}
		if(flag == -1)
		cout<<"Could not be processed\n";
	}
	cout<<"\n";
}


void simulator2(int A[50], int n)
{
	int i,m,j,flag = -1,pos,apt,q,k;
	cout<<"Enter number of queries:";
	cin>>m;
	for(i = 0;i < m; i++)
	{
		cout<<"Enter query:";
		cin>>q;
		cout<<"\n";
		apt = 0;
		for(j = 0; j < n; j++)
		    {
			    if(A[j] >= q)
		        {   
			        if(apt == 0) 
			        {
				        apt = A[j];
				        pos = j;
				        
			        }
			    
			        else if(A[j] < apt)
			        {
				        apt = A[j];
				        pos = j;
			        }
		        }
		    
			} 
			cout<<"Status:\n";
			if(apt == 0)
			    cout<<"Not processable Status:\n";
				   
			else
			{
			    A[pos] -= q;                  // update taken piece
				for(k = 0; k < n; k++)
				{
					if(A[k] != 0)   //if only cloth removed partially
					cout<<A[k]<<" ";
				}
		    }
	}
	cout<<"\n";
}



void simulator3(int A[50], int n)
{
	int i,m,j,flag = -1,pos,apt,q,k;
	cout<<"Enter number of queries:";
	cin>>m;
	for(i = 0;i < m; i++)
	{
		cout<<"Enter query:";
		cin>>q;
		cout<<"\n";
		apt = 0;
		for(j = 0; j < n; j++)
		    {
			    if(A[j] >= q)
		        {   
			        if(apt == 0) 
			        {
				        apt = A[j];
				        pos = j;
				        
			        }
			    
			        else if(A[j] > apt)
			        {
				        apt = A[j];
				        pos = j;
			        }
		        }
		    
			} 
			cout<<"Status:\n";	
			if(apt == 0)
			    cout<<"Not processable  Status:\n";  
		    else
			{
			    A[pos] -= q;                  // update taken piece
				for(k = 0; k < n; k++)
				{
					if(A[k] != 0)   //if only cloth removed partially
					cout<<A[k]<<" ";
				}
		    }
	}
	cout<<"\n";
}


int main()
{
	int i,A[50],n;
	cout<<"Enter number of curtains for sim1:";
	cin>>n;
	cout<<"Enter sizes:\n";
	
	for(i = 0; i < n; i++)
	    cin>>A[i];
	simulator1(A,n);
	
	cout<<"Enter number of curtains for sim2:";
	cin>>n;
	cout<<"Enter sizes:\n";
	
	for(i = 0; i < n; i++)
	    cin>>A[i];
	simulator2(A,n);
	
	cout<<"Enter number of curtains for sim3:";
	cin>>n;
	cout<<"Enter sizes:\n";
	
	for(i = 0; i < n; i++)
	    cin>>A[i];
	simulator3(A,n);
    return 0;	
	    
}
