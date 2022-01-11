#include<bits/stdc++.h>
#define ll long long
#define inf 0x7F7F7F7F7F7F7F7FLL
using namespace std;
struct node
{
	int ps;
	ll nf;
};
int n;
int p[300009],s[300009];
ll f[300009];
node st[300009];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",p+i);
	for(int i=1;i<=n;i++)
		scanf("%d",s+i);
	int tp=0;
	multiset<ll> q;
	st[++tp]=node{0,0};
	// q.insert(-inf);
	for(int i=1;i<=n;i++)
	{
		ll mxf=f[i-1];
		while(p[i]<p[st[tp].ps])
		{
			mxf=max(mxf,st[tp].nf);
			q.erase(q.find(s[st[tp].ps]+st[tp].nf));
			tp--;
		}
		st[++tp]=node{i,mxf};
		q.insert(mxf+s[i]);
		f[i]=*q.rbegin();
	}
	printf("%lld",f[n]);
	return 0;
}