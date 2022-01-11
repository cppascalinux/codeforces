#include<bits/stdc++.h>
using namespace std;
int n,m;
int ls[200009];
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		if(a>b)
			ls[b]++;
		else
			ls[a]++;
	}
	int ans=0;
	for(int i=1;i<=n;i++)
		if(ls[i]==0)
			ans++;
	int q;
	scanf("%d",&q);
	for(int i=1;i<=q;i++)
	{
		int a,b,c;
		scanf("%d",&a);
		if(a==3)
			printf("%d\n",ans);
		else if(a==1)
		{
			scanf("%d%d",&b,&c);
			int v=min(b,c);
			if(ls[v]==0)
				ans--;
			ls[v]++;
		}
		else
		{
			scanf("%d%d",&b,&c);
			int v=min(b,c);
			ls[v]--;
			if(ls[v]==0)
				ans++;
		}
	}
	return 0;
}