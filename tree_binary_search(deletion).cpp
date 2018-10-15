#include<iostream>
#include<conio.h>
using namespace std;
struct node{
	int data;
	node *left,*right;
};
struct node1{
	node *t;
	node1 *next;
};
class tree1{
	public:
		node1 *top;
		node *root;
		
		tree1(){
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
		if(top==NULL){
			cout<<"underflow"<<endl;
		}
		else{
			temp=top;
			top=top->next;
			
		}
		return temp;
	}
	
	void insert(node *root1,node *newnode){
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
	
	node* min_val_node(node *node1){
	node *current=node1;
	while(current->left!=NULL)
		current=current->left;
	return current;
}


	struct node* deletee(node *root,int key){       
	if(root==NULL)                               
		return NULL;                              
	if(key<root->data)                              
		root->left=deletee(root->left,key);  
	else if(key>root->data)
		root->right=deletee(root->right,key);
	else{
		if(root->right==NULL && root->left==NULL){
			delete root;
			root=NULL;
		}
		else if(root->right==NULL){
			node *temp=root;
			root=root->left;
			delete temp;
		}
		else if(root->left==NULL){
		node *temp=root;
		root=root->right;
		delete temp;
		}
		else{
			node *temp=min_val_node(root->right);
			root->data=temp->data;
			root->right=deletee(root->right,temp->data);
		}
	}	
	return root;
}

	void inorder(node *root1){          
		if(root1==NULL)
			return;
		node *curr=root1;
		while(curr!=NULL || top!=NULL){
			while(curr!=NULL){
				push(curr);
				curr=curr->left;
			}
			curr=pop()->t;
			cout<<curr->data<<" ";
		
			curr=curr->right;
		}
	}
};
int main(){
	tree1 t;
	int n,i,key;
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
		t.insert(t.root,temp);
	}
	cout<<"enter the key"<<endl;
	cin>>key;
	node *temp=	t.deletee(t.root,key);
	cout<<"final tree"<<endl;
	t.inorder(t.root);
	getch();
	return 0;
}
