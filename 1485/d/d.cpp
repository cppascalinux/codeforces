#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,m;
int mt[509][509];
int ans[509][509];
int pow4(int x)
{
	x*=x;
	x*=x;
	return x;
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			scanf("%d",mt[i]+j);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			if((i+j)%2==0)
				ans[i][j]=720720;
			else
				ans[i][j]=720720-pow4(mt[i][j]);
		}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			printf("%d%c",ans[i][j],j==m?'\n':' ');
	return 0;
}