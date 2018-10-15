#include<iostream>
using namespace std;
struct node{
	int data;
	node *left,*right;
};
struct node1{
	node *t;
	node1 *next;
};
class tree{
	public:
		node1 *top;
		node *root;
		
		tree(){
			top=NULL;
			root=NULL;
		}
		
		void push(node *d){
		node1 *temp=new node1;
	    temp->t=d;
	    temp->next=NULL;
		if(top==NULL){
			top=temp;
		}
		else{
			temp->next=top;
			top=temp;
	}
	}
	
	
	node1* pop(){
		node1 *temp;
		
			temp=top;
			top=top->next;
		    return temp;
	}
	
	void insert(node *root1,node *newnode){
		//cout<<"Hello"<<endl;
		if(root1==NULL){
			root=newnode;
			return;
		}
		if((root1->data)>=(newnode->data)){
			if((root1->left)==NULL)
				root1->left=newnode;
			else
				insert((root1->left),newnode);
		}
		else{
			if((root1->right)==NULL)
				root1->right=newnode;
			else
				insert((root1->right),newnode);
		}
	}
	
	void postorder(node *root1){    
	   
		if(root1==NULL)
			return ;
		do{
			while(root1!=NULL){
			if(root1->right){
				push(root1->right);}
				push(root1);
				root1=root1->left;
			
		}
			root1=pop()->t;  
			        
			if((root1->right)!=NULL && (top->t)==root1->right)
			{
				pop(); 
				push(root1);
				root1=root1->right;
			}
			else{
				cout<<root1->data<<" ";
				root1=NULL;
			}
			}while(top!=NULL);
	}
};
int main(){
	tree obj;
	int n,i;
	cout<<"enter range"<<endl;
	cin>>n;
	
	cout<<"enter values"<<endl;

	for(int j=1;j<=n;j++)
	{
		cout<<"Enter element"<<endl;
		cin>>i;
	
	node *temp=new node;
	temp->data=i;
	temp->left=NULL;
	temp->right=NULL;
		obj.insert(obj.root,temp);
	}
	
	cout<<"final tree"<<endl;
	obj.postorder(obj.root);
	return 0;
}
