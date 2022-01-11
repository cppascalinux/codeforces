#include<bits/stdc++.h>
using namespace std;
int n;
vector<int> g[70000];
int p[70000],rp[70000];
int cl[70000];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(int i=0;i<(1<<n);i++)
			g[i].clear(),p[i]=rp[i]=-1;
		for(int i=1;i<=(n<<(n-1));i++)
		{
			int a,b;
			scanf("%d%d",&a,&b);
			g[a].push_back(b);
			g[b].push_back(a);
		}
		p[0]=rp[0]=0;
		int s=1;
		for(int v:g[0])
		{
			// printf("s:%d v:%d\n",s,v);
			p[s]=v;
			rp[v]=s;
			s<<=1;
		}
		for(int s=1;s<(1<<n);s++)
			if(s!=(s&-s))
			{
				// printf("s:%d\n",s);
				int b1=s^(s&-s);
				int b2=s^(b1&-b1);
				set<int> r;
				for(int v:g[p[b1]])
					r.insert(v);
				for(int v:g[p[b2]])
					if(r.count(v)&&rp[v]==-1)
						p[s]=v,rp[v]=s;
			}
		for(int s=0;s<(1<<n);s++)
			printf("%d ",p[s]);
		printf("\n");
		if(n!=(n&-n))
		{
			printf("-1\n");
			continue;
		}
		for(int s=0;s<(1<<n);s++)
		{
			cl[s]=0;
			for(int i=0;i<n;i++)
				cl[s]^=(s>>i&1)*i;
			// printf("s:%d rp:%d cl:%d\n",s,rp[s],cl[s]);
		}
		for(int s=0;s<(1<<n);s++)
			printf("%d ",cl[rp[s]]);
		printf("\n");
	}
	return 0;
}