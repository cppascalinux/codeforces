#include<bits/stdc++.h>
#define ll long long
using namespace std;
struct node
{
	ll a,b;
	bool operator<(const node &p)const{return b<p.b;}
};
int n;
node s[100009];
int main()
{
	scanf("%d",&n);
	ll sm=0;
	for(int i=1;i<=n;i++)
	{
		scanf("%lld%lld",&s[i].a,&s[i].b);
		sm+=s[i].a;
	}
	sort(s+1,s+n+1);
	s[n+1].b=sm;
	int lp=1,rp=n;
	ll cur=0,ans=sm;
	for(int i=1;i<=n+1;i++)
	{
		s[i].b=min(s[i].b,sm);
		// printf("i:%d cur:%lld\n",i,cur);
		while(cur<s[i].b)
		{
			// printf("lp:%d rp:%d slp:%d srp:%d\n",lp,rp,s[lp].a,s[rp].a);
			if(lp<i)
			{
				ll dt=min(s[lp].a,s[i].b-cur);
				s[lp].a-=dt;
				if(!s[lp].a)
					lp++;
				cur+=dt;
			}
			else
			{
				ll dt=min(s[rp].a,s[i].b-cur);
				s[rp].a-=dt;
				if(!s[rp].a)
					rp--;
				ans+=dt;
				cur+=dt;
			}
		}
	}
	printf("%lld",ans);
	return 0;
}