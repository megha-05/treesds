#include<iostream>
#include<conio.h>
using namespace std;
struct node{
	int data;
	node *left,*right;
};
class tree1{
	public:
		node *root;
	tree1(){
		root=NULL;
		
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
	void postorder(node *t)
	{
		if(t==NULL)
		cout<<"tree is empty";
		if(t->left)
		postorder(t->left);
		if(t->right)
		postorder(t->right);
		cout<<t->data<<endl;
	}
};
		int main()
	{
	tree1 t;
	int n,i;
	cout<<"enter range"<<endl;
	cin>>n;
	
	cout<<"enter values"<<endl;
	for(int j=1;j<=n;j++)
	{
		cin>>i;
	
	node *temp=new node;
	temp->data=i;
	temp->left=NULL;
	temp->right=NULL;
		t.insert(t.root,temp);
	}
	
	cout<<"final tree"<<endl;
	t.postorder(t.root);
	getch();
	return 0;
}
