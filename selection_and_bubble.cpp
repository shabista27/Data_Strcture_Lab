/*
Write C++ program to store first year percentage of students in array.
Write function for sorting array of floating point numbers in ascending order using
a) Selection Sort b) Bubble sort and display top five scores.

*/


//========================================
// Name        :sorting1.cpp
// Author      : Shabista shaikh 
// Version     : 1
// Copyright   : Your copyright notice
// Description : C++, Ansi-style
//================================================
#include<iostream>
using namespace std;
class sort
{
 float m[30];
 int i,j,n;
public:
 void insert()
 {
  cout<<"ENTER NUMBER OF STUDENTS:"<<endl;
  cin>>n;
  cout<<"ENTER MARKS:"<<endl;
  for(i=0;i<n;i++)
  {
   cin>>m[i];
  }
 }
 void display()
 {
  cout<<"ENTERED MARKS ARE:"<<endl;
  for(i=0;i<n;i++)
  cout<<m[i]<<endl;
 }

 void bubble()
 {
  float temp;
  for(i=0;i<n-1 ;i++)
  {
   for(j=0;j<(n-1)-i;j++)
   {
    if(m[j]>m[j+1])
    {
     temp=m[j];
     m[j]=m[j+1];
     m[j+1]=temp;
    }
   }
  }
cout<<"TOP FIVE:"<<endl;
  for(i=n-1;i>=(n-5);i--)
  {
   cout<<m[i]<<endl;

  }
 }
 void selection()
 {
  int min;
  float temp;
  for(i=0;i<(n-1);i++)
  {
   min=i;
   for(j=i+1;j<n;j++)
   {
    if(m[j]<m[min])
    {
     min=j;
    }
   }
    temp=m[i];
    m[i]=m[min];
    m[min]=temp;

  }
  cout<<"TOP FIVE:"<<endl;
  for(i=n-1;i>= (n-5);i--)
  {
   cout<<m[i]<<endl;
  }
 }
};
int main()
{
 sort s;
 int ch,x;
 cout<<"LIST OF TOP FIVE STUDENTS:"<<endl;
 do
 {
 cout<<"1.CREATE \n2.DISPLAY\n3.TOP FIVE BY BUBBLE SORT\n4.TOP FIVE BY INSERTION SORT\nENTER CHOICE:"<<endl;
  cin>>ch;
  switch(ch)
  {
  case 1:
   s.insert();
   break;
  case 2:
   s.display();
   break;
  case 3:
   s.bubble();
   break;
  case 4:
   s.selection();
   break;
  default:
   cout<<"INVALID CHOICE!"<<endl;
  }
  cout<<"DO YOU WANT TO CONTINUE? 1.YES 2.NO"<<endl;
  cin>>x;
 }while(x==1);
 return 0;
}

----------------------------------------------------------------------------------------------------------------------------------
   
/**********************output***********************
LIST OF TOP FIVE STUDENTS:
1.CREATE
2.DISPLAY
3.TOP FIVE BY BUBBLE SORT
4.TOP FIVE BY INSERTION SORT
ENTER CHOICE:
1
ENTER NUMBER OF STUDENTS:

4
ENTER MARKS;
22
33
11
44
DO YOU WANT TO CONTINUE? 1.YES 2.NO
1
1.CREATE
2.DISPLAY
3.TOP FIVE BY BUBBLE SORT
4.TOP FIVE BY INSERTION SORT
ENTER CHOICE:
2
ENTERED MARKS ARE:
22
33
11
44
DO YOU WANT TO CONTINUE? 1.YES 2.NO
1
1.CREATE
2.DISPLAY
3.TOP FIVE BY BUBBLE SORT
4.TOP FIVE BY INSERTION SORT
ENTER CHOICE:
3
TOP FIVE:
44
33
22
11
7.62881e+033
DO YOU WANT TO CONTINUE? 1.YES 2.NO
1
1.CREATE
2.DISPLAY
3.TOP FIVE BY BUBBLE SORT
4.TOP FIVE BY INSERTION SORT
ENTER CHOICE:
4
TOP FIVE:
44
33
22
11
7.62881e+033
*************************************end**************************************/
