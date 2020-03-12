/* 
 Write a function to get the number of vertices in an undirected graph  and its edges. 
 You may assume that no edge is input twice. 
 Use adjacency matrix representation of the graph and find runtime of the function  	 
*/

 
#include <iostream> 
#include <cstdlib> 
#include<stdlib.h> 
#include<list> 
using namespace std; 
 
 
int visited[20],visit[20],stk[20],top=0,qu[12],front,rear; 
 

/* Adjacency List Node */ 
struct AdjListNode 
{ 
    int dest; 
    struct AdjListNode* next; 
}; 
 
 
/*  Adjacency List */ struct AdjList 
{    
 struct AdjListNode *head; 
}; 
 
 
/* Class Graph */ class Graph 
{ 
    private:        

	int V,k; 
        struct AdjList* array;     
        int adjM[10][10]; 
        list<int>* adj; 
 
    public: 

        Graph(int V) 
        { 
            this->V = V; 
            array = new AdjList [V]; 
            for (int i=1;i<=V; ++i) 
            { 
                array[i].head = NULL;   //In Adjacency list all vertices initially null 

                for(int j=1; j<=V; ++j) 
                { 
                adjM[i][j]=0;   //nXn all values initially zero 
                } 
            } 
            adj = new list<int>[V];    
    
            for (int i=1; i<=V; ++i)           
       		 visited[i]=0; 
        } 
 
        /* Creating New Adjacency List Node  */ 
 
        AdjListNode* newAdjListNode(int dest) 
        { 
            AdjListNode* newNode = new AdjListNode; 
            newNode->dest = dest;       
	    newNode->next = NULL; 
            return newNode; 
        }  
        /*Add Edge to Graph */ 
 
   void addEdge() 
        { 
            int src,des; 
            cout<<"\n Enter Edge ";      
	    cout<<"\n From -> ";     
            cin>>src;       
            cout<<"\n To -> ";      
            cin>>des; 
            adjM[src][des]=1;           //value changes in matrix example src is 1 and dest is 0 so [1,0]=1 
            adjM[des][src]=1;           //opposite [0,1]=1         
            adj[src].push_back(des);// update adjlist  ex 1->0         
	    adj[des].push_back(src);//update 0->1       
	    AdjListNode* newNode = newAdjListNode(des);       
	    newNode->next = array[src].head;      
 	    array[src].head = newNode;       
	    newNode = newAdjListNode(src);     
	    newNode->next = array[des].head; 
            array[des].head = newNode; 
        }  


/* Print the graph*/ 
 
  void printGraph() 
        {           
	 int v; 
        cout<<"\n Adjucency Matrix is : \n ";   

	for (int i=1; i<=V; ++i) 
        { 
           for(int j=1; j<=V; ++j) 
            { 
               cout<<adjM[i][j]<<" "; 
            } 

        cout<<"\n"; 
        } 


            for (v=1; v<=V;++v) 
            { 
                AdjListNode* p = array[v].head; 
                cout<<"\n Adjacency list of vertex "<<v<<"\n head ";   

	        while(p) 
                { 
                   cout<<"-> "<<p->dest;            
		   p = p->next; 
                } 
               cout<<endl; 
            } 
        }  
}; 
 
 
/* * Main */ 
 
int main() 
{ 
    int ver,ed,ch,i,j,s; 
    cout<<"Enter Count of No of Vertices"; 
    cin>>ver; 
 
    cout<<"Enter Count of No of Egdes";   
    cin>>ed;   


    Graph gh(ed); 
    do 
    { 
    cout<<"\n Select option :"; 
    cout<<"\n\t 1. Create graph \n \t2.Display graph \n \t 3.Exit";   
    cin>>ch; 

    switch(ch) 
    { 
    case 1: 
    for(i=0;i<ed;i++)   
       gh.addEdge();  
       break;    
   
     case 2: 
        // print the adjacency list representation of the above graph       
        gh.printGraph();     
        break; 
 
    default : 
	cout<<"\n Enter correct choice"; 
     } 

    }while(ch!=3); 
 
    return 0; 
} 
 
