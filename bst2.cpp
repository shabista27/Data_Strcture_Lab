/*ASSIGNMENT NO-2 
Beginning with an empty binary search tree, Construct binary search tree by inserting the values in the order given.
After constructing a binary tree 
i.insert new node
ii.Find number of nodes in longest path 
iii.Minimum data value found in the tree 
iv.Change a tree so that the roles of the left and right pointers are swapped at every node v.Seach tree 
 
*/
 
  #include<iostream> 
  #include<cstdlib>  
  using namespace std; 
 
    class node 
    { 
    public:   
	  int data;     
	  node *lchild,*rchild;    
	 node(); 
    }; 
 

    node::node() 
    { 
    lchild=rchild=NULL; 
    } 
 
    class BST 
    { 
    node *root;
     
	public: 
 
    BST() 
    { 
    root=NULL; 
    } 

    void create(); 
    void Inorder(node *); 
 
    void Smallest(); 
 
    int Height(node *);   
    void search(node *,int);  
    node* getroot(); 
    node* mirror(node *); 
    }; 
 
    node* BST::getroot() 
    { 
    return root; 
    } 
 
    void BST::create() 
        { 
        char ans; 
        node *temp; 
 
 
 
        do 
        { 
        temp=new node();        
        cout<<"Enter data:";      
	cin>>temp->data; 
 
        if(root==NULL) 
        { 
        root=temp; 
        }        
	 else 
        { 
        node *trav,*parent;     
        trav=root; 
        parent=trav; 
 
 
        while(trav!=NULL) 
        { 
        if(temp->data<trav->data) 
        { 
        parent=trav; 
        trav=trav->lchild; 
        }        
	 else 
        { 
        parent=trav; 
        trav=trav->rchild; 
            } 

        } 
 
        if(temp->data<parent->data) 
        { 
        parent->lchild=temp; 
        }       
	  else 
        { 
        parent->rchild=temp; 
        } 
 
        }
	cout<<"ADD ANOTHER..(y/n)";    
	cin>>ans;        
      }
       while(ans=='y'||ans=='Y'); 
 
        } 
 
    void BST::Inorder(node *n) 
    { 
    if(n!=NULL) 
    { 
    Inorder(n->lchild);   
    cout<<endl<<n->data<<" "; 
    Inorder(n->rchild); 
 
    } 
 
    } 
 
    void BST::Smallest() 
    { 
    node *temp;   
    temp=root; 
 
    while(temp->lchild!=NULL) 
    { 
    temp=temp->lchild; 
    } 
    cout<<"The Smallest element is:"<<temp->data<<""; 
 
 
    } 
 
    int BST::Height(node *n) 
    { 
    if(n==NULL) 
    { 
    return 0; 
    } 
 
    int lheight=Height(n->lchild); 
    int rheight=Height(n->rchild); 
 
    if(lheight>rheight)    
	 return (1+lheight);  
    else 
   	 return (1+rheight); 
    } 
 
    void BST::search(node *n,int temp) 
    { 
 
    if(n!=NULL) 
    { 
 
    if(temp < n->data) 
    { 
    search(n->lchild,temp); 
    } 
    else if(temp > n->data) 
    { 
    search(n->rchild,temp); 
    }  
    else 
    { 
    cout<<endl<<"Entered element found."; 
    } 
    }     
    else 
    { 
    cout<<endl<<"Element not Found...!"; 
    } 
 
    } 
 
    node *BST::mirror(node *n) 
    { 
    if(n==NULL) 
    { 
    return 0; 
    }     
     else 
    { 
    node *temp;     
    mirror(n->lchild);     
    mirror(n->rchild); 
 
    temp=n->lchild;    
    n->lchild=n->rchild;
    n->rchild=temp; 
 
    return n;
} 
    } 
 
    int main() 
    { 
            BST s;            
	    int ch,a,temp; 
            cout<<"\n**********TREE***********"; 
            cout<<endl<<"CREATING A TREE "<<endl; 
            s.create(); 
 
            while(1) 
            {             
		cout<<endl<<"*****************\n1.INSERT\n2.NUMBERS OF NODES IN LONGEST PATH\n3.MINIMUM DATA VALUE IN A 			TREE\n4.SWAPPING\n5.SEARCH\n" 
	              	"7.DISPLAY\n8.EXIT **************"<<endl 
                        <<"ENTER YOUR CHOICE: ";        
	        cin>>ch; 
 
            switch(ch) 
            { 
 
            case 1: 
                        cout<<endl<<"\nFOR INSERTION"<<endl; 
                        s.create();                        
			break; 
 
            case 2:
			a=s.Height(s.getroot()); 
                  	cout<<endl<<"Longest path is of "<<a<<" nodes"<<endl;                    
			break; 
 
 
            case 3:
			s.Smallest(); 
          		break; 
 
 
            case 4:
			s.mirror(s.getroot());             
			s.Inorder(s.getroot()); 
            		break; 
 
 
            case 5:
			cout<<endl<<"Enter element to search:";             
			cin>>temp; 
            		s.search(s.getroot(),temp); 
            		break; 
 
            case 7: 
                	cout<<endl<<"Displaying in inorder: ";                 
			s.Inorder(s.getroot()); 
              		break; 
 
            case 8:                
			 exit(0); 
                	 break; 
            } 
 
            } 
 
 
 
 
        return 0; 
    } 
