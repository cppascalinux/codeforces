#include<bits/stdc++.h>
using namespace std;
int n,k;
int tmp1[100009],tmp2[100009];
int ask(int x)
{
	printf("%d\n",x);
	fflush(stdout);
	scanf("%d",&x);
	return x;
}
int add(int a,int b)
{
	int tp=30;
	for(int i=1;i<=tp;i++)
	{
		tmp1[i]=a%k,a/=k;
		tmp2[i]=b%k,b/=k;
	}
	int ans=0;
	for(int i=tp;i>=1;i--)
		ans=ans*k+(tmp1[i]+tmp2[i])%k;
	return ans;
}
int sub(int a,int b)
{
	int tp=30;
	for(int i=1;i<=tp;i++)
	{
		tmp1[i]=a%k,a/=k;
		tmp2[i]=b%k,b/=k;
	}
	int ans=0;
	for(int i=tp;i>=1;i--)
		ans=ans*k+(tmp1[i]-tmp2[i]+k)%k;
	return ans;
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&k);
		int cur=0,mul=1;
		for(int i=0;i<=n-1;i++)
		{
			int qry=cur;
			if(mul)
				qry=add(qry,i);
			else
				qry=sub(qry,i);
			if(ask(qry))
				break;
			mul^=1;
			cur=sub(qry,cur);
		}
	}
	return 0;
}