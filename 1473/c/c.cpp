#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,k;
int ans[100009];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&k);
		for(int i=1;i<=k;i++)
			ans[i]=i;
		reverse(ans+2*k-n,ans+k+1);
		for(int i=1;i<=k;i++)
			printf("%d ",ans[i]);
		printf("\n");
	}
	return 0;
}