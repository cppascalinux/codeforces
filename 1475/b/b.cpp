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
		scanf("%d",&n);
		int rep=n/2020,rs=n%2020;
		if(rs<=rep)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}