#include<iostream>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<vector>
#include<fstream>
using namespace std;
vector<int> lsp;
 vector<string> lines;

void arrfill(string P)
{
	lsp.clear();
	int i,j,n;
	n = P.length();
	
	i = 0;
	j = 1;
	lsp.push_back(0);
	while( j < n)
	{
		if(P[i] == P[j])
		{
			i++;
			lsp.push_back(i);
			j++;
		}
		else
		{
			if(i != 0)
			{
				i = lsp[i - 1];
			}
			
			else
			{
				lsp.push_back(0);
				j++; 
			}
		}
	}

}

int searchops(string txt, string P)
{
	int i,j,count = 0;
	arrfill(P);
	i = 0;
	j = 0;
	while(i < txt.length())
   {
       if((toupper)(txt[i]) == (toupper)(P[j]))
	   {
	       i++;
	       j++;
	   }
	   else
	   {
	       if(j != 0)
		   {
		       j = lsp[j - 1];
		   }
		
		   else
		       i++;
	   }
	
	   if(j == P.length())
	   {
	       if((txt[i - P.length() - 1] ==' ' && txt[i] == ' ') || (i - P.length() == 0  && txt[i] ==' ')|| (i == txt.length() && txt[i - P.length() - 1] == ' ' ))  //check if an independent word
		   count++;
	       j = lsp[j - 1];
	       
       } 
	
   }
   if(count == 0)
   return -1;
   
   else
   return count;
}
void pagereader(char filnam[30])      //reads page by page and fills in the lines array
 {
	 ifstream q;
	 
	 int index = 0;
     strcat(filnam,".txt");
     string lin;
	 q.open(filnam);
	 if(!q)                 // unable to open file
	 cout<<"ERROR";
	 else
	 {
	     while(q.eof() != 1)
		 {  getline(q,lin);
		 
		    if(q.eof() != 1)
		 	    lines.push_back(lin);
	     }
	     q.close();
     }
     
}  
int main()
{ 
   	string P,txt;
   	ifstream st;
   	int flag = -1,m;
   	st.open("queries.txt");
   	char pagenum[30],appendix[2];
   	strcpy(pagenum,"page_");
   	while(st>>P)
   	{
	    cout<<"Word:"<<P<<"\n";
	    cout<<"Occurances:"<<"\n";
	    flag = -1;
	   	for(int i = 1; i <= 25; i++)
	   	{   lines.clear();
	   	    itoa(i,appendix,10);
			strcat(pagenum,appendix);
			pagereader(pagenum);
			for(int k = 0; k < lines.size(); k++)  
			{  
				m = searchops(lines[k],P);            // pass line by line
				if(m != -1)
				{
				    for(int j = 1; j <= m; j++)     // number of times word found on line k+1
					cout<<"Page: "<<i<<", "<<"line: "<<k + 1<<"\n";
				flag = 1;
			    }
		    }
		    strcpy(pagenum,"page_");
	    }
		if(flag == -1)
		cout<<"None"<<"\n";
    }
   	st.close();
}
   
