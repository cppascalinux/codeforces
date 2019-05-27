#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;
int n,m;
pii s[300009];
vector<int> v[300009];
int hs[300009];
int main()
{
#ifdef I_LOVE_KTY
	freopen("b.in","r",stdin);
	freopen("b.out","w",stdout);
#endif
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d",&s[i].fi,&s[i].se);
		if(s[i].fi>s[i].se)
			swap(s[i].fi,s[i].se);
	}
	sort(s+1,s+m+1);
	m=unique(s+1,s+m+1)-s-1;
	for(int i=1;i<=m;i++)
	{
		v[s[i].fi].push_back(i);
		v[s[i].se].push_back(i);
	}
	for(int i=1;i<=n;i++)
		if((int)v[i].size()>=m-1)
			return printf("YES"),0;
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<(int)v[i].size();j++)
			hs[v[i][j]]=1;
		int s1=0,s2=0;
		for(int j=1;j<=m;j++)
			if(!hs[j])
			{
				if(!s1)
					s1=j;
				else
				{
					s2=j;
					break;
				}
			}
		for(int j=0;j<(int)v[i].size();j++)
			hs[v[i][j]]=0;
		int cmn=0;
		pii p1=s[s1],p2=s[s2];
		if(p1.fi==p2.fi||p1.fi==p2.se)
			cmn=p1.fi;
		else if(p1.se==p2.fi||p1.se==p2.se)
			cmn=p1.se;
		if(!cmn)
			continue;
		pii nxt(i,cmn);
		if(nxt.fi>nxt.se)
			swap(nxt.fi,nxt.se);
		int mns=0;
		if(*lower_bound(s+1,s+m+1,nxt)==nxt)
			mns=1;
		if((int)v[cmn].size()+(int)v[i].size()-mns==m)
			return printf("YES"),0;
	}
	printf("NO");
	return 0;
}