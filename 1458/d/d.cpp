#include<bits/stdc++.h>
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;
int n,tot=1;
char s[500009];
int sm[500009];
int hd[500009],eg[2000009],nxt[2000009],id[2000009],vis[2000009];
vector<pii> e[2];
vector<int> ans;
void adde(int a,int b,int v)
{
	// printf("a:%d b:%d v:%d\n",a,b,v);
	tot+=2;
	eg[tot]=b;
	id[tot]=v;
	nxt[tot]=hd[a];
	hd[a]=tot;
}
void dfs(int x)
{
	for(int &i=hd[x];i;i=nxt[i])
		if(!vis[i])
		{
			int t=id[i];
			vis[i]=vis[i^1]=1;
			dfs(eg[i]);
			ans.push_back(t);
		}
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%s",s+1);
		n=strlen(s+1);
		int mn=0;
		sm[0]=0;
		for(int i=1;i<=n;i++)
		{
			s[i]-='0';
			sm[i]=sm[i-1];
			if(s[i]==0)
				sm[i]++;
			else
				sm[i]--;
			mn=min(mn,sm[i]);
		}
		for(int i=0;i<=n;i++)
			sm[i]-=mn-1;
		e[0].clear(),e[1].clear();
		for(int i=1;i<=n;i++)
		{
			e[s[i]].push_back(pii(sm[i-1],sm[i]));
			e[s[i]^1].push_back(pii(sm[i],sm[i-1]));
		}
		for(int i=0;i<=n;i++)
			hd[sm[i]]=0;
		for(int i=1;i<=tot;i++)
			vis[i]=0;
		tot=0;
		for(pii t:e[1])
			adde(t.fi,t.se,1);
		tot=1;
		for(pii t:e[0])
			adde(t.fi,t.se,0);
		ans.clear();
		dfs(sm[0]);
		// printf("sm0:%d smn:%d\n",sm[0],sm[n]);
		reverse(ans.begin(),ans.end());
		for(int v:ans)
			printf("%d",v);
		printf("\n");
	}
	return 0;
}