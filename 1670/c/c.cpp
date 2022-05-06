#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int mod=1000000007;
int n;
int sa[100009],sb[100009];
int sd[100009];
int p[100009],f[100009],mk[100009],sz[100009];
int fnd(int x)
{
	return x==f[x]?x:(f[x]=fnd(f[x]));
}
int main()
{
	int tt;
	scanf("%d",&tt);
	while(tt--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			f[i]=i,mk[i]=sz[i]=0;
		for(int i=1;i<=n;i++)
			scanf("%d",sa+i);
		for(int i=1;i<=n;i++)
			scanf("%d",sb+i),p[sa[i]]=sb[i];
		for(int i=1;i<=n;i++)
			f[fnd(i)]=fnd(p[i]);
		for(int i=1;i<=n;i++)
			sz[fnd(i)]++;
		for(int i=1;i<=n;i++)
		{
			scanf("%d",sd+i);
			if(sd[i])
				mk[fnd(sa[i])]=1;
		}
		int ans=1;
		for(int i=1;i<=n;i++)
			if(i==fnd(i)&&!mk[i]&&sz[i]>1)
				ans=ans*2%mod;
		printf("%d\n",ans);
	}
	return 0;
}