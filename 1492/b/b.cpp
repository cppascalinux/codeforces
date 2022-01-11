#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n;
int p[100009];
int mx[100009];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d",p+i);
		for(int i=1;i<=n;i++)
		{
			mx[i]=mx[i-1];
			if(p[i]>p[mx[i]])
				mx[i]=i;
		}
		for(int i=n;i;i=mx[i]-1)
		{
			for(int j=mx[i];j<=i;j++)
				printf("%d ",p[j]);
		}
		printf("\n");
	}
	return 0;
}