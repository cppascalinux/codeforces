#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n;
int s[200009];
int main()
{
#ifdef I_LOVE_KTY
	freopen("c.in","r",stdin);
	freopen("c.out","w",stdout);
#endif
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d",s+i);
		int mid=n;
		for(int i=n;i>=1;i--)
			if(s[i]>=s[i+1])
				mid=i;
			else
				break;
		if(mid<=1)
		{
			printf("0\n");
			continue;
		}
		int ls=mid;
		for(int i=mid-1;i>=1;i--)
			if(s[i+1]>=s[i])
				ls=i;
			else
				break;
		printf("%d\n",ls-1);
	}
	return 0;
}