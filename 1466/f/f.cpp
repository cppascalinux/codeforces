#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define ll long long
#define mod 1000000007
using namespace std;
int n,m;
int f[500009],sm[500009];
int used[500009];
int fnd(int x)
{
	return x==f[x]?x:f[x]=fnd(f[x]);
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
		f[i]=i;
	int tl=0;
	for(int i=1;i<=n;i++)
	{
		int k,a,b;
		scanf("%d%d",&k,&a);
		if(k==1)
		{
			int ta=fnd(a);
			if(sm[ta])
				continue;
			sm[ta]++;
			used[i]=1;
			tl++;
			continue;
		}
		scanf("%d",&b);
		int ta=fnd(a),tb=fnd(b);
		// printf("ta:%d sma:%d tb:%d smb:%d\n",ta,sm[ta],tb,sm[tb]);
		if(ta==tb)
			continue;
		if(sm[ta]+sm[tb]>=2)
			continue;
		f[ta]=tb,sm[tb]+=sm[ta];
		tl++;
		used[i]=1;
	}
	int ans=1;
	for(int i=1;i<=tl;i++)
		(ans*=2)%=mod;
	printf("%d %d\n",ans,tl);
	for(int i=1;i<=n;i++)
		if(used[i])
			printf("%d ",i);
	return 0;
}