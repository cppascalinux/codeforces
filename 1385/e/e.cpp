#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
#define PB push_back
using namespace std;
int n,m;
int dep[200009],ind[200009];
vector<int> e0[200009],e1[200009];
void solve()
{
	printf("YES\n");
	for(int i=1;i<=n;i++)
	{
		for(auto j:e1[i])
			printf("%d %d\n",i,j);
		for(auto j:e0[i])
			if(dep[i]<dep[j]||(dep[i]==dep[j]&&i<j))
				printf("%d %d\n",i,j);
	}
}
void topo()
{
	queue<int> q;
	for(int i=1;i<=n;i++)
		if(!ind[i])
			dep[i]=1,q.push(i);
	int cnt=0;
	while(!q.empty())
	{
		int x=q.front();
		q.pop();
		cnt++;
		for(auto t:e1[x])
		{
			dep[t]=dep[x]+1;
			if(!--ind[t])
				q.push(t);
		}
	}
	if(cnt<n)
		printf("NO\n");
	else
		solve();
}
void clr()
{
	memset(dep,0,(n+1)*sizeof(int));
	memset(ind,0,(n+1)*sizeof(int));
	for(int i=1;i<=n;i++)
		e0[i].clear(),e1[i].clear();
}
int main()
{
#ifdef I_LOVE_KTY
	freopen("e.in","r",stdin);
	freopen("e.out","w",stdout);
#endif
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		for(int i=1,a,b,c;i<=m;i++)
		{
			scanf("%d%d%d",&a,&b,&c);
			if(a==0)
				e0[b].PB(c),e0[c].PB(b);
			else
				e1[b].PB(c),ind[c]++;
		}
		topo();
		clr();
	}
	return 0;
}