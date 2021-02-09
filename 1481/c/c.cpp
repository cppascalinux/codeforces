#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<deque>
#define ll long long
using namespace std;
int n,m;
deque<int> p[100009];
int la[100009],lb[100009],lc[100009];
int flg[100009],ans[100009];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++)
			scanf("%d",la+i);
		for(int i=1;i<=n;i++)
			scanf("%d",lb+i);
		for(int i=1;i<=m;i++)
			scanf("%d",lc+i);
		for(int i=1;i<=n;i++)
			flg[i]=(la[i]==lb[i]);
		for(int i=1;i<=n;i++)
			if(!flg[i])
				p[lb[i]].push_back(i);
		for(int i=1;i<=n;i++)
			if(flg[i])
				p[lb[i]].push_back(i);
		int suc=1;
		for(int i=m;i>=1;i--)
		{
			if(p[lc[i]].empty())
			{
				if(i!=m)
				{
					ans[i]=ans[i+1];
					continue;
				}
				else
				{
					suc=0;
					break;
				}
			}
			int t=p[lc[i]].front();
			p[lc[i]].pop_front();
			p[lc[i]].push_back(t);
			ans[i]=t;
			la[t]=lb[t];
			flg[t]=1;
		}
		for(int i=1;i<=n;i++)
			if(!flg[i])
			{
				suc=0;
				break;
			}
		for(int i=1;i<=n;i++)
			p[lb[i]].clear();
		if(!suc)
		{
			printf("NO\n");
			continue;
		}
		printf("YES\n");
		for(int i=1;i<=m;i++)
			printf("%d ",ans[i]);
		printf("\n");
	}
	return 0;
}