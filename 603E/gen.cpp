#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<random>
using namespace std;
int main()
{
	freopen("lct.in","w",stdout);
	random_device sd;
	mt19937 rnd(sd());
	int n=10,m=9;
	printf("%d %d\n",n,m);
	for(int i=2;i<=n;i++)
		printf("%d %d %d\n",i,rnd()%(i-1)+1,rnd()%1000000000+1);
	for(int i=n;i<=m;i++)
	{
		int a=rnd()%n+1,b=rnd()%n+1;
		if(a==b)
			i--;
		else
			printf("%d %d %d\n",a,b,rnd()%1000000000+1);
	}
	return 0;
}