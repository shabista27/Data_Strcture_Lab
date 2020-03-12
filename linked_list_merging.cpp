/*


Write C++ program to store set of negative and positive numbers using linked list. Write functions a) Insert number b) Delete nodes with negative numbers c) To create two more linked lists using this list, one containing all positive numbers and other containing negative numbers d) For two lists that are sorted; Merge these two lists into third resultant list that is sorted

*/


//============================================================================
// Name        :merging.cpp
// Author      :shabista shaikh
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================


#include <iostream>
#include<cstdlib>

using namespace std;

struct node
{
	int number;
	node *next;
};

class num
{
public:
	node *head, *head1, *head2;

	num()
	{
		head=NULL;
		head1=NULL;
		head2=NULL;
	}

	void create()
	{
		node *current, *newnode;
		char ch;
		cout<<"\n*************CREATING NUMBER LIST**********************";
		do
		{

			newnode=new node;
			cout<<"\nENTER NUMBER: ";
			cin>>newnode->number;
			newnode->next=NULL;
			if(head==NULL)
			{
				head=newnode;
				current=newnode;
			}
			else
			{
				current->next=newnode;
				current=newnode;
			}
			cout<<"DO YOU WANT TO ENTER NUMBER (y/n): ";
			cin>>ch;
		}while(ch!='n');
	}


	void display(node *head)
	{
		node *p;
		p=head;
		if(p==NULL)
		{
			cout<<"\nLIST IS EMPTY!!!";
		}
		else
		{
			while(p!=NULL)
			{
				cout<<p->number<<"\t";
				p=p->next;
			}
			cout<<"\n";
		}
	}

	void insert()
	{
		node *p, *temp;
		p=new node;
		cout<<"\nENTER THE NUMBER YOU WANT TO INSERT::";
		cin>>p->number;
		p->next=NULL;
		temp=head;
		while(temp->next!=NULL)
		{
			temp=temp->next;

		}
		temp->next=p;
	}

	void separate()
	{
		node *temp,*current1,*current2,*n1,*n2;
		    temp=head;

		    while(temp!=NULL)
		    {
		        if((temp->number)<0)
		        {
		            n1=new node;
		            n1->number=temp->number;
		            n1->next=NULL;

		            if(head1==NULL)
		            {
		                current1=n1;
		                head1=n1;
		            }
		            else
		            {
		            current1->next=n1;
		            current1=n1;
		            }

		        }
		        else if((temp->number)>=0)
		        {
		            n2=new node;
		            n2->number=temp->number;
		            n2->next=NULL;
		            if(head2==NULL)

		            {
		                current2=n2;
		                head2=n2;
		            }
		            else
		            {
		              current2->next=n2;
		              n2->next=NULL;
		              current2=n2;
		            }
		        }
		          temp=temp->next;
		     }
	}

	void sorting(node *head45)
	{
		node *temp1,*temp2,*temp3;
		temp1=head45;
		for(;temp1->next!=NULL;temp1=temp1->next)
		{
			for(temp2=temp1->next;temp2!=NULL;temp2=temp2->next)
			{
				if(temp1->number>temp2->number)
				         {
				             int temp= temp1->number;
				             temp1->number = temp2->number;
				             temp2->number = temp;
				         }
			}
		}

	}

	void merge()
	{
		node *temp;
		temp=head1;
		while(temp->next!=NULL)
		{
			temp=temp->next;
		}
		temp->next=head2;
	}
};


int main()
{
    num n;
    n.create();
    cout<<"\n \nTHE LIST OF +VE AND -VE NUMBERS IS: \n";
    n.display(n.head);
    n.insert();
    cout<<"\n \nTHE LIST AFTER INSERTION IS: \n";
    n.display(n.head);
    n.separate();
    cout<<"\n\n THE LIST OF ONLY -VE NUMBERS IS: \n";
    n.display(n.head1);
    cout<<"\n\n THE LIST OF ONLY +VE NUMBERS IS: \n";
    n.display(n.head2);
    cout<<"\n\n THE LIST OF ONLY SORTED -VE NUMBERS IS : \n";
    n.sorting(n.head1);
    n.display(n.head1);
    cout<<"\n\n THE LIST OF ONLY SORTED +VE NUMBERS IS : \n";
    n.sorting(n.head2);
    n.display(n.head2);
    n.merge();
    cout<<"\n AFTER MERGE .....THE LIST IS AS FOLLOWS: \n";
    n.display(n.head1);
    cout<<"\n\n THE LIST OF SORTED +VE AND -VE NUMBERS IS : \n";
    n.display(n.head1);
    return 0;
}


/*


OUTPUTS: 
 
Enter the no:
 1

Do you want to add new membery

 Enter the no:
 -5

Do you want to add new membery

 Enter the no:
 6

Do you want to add new membery

 Enter the no:
 -7

Do you want to add new membery

 Enter the no:
 -3

Do you want to add new membery

 Enter the no:
 -4

Do you want to add new membery

 Enter the no:
 7

Do you want to add new membern


THE LIST OF +VE AND -VE NUMBERS IS:
1    -5    6    -7    -3    -4    7

 Enter New Number to be insert  :  10


THE LIST AFTER INSERTION IS:
1    -5    6    -7    -3    -4    7    10

 THE LIST OF ONLY -VE NUMBERS IS:
-5    -7    -3    -4

 THE LIST OF ONLY +VE NUMBERS IS:
1    6    7    10

 THE LIST OF ONLY SORTED -VE NUMBERS IS :
    -7    -5    -4    -3

 THE LIST OF ONLY SORTED +VE NUMBERS IS :
    1    6    7    10
 AFTER MERGE .....THE LIST IS AS FOLLOWS:
-7    -5    -4    -3    1    6    7    10

 THE LIST OF SORTED +VE AND -VE NUMBERS IS :
-7    -5    -4    -3    1    6    7    10

*/