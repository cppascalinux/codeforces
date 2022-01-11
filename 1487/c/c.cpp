#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		static int s[109][109];
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				s[i][j]=0;
		int hf=(n-1)/2;
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=i+hf;j++)
				s[i][(j-1)%n+1]=1;
			for(int j=i-1;j>=i-hf;j--)
				s[i][(j+2*n-1)%n+1]=-1;
		}
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				printf("%d ",s[i][j]);
		printf("\n");
	}
	return 0;
}