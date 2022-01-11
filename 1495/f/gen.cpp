#include<bits/stdc++.h>
using namespace std;
int n=200000,q=200000,m=1e9;
random_device rnd;
uniform_int_distribution<int> gp(-m,m);
int p[200009];
int main()
{
	printf("%d %d\n",n,q);
	for(int i=1;i<=n;i++)
		p[i]=i;
	shuffle(p+1,p+n+1,rnd);
	for(int i=1;i<=n;i++)
		printf("%d ",p[i]);
	printf("\n");
	for(int i=1;i<=n;i++)
		printf("%d ",gp(rnd));
	printf("\n");
	for(int i=1;i<=n;i++)
		printf("%d ",gp(rnd));
	printf("\n");
	for(int i=1;i<=q;i++)
		printf("%d\n",rnd()%n+1);
	return 0;
}