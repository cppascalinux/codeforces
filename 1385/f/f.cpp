#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
#define PB push_back
using namespace std;
int n,m;
int vis[200009],deg[200009],sm[200009];
vector<int> e[200009];
void topo()
{
	queue<int> q;
	for(int i=1;i<=n;i++)
		if(deg[i]==1)
			q.push(i);
	int ans=0;
	while(!q.empty())
	{
		int x=q.front();
		q.pop();
		vis[x]=1;
		for(auto t:e[x])
			if(!vis[t])
			{
				if(++sm[t]>=m)
					ans++,deg[t]-=m,sm[t]-=m;
				if(deg[t]==1)
					q.push(t);
			}
	}
	printf("%d\n",ans);
}
void clr()
{
	for(int i=1;i<=n;i++)
		vis[i]=deg[i]=sm[i]=0,e[i].clear();
}
int main()
{
#ifdef I_LOVE_KTY
	freopen("f.in","r",stdin);
	freopen("f.out","w",stdout);
#endif
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		for(int i=1,a,b;i<=n-1;i++)
		{
			scanf("%d%d",&a,&b);
			e[a].PB(b),e[b].PB(a);
			deg[a]++,deg[b]++;
		}
		topo();
		clr();
	}
	return 0;
}