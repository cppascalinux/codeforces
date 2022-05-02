#include<bits/stdc++.h>
using namespace std;
int n;
int getsm(int x)
{
	x%=32768;
	if(x==0)
		return 0;
	for(int i=0;i<=14;i++)
		if(x>>i&1)
			return 15-i;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		int a;
		scanf("%d",&a);
		int ans=15;
		for(int j=0;j<=15;j++)
		{
			int b=a+j;
			if(getsm(b)+j<ans)
				ans=getsm(b)+j;
		}
		printf("%d ",ans);
	}
	return 0;
}