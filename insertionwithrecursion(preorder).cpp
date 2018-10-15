#include<iostream>
#include<conio.h>
using namespace std;
struct node{
	int data;
	node *left,*right;
};
class tree{
	public:
		node *root;
	tree(){
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
	void preorder(node *t)
	{
		if(t==NULL)
		cout<<"tree is empty";
		cout<<t->data<<endl;
		if(t->left)
		preorder(t->left);
		if(t->right)
		preorder(t->right);
	}
};

	int main()
	{
	tree obj;
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
		obj.insert(obj.root,temp);
	}
	
	cout<<"final tree"<<endl;
	obj.preorder(obj.root);
	getch();
	return 0;
}
