#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n;
char s[100],ns[100];
int main()
{
	freopen("a.in","w",stdout);
	int t=5000;
	n=50;
	printf("%d\n",t);
	while(t--)
	{
		printf("%d\n",n);
		for(int i=1;i<=n;i+=4)
			printf("abac");
		printf("\n");
	}
	return 0;
}