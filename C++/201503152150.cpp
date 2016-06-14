#include <iostream>
using namespace std;
struct Node{
	int data;
	Node *next;

};
/**/
struct List{
	Node *head;
	int size;
};
List CreatListOfNull(){	//creat a null list
	List list;
	list.head=NULL;
	list.size=0;
	return list;
}
List CreatList(const int a[],int n){	// creat a list
	List list =  CreatListOfNull();
	Node *p1,*p2;
	for (int i=0;i<n;i++){
		p1=new Node();
		p1->data=a[i];
		p1->next=NULL;
		if (list.head==NULL)
			list.head=p1;
		else
			p2->next=p1;
		p2=p1;
	}
	list.size = n;
	return list;
}
void Delete(List &list,int x){	// delete data x
	Node *q=list.head;
	Node *p=q;
	int flag=0;
	while (q!=NULL){
		if (q->data==x){
			p=q->next;
			delete q;
			flag=1;
			cout<<"Delete data x successful!"<<endl;
			break;	
		}
		else{
			q=q->next;
			p=q;
		}		
	}
	if (flag==0)
		cout<<"Not found! x is not exist!"<<endl;
}
int main(){
	int n,x,a[100];
	while (cin>>n){
		for (int i=0;i<n;i++){
			cin>>a[i];
		}
		List list = CreatList(a,n);
		cin>>x;
		Delete(list,x);
	}
	
	return 0;
}
