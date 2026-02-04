#include <iostream>
#include <vector>
using namespace std;

vector<int> add(vector<int>&A,vector<int>&B)
{
	vector<int>c;
	int t=0;
	for(int i=0;i<A.size()||i<B.size();i++)
	{
		//int t=0;
		if(i<A.size())t+=A[i];
		if(i<B.size())t+=B[i];
		c.push_back(t%10);
		t/=10;
	}
	if(t)c.push_back(1);
	return c;
} 
int main()
{
	string a,b;
	vector<int>A,B;
	cin>>a>>b;

	for(int i=a.size()-1;i>=0;i--)
	{
		//cout<<(int)a[i]<<' '<<a[i]<<' '<<(int)'0'<<' '<<a[i]-'0'<<endl;
		A.push_back(a[i]-'0');
	}
	hjty
	for(int i=b.size()-1;i>=0;i--)
	{
		B.push_back(b[i]-'0');
	}
	vector<int> c=add(A,B);
	for(int i=c.size()-1;i>=0;i--)cout<<c[i];
	
	
}
