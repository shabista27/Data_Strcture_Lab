/*

Problem Statement:
Let x = (x1,x2, ... , xn) and y = (y1, y2,.... , ym) be two doubly linked lists. 
Assume that in each linked list, the nodes are in non-decreasing order of  their data-field values. 
Write C/C++ program to merge the two lists to obtain a new linked list z in which the nodes are also in this order. 
Following the merge, x and y should represent empty lists because each node initially in x or y is now in z.
No additional nodes may be used.

*/


//============================================================================
// Name        :doublylikedlist.cpp
// Author      :shabista shaikh
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

struct node
{
    int data;
    node *prev,*next;
};


struct hnode
{
    int cnt;
    node *next;
};


class dll
{
    hnode *head;
    node *temp,*p;
public:
    dll()
    {
        head=NULL;
        temp=p=NULL;
    }

    hnode *create();
    void show(hnode *);
    hnode *merge_dll(hnode *,hnode *);

};


hnode * dll::create()
{
 int n;
 cout<<"\nHow many node u want to insert in DLL: ";
 cin>>n;
 if(n==0)
 {
  head=new hnode;
  head->next=NULL;
  head->cnt=0;
  return head;
 }
 while(n>0)
 {
     p= new node;
     cout<<"\nEnter Data of node: ";
     cin>>p->data;
     p->next=NULL;
     p->prev=NULL;
     if(head==NULL)
     {
         head=new hnode;
         head->next=p;
         head->cnt=1;
     }
     else
     {
         temp=head->next;
         while(temp->next!=NULL)
         {
             temp=temp->next;
         }
         temp->next=p;
         p->prev=temp;
         head->cnt=head->cnt+1;
     }
     n=n-1;
 }
    return head;
}

void dll::show(hnode *h1)
{
    temp=h1->next;
    cout<<"\n|cnt : "<<h1->cnt<<"|-->";
    while(temp!=NULL)
    {

        cout<<"|Data is:"<<temp->data<<"|<->";
        temp=temp->next;
    }
        cout<<"\n";
}



hnode * dll::merge_dll(hnode *h1,hnode *h2)
{
  node *p,*t1,*t2;
  t1=h1->next;
  cout<<"\nt1 is...>"<<t1;
  t2=h2->next;
  cout<<"\nt2 is...>"<<t2;
  hnode *h3;
  h3=new hnode;
  h3->cnt=0;
  h3->next=NULL;
  if(h1->next==NULL)
  {
   h3->next=h2->next;
   h3->cnt=h2->cnt;
   h2->next=NULL;
   return h3;
  }
  if(h2->next==NULL)
  {
   h3->next=h1->next;
   h3->cnt=h1->cnt;
   h1->next=NULL;
   return h3;
  }
  if(t1->data<t2->data)
  {
   h3->next=t1;
   h3->cnt=1;
   p=h3->next;
   t1=t1->next;
  }
  else
  {
   h3->next=t2;
   h3->cnt=1;
   p=h3->next;
   t2=t2->next;
  }
  while(t1!=NULL&&t2!=NULL)
  {
   if(t1->data<t2->data)
   {
    p->next=t1;
    t1->prev=p;
    t1=t1->next;
    h3->cnt=h3->cnt+1;
    p=p->next;
   }
   else
   {
    p->next=t2;
    t2->prev=p;
    t2=t2->next;
    h3->cnt=h3->cnt+1;
    p=p->next;
   }
  }
  if(t1!=NULL)
  {
   p->next=t1;
   t1->prev=p;
   h3->cnt=h3->cnt+1;
  }
  if(t2!=NULL)
  {
   p->next=t2;
   t2->prev=p;
   h3->cnt=h3->cnt+1;
  }
  h1->next=h2->next=NULL;
 return h3;
}

int main()
{
    dll d1,d2,d3;
    hnode *hd1,*hd2,*hd3;
    hd1=hd2=NULL;
    cout<<"\nFirst DLL :";
    hd1=d1.create();
    d1.show(hd1);
    cout<<"\n\nSecond DLL :";
    hd2=d2.create();
    d2.show(hd2);
    cout<<"\n\nAfter Merge the DLL as Follows...\n";
    hd3=d3.merge_dll(hd1,hd2);

    d3.show(hd3);

    return 0;
}

/*
****************************************************************************************

OUTPUT


First DLL :
How many node u want to insert in DLL: 3

Enter Data of node: 5

Enter Data of node: 15

Enter Data of node: 18

|cnt : 3|0x89a010|-->|0|Data is:5 |0x89a050|<->|0x89a010|Data is:15 
|0x89a070|<->|0x89a050|Data is:18 |0|<->

Second DLL :
How many node u want to insert in DLL: 3

Enter Data of node: 10

Enter Data of node: 20

Enter Data of node: 30

|cnt : 3|0x89a090|-->|0|Data is:10 |0x89a0d0|<->|0x89a090|Data is:20 |0x89a0f0|<->|0x89a0d0|Data is:30 |0|<->

After Merge the DLL as Follows...

t1 is...>0x89a010
t2 is...>0x89a090

|cnt : 6|0x89a010|-->|0|Data is:5 |0x89a090|<->|0x89a010|Data is:10 |0x89a050|<->|0x89a090|Data is:15 |0x89a070|<->|0x89a050|Data is:18 |0x89a0d0|<->|0x89a070|Data is:20 |0x89a0f0|<->|0x89a0d0|Data is:30 |0|<->


*/
