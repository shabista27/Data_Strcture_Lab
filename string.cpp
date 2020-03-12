/*
PROBLEM STATEMENT:
Write a program for string operations-copy, concatenate, check substring, equal,  reverse and length.
*/

//============================================================================
// Name        : string.cpp
// Author      :shabista shaikh
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include<cstring>
#include<cstdio>
#include<cstdlib>
using namespace std;

class operation
{
private:
	char a[30];
public:
	void getdata()
	{
		cout<<"\nENTER ANY STRING: ";
		cin>>a;
	}
	void lenght()
	{
		int l;
		l=strlen(a);
		cout<<"\nTHE LENGHT OF THE STRING "<<a<<"WILL BE: "<<l;
	}
	void copy()
	{
		char b[30];
		strcpy(b,a);
		cout<<"\nTHE STRING GIVEN IN VARRIABLE a"<<a<<"IS COPIED INTO VARRIBLE b: "<<b;
	}
	void join()
	{
		char b[30],a[30];
		cout<<"\n ENTER ANY STRING: ";
		cin>>b;
		strcat(b,a);
		cout<<"\nTHE FINAL STRING WILL BE: "<<b;
	}
	void compare()
	{
		char b[30];
		int l;
		cout<<"\n ENTER THE STATEMANT YOU WANT TO COMPARE: ";
		cin>>b;
		l=strcmp(a,b);
		if(l==0)
		{
			cout<<"\n**********MATCHED!!*********";
		}
		else
		{
			cout<<"\n*********NOT MATCHED !!******";
		}
	}
	void reverse()

	{
		char ab[30],temp;
		int i,j;
		cout<<"\n ENTER THE STRING YOU WANT TO REVERSE: ";
		cin>>ab;
		i=0;
		j=strlen(a)-1;
		while(i<j)
		{
			temp=ab[i];
			a[i]=a[j];
			a[j]=temp;
			i++;
			j--;
		}
		cout<<"\n REVERSED STRING WILL BE :"<<ab;
	}
	void palindrome()

	{
		int i,j;
		j=strlen(a)-1;
		while(j>i)
		{
			if(a[i++]!=a[j])
			{
				cout<<"\n********* NOT A PALINDROME!!***********";
			}
			else
			{
				cout<<"\n***********PALINDROME****************";
			}
			i++,j++;
		}
	}
	void count()
	{
		int count=0,i=0;
		char x;
		cout<<"\n ENTER ANY CHARACTER: ";
		cin>>x;
		while(a[i]!='\0')
		{
			if(a[i]==x)
			{
				count++;
			}
			i++;
			cout<<"\n THE OCCURENCE OF LETTER "<<x<<"IS"<<count<<"TIMES";
	}

};

int main()
{
	operation s;
	int ch;
	cout<< "\n********STRING OPERATIONS*********";
	cout<<"\nENTER A STRING: ";
			s.getdata();
	while(1)
	{
		cout<<"\nENTER YOUR CHOICE:"<<"\n1.MEASURING THE LENGHT OF STRING"<<"\n2. COPY STRING IN ANOTHER VARRIABLE: "<<"\n3. JOIN TWO STRINGS: "<<"\n4. COMPARE TWO STRINGS"
				<<"\n5.REVERSE THE STRING "<<"\n6. IS THE STRING A PALINDROME??"<<"\n7.COUNTING THE OCCERNCE OF A LETTER "<<"\n8. EXIT: ";
		cin>>ch;
		switch(ch)
		{
		case 1:
			s.lenght();
			break;
		case 2:
			s.copy();
			break;
		case 3:
			s.join();
			break;
		case 4:
			s.compare();
			break;
		case 5:
			s.reverse();
			break;
		case 6:
			s.palindrome();
			break;
		case 7:
			s.count();
			break;
		case 8:
			exit(0);
		default:
			cout<<"\n*********INVALID**********";
		}
	}
	return 0;
}










