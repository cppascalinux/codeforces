#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int n;
int x[200009];
int test(int v)
{
	for(int i=1;i<=n;i++)
		if(abs(x[i]-(v+i-1))>1)
			return 0;
	return 1;
}
int main()
{
	int tt;
	scanf("%d",&tt);
	while(tt--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d",x+i);
		if(test(x[1]-1)||test(x[1])||test(x[1]+1))
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}