#include<bits/stdc++.h>
using namespace std;
int n,tot;
char s[1009],out[1009];
int nxt[1000009][27];
int f[1000009],ch[1000009];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		tot=0;
		scanf("%d",&n);
		scanf("%s",s+1);
		for(int i=1;i<=n;i++)
			s[i]-='a'-1;
		for(int i=1;i<=n;i++)
		{

			int cur=0;
			for(int j=i;j<=n;j++)
			{
				if(!nxt[cur][s[j]])
				{
					nxt[cur][s[j]]=++tot;
					f[tot]=cur;
					ch[tot]=s[j];
				}
				cur=nxt[cur][s[j]];
			}
		}
		queue<int> q;
		q.push(0);
		int ans=0,qi=0;
		while(!q.empty())
		{
			int x=q.front();
			q.pop();
			int fg=0;
			for(int i=1;i<=26;i++)
				if(nxt[x][i]==0)
				{
					ans=x;
					qi=i;
					fg=1;
					break;
				}
				else
					q.push(nxt[x][i]);
			if(fg)
				break;
		}
		int tp=0;
		out[++tp]=qi;
		for(int x=ans;x;x=f[x])
			out[++tp]=ch[x];
		for(int i=tp;i>=1;i--)
			printf("%c",'a'-1+out[i]);
		printf("\n");
		for(int i=0;i<=tot;i++)
			memset(nxt[i],0,sizeof(nxt[i]));
	}
	return 0;
}