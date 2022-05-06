#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int mod=998244353;
int n,m,tp=0;
char s[270009];
int v[270009];
int solve(int d,int l)
{
	if(d==m)
		return 1;
	int ls=solve(d+1,l+1);
	int rs=solve(d+1,l+(1<<(m-d)));
	int df=0;
	for(int i=1;i<=(1<<(m-d))-1;i++)
		if(v[l+i]!=v[l+(1<<(m-d))-1+i])
		{
			df=(v[l+i]<v[l+(1<<(m-d))-1+i])?1:-1;
			break;
		}
	if(df==0)
		return (ll)ls*rs%mod;
	else
	{
		if(df==-1)
			for(int i=1;i<=(1<<(m-d))-1;i++)
				swap(v[l+i],v[l+(1<<(m-d))-1+i]);
		return (ll)ls*rs*2%mod;
	}
}
void rg(int d,int a)
{
	v[++tp]=s[a];
	if(d<m)
	{
		rg(d+1,a*2);
		rg(d+1,a*2+1);
	}
}
int main()
{
	scanf("%d",&m);
	n=(1<<m)-1;
	scanf("%s",s+1);
	rg(1,1);
	printf("%d",solve(1,1));
	return 0;
}