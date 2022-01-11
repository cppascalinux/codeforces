#include<bits/stdc++.h>
using namespace std;
int n,d;
int s[200009],v[200009];
int c[200009];
int vis[200009];
void add(int x,int v)
{
	for(;x<=d;x+=x&-x)
		c[x]+=v;
}
int ask(int x)
{
	int ans=0;
	for(;x;x-=x&-x)
		ans+=c[x];
	return ans;
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d",s+i);
		memcpy(v,s,(n+1)*4);
		sort(v+1,v+n+1);
		d=unique(v+1,v+n+1)-v-1;
		for(int i=1;i<=n;i++)
			s[i]=lower_bound(v+1,v+d+1,s[i])-v;
		add(s[1],1);
		// printf("ask:%d\n",ask(s[1]));
		vis[s[1]]=1;
		int fg=0;
		for(int i=2;i<=n;i++)
		{
			// printf("i:%d s:%d\n",i,s[i]);
			if(!vis[s[i]])
			{
				vis[s[i]]=1;
				add(s[i],1);
			}
			int r1=ask(s[i-1]),r2=ask(s[i]);
			// printf("i:%d r1:%d r2:%d\n",i,r1,r2);
			if(abs(r1-r2)>1)
				fg=1;
		}
		printf("%s\n",fg?"NO":"YES");
		for(int i=1;i<=n;i++)
			c[i]=vis[i]=0;
	}
	return 0;
}