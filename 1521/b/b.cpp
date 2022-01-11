#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n;
int s[100009];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d",s+i);
		int mn=2e9,p=0;
		for(int i=1;i<=n;i++)
			if(s[i]<mn)
				mn=s[i],p=i;
		printf("%d\n",n-1);
		for(int i=1;i<p;i++)
			printf("%d %d %d %d\n",i,p,mn+(p-i),mn);
		for(int i=p+1;i<=n;i++)
			printf("%d %d %d %d\n",i,p,mn+(i-p),mn);
	}
	return 0;
}