#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define PII pair<int,int>
#define FI first
#define SE second
using namespace std;
int n,cnt,tp;
int tmp[200009];
int s[2][200009];
PII pos[200009][2];
int cl[200009],vis[200009],st[200009];
void dfs(int x)
{
	vis[x]=1;
	st[++tp]=x;
	cnt+=cl[x];
	for(int i=0;i<=1;i++)
	{
		int nm=s[i][x];
		for(int j=0;j<=1;j++)
			if(!vis[pos[nm][j].SE])
			{
				cl[pos[nm][j].SE]=cl[x]^(i^pos[nm][j].FI^1);
				dfs(pos[nm][j].SE);
			}
	}
}
void clr()
{
	for(int i=1;i<=n;i++)
	{
		tmp[i]=s[0][i]=s[1][i]=cl[i]=vis[i]=0;
		pos[i][0]=pos[i][1]=PII(0,0);
	}
}
int main()
{
#ifdef I_LOVE_KTY
	freopen("g.in","r",stdin);
	freopen("g.out","w",stdout);
#endif
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			scanf("%d",s[0]+i);
			tmp[s[0][i]]++;
			if(!pos[s[0][i]][0].SE)
				pos[s[0][i]][0]=PII(0,i);
			else
				pos[s[0][i]][1]=PII(0,i);
		}
		for(int i=1;i<=n;i++)
		{
			scanf("%d",s[1]+i);
			tmp[s[1][i]]++;
			if(!pos[s[1][i]][0].SE)
				pos[s[1][i]][0]=PII(1,i);
			else
				pos[s[1][i]][1]=PII(1,i);
		}
		int err=0;
		for(int i=1;i<=n;i++)
			if(tmp[i]!=2)
				err=1;
		if(err)
		{
			printf("-1\n");
			clr();
			continue;
		}
		int ans=0;
		for(int i=1;i<=n;i++)
			if(!vis[i])
			{
				cnt=tp=0;
				dfs(i);
				if(cnt>tp-cnt)
				{
					cnt=tp-cnt;
					for(int j=1;j<=tp;j++)
						cl[st[j]]^=1;
				}
				ans+=cnt;
			}
		printf("%d\n",ans);
		for(int i=1;i<=n;i++)
			if(cl[i])
				printf("%d ",i);
		printf("\n");
		clr();
	}
	return 0;
}