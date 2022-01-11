#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,m,p;
char s[70];
ll vl[200009];
ll tl[200009];
int sm[100009],pm[100009];
int tot=-1;
ll op;
int ppc(int x)
{
	int ans=0;
	for(;x;x-=(x&-x))
		ans++;
	return ans;
}
void solve(int x)
{
	vector<int> tmp;
	for(int i=m;i>=1;i--)
		if(vl[x]>>(i-1)&1)
			tmp.push_back(i);
	memset(sm,0,sizeof(sm));
	memset(pm,0,sizeof(pm));
	for(int i=1;i<=n;i++)
	{
		tl[i]=0;
		for(int v:tmp)
		{
			tl[i]<<=1;
			if(vl[i]>>(v-1)&1)
				tl[i]|=1;
		}
		// printf("x:%d i:%d vl:%lld tl:%lld\n",x,i,vl[i],tl[i]);
		sm[tl[i]]++;
	}
	int sz=tmp.size();
	for(int s=0;s<(1<<sz);s++)
	{
		for(int t=s;t;t=(t-1)&s)
			pm[t]+=sm[s];
		pm[0]+=sm[s];
	}
	for(int s=0;s<(1<<sz);s++)
	{
		if(pm[s]>=(n+1)/2&&ppc(s)>tot)
		{
			tot=ppc(s);
			op=0;
			for(int i=0;i<sz;i++)
				if(s>>i&1)
					op|=(1LL<<(tmp[sz-1-i]-1));
			// printf("s:%d tot:%d op:%lld\n",s,tot,op);
		}
	}
}
int main()
{
	mt19937 rnd(time(0));
	scanf("%d%d%d",&n,&m,&p);
	for(int i=1;i<=n;i++)
	{
		scanf("%s",s+1);
		for(int j=1;j<=m;j++)
			vl[i]=(vl[i]*2+(s[j]-'0'));
	}
	for(int i=1;i<=10;i++)
	{
		int x=rnd()%n+1;
		solve(x);
	}
	for(int i=m-1;i>=0;i--)
		printf("%d",(int)(op>>i&1));
	return 0;
}