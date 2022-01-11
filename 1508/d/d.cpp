#include<bits/stdc++.h>
#define db double
#define ll long long
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;
struct pt
{
	int x,y,id;
	db geta(){return atan2((db)y,(db)x);}
	bool operator<(pt &p)
	{
		return geta()<p.geta();
	}
};
int n;
int f[2009];
int p[2009];
pt q[2009];
db dot(pt a,pt b)
{
	return (db)a.x*b.x+(db)a.y*b.y;
}
int fnd(int x)
{
	return x==f[x]?x:f[x]=fnd(f[x]);
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		f[i]=i;
	int fg=0;
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d%d",&q[i].x,&q[i].y,p+i);
		q[i].id=i;
		f[fnd(i)]=fnd(p[i]);
		if(p[i]!=i)
			fg=i;
	}
	if(!fg)
		return printf("0"),0;
	for(int i=1;i<=n;i++)
		if(i!=fg)
			q[i].x-=q[fg].x,q[i].y-=q[fg].y;
	for(int i=fg;i<=n;i++)
		q[i]=q[i+1];
	for(int i=1;i<=n-1;i++)
		assert(q[i].id!=fg),assert(q[i].x!=0||q[i].y!=0);
	sort(q+1,q+n);
	int bg=1;
	for(int i=1;i<=n-2;i++)
		if(dot(q[i],q[i+1])<0)
		{
			bg=i+1;
			break;
		}
	vector<pii> ans;
	for(int i=1;i<=n-2;i++)
	{
		int s=(bg+i-2)%(n-1)+1,t=(bg+i-1)%(n-1)+1;
		if(fnd(q[s].id)!=fnd(q[t].id))
		{
			int a=q[s].id,b=q[t].id;
			ans.emplace_back(a,b);
			swap(p[a],p[b]);
			f[fnd(a)]=fnd(b);
		}
	}
	for(int i=1;i<=n-1;i++)
	{
		int x=p[fg];
		swap(p[fg],p[x]);
		ans.emplace_back(fg,x);
	}
	// if(ans[0].fi==61)
	// {
	// 	printf("fg:%d\n",fg);
	// 	printf("262:%d %d\n",ans[261].fi,ans[261].se);
	// 	printf("464:%d %d\n",ans[463].fi,ans[463].se);
	// }
	// else
	// {
	printf("%d\n",(int)ans.size());
	for(pii t:ans)
		printf("%d %d\n",t.fi,t.se);
	// }
	return 0;
}