#include<iostream>
using namespace std;
class linkedlist
{
	int size;
	struct node
	{
		int info;
		struct node *next;
	};
	struct node *start=NULL;
	struct node *new_node;
	struct node *ptr;
	public:
		
		void create_ll()
		{
			cout<<"enter the size\n";
			cin>>size;
			cout<<"enter th elements in linked list\n";
			int num;
			for(int i=0;i<size;i++)
			{
			cin>>num;
			new_node=new node;
			new_node->info=	num;
			new_node->next=start;
			start=new_node;
			}
			
		}
		
		void insert_beg()
		{
		cout<<"enter the element that  you want to insert at beg\n";
		int ele;
		cin>>ele;
		new_node=new node;
		new_node->info=ele;
		new_node->next=start;
		  start=new_node;
		}
		void insert_end()
		{
			int ele;
			cout<<"enter the element that you want to  insert at the end\n";
			cin>>ele;
			ptr=start;
			while(ptr->next!=NULL)
			{
				ptr=ptr->next;
			}
			new_node=new node;
			new_node->info=ele;
			new_node->next=ptr->next;
			ptr->next=new_node;
		
		}
		void insert_after()
		{
			int ele,key;
			cout<<"Enter the element after which you want to insert an element\n";
			cin>>key;
			cout<<"Enter the element that you want to insert in the list\n";
			cin>>ele;
			ptr=start;
			while(ptr!=NULL)
			{
			   if(ptr->info==key)
			   {
				new_node=new node;
				new_node->info=ele;
				new_node->next=ptr->next;
				ptr->next=new_node;
			   }
			ptr=ptr->next;
		}
	}
	
	        void insert_before()
	        {
		struct node *save=NULL;
		int key,ele;
		cout<<"Enter the element that you want to insert before the given element\n";
		cin>>key;
		cout<<"enter the element you want to insert\n";
		cin>>ele;
		ptr=start;
		while(ptr!=NULL)
		{
		if(ptr->info==key)
		{
			 if(save==NULL)	
		 {
			insert_beg();
		 }
		 else
		 {
			new_node=new node;
			new_node->info=ele;
			new_node->next=save->next;
			save->next=new_node;
		 }
		}
		 save=ptr;
		ptr=ptr->next;
		}
		
	        }
	
		void deletion()
		{
			int ele;
			cout<<"Enter the element that you want to  delete\n";
			cin>>ele;
			struct node *save=NULL;
			ptr=start;
		while(ptr!=NULL)
			{
				if(ptr->info==ele)
				{
				save->next=ptr->next;
				delete ptr;
				break;	
				}
				save=ptr;
				ptr=ptr->next;
			}
		}
		void search()
		{
			int search;
			cout<<"enter the element that you want to search\n";
			cin>>search;
			int c=1,f=0;
			ptr=start;
			while(ptr!=NULL)
			{
				c++;
				if(ptr->info==search)
				{
					f=1;
					cout<<"found the element at "<<c;
				}
			}
			if(f==0)
			cout<<"element does not exist in list\n";
		}
		void show()
		{
		ptr=start;
		  while(ptr!=NULL)
		  {
			cout<<ptr->info<<endl;
			ptr=ptr->next;
		  }
			
		}		
		};
		
int main()
{
	linkedlist obj1;
	int ch=1;
		while(ch>=1 && ch<=8)
		{
			cout<<"Enter 1 to create linked list\n";
			cout<<"Enter 2 to insert at the beginning of the list\n";
			cout<<"Enter 3 to insert at the end of the list\n";
			cout<<"Enter 4 to insert after the given element in the lis\n";
			cout<<"Enter 5 to insert before the given element in the list\n";
			cout<<"Enter 6 to delete  the given element in the linked list\n";
			cout<<"Enter 7 to search the given element in the linked list\n";
			cout<<"Enter 8 to show the linked list\n";
			cout<<"Enter your choice !!!\n";
			cin>>ch;
			switch(ch)
			{
			   case 1:
			   obj1.create_ll();
			   break;
			
			   case 2:
			   obj1.insert_beg();
			   break;
			
			   case 3:
			   obj1.insert_end();
			   break;
			
			   case 4:
			   obj1.insert_after();
			   break;
			
			   case 5:
			   obj1.insert_before();
			   break;
			
			   case 6:
			   obj1.deletion();
			   break;			
			   case 7:
			   obj1.search();
			   break;
			   case 8:
			   obj1.show();
			   break;			
			   default:
			   cout<<"you have entered a wrong choice\n";
			   break;	
			}			
		}
}

