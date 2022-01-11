#include<bits/stdc++.h>
using namespace std;
struct node
{
	int a,b,k;
	bool operator<(const node &p)const{return a<p.a;}
};
int n;
node p[200009];
int f[200009],g[200009];
int st[200009];
void fail()
{
	printf("-1\n");
	exit(0);
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&p[i].a,&p[i].b);
		if(p[i].a>p[i].b)
			swap(p[i].a,p[i].b),p[i].k=1;
		if(p[i].a>=n+1||p[i].b<=n)
			fail();
	}
	sort(p+1,p+n+1);
	memset(f,0x7F,sizeof(f));
	f[0]=0;
	for(int i=1;i<=n;i++)
	{
		int pos=upper_bound(f+1,f+n+1,p[i].b)-f;
		f[pos]=p[i].b;
		g[i]=pos;
		if(pos>2)
			fail();
	}
	int lp=1,tp=0,ls=1,ans=0;
	vector<int> tmp1,tmp2,tl;
	for(int i=1;i<=n;i++)
	{
		if(g[i]==1)
		{
			st[++tp]=i;
			tl.push_back(i);
		}
		else
		{
			while(lp<tp&&p[st[lp]].b>p[i].b)
			{
				lp++;
			}
			if(st[lp]>ls)
			{
				int sm=0;
				for(int v1:tmp1)
					sm+=p[v1].k;
				for(int v2:tmp2)
					sm+=p[v2].k^1;
				sm=min(sm,(int)tmp1.size()+(int)tmp2.size()-sm);
				ans+=sm;
				tmp1.clear(),tmp2.clear();
			}
			if(tl.size())
				ls=tl.back();
			// assert(p[ls].b<p[i].b);
			for(int v:tl)
				if(p[v].b<p[i].b)
					tmp1.push_back(v);
			tl.clear();
			tmp2.push_back(i);
		}
	}
	if(tmp2.size())
	{
		// printf("tmp1:%d tmp2:%d\n",(int)tmp1.size(),(int)tmp2.size());
		int sm=0;
		for(int v1:tmp1)
			sm+=p[v1].k;
		for(int v2:tmp2)
			sm+=p[v2].k^1;
		sm=min(sm,(int)tmp1.size()+(int)tmp2.size()-sm);
		ans+=sm;
		tmp1.clear(),tmp2.clear();
	}
	printf("%d\n",ans);
	return 0;
}