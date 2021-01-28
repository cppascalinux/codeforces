#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;
int n;
const int m=200000;
int p[200009],f[200009],deg[200009];
vector<int> e[200009];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		memset(p,0,sizeof(p));
		memset(f,0,sizeof(f));
		memset(deg,0,sizeof(deg));
		for(int i=1;i<=m;i++)
			e[i].clear();
		for(int i=1,a;i<=n;i++)
			scanf("%d",&a),p[a]++;
		for(int i=1;i<=m;i++)
			for(int j=2*i;j<=m;j+=i)
				e[i].push_back(j),deg[j]++;
		queue<int> q;
		for(int i=1;i<=m;i++)
			if(!deg[i])
				f[i]=p[i],q.push(i);
		while(!q.empty())
		{
			int x=q.front();
			q.pop();
			for(int u:e[x])
			{
				f[u]=max(f[u],f[x]+p[u]);
				if(--deg[u]==0)
					q.push(u);
			}
		}
		int ans=0;
		for(int i=1;i<=m;i++)
			ans=max(ans,f[i]);
		printf("%d\n",n-ans);
	}
	return 0;
}