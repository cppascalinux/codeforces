#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;
int n,m;
pii s[200009];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		for(int i=1;i<=m;i++)
			scanf("%d%d",&s[i].se,&s[i].fi);
		sort(s+1,s+m+1);
		if(m&1)
		{
			printf("NO\n");
			continue;
		}
		int fg=1;
		s[m+1].fi=-1;
		for(int i=1;i<=m;i+=2)
		{
			if(s[i+1].se==s[i].se&&(s[i+1].fi-s[i].fi)%2==0)
				fg=0;
			if(s[i+1].se!=s[i].se&&(s[i+1].fi-s[i].fi)%2==1)
				fg=0;
			if(s[i+2].fi==s[i+1].fi)
				fg=0;
		}
		printf("%s\n",fg?"YES":"NO");
	}
	return 0;
}