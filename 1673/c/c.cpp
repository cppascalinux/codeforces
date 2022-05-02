#include<bits/stdc++.h>
using namespace std;
const int mod=1000000007;
int n,m=40000;
int f[40009],is[40009];
int tst(int x)
{
	int s[10],tp=0;
	while(x)
	{
		s[++tp]=x%10;
		x/=10;
	}
	for(int i=1;i<=tp;i++)
		if(s[i]!=s[tp-i+1])
			return 0;
	return 1;
}
int main()
{
	int tt;
	scanf("%d",&tt);
	f[0]=1;
	for(int i=1;i<=m;i++)
		if(tst(i))
		{
			// printf("i:%d\n",i);
			for(int j=i;j<=m;j++)
				(f[j]+=f[j-i])%=mod;
		}
	while(tt--)
	{
		scanf("%d",&n);
		printf("%d\n",f[n]);
	}
	return 0;
}