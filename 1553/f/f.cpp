#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,m;
int s[200009];
ll pr[200009];
ll sm1[600009],sm2[600009];
void add1(int p,ll v)
{
	for(;p<=2*m;p+=p&-p)
		sm1[p]+=v;
}
ll ask1(int p)
{
	if(p<0)
		return 0;
	ll ans=0;
	for(;p;p-=p&-p)
		ans+=sm1[p];
	return ans;
}
void add2(int p,ll v)
{
	for(;p;p-=p&-p)
		sm2[p]+=v;
}
ll ask2(int p)
{
	ll ans=0;
	for(;p<=2*m;p+=p&-p)
		ans+=sm2[p];
	return ans;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",s+i);
		m=max(m,s[i]);
		pr[i]=pr[i-1]+s[i];
	}
	ll ans=0;
	for(int i=1;i<=n;i++)
	{
		ans+=pr[i-1];
		for(int j=2*s[i]-1,k=1;j-s[i]<=m;j+=s[i],k++)
			ans-=(ask1(j)-ask1(j-s[i]))*k*s[i];
		// printf("i:%d ans:%lld\n",i,ans);
		ans+=(ll)(i-1)*s[i];
		ans-=ask2(s[i]);
		add1(s[i],1);
		for(int j=2*s[i]-1,k=1;j-s[i]<=m;j+=s[i],k++)
		{
			add2(j,(ll)k*s[i]);
			add2(j-s[i],-(ll)k*s[i]);
			// printf("i:%d j:%d lj:%d k:%d \n",i,j,j-s[i],k);
		}
		printf("%lld ",ans);
	}
	return 0;
}