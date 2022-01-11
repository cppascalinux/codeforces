#include<bits/stdc++.h>
#define ll long long
using namespace std;
struct node
{
	int a,c;
	bool operator<(const node &p)const{return a<p.a;}
};
int n;
node p[100009];
int main()
{
	scanf("%d",&n);
	ll ans=0;
	for(int i=1;i<=n;i++)
		scanf("%d%d",&p[i].a,&p[i].c),ans+=p[i].c,p[i].c+=p[i].a;
	sort(p+1,p+n+1);
	int mx=p[1].c;
	for(int i=1;i<=n;i++)
	{
		ans+=max(0,p[i].a-mx);
		mx=max(mx,p[i].c);
	}
	printf("%lld",ans);
	return 0;
}