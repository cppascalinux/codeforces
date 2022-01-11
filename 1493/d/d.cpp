#include<bits/stdc++.h>
#define pii pair<int,int>
#define fi first
#define se second
#define inf 0x7F7F7F7F
#define mod 1000000007
#define ll long long
using namespace std;
int n,q;
const int m=200000;
int s[200009];
map<int,int> mp[200009];
int rm[200009];
map<int,int> fc[200009];
pii qr[200009];
int mn[200009],out[200009],vis[200009];
int qpow(int a,int b)
{
	int ans=1;
	for(;b;b>>=1,a=(ll)a*a%mod)
		if(b&1)
			ans=(ll)ans*a%mod;
	return ans;
}
void init()
{
	for(int i=1;i<=m;i++)
		rm[i]=i;
	for(int i=2;i<=m;i++)
		for(int j=i;j<=m;j+=i)
			if(rm[j]%i==0)
			{
				int te=0;
				while(rm[j]%i==0)
					te++,rm[j]/=i;
				fc[j][i]=te;
			}
}
int main()
{
	init();
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++)
		scanf("%d",s+i),mp[i]=fc[s[i]];
	for(int i=1;i<=q;i++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		qr[i]=pii(a,b);
		for(pii t:fc[b])
			mp[a][t.fi]+=t.se;
	}
	for(int i=1;i<=m;i++)
		mn[i]=inf;
	for(int i=1;i<=n;i++)
		for(pii t:mp[i])
		{
			mn[t.fi]=min(mn[t.fi],t.se);
			if(t.se)
				vis[t.fi]++;
		}
	for(int i=1;i<=m;i++)
		if(vis[i]<n)
			mn[i]=0;
	// for(int i=1;i<=n;i++)
	// {
	// 	printf("i:%d----\n",i);
	// 	for(pii t:mp[i])
	// 		printf("%d %d\n",t.fi,t.se);
	// }
	// for(int i=1;i<=4;i++)
	// 	printf("i:%d mn:%d\n",i,mn[i]);
	int ans=1;
	for(int i=1;i<=m;i++)
		ans=(ll)ans*qpow(i,mn[i])%mod;
	for(int i=q;i>=1;i--)
	{
		out[i]=ans;
		pii s=qr[i];
		for(pii t:fc[s.se])
		{
			auto it=mp[s.fi].find(t.fi);
			it->se-=t.se;
			// printf("i:%d pos:%d num:%d rep:%d\n",i,s.fi,t.fi,it->se);
			if(it->se<mn[t.fi])
			{
				ans=(ll)ans*qpow(qpow(t.fi,mn[t.fi]-it->se),mod-2)%mod;
				// printf("ans:%d\n",ans);
				mn[t.fi]=it->se;
			}
		}
	}
	for(int i=1;i<=q;i++)
		printf("%d\n",out[i]);
	return 0;
}