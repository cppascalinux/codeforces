#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,m;
int s[200009];
ll c[200009];
set<int> st;
void add(int p,ll v)
{
	for(;p<=n+1;p+=p&-p)
		c[p]+=v;
}
ll ask(int p)
{
	ll ans=0;
	for(;p;p-=p&-p)
		ans+=c[p];
	return ans;
}
ll cal(int l)
{
	return (ll)l*(l+1)/2;
}
void delp(int p)
{
	auto it=st.find(p);
	int pre=*(--it);
	it++;
	int nxt=*(++it);
	add(p,-cal(p-pre));
	add(nxt,-cal(nxt-p));
	add(nxt,cal(nxt-pre));
	st.erase(--it);
}
void newp(int p)
{
	auto it=st.upper_bound(p);
	int nxt=*it;
	int pre=*(--it);
	add(nxt,-cal(nxt-pre));
	add(nxt,cal(nxt-p));
	add(p,cal(p-pre));
	st.insert(p);
}
int main()
{
	scanf("%d%d",&n,&m);
	s[0]=2e9;
	for(int i=1;i<=n;i++)
		scanf("%d",s+i);
	st.insert(1);
	st.insert(n+1);
	add(n+1,cal(n));
	for(int i=2;i<=n;i++)
	{
		if(s[i]<s[i-1])
			newp(i);
	}
	// for(int i=1;i<=n+1;i++)
	// 	printf("i:%d ask:%lld\n",i,ask(i));
	for(int i=1;i<=m;i++)
	{
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		if(a==1)
		{
			if(b>1&&s[b]<s[b-1])
				delp(b);
			if(b<n&&s[b]>s[b+1])
				delp(b+1);
			s[b]=c;
			if(b>1&&s[b]<s[b-1])
				newp(b);
			if(b<n&&s[b]>s[b+1])
				newp(b+1);
		}
		else
		{
			c++;
			int nl=*st.lower_bound(b);
			auto it=st.upper_bound(c);
			int nr=*(--it);
			// printf("l:%d r:%d nl:%d nr:%d\n",b,c,nl,nr);
			ll ans=0;
			if(nr>=nl)
			{
				ans+=ask(nr)-ask(nl);
				ans+=cal(nl-b);
				ans+=cal(c-nr);
			}
			else
			{
				ans+=cal(c-b);
			}
			printf("%lld\n",ans);
		}
	}
	return 0;
}