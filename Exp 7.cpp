#include<iostream>
using namespace std;
class queue
{
	int rear;
	int front;
	int data;
	int size;
	int *a;
	public:
		queue()
		{
			cout<<"enter size"<<endl;
			cin>>size;
			a=new int[size];
			rear=-1;
			front=-1;
		}
		int empty()
		{
			if(front==-1 && rear==-1)
			{
				return 1;
			}
			else
			return 0;
		}
		int full()
		{
			if(rear==(size-1) && front==0)
			return 1;
			else
			return 0;
		}
		void enque(int data)
		{
			if(full()||rear==front-1)
			{
				cout<<"overflow"<<endl;
			}
			else if(empty())
			{
				front++;
				rear++;
				a[rear]=data;	
			} 
			else if(rear==size-1)
			{
				rear=0;
				a[rear]=data;
			}
			else
			{
				rear=rear+1;
				a[rear]=data;  
			}
		}
		void dequeue()
		{
			int t;
			if(empty())
			{
				cout<<"underflow"<<endl;
			}
			else if(front==rear)
			{
				front=-1;
				rear=-1;
				//cout<<"queue is empty"<<endl;
			}
			else if(front==size-1 && rear<front)
			{
				front=0;
			}
			else
			{
				t=a[front];
				front=front+1;
			}
		}
		void print()
		{
			if(empty())
			{
				cout<<"queue is empty"<<endl;
			}
			else if(rear<front)
			{
				rear=0;
				for(int i=rear;i<=front;i++)
				{
					cout<<a[i]<<" ";
				}
				cout<<endl;
		}
		else
		{
			for(int i=front;i<=rear;i++)
			{
				cout<<a[i]<<" ";
			}
			cout<<endl;
		}
		}
};
int main()
{
	queue obj;
	int x;
	int m;
	int n;
	while(1)
	{
		cout<<"1. To enter"<<endl<<"2. To delete"<<endl<<"3. To print"<<endl;
		cin>>x;
		switch(x){
			case(1):
				cout<<"enter data"<<endl;
				cin>>m;
			obj.enque(m);
			     break;
			case(2):
				obj.dequeue();
				break;
			case(3):
				obj.print();
				break;
		}
	}
}

