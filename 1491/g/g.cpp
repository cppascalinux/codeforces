#include<bits/stdc++.h>
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;
int n,m;
int r[200009],p[200009];
int f[200009];
int vis[200009];
vector<int> bg;
pii ans[200009];
void add(int a,int b)
{
	ans[++m]=pii(p[a],p[b]);
	swap(r[p[a]],r[p[b]]);
	swap(p[a],p[b]);
}
void output()
{
	printf("%d\n",m);
	for(int i=1;i<=m;i++)
		printf("%d %d\n",ans[i].fi,ans[i].se);
}
int fnd(int x)
{
	return x==f[x]?x:f[x]=fnd(f[x]);
}
void solve1()
{
	int t=p[1];
	add(r[1],1);
	add(1,t);
	for(int i=1;i<=n-2;i++)
		add(r[t],r[r[t]]);
	add(t,r[t]);
}
void solve2()
{
	for(int i=0;i<bg.size();i+=2)
	{
		int a=bg[i],b=bg[i+1];
		add(a,b);
		int ta=p[a],tb=p[b];
		while(r[ta]!=tb)
			add(r[ta],r[r[ta]]);
		while(r[tb]!=ta)
			add(r[tb],r[r[tb]]);
		add(ta,tb);
	}
}
void solve3()
{
	for(int i=0;i<bg.size()-3;i+=2)
	{
		int a=bg[i],b=bg[i+1];
		add(a,b);
		int ta=p[a],tb=p[b];
		while(r[ta]!=tb)
			add(r[ta],r[r[ta]]);
		while(r[tb]!=ta)
			add(r[tb],r[r[tb]]);
		add(ta,tb);
	}
	int a=*(bg.end()-1),b=*(bg.end()-2),c=*(bg.end()-3);
	// printf("a:%d b:%d c:%d\n",a,b,c);
	add(a,c);
	add(b,c);
	int ta=p[a],tb=p[b];
	while(r[ta]!=tb)
		add(r[ta],r[r[ta]]);
	while(r[tb]!=ta)
		add(r[tb],r[r[tb]]);
	add(ta,tb);
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		f[i]=i;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",r+i);
		p[r[i]]=i;
		f[fnd(r[i])]=fnd(i);
	}
	for(int i=1;i<=n;i++)
		if(i==fnd(i))
			bg.push_back(i);
	if(bg.size()==1)
		solve1();
	else if(bg.size()%2==0)
		solve2();
	else
		solve3();
	output();
	return 0;
}