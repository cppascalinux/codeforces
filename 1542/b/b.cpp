#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,a,b;
		scanf("%d%d%d",&n,&a,&b);
		if(a==1)
		{
			if((n-1)%b==0)
				printf("Yes\n");
			else
				printf("No\n");
		}
		else
		{
			int fg=0;
			for(ll s=1;s<=n;s*=a)
				if((n-s)%b==0)
					fg=1;
			printf("%s\n",fg?"Yes":"No");
		}
	}
	return 0;
}