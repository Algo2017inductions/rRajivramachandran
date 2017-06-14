#include<iostream>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<vector>
#include<fstream>
using namespace std;
int arr[256];
 vector<string> lines;

void arrfill(string P)
{
    int m,i;
	m = P.length();
	for(i = 0; i < 256; i++)
	    arr[i] = m;
	for(i = 0; i < m - 1; i++)
	arr[toascii(P[i])] =  m - i - 1; 
}

int searchops(string txt, string P)
{
	arrfill(P);
	int shift = 0,m,i,count = 0;
	m = P.size();
	i = m - 1;
	while(shift + i < txt.length())
	{
		while(i >= 0)
		{
			if(txt[shift + i] == P[i])
			    i--;
			else
			    break;    
		}
		if(i == -1)
		{
			if((shift == 0 && txt[shift + m] == ' ') || (shift + m == txt.length() && txt[shift - 1] == ' ')||(txt[shift - 1] == ' ' && txt[shift + m] == ' '))
			count++;
		}
		    
		shift += arr[toascii(txt[shift + m - 1])];
		i = m - 1;
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

