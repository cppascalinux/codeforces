#include<bits/stdc++.h>
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;
int m,k,mx,n;
int ans[2009][2009];
int judge(int x)
{
	return x*x-(x/2)*(x/2)>=m&&x*((x+1)/2)>=mx;
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&m,&k);
		vector<pii> s;
		mx=0;
		for(int i=1;i<=k;i++)
		{
			int a;
			scanf("%d",&a);
			mx=max(mx,a);
			if(a)
				s.emplace_back(a,i);
		}
		int l=0,r=2000;
		while(l<r)
		{
			int mid=(l+r)/2;
			if(judge(mid))
				r=mid;
			else
				l=mid+1;
		}
		n=l;
		vector<pii> pt[5];
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
			{
				int v=1;
				if(i%2==0)
					v+=2;
				if(j%2==0)
					v++;
				pt[v].emplace_back(i,j);
			}
		sort(s.begin(),s.end(),greater<pii>());
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				ans[i][j]=0;
		for(pii t:s)
		{
			if(!pt[2].empty())
			{
				for(int i=1;i<=t.fi;i++)
					if(!pt[2].empty())
					{
						pii p=pt[2].back();
						ans[p.fi][p.se]=t.se;
						pt[2].pop_back();
					}
					else
					{
						pii p=pt[1].back();
						ans[p.fi][p.se]=t.se;
						pt[1].pop_back();
					}
			}
			else
			{
				for(int i=1;i<=t.fi;i++)
					if(!pt[1].empty())
					{
						pii p=pt[1].back();
						ans[p.fi][p.se]=t.se;
						pt[1].pop_back();
					}
					else
					{
						pii p=pt[3].back();
						ans[p.fi][p.se]=t.se;
						pt[3].pop_back();
					}
			}
		}
		printf("%d\n",n);
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
				printf("%d ",ans[i][j]);
			printf("\n");
		}
	}
	return 0;
}