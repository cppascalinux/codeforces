#include<bits/stdc++.h>
using namespace std;
int p[200009];
int main()
{
	int n=5;
	printf("%d\n",n);
	random_device rnd;
	for(int i=1;i<=2*n;i++)
		p[i]=i;
	shuffle(p+1,p+2*n+1,rnd);
	for(int i=1;i<=2*n;i++)
		printf("%d ",p[i]);
	return 0;
}