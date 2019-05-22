//2019.05.22
//CF436E Cardboard Box 先把所有关卡按b排序,则选b的关卡的前面所有关卡都必须玩,枚举最后一个选b的位置,用multiset维护答案即可
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<set>
#define li long long
#define inf 0x7F7F7F7F7F7F7F7FLL
#define pii pair<int,int>
#define ppi pair<pii,int>
#define fi first
#define se second
using namespace std;
struct node
{
	set<pii> s1,s2;
	li sm;
	int k;
	node(){sm=k=0;}
	int ok()
	{
		return s1.size()==k;
	}
	void adj()
	{
		while(s1.size()<k&&!s2.empty())
		{
			sm+=s2.begin()->fi;
			s1.insert(*s2.begin());
			s2.erase(s2.begin());
		}
		while(s1.size()>k&&!s1.empty())
		{
			set<pii>::iterator it=s1.end();
			it--;
			sm-=it->fi;
			s2.insert(*it);
			s1.erase(*it);
		}
		while(!s1.empty()&&!s2.empty())
		{
			set<pii>::iterator it=s1.end();
			it--;
			if(it->fi<=s2.begin()->fi)
				break;
			else
			{
				pii v1=*it,v2=*s2.begin();
				sm-=v1.fi,sm+=v2.fi;
				s1.erase(it),s2.erase(s2.begin());
				s1.insert(v2),s2.insert(v1);
			}
		}
	}
	void newk(int a)
	{
		k=a,adj();
	}
	void ins(pii x)
	{
		s2.insert(x),adj();
	}
	void del(pii x)
	{
		if(s2.count(x))
			s2.erase(x);
		else
			sm-=x.fi,s1.erase(x);
		adj();
	}
};
int n,w;
ppi p[300009];//fi as b,se as a
int out[300009];
li solve()
{
	node s;
	li ans=inf;
	for(int i=1;i<=n;i++)
		s.ins(pii(p[i].fi.se,p[i].se));
	s.newk(w);
	if(s.ok())
		ans=min(ans,s.sm);
	li tsm=0;
	for(int i=1;i<=min(w,n);i++)
	{
		s.del(pii(p[i].fi.se,p[i].se));
		s.ins(pii(p[i].fi.fi-p[i].fi.se,p[i].se));
		s.newk(w-i);
		tsm+=p[i].fi.se;
		if(s.ok())
			ans=min(ans,s.sm+tsm);
	}
	return cout<<ans<<endl,ans;
}
void getans(li tmp)
{
	node s;
	li ans=inf;
	for(int i=1;i<=n;i++)
		s.ins(pii(p[i].fi.se,p[i].se));
	s.newk(w);
	if(s.ok())
		ans=min(ans,s.sm);
	// printf("ans0:%lld\n",ans);
	li tsm=0;
	int edp=0;
	for(int i=1;i<=min(w,n);i++)
	{
		if(ans==tmp)
			break;
		s.del(pii(p[i].fi.se,p[i].se));
		s.ins(pii(p[i].fi.fi-p[i].fi.se,p[i].se));
		s.newk(w-i);
		tsm+=p[i].fi.se;
		if(s.ok())
			ans=min(ans,s.sm+tsm);
		edp=i;
	}
	// printf("edp:%d\n",edp);
	for(int i=1;i<=edp;i++)
		out[p[i].se]=1;
	set<pii>::iterator it;
	for(it=s.s1.begin();it!=s.s1.end();it++)
		out[it->se]++;
	for(int i=1;i<=n;i++)
		printf("%d",out[i]);
}
int main()
{
#ifdef I_LOVE_KTY
	freopen("box.in","r",stdin);
	freopen("box.out","w",stdout);
#endif
	scanf("%d%d",&n,&w);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&p[i].fi.se,&p[i].fi.fi);
		p[i].se=i;
	}
	sort(p+1,p+n+1);
	li tmp=solve();
	getans(tmp);
	return 0;
}