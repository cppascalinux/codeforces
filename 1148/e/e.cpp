#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define li long long
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;
int n,m;
pii ors[300009],ort[300009];
int s[300009],t[300009];
int ans1[1500009],ans2[1500009],ans3[1500009];
pii st[300009];
int trs[300009],trt[300009];
void add(int a,int b,int c)
{
	m++;
	ans1[m]=a,ans2[m]=b,ans3[m]=c;
}
void solve()
{
	int tp=0;
	for(int i=1;i<=n;i++)
	{
		if(s[i]==t[i])
			continue;
		if(s[i]<t[i])
			st[++tp]=pii(i,t[i]-s[i]);
		else
		{
			int dt=s[i]-t[i];
			while(tp&&dt)
			{
				int dv=min(st[tp].se,dt);
				dt-=dv,st[tp].se-=dv;
				add(st[tp].fi,i,dv);
				if(!st[tp].se)
					tp--;
			}
			if(dt&&!tp)
				return printf("NO"),void();
		}
	}
	printf("YES\n");
	printf("%d\n",m);
	for(int i=1;i<=m;i++)
		printf("%d %d %d\n",ors[ans1[i]].se,ors[ans2[i]].se,ans3[i]);
}
int main()
{
#ifdef I_LOVE_KTY
	freopen("e.in","r",stdin);
	freopen("e.out","w",stdout);
#endif
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",s+i),ors[i]=pii(s[i],i);
	for(int i=1;i<=n;i++)
		scanf("%d",t+i),ort[i]=pii(t[i],i);
	sort(s+1,s+n+1);
	sort(t+1,t+n+1);
	sort(ors+1,ors+n+1);
	sort(ort+1,ort+n+1);
	if(t[1]<s[1]||t[n]>s[n])
		return printf("NO"),0;
	li sms=0,smt=0;
	for(int i=1;i<=n;i++)
		sms+=s[i],smt+=t[i];
	if(sms!=smt)
		return printf("NO"),0;
	solve();
	return 0;
}