#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int inf=1e9;
int n,d;
ll s[500009];
int f[500009];
int cl[500009],cg[500009],ce[500009];
void lsh()
{
	static ll v[500009];
	memcpy(v+1,s,sizeof(ll)*(n+1));
	sort(v+1,v+n+2);
	d=unique(v+1,v+n+2)-v-1;
	for(int i=0;i<=n;i++)
		s[i]=lower_bound(v+1,v+d+1,s[i])-v;
	for(int i=0;i<=d;i++)
		cl[i]=cg[i]=ce[i]=-inf;
}
void add(int *c,int p,int v)
{
	for(;p<=d;p+=p&-p)
		c[p]=max(c[p],v);
}
int ask(int *c,int p)
{
	int ans=-inf;
	for(;p;p-=p&-p)
		ans=max(ans,c[p]);
	return ans;
}
int main()
{
	int tt;
	scanf("%d",&tt);
	while(tt--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%lld",s+i),s[i]+=s[i-1];
		lsh();
		add(cl,s[0],0);
		add(cg,d+1-s[0],0);
		ce[s[0]]=0;
		for(int i=1;i<=n;i++)
		{
			f[i]=-inf;
			f[i]=max(f[i],i+ask(cl,s[i]-1));
			f[i]=max(f[i],-i+ask(cg,d+1-s[i]-1));
			f[i]=max(f[i],ce[s[i]]);
			add(cl,s[i],f[i]-i);
			add(cg,d+1-s[i],f[i]+i);
			ce[s[i]]=max(ce[s[i]],f[i]);
			// printf("i:%d s:%d f:%d\n",i,s[i],f[i]);
		}
		printf("%d\n",f[n]);
	}
	return 0;
}