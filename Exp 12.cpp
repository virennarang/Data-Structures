#include<iostream>
#include<algorithm>
#include<stack>
using namespace std;
class heaps
{
int *arr;
int n,left,right,largest;
public:
	heaps()
    {
        n=0,left=0,right=0,largest=0;
		cout<<"Enter the no of elements\n";
		cin>>n;
		arr=new int[n];
		cout<<"Enter the elements\n";
		for(int i=1;i<=n;i++)
        {
			cin>>arr[i];
        }
    }
    void max_heapify(int arr[],int k)
    {
        left=2*k;
        right=2*k +1;
        if(left<=n&&arr[left]>arr[k])
        {
            largest=left;
        }
        else
            largest=k;
        if(right<=n&&arr[right]>arr[largest])
        {
            largest=right;
        }
        if(largest!=k)
        {
            swap(arr[largest],arr[k]);
			max_heapify(arr,largest);
        }
    }
    void create_heap()
    {
		for(int i=n/2; i>=1; i--)
        {
			max_heapify(arr,i);
        }
    }

    void display()
    {
		cout<<"The heap is:\n";
		for(int i=1;i<=n;i++)
		cout<<arr[i]<<"\t";
    }

    void insert_ele()
    {
		int key=0,i=0;
		cout<<"Enter the element to be inserted\n";
		cin>>key;
        n=n+1;
		arr[n]=key;
		i=n;
        while(i>1&&arr[i]>arr[i/2])
        {
            swap(arr[i],arr[i/2]);
			i/=2;
        }
    }

    void heap_sort()
    {
        stack<int>s;
        while(n>0)
        {
			// cout<<arr[1]<<" ";
			s.push(arr[1]);
			arr[1]=arr[n];
            n=n-1;
            if(n==0)
            	break;
			max_heapify(arr,1);
        }
		cout<<"The sorted output is:\n";
        while(!s.empty())
        {
			cout<<s.top()<<" ";
			s.pop();
    	}
    }
};
int main()
{
    heaps h;
	h.create_heap();
	h.heap_sort();
	h.display();
}

