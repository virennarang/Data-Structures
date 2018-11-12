#include<iostream>
#include<string.h>
using namespace std;

char prec(int x)
{
	if(x==1)
		return '+';
	else if(x==2)
		return '-';
	else if(x==3)
		return '*';
	else if(x==4)
		return '/';
	else if(x==5)
		return '^';
	else if(x==0)
		return '(';
}


int main()
{
	cout<<"Enter the expression to be converted:";
	string s;
	cin>>s;
	cout<<s;
	int arr[10];
	int top=-1,b;
	string ans="";
	for(int i=0;i<s.length();i++)
	{
		if(s[i]=='(')
		{
			arr[++top]=0;
			b=top;
		}
		else if(s[i]=='+')
		{
				if(arr[top]>1)
				{
					char c=prec(arr[top]);
					ans+=c;
					arr[top]=1;
				}
				else
				{
					arr[++top]=1;			
				}
				
		}
			
		else if(s[i]=='-')
			{
				if(arr[top]>2)
				{
						char c=prec(arr[top]);
						ans+=c;
						arr[top]=2;
				}
				else
				{
					arr[++top]=2;					
				}
			}
			
		else if(s[i]=='*')
			{
				if(arr[top]>3)
				{
					char c=prec(arr[top]);
					ans+=c;
					arr[top]=3;
				}
				else
				{
					arr[++top]=3;					
				}
			}
			
		else if(s[i]=='/')
			{
				if(arr[top]>4)
				{
					char c=prec(arr[top]);
					ans+=c;
					arr[top]=4;
				}
				else
				{
					arr[++top]=4;					
				}
			}
			
		else if(s[i]=='^')
			{
				if(arr[top]>5)
				{
					char c=prec(arr[top]);
					ans+=c;
					arr[top]=5;
				}
				else
				{
					arr[++top]=5;					
				}
			}
			
		else if(s[i]==')')
			{
				for(int i=top;i>b;i--)
				{
					char c=prec(arr[i]);
					ans+=c;
					top--;
				}
				top--;
			}
			
		else
			{
				ans+=s[i];
			}
	}
	
	
	
	
	for(int i=top;i>=0;i--)
	{
			char c=prec(arr[i]);
			ans+=c;
	}
	cout<<endl<<ans;
}
