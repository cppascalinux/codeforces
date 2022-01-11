#include<bits/stdc++.h>
using namespace std;
int n,m;
vector<int> v[100009];
int sm[100009],ans[100009];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		for(int i=1;i<=m;i++)
		{
			v[i].clear();
			int a,b;
			scanf("%d",&a);
			for(int j=1;j<=a;j++)
			{
				scanf("%d",&b);
				v[i].push_back(b);
			}
		}
		for(int i=1;i<=n;i++)
			sm[i]=0;
		for(int i=1;i<=m;i++)
			if(v[i].size()==1)
				sm[v[i][0]]++;
		int fg=1;
		for(int i=1;i<=n;i++)
			if(sm[i]>(m+1)/2)
				fg=0;
		if(!fg)
		{
			printf("NO\n");
			continue;
		}
		printf("YES\n");
		sm[0]=10000000;
		for(int i=1;i<=m;i++)
			if(v[i].size()==1)
				ans[i]=v[i][0];
			else
			{
				int mn=0;
				for(int j:v[i])
					if(sm[j]<sm[mn])
						mn=j;
				sm[mn]++;
				ans[i]=mn;
			}
		for(int i=1;i<=m;i++)
			printf("%d ",ans[i]);
		printf("\n");
	}
	return 0;
}