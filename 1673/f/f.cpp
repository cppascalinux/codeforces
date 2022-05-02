#include<bits/stdc++.h>
using namespace std;
int n,k;
int main()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n-1;j++)
			printf("%d ",2*(j&-j)*(j&-j));
		printf("\n");
	}
	for(int j=1;j<=n-1;j++)
	{
		for(int i=1;i<=n;i++)
			printf("%d ",(j&-j)*(j&-j));
		printf("\n");
	}
	fflush(stdout);
	int lv=0;
	for(int i=1;i<=k;i++)
	{
		int v;
		scanf("%d",&v);
		v^=lv;
		lv=v;
		int sx=0,sy=0;
		int t=v;
		for(int j=4;j>=0;j--)
		{
			if(t&(1<<(j*2)))
			{
				sx+=1<<j;
				t^=1<<(j*2);
				if(j)
					t^=1<<(j*2-2);
			}
		}
		t>>=1;
		for(int j=4;j>=0;j--)
		{
			if(t&(1<<(j*2)))
			{
				sy+=1<<j;
				t^=1<<(j*2);
				if(j)
					t^=1<<(j*2-2);
			}
		}
		printf("%d %d\n",sx+1,sy+1);
		fflush(stdout);
	}
	return 0;
}