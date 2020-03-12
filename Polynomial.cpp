/*
	
Problem Statement: 
Write a C++ program to realize polynomial equation and perform operations. Write function
a)	To input and output polynomials represented as bmxem+bm-1xem-1+…+b0xe0.
Your functions should overload the <<and >>operators.
b)	Evaluates a polynomial at given value of x.
c)   Add two polynomials
d)   Multiplies two polynomials.

*/

//============================================================================
// Name        :polynomial.cpp
// Author      :shabista shaikh
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================





#include<iostream>
using namespace std;
struct poly
{
int coeff;
int exp;
};
class polynomial
{
struct poly p[20];
public:
int n;
void read();
void display();
polynomial operator +(polynomial);
void multiply();
};
void polynomial::read()
{
int i;
for(i=0;i<n;i++)
{
cout<<”\n Enter the coefficient & exponents:”;
cin>>p[i].coeff>>p[i].exp;
}
}
void polynomial::display()
{
for(int i=0;i<n;i++)
{
cout<<p[i].coeff<<” x^ ”<<p[i].exp;
if(i!=n-1)
cout<<” + ”;
}
cout<<”\n”;
}
polynomial polynomial::operator +(polynomial p2)
{
polynomial p3;
int i=0,j=0,k=0;
while((i<n)&&(j<p2.n))
{
if(p[i].exp>p2.p[j].exp)
{
p3.p[k]=p[i];
i++;
}
else if(p[i].exp<p2.p[j].exp)
{
p3.p[k]=p2.p[j];
j++;
}
else
p3.p[k].coeff=p[i].coeff+p2.p[j].coeff;
p3.p[k].exp=p[i].exp;
i++;
j++;
}
k++;
}
while(i<n)
{
p3.p[k]=p[i];
i++;
k++;
}
while(j<p2.n)
{
p3.p[k]=p2.p[j];
j++;
k++;
}
p3.n=k;
return p3;
}

void polynomial::multiply(int A[], int B[], int m, int n)
{
   int *prod = new int[m+n-1]; 
  
   // Initialize the porduct polynomial 
   for (int i = 0; i<m+n-1; i++) 
     prod[i] = 0; 
  
   // Multiply two polynomials term by term 
  
   // Take ever term of first polynomial 
   for (int i=0; i<m; i++) 
   { 
     // Multiply the current term of first polynomial 
     // with every term of second polynomial. 
     for (int j=0; j<n; j++) 
         prod[i+j] += A[i]*B[j]; 
   } 
  
   return prod; 
} 


int main()
{
      polynomial p1,p2,p3;
      cout<<”\n Enter the no of terms in 1st polynomial:”;
      cin>>p1.n;
      p1.read();
      cout<<”\n Enter the no of terms in 2nd polynomial:”;
      cin>>p2.n;
      p2.read();
      cout<<”\n 1st polynomial is:\n”;
      p1.display();
      cout<<”\n 2nd polynomial is:\n”;
      p2.display();
      p3=p1+p2;
      cout<<”\n Resultant polynomial is:”;
      p3.display();
      int A[] = {5, 0, 10, 6}; 
    int B[] = {1, 2, 4}; 
    int m = sizeof(A)/sizeof(A[0]); 
    int n = sizeof(B)/sizeof(B[0]); 
  
    cout << "First polynomial is n"; 
    printPoly(A, m); 
    cout << "nSecond polynomial is n"; 
    printPoly(B, n); 
  
    int *prod = multiply(A, B, m, n); 
  
    cout << "nProduct polynomial is n"; 
    p3.display();

	return 0;
}


/*
***************************************************


OUTPUT

Enter the no of terms in 1st polynomial:3

Enter the coefficient & exponents:5
5

Enter the coefficient & exponents:7
3

Enter the coefficient & exponents:6
2

Enter the no of terms in 2nd polynomial:2

Enter the coefficient & exponents:6
5

Enter the coefficient & exponents:3
2

1st polynomial is:
5 x^ 5 + 7 x^ 3 +6 x^ 2

2nd polynomial is:
6 x^ 5 + 3 x^ 2

Resultant polynomial is:11 x^ 5 + 7 x^ 3 + 9 x^ 2

First polynomial is 
5+0x^1+10x^2+6x^3

Second polynomial is 
1+2x^1+4x^2

Product of polynomial is
5+10x^1+30x^2+26x^3+52x^4+24x^5

*/