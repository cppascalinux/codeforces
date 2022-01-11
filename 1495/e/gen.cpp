#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n=1000;
	random_device rnd;
	printf("%d %d\n",n,n);
	for(int i=1;i<=n;i++)
		printf("%d %d\n",rnd()%2+1,rnd()%2+1);
	return 0;
}