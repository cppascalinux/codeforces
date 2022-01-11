#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,m,g,l;
ll lm,k,tot;
int sa[500009],sb[500009];
vector<int> sme[500009];
int pa[1000009],pb[1000009];
int stp[500009];
int gcd(int a,int b)
{
	return !a||!b?a+b:gcd(b,a%b);
}
int main()
{
	scanf("%d%d%lld",&n,&m,&k);
	for(int i=1;i<=n;i++)
		scanf("%d",sa+i),pa[sa[i]]=i;
	for(int i=1;i<=m;i++)
		scanf("%d",sb+i),pb[sb[i]]=i;
	l=2*max(n,m);
	g=gcd(n,m);
	lm=(ll)n*m/g;
	stp[1]=1;
	for(int i=2;i<=n/g;i++)
		stp[i]=(stp[i-1]+m-1)%n+1;
	for(int i=1;i<=l;i++)
		if(pa[i]&&pb[i])
			if(pa[i]%g==pb[i]%g)
			{
				tot++;
				int x=pa[i],y=pb[i];
				int dt=((x-y)%n+n)%n+1;
				// printf("x:%d y:%d dt:%d\n",x,y,dt);
				sme[dt].push_back(y);
			}
	for(int i=1;i<=n;i++)
		sme[i].push_back(m+10),sort(sme[i].begin(),sme[i].end());
	ll r=(k-1)/(lm-tot),ans=0;
	k-=r*(lm-tot),ans+=r*lm;
	// printf("r:%lld tot:%lld lm:%lld k:%lld ans:%lld\n",r,tot,lm,k,ans);
	for(int i=1;i<=n/g;i++)
	{
		// printf("i:%d stp:%d\n",i,stp[i]);
		if(k<=m-sme[stp[i]].size()+1)
		{
			// printf("i:%d\n",i);
			for(int j=1;j<=m;j++)
			{
				ans++;
				if(*lower_bound(sme[stp[i]].begin(),sme[stp[i]].end(),j)!=j)
					k--;	
				if(k==0)
					break;
			}
			break;
		}
		k-=m-sme[stp[i]].size()+1;
		ans+=m;
	}
	printf("%lld",ans);
	return 0;
}