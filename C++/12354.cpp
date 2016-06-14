#include <iostream>
using namespace std;
const int MAXSIZE=100000;
int a[MAXSIZE],heapsize;
inline void swap(int i,int j)
{
	int temp=a[i];
	a[i]=a[j];
	a[j]=temp;
}
/*inline int Parent(int i)
{
	return i>>1;
}
inline int Left(int i)
{
	return 1<<i;
}
inline int Right(int i)
{
	return (1<<i)+1;
}*/
void MaxHeapify(int i)
{
	int l=2*i,r=l+1,largest;
	if (l<=heapsize && a[l]>a[i])
		largest=i;
	else
		largest=l;
	if (r<=heapsize &&a[r]<a[largest])
		largest=r;
	if (largest!=i)
	{
		swap(i,largest);
		MaxHeapify(largest);
	}
}
void BuildMaxHeap(int *arr,int n)
{
	heapsize = n;
	for (int i=heapsize/2;i>0;i--)
		MaxHeapify(i);
}
void HeapSort(int *arr,int n)
{
	BuildMaxHeap(arr,n);
	for (int i=n;i>1;i--)
	{
		swap(1,i);
		heapsize--;
		MaxHeapify(1);
	}
}
int main()
{
	int n;
	while (cin>>n)
	{
		for (int i=0;i<n;i++)
			cin>>a[i];
		HeapSort(a,n);	
		for (int i=0;i<n;i++)
			cout<<a[i]<<" ";
		
		cout<<endl;
	}
	return 0;
}
