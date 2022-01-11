#include<bits/stdc++.h>
using namespace std;
int n,mod,tot;
int vis[100],p[100];
int num[10000009];
int c[10000009];
void add(int p,int v)
{
	for(int i=p;i<=tot;i+=i&-i)
		c[i]+=v;
}
int ask(int p)
{
	if(!p)
		return 0;
	int ans=0;
	for(int i=p;i;i-=i&-i)
		ans+=c[i];
	return ans;
}
void dfs(int d)
{
	if(d>n)
	{
		tot++;
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				if(p[i]>p[j])
					num[tot]++;
		return;
	}
	for(int i=1;i<=n;i++)
		if(!vis[i])
		{
			vis[i]=1;
			p[d]=i;
			dfs(d+1);
			vis[i]=0;
		}
}
int main()
{
	scanf("%d%d",&n,&mod);
	dfs(1);
	for(int i=1;i<=tot;i++)
		printf("i:%d num:%d\n",i,num[i]);
	int ans=0;
	for(int i=tot;i>=1;i--)
		ans+=ask(num[i]),add(num[i]+1,1);
	printf("%d",ans);
	return 0;
}