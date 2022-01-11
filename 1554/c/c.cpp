#include<bits/stdc++.h>
#define ui unsigned int
using namespace std;
ui n,m;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%u%u",&n,&m);
		ui ans=0;
		for(int i=31;i>=0;i--)
		{
			ui t1=(ans^n)|((1u<<i)-1);
			if(t1<=m)
				ans+=1u<<i;
		}
		printf("%u\n",ans);
	}
	return 0;
}