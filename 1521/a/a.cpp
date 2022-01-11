#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		if(b==1)
			printf("NO\n");
		else if(b==2)
		{
			printf("YES\n");
			printf("%d %d %d\n",a,3*a,4*a);
		}
		else
		{
			printf("YES\n");
			printf("%d %lld %lld\n",a,(ll)a*(b-1),(ll)a*b);
		}
	}
	return 0;
}