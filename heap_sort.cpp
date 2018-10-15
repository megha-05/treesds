#include<iostream>
using namespace std;
int i;
void max_heapify(int a[],int i,int n){
	int j,temp;
	temp=a[i];
	j=2*i;
	while(j<=n){
		if((j<n)&&(a[j]<a[j+1]))
			j=j+1;
		if(temp>a[j])
			break;
		else if(temp<=a[j]){
			a[j/2]=a[j];
			j=j*2;
		}
	}
		a[j/2]=temp;
		return ;
}
void build_max_heap(int a[],int n){
	for(i=n/2;i>=1;i--){
		max_heapify(a,i,n);
	}
}
void heap_sort(int a[],int n){
	int temp;
	for(i=n;i>=2;i--){
		temp=a[i];
		a[i]=a[1];
		a[1]=temp;
		max_heapify(a,1,i-1);
	}	
}
int main(){
	int a[100],n;
	cout<<"enter number of elements"<<endl;
	cin>>n;
	cout<<"enter array elements"<<endl;
	for(i=1;i<=n;i++){
		cin>>a[i];
	}
	build_max_heap(a,n);
	heap_sort(a,n);
	cout<<"final array"<<"  ";
	for(i=1;i<=n;i++){
		cout<<a[i]<<endl;
	}
	return 0;
}
