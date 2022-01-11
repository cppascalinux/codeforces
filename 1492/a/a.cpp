#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		ll p,a,b,c;
		cin>>p>>a>>b>>c;
		ll t1=((p-1)/a+1)*a-p;
		ll t2=((p-1)/b+1)*b-p;
		ll t3=((p-1)/c+1)*c-p;
		cout<<min(t1,min(t2,t3))<<endl;
	}
	return 0;
}