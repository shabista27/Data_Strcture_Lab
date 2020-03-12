/*

There are flight paths between cities. If there is a flight between city A and city B then there is an edge between the cities. 
The cost of the edge can be the time that flight takes to reach city B from A, or the amount of fuel used for the journey. 
Represent this as a graph.
 The node can be represented by airport name or name of the city.
 Use adjacency list representation of the graph or use adjacency matrix representation of the graph. 
Justify the storage representation used.  

*/


#include<iostream> 
#define MAX 10 using namespace std; 
 
class airport 
{ 
    string city[MAX];   
    int distance[10][10]; 
 
    public :  
     int n; 
     airport();  
     void input_g(); 
    void output_g(); 
}; 
 
 
airport :: airport() 
{
    n = 0; 
    for(int i=0 ; i<MAX ; i++) 
    { 
        for(int j=0 ; j<MAX ; j++) 
            distance[i][j] = 0; 
    } 
} 
 
 
void airport :: input_g() 
{ 
    int k;
    cout << "\nEnter the no. of cities: " ;
    cin >> n; 
 
 
for(int k=0;k<n;k++) 
{ 
    cout<<"Enter "<<k+1<<"  city name:";   
    cin>>city[k]; 
}
 
 
for(int i=0 ; i<n ; i++) 
{   
   for(int j=i+1 ; j<n ; j++) 
    { 
        cout << "\nEnter Distance between " <<city[i]<< "  to  " 
		<<city[j]<<":\n";         cin >> distance[i][j]; 

        distance[j][i] = distance[i][j]; 

    } } 
} 
 
 
void airport :: output_g() 
{ 
    cout<<"  "; 
 
    for(int k=0;k<n;k++) 
    { 
        cout<<city[k]<<" ";   
    }

	 cout<<"Enter city name:";  
  	 cout << "\n"; 

 
    for(int i=0 ; i<n ; i++) 
	{      
  	 cout <<city[i] <<" "; 
 
        for(int j=0 ; j<n ; j++) 
        { 
            cout<<"   "<< distance[i][j] ; 
        } 
     	   cout << "  ";     
	    cout << "\n"; }
}
 
 
int main() 
{ 
    airport obj;   
    obj.input_g();   
    obj.output_g();
}  
