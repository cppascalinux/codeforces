#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,k;
		scanf("%d",&n);
		for(int i=0;i<=30;i++)
			if((1<<i)&n)
				k=1<<i;
		printf("%d\n",k-1);
	}
	return 0;
}