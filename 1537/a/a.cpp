#include<bits/stdc++.h>
using namespace std;
int s[109];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,sm=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d",s+i),s[i]--,sm+=s[i];
		if(sm==0)
			printf("0\n");
		else if(sm<0)
			printf("1\n");
		else
			printf("%d\n",sm);
	}
	return 0;
}