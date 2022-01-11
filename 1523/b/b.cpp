#include<bits/stdc++.h>
using namespace std;
int n;
int s[10009];
int main()
{
	int ttt;
	scanf("%d",&ttt);
	while(ttt--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d",s+i);
		printf("%d\n",n*3);
		for(int i=1;i<=n;i+=2)
		{
			for(int j=1;j<=3;j++)
			{
				printf("1 %d %d\n",i,i+1);
				printf("2 %d %d\n",i,i+1);
			}
		}
	}
	return 0;
}