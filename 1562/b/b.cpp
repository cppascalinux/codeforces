#include<bits/stdc++.h>
using namespace std;
int n;
char s[109];
int vis[1000009],pm[1000009];
int st[100009],tot;
vector<int> pr[20];
void init()
{
	vis[1]=1;
	int m=1000000,tp=0;
	for(int i=2;i<=m;i++)
	{
		if(!vis[i])
			pm[++tp]=i;
		for(int j=1;j<=tp&&i*pm[j]<=m;j++)
		{
			vis[i*pm[j]]=1;
			if(i%pm[j]==0)
				break;
		}
	}
}
int main()
{
	init();
	for(int i=1;i<=10000;i++)
		if(vis[i])
			st[++tot]=i;
	// for(int i=1;i<=10;i++)
	// 	printf("i:%d st:%d\n",i,st[i]);
	int ttt;
	scanf("%d",&ttt);
	while(ttt--)
	{
		scanf("%d",&n);
		scanf("%s",s+1);
		for(int i=1;i<=n;i++)
			s[i]-='0';
		for(int i=0;i<=9;i++)
			pr[i].clear();
		for(int i=1;i<=n;i++)
			pr[s[i]].push_back(i);
		for(int i=0;i<=9;i++)
			pr[i].push_back(n+1);
		for(int i=1;i<=tot;i++)
		{
			vector<int> tmp;
			for(int x=st[i];x;x/=10)
				tmp.push_back(x%10);
			reverse(tmp.begin(),tmp.end());
			int cur=0;
			for(auto v:tmp)
			{
				// printf("i:%d st:%d v:%d\n",i,st[i],v);
				cur=*upper_bound(pr[v].begin(),pr[v].end(),cur);
				if(cur==n+1)
					break;
			}
			if(cur<=n)
			{
				printf("%d\n%d\n",(int)tmp.size(),st[i]);
				break;
			}
		}
	}
	return 0;
}