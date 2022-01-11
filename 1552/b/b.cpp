#include<bits/stdc++.h>
using namespace std;
int n;
int s[50009][6];
int cmp(int a,int b)// a better than b
{
	int sm=0;
	for(int i=1;i<=5;i++)
		if(s[a][i]<s[b][i])
			sm++;
	return sm>=3;
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=5;j++)
				scanf("%d",&s[i][j]);
		}
		int mx=1;
		for(int i=2;i<=n;i++)
			if(cmp(i,mx))
				mx=i;
		int fg=1;
		for(int i=1;i<=n;i++)
			if(i!=mx&&cmp(i,mx))
				fg=0;
		printf("%d\n",fg?mx:-1);
	}
}