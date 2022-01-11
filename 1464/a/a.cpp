#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map>
using namespace std;
int n,m;
int f[100009];
int x[100009],y[100009];
int sx[100009],sy[100009];
int fnd(int x)
{
	return x==f[x]?x:f[x]=fnd(f[x]);
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++)
			sx[i]=sy[i]=0;
		for(int i=1;i<=m;i++)
		{
			scanf("%d%d",x+i,y+i);
			f[i]=i;
			sx[x[i]]=i;
			sy[y[i]]=i;
		}
		int ans=m;
		for(int i=1;i<=m;i++)
		{
			if(x[i]==y[i])
			{
				ans--;
				continue;
			}
			if(sx[y[i]])
			{
				int p=sx[y[i]];
				int fp=fnd(p),fi=fnd(i);
				if(fp==fi)
					ans++;
				else
					f[fp]=fi;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}