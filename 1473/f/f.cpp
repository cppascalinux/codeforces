#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#define inf 0x7F7F7F7F
using namespace std;
int n,tot=1,s,t;
int sa[3009],sb[3009];
int pos[109];
int hd[3009],eg[2000009],nxt[2000009],cap[2000009];
int cur[3009],dep[3009];
void add(int a,int b,int c)
{
	eg[++tot]=b;
	cap[tot]=c;
	nxt[tot]=hd[a];
	hd[a]=tot;
	eg[++tot]=a;
	cap[tot]=0;
	nxt[tot]=hd[b];
	hd[b]=tot;
}
int bfs()
{
	queue<int> q;
	memset(dep,0,sizeof(dep));
	dep[s]=1;
	q.push(s);
	while(!q.empty())
	{
		int x=q.front();
		q.pop();
		for(int i=hd[x];i;i=nxt[i])
			if(cap[i]&&!dep[eg[i]])
				dep[eg[i]]=dep[x]+1,q.push(eg[i]);
	}
	return dep[t];
}
int dfs(int x,int a)
{
	if(x==t||a==0)
		return a;
	int f,totf=0;
	for(int &i=cur[x];i;i=nxt[i])
		if(cap[i]&&dep[eg[i]]==dep[x]+1&&(f=dfs(eg[i],min(a,cap[i]))))
		{
			cap[i]-=f;
			cap[i^1]+=f;
			a-=f;
			totf+=f;
			if(!a)
				break;
		}
	return totf;
}
int flow()
{
	int totf=0;
	while(bfs())
	{
		for(int i=1;i<=n+2;i++)
			cur[i]=hd[i];
		totf+=dfs(s,inf);
	}
	return totf;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",sa+i);
	for(int i=1;i<=n;i++)
		scanf("%d",sb+i);
	s=n+1,t=n+2;
	int sm=0;
	for(int i=1;i<=n;i++)
	{
		if(pos[sa[i]])
			add(i,pos[sa[i]],inf);
		pos[sa[i]]=i;
		for(int j=1;j<i;j++)
			if(sa[i]%sa[j]==0&&pos[sa[j]]==j)
				add(i,j,inf);
		if(sb[i]>=0)
			add(s,i,sb[i]),sm+=sb[i];
		else
			add(i,t,-sb[i]);
	}
	printf("%d",sm-flow());
	return 0;
}