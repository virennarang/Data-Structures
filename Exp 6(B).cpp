#include<iostream>
#include<string.h>
using namespace std;
int main()
{
	cout<<"Enter the postfix expression to be solved:";
	string s;
	cin>>s;
	int top=-1;
	int z=0;
	int arr[10];
	for(int i=0;i<s.length();i++)
	{
		if(s[i]>='0' && s[i]<='9')
		{
			arr[++top]=(int)(s[i]);	
		}
		else
		{
			switch(s[i])
			{
				case '+':
					{
						int a=(int)(arr[top]-48);
						int b=(int)(arr[top-1]-48);
						cout<<a<<b;
						top-=1;
						int z=a+b;
						arr[top]=z;
						break;
					}

				case '-':
					{
						int a=arr[top];
						int b=arr[top-1];
						top-=1;
						int z=b-a;
						arr[top]=z;
						break;
					}
					
				case '*':
					{
						int a=arr[top];
						int b=arr[top-1];
						top-=1;
						int z=a*b;
						arr[top]=z;
						break;
					}
				
				case '/':
					{
						int a=arr[top];
						int b=arr[top-1];
						top-=1;
						int z=b/a;
						arr[top]=z;
						break;
					}
				
				case '^':
					{
						int a=arr[top];
						int b=arr[top-1];
						cout<<a<<" "<<b;
						top-=1;
						int z=b^a;
						arr[top]=z;
						break;
					}		
				
			}
			
		}
	}
	
	cout<<endl<<arr[top];
	
}
