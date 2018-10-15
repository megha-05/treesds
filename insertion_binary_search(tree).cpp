#include<iostream>
#include<conio.h>
using namespace std;
class binary{
	int tree[40]={-1},t=1;
	public:
		binary(){
			for(int i=0;i<40;i++){
				tree[i]=-1;
			}
			t=1;
		}
		void insert(int ,int);
		int search(int,int);
		void display();
};
void binary::insert(int s,int num){
	int x;
	if(t==1){
		tree[t]=num;
		t++;
		return ;
	}
	x=search(s,num);
	if(tree[x]>num)
		tree[2*x]=num;
	else
		tree[2*x+1]=num;
	t++;
}
int binary:: search(int s,int num){
	if(t==1){
		cout<<"no element in tree"<<endl;
		return -1;
	}
	if(tree[s]==-1)
		return s/2;
	if(tree[s]>num)
		search(2*s,num);
	else
		search(2*s+1,num);
}
void binary::display()
{
	for(int i=0;i<40;i++){
		if(tree[i]==-1)
			cout<<" ";
		else
			cout<<tree[i]<<" ";
	}
}
int main(){
	binary b;
	int s,num,val;
	cout<<"enter elements"<<endl;
	cin>>val;
	for(int i=0;i<val;i++){
		cin>>num;
		b.insert(1,num);
	}
	b.display();
	getch();
	return 0;
}
