#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n=1500,q=10;
	random_device rnd;
	printf("%d %d\n",n,q);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
			printf("%d ",rnd()%10+1);
		printf("\n");
	}
	return 0;
}