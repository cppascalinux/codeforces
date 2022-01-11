#include<bits/stdc++.h>
using namespace std;
int n;
int deg[200009];
int f[200009];
vector<int> e[200009];
int main()
{
	int ttt;
	scanf("%d",&ttt);
	while(ttt--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			deg[i]=f[i]=0;
			e[i].clear();
		}
		for(int i=1;i<=n;i++)
		{
			int a;
			scanf("%d",&a);
			deg[i]=a;
			for(int j=1;j<=a;j++)
			{
				int b;
				scanf("%d",&b);
				e[b].push_back(i);
			}
		}
		queue<int> q;
		for(int i=1;i<=n;i++)
			if(deg[i]==0)
			{
				f[i]=1;
				q.push(i);
			}
		while(!q.empty())
		{
			int x=q.front();
			q.pop();
			for(int v:e[x])
			{
				f[v]=max(f[v],f[x]+(v<x));
				if(!--deg[v])
					q.push(v);
			}
		}
		int err=0,ans=0;
		for(int i=1;i<=n;i++)
		{
			if(deg[i])
				err=1;
			ans=max(ans,f[i]);
		}
		printf("%d\n",err?-1:ans);
	}
	return 0;
}