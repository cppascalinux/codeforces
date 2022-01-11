#include<bits/stdc++.h>
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;
int n;
int s[1009];
int vis[1009];
int st[1009];
vector<int> ans[1009];
int main()
{
	int ttt;
	scanf("%d",&ttt);
	while(ttt--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d",s+i);
		for(int i=0;i<=n;i++)
			ans[i].clear(),vis[i]=0;
		ans[1].push_back(1);
		int tp=1;
		st[1]=1;
		for(int i=2;i<=n;i++)
		{
			if(s[i]==1)
			{
				ans[i]=ans[i-1];
				ans[i].push_back(1);
				st[++tp]=i;
			}
			else
			{
				for(int j=tp;j>=1;j--)
				{
					if(ans[st[j]].back()==s[i]-1)
					{
						ans[i]=ans[st[j]];
						ans[i].back()++;
						tp=j;
						st[tp]=i;
						break;
					}
				}
			}
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=0;j+1<(int)ans[i].size();j++)
				printf("%d.",ans[i][j]);
			printf("%d\n",ans[i].back());
		}
	}
	return 0;
}