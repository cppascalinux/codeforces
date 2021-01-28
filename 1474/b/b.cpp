#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;
int n,m=1000000,tot;
int vis[1000009],pm[100009];
void init()
{
	for(int i=2;i<=m;i++)
	{
		if(!vis[i])
			pm[++tot]=i;
		for(int j=1;j<=tot&&i*pm[j]<=m;j++)
		{
			vis[i*pm[j]]=1;
			if(i%pm[j]==0)
				break;
		}
	}
	// for(int i=1;i<=10;i++)
	// 	printf("i:%d pm:%d\n",i,pm[i]);
}
int main()
{
	init();
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		// printf("n:%d\n",n);
		int p1=0,p2=0;
		p1=*lower_bound(pm+1,pm+tot+1,1+n);
		p2=*lower_bound(pm+1,pm+tot+1,p1+n);
		// printf("p1:%d p2:%d\n",p1,p22);
		printf("%I64d\n",(ll)p1*p2);
	}
	return 0;
}