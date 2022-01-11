#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		int s[109];
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d",s+i);
		int ans=0;
		for(int i=2;i<=n;i++)
		{
			int a=s[i-1],b=s[i];
			if(a>b)
				swap(a,b);
			while(2*a<b)
				a*=2,ans++;
		}
		printf("%d\n",ans);
	}
	return 0;
}