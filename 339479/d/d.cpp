#include<bits/stdc++.h>
#define ll long long
#define db double
#define mod 1000000007
#define pii pair<int,int>
#define fi first
#define se second
#define pb push_back
using namespace std;
int n,m1,m2;
int f1[100009],f2[100009];
vector<int> p1[100009],p2[100009];
set<pii> h1,h2;
int fnd1(int x)
{
	return x==f1[x]?x:f1[x]=fnd1(f1[x]);
}
int fnd2(int x)
{
	return x==f2[x]?x:f2[x]=fnd2(f2[x]);
}
void clr(vector<int> &v)
{
	vector<int> tmp;
	tmp.swap(v);
}
void merge(int u,int v)
{
	printf("%d %d\n",u,v);
	int fu=fnd1(u),fv=fnd1(v);
	assert(fu!=fv);
	if(fu!=fv)
	{
		if(p1[fu].size()<p1[fv].size())
			swap(fu,fv);
		h1.erase(pii(p1[fu].size(),fu));
		h1.erase(pii(p1[fv].size(),fv));
		f1[fv]=fu;
		p1[fu].insert(p1[fu].end(),p1[fv].begin(),p1[fv].end());
		clr(p1[fv]);
		h1.insert(pii(p1[fu].size(),fu));
	}
	fu=fnd2(u),fv=fnd2(v);
	assert(fu!=fv);
	if(fu!=fv)
	{
		if(p2[fu].size()<p2[fv].size())
			swap(fu,fv);
		h2.erase(pii(p2[fu].size(),fu));
		h2.erase(pii(p2[fv].size(),fv));
		f2[fv]=fu;
		p2[fu].insert(p2[fu].end(),p2[fv].begin(),p2[fv].end());
		clr(p2[fv]);
		h2.insert(pii(p2[fu].size(),fu));
	}
}
int main()
{
	scanf("%d%d%d",&n,&m1,&m2);
	for(int i=1;i<=n;i++)
	{
		f1[i]=f2[i]=i;
		p1[i].pb(i),p2[i].pb(i);
	}
	for(int i=1;i<=m1;i++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		int fa=fnd1(a),fb=fnd1(b);
		if(p1[fa].size()<p1[fb].size())
			swap(fa,fb);
		f1[fb]=fa;
		p1[fa].insert(p1[fa].end(),p1[fb].begin(),p1[fb].end());
		clr(p1[fb]);
	}
	for(int i=1;i<=m2;i++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		int fa=fnd2(a),fb=fnd2(b);
		if(p2[fa].size()<p2[fb].size())
			swap(fa,fb);
		f2[fb]=fa;
		p2[fa].insert(p2[fa].end(),p2[fb].begin(),p2[fb].end());
		clr(p2[fb]);
	}
	if(m1<m2)
	{
		swap(m1,m2);
		for(int i=1;i<=n;i++)
		{
			swap(f1[i],f2[i]);
			p1[i].swap(p2[i]);
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(fnd1(i)==i)
			h1.insert(pii(p1[i].size(),i));
		if(fnd2(i)==i)
			h2.insert(pii(p2[i].size(),i));
	}
	printf("%d\n",n-1-m1);
	for(int i=1;i<=n-1-m1;i++)
	{
		int x=h1.begin()->se;
		int fx=fnd2(x),p=0;
		for(int v:p1[x])
			if(fnd2(v)!=fx)
				p=v;
		if(p)
		{
			int y=h1.rbegin()->se;
			if(fnd2(y)==fnd2(x))
				x=p;
			merge(x,y);
		}
		else
		{
			auto it=h2.begin();
			if(it->se==fx)
				it++;
			int y=it->se;
			merge(x,y);
		}
	}
	return 0;
}