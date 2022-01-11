#include<bits/stdc++.h>
using namespace std;
int k;
int mat[1509][1509];
int p[1509],q[1509];
bool cmp(int a,int b)
{
	return mat[a][k]<mat[b][k];
}
int main()
{
	int n=1500,m=1500;
	printf("%d %d\n",n,m);
	random_device rnd;
	uniform_int_distribution<int> mp(1,n);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			mat[i][j]=mp(rnd);
			printf("%d ",mat[i][j]);
		}
		printf("\n");
	}
	for(int i=1;i<=m;i++)
		p[i]=i;
	shuffle(p+1,p+m+1,rnd);
	for(int i=1;i<=n;i++)
		q[i]=i;
	for(int i=1;i<=m;i++)
	{
		k=p[i];
		stable_sort(q+1,q+n+1,cmp);
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
			printf("%d ",mat[q[i]][j]);
		printf("\n");
	}
	return 0;
}