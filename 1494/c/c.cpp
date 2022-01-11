#include<bits/stdc++.h>
#define inf 0x7F7F7F7F
using namespace std;
int n,m;
int sa[200009],sb[200009];
int pa[200009],pb[200009];
int qa[200009],qb[200009];
int mt[200009];
int solve(int *s,int *t,int n,int m)
{
	sort(s+1,s+n+1);
	sort(t+1,t+m+1);
	// for(int i=1;i<=n;i++)
	// 	printf("i:%d s:%d\n",i,s[i]);
	// for(int i=1;i<=m;i++)
	// 	printf("i:%d t:%d\n",i,t[i]);
	t[m+1]=inf;
	int lp=0,rp=0,sm=0,ans=0;
	for(int i=1;i<=n;i++)
		if(*lower_bound(t+1,t+m+1,s[i])==s[i])
			mt[i]=1,sm++;
		else
			mt[i]=0;
	ans=sm;
	s[n+1]=inf;
	for(int i=1;i<=n;i++)
	{
		if(mt[i])
			sm--;
		while(rp<m&&t[rp+1]<=s[i+1]-1)
		{
			rp++;
			while(lp<rp&&t[rp]-t[lp]+1>i)
				lp++;
			if(t[rp]>=s[i])
				ans=max(ans,sm+rp-lp+1);
		}
	}
	return ans;
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		int pn=0,pm=0,qn=0,qm=0;
		for(int i=1;i<=n;i++)
		{
			scanf("%d",sa+i);
			if(sa[i]>0)
				pa[++pn]=sa[i];
			else
				qa[++qn]=-sa[i];
		}
		for(int i=1;i<=m;i++)
		{
			scanf("%d",sb+i);
			if(sb[i]>0)
				pb[++pm]=sb[i];
			else
				qb[++qm]=-sb[i];
		}
		int ans=solve(pa,pb,pn,pm)+solve(qa,qb,qn,qm);
		printf("%d\n",ans);
	}
	return 0;
}