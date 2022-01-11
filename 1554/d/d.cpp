#include<bits/stdc++.h>
using namespace std;
int n;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		if(n==1)
		{
			printf("a\n");
			continue;
		}
		int md=n/2;
		for(int i=1;i<=md-1;i++)
			printf("a");
		printf("b");
		for(int i=1;i<=md;i++)
			printf("a");
		if(n&1)
			printf("c");
		printf("\n");
	}
	return 0;
}