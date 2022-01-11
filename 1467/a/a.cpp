#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n;
int ans[200009];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		ans[2]=8;
		for(int i=1;i<=n;i++)
		{
			if(i!=2)
				ans[i]=(8+abs(i-2))%10;
			printf("%d",ans[i]);
		}
		printf("\n");
	}
	return 0;
}