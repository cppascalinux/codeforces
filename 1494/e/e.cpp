#include<bits/stdc++.h>
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;
struct node
{
	int u,v,c;
	bool operator<(const node &p)const{return u<p.u||(u==p.u&&v<p.v)||(u==p.u&&v==p.v&&c<p.c);}
};
int n,m;
char s[10];
int main()
{
	scanf("%d%d",&n,&m);
	set<node> p;
	int sm1=0,sm2=0;
	for(int i=1;i<=m;i++)
	{
		int a,b;
		char c[10];
		scanf("%s%d",s+1,&a);
		if(s[1]=='+')
		{
			scanf("%d%s",&b,c+1);
			p.insert(node{a,b,c[1]});
			if(p.count(node{b,a,c[1]}))
				sm1++;
			auto it=p.lower_bound(node{b,a,0});
			if(it!=p.end()&&it->u==b&&it->v==a)
				sm2++;
		}
		else if(s[1]=='-')
		{
			scanf("%d",&b);
			auto it1=p.lower_bound(node{a,b,0});
			auto it2=p.lower_bound(node{b,a,0});
			assert(it1!=p.end());
			if(it1!=p.end()&&it2!=p.end()&&it2->u==b&&it2->v==a&&it1->c==it2->c)
				sm1--;
			if(it2!=p.end()&&it2->u==b&&it2->v==a)
				sm2--;
			p.erase(it1);
		}
		else
		{
			if(a&1)
				printf("%s\n",sm2>0?"YES":"NO");
			else
				printf("%s\n",sm1>0?"YES":"NO");
		}
	}
	return 0;
}