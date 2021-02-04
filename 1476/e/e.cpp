#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<set>
#include<vector>
#include<queue>
using namespace std;
int n,m,k,tp;
int pt[100009];
char org[100009][5];
char st[5];
int qs[100009],pos[600009];
int mt[100009][17];
int deg[100009];
int ans[100009];
vector<int> g[100009];
int chg(char *s)
{
	int ans=0;
	for(int i=1;i<=k;i++)
		ans*=27,ans+=s[i]=='_'?0:s[i]-'a'+1;
	return ans+1;
}
void dfs(int d,int id)
{
	if(d>k)
	{
		int t=chg(st);
		// if(id==6)
		// 	printf("qwqwqwqwqwqwq %s %d\n",st+1,t);
		if(pos[t])
			mt[id][++tp]=t;
		return;
	}
	st[d]=org[id][d];
	dfs(d+1,id);
	st[d]='_';
	dfs(d+1,id);
}
void fail()
{
	printf("NO");
	exit(0);
}
int mat(int s,int p)
{
	for(int i=1;i<=16;i++)
		if(mt[s][i]==p)
			return 1;
	return 0;
}
int main()
{
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n;i++)
	{
		char t[5];
		scanf("%s",t+1);
		pt[i]=chg(t);
		pos[pt[i]]=i;
		// printf("i:%d pt:%d\n",i,pt[i]);
	}
	for(int i=1;i<=m;i++)
	{
		int a;
		scanf("%s%d",org[i]+1,qs+i);
	}
	for(int i=1;i<=m;i++)
	{
		tp=0;
		dfs(1,i);
		int fg=0;
		// printf("i:%d org:%s\n",i,org[i]+1);
		for(int j=1;j<=16;j++)
		{
			// printf("i:%d mt:%d\n",i,mt[i][j]);
			if(mt[i][j]!=pt[qs[i]]&&pos[mt[i][j]])
				g[qs[i]].push_back(pos[mt[i][j]]),deg[pos[mt[i][j]]]++;
			else if(mt[i][j]==pt[qs[i]])
				fg=1;
		}
		if(!fg)
			fail();
	}
	// printf("qwq");
	queue<int> q;
	for(int i=1;i<=n;i++)
		if(!deg[i])
			q.push(i);
	int tp=0;
	while(!q.empty())
	{
		int x=q.front();
		q.pop();
		ans[++tp]=x;
		for(int u:g[x])
			if(!--deg[u])
				q.push(u);
	}
	if(tp<n)
		fail();
	printf("YES\n");
	for(int i=1;i<=n;i++)
		printf("%d ",ans[i]);
	return 0;
}