#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;
int n,k;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&k);
		int fl=(k-1)/n+1,cl=k/n;
		if(k<n)
			printf("%d\n",n%k==0?1:2);
		else
			printf("%d\n",fl);
	}
	return 0;
}