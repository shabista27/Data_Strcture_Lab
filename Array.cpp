/*
Write C/C++ program to store marks scored for first test of subject 'Data Structures and Algorithms' for N students. Compute
I. The average score of class
ii. Highest score and lowest score of class
iii. Marks scored by most of the students
iv. list of students who were absent for the test

*/
//============================================================================
// Name        : Test.cpp
// Author      : SHABISTA SHAIKH
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

class Test
{
private:
    int dsa[30],i,j,n,sum,cnt[50],k,rn[30];   
 float av;
public:
    Test() 
    {
        i=j=n=0;
        av=sum=k=0;
    }
 
void getdata()
{
    cout<<"\nHow many student in SE Comp Div: A : ";
    cin>>n;
    cout<<"\n\t-----------------------------------------------------";
    cout<<"\n\tEnter the marks scored for first test of subject DSA: ";
    cout<<"\n\t-----------------------------------------------------";
    cout<<"\n\nStudent who remains Absent for the test please enter -1 for them:";
    cout<<"\n                     -------------------------------------         ";
    for(i=0;i<n;i++)
    {
     cout<<"\nEnter the marks of Roll no: "<<i+1<<" : ";
     cin>>dsa[i];
    }
}

void MS_score()
{
    for(i=0;i<50;i++)
    {
        cnt[i]=0;
    }
    for(i=0;i<50;i++)
    {
        for(j=0;j<n;j++)
        {
            if(dsa[j]==i)
            {
                cnt[i]=cnt[i]+1;
            }
        }
    }
    /*cout<<"\n\nCount of marks..\n\n";
    for(i=0;i<50;i++)
    {
        cout<<"\t"<<cnt[i];
    }*/
    cout<<"\n\n Marks Scored by most of the student in test are: \n";
    
    k=0;
    j=0;
        int max=cnt[j];
    for(i=0;i<50;i++)
    {
     if(cnt[i]>=max)
     {
         max=cnt[i];
         k=i;
     }
    }
    cout<<"\n\nMAximum marks "<<k<<" scored by "<<max <<" Students...\n";
    for(i=0;i<n;i++)
    {
        if(dsa[i]==k)
        {
            rn[j]=i;
            j++;
        }
    }
    cout<<"\n\n Students Roll Number are as follows..\n\n";
    for(i=0;i<j;i++)
    {
        cout<<"\t"<<rn[i]+1;
    }
}




void show()
{
    cout<<"\n\nFirst Test Marks of Subject DSA are as follows...\n";
    cout<<"\n*********************************\n";
    cout<<"|  Roll No\t"<<"|"<<" DSA Marks     |";
    cout<<"\n*********************************\n";
    for(i=0;i<n;i++)
    {
        cout<<"|\t"<<i+1<<"\t|\t"<<dsa[i]<<"\t|\n";
    }
    cout<<"---------------------------------\n";
}

void avg()
{
    int p=0;
    cout<<"\nAverage Score of Class = > ";
    for(i=0;i<n;i++)
    {
        if(dsa[i]!=-1)
        {
            sum=sum+dsa[i];
            p++;
        }

    }
    av=sum/p;
    cout<<av;
}



void Ab_stud()
{
    int cnt=0;
    cout<<"\n\nTotal Number of Student Absent for DSA Test\n";
    cout<<"\nRoll No\t Marks\n";
    for(i=0;i<n;i++)
    {
        if(dsa[i]==-1)
        {
            cout<<i+1<<"\tAbsent\n";
            cnt++;
        }
    }
    cout<<"\n\tTotal_Absent_Student :=: "<<cnt;
}





void HS_LS()
{
    int min=0;
    int max=0,rno=0,i=0;
    cout<<"\n\nHighest Score of the Class for DSA Subject are as follows..\n";
    max=dsa[i];
    for(i=0;i<n;i++)
    {
        if(dsa[i]==-1)
        {

        }
        else if(dsa[i]>=max)
        {
            max=dsa[i];
            rno=i;
        }
    }
    cout<<"\n\tDSA Highest Score: "<<"Roll No : "<<rno+1<<" Marks : "<<max;
    cout<<"\n\nLowest Score of the Class for DSA Subject are as follows..\n";
    rno=0;
    min=dsa[j];
    for(j=0;j<n;j++)
    {
        if(dsa[j]==-1)
        {

        }
        else if(dsa[j]<=min)
        {
         min=dsa[j];
         rno=j;
        }
    }
    cout<<"\n\tDSA Lowest Score: "<<"Roll No : "<<rno+1<<" Marks : "<<min;
}

};

int main()
{
    Test T;
    T.getdata();
    T.show();
    T.avg();
    T.Ab_stud();
    T.HS_LS();
    T.MS_score();
    return 0;
}



/***************************************************************************************


   	OUTPUT :


How many student in SE Comp Div: A : 10

    -----------------------------------------------------
    Enter the marks scored for first test of subject DSA: 
    -----------------------------------------------------

Student who remains Absent for the test please enter -1 for them:
                     -------------------------------------         
Enter the marks of Roll no: 1 : 20

Enter the marks of Roll no: 2 : 23

Enter the marks of Roll no: 3 : 25

Enter the marks of Roll no: 4 : -1

Enter the marks of Roll no: 5 : 36

Enter the marks of Roll no: 6 : 40

Enter the marks of Roll no: 7 : 36

Enter the marks of Roll no: 8 : 36

Enter the marks of Roll no: 9 : 36

Enter the marks of Roll no: 10 : 22


First Test Marks of Subject DSA are as follows...

*********************************
|  Roll No    | DSA Marks     |
*********************************
|    1    |    20    |
|    2    |    23    |
|    3    |    25    |
|    4    |    -1    |
|    5    |    36    |
|    6    |    40    |
|    7    |    36    |
|    8    |    36    |
|    9    |    36    |
|    10    |    22    |
---------------------------------

Average Score of Class = > 30

Total Number of Student Absent for DSA Test

Roll No     Marks
4    Absent

    Total_Absent_Student :=: 1

Highest Score of the Class for DSA Subject are as follows..

    DSA Highest Score: Roll No : 6 Marks : 40

Lowest Score of the Class for DSA Subject are as follows..

    DSA Lowest Score: Roll No : 1 Marks : 20

 Marks Scored by most of the student in test are: 


Maximum marks 36 scored by 4 Students...


 Students Roll Number are as follows..

    5    7    8    9


