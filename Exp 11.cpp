#include<iostream>
using namespace std;
struct node
{
	public:
		int data;
		node* left;
		node* right;
		int value;
};
class binary_search_tree
{
	public:
    node* insertion(node *root,int key)
    {
       if(root==NULL)
        {
			node  *nn=new node;
			nn->data=key;
			nn->left=NULL;
			nn->right=NULL;
           	root=nn;
        }
        else if(key<root->data)
			root->left=insertion(root->left,key);
    	else if(key>root->data)
	root->right=insertion(root->right,key);
        return root;
    }

        void print_pre_order(node *t)
        {
            if(!t)
                return;
            else
            {
				cout<<t->data<<endl;
				print_pre_order(t->left);
				print_pre_order(t->right);

            }
        }
        
		void print_in_order(node *t)
        {
            if(!t)
                return;

            else
            {
				print_in_order(t->left);
				cout<<t->data<<endl;
				print_in_order(t->right);
            }
        }

        void print_post_order(node *t)
        {
            if(!t)
                return;

            else
            {
				print_post_order(t->left);
				print_post_order(t->right);
				cout<<t->data<<endl;
            }
        }

        node* deletenode(node *root,int value)
        {
                if(root==NULL)
					cout<<"Element not found:"<<endl;
                else if(root->data>value)
					root->left=deletenode(root->left,value);
                else if(root->data<value)
                    root->right=deletenode(root->right,value); 
                else
                {
                    if(root->left==NULL)
                    {
                        node* temp=root->right;
                        delete root;
                        return temp;
                    }
                    if(root->right==NULL)
                    {
                        node* temp=root->left;
                        delete root;
                        return temp;
                    }
                }
                return root;
        }
};
int main()
{
	binary_search_tree bst;
    node *root=NULL;
	int n,i;
	cout<<"Enter number of elements in array:"<<endl;
	cin>>n;
	int a[n];
	cout<<"Enter element you want in ll:"<<endl;
   	for(i=0;i<n;i++)
   	{
		int key;
		cin>>key;
       	root=bst.insertion(root,key);
   	}
	cout<<"output according to IN order is:"<<endl;
	bst.print_in_order(root);
	cout<<"output  according to POST order is:"<<endl;
	bst.print_post_order(root);
	cout<<"output according to PRE is:"<<endl;
	bst.print_pre_order(root);
	
	cout<<"Enter node you want to delete:"<<endl;
	cin>>n;
    node* y=bst.deletenode(root,n);
	cout<<"IN order output after deleting "<<endl;
	bst.print_in_order(y);
}

