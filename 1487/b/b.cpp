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
		int n,k;
		scanf("%d%d",&n,&k);
		if(n%2==0)
		{
			printf("%d\n",(k-1)%n+1);
			continue;
		}
		int hf=(n-1)/2;
		int cl=(k-1)/hf;
		printf("%d\n",(k+cl-1)%n+1);
	}
	return 0;
}