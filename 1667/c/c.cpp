#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int n;
int main()
{
	int n;
	scanf("%d",&n);
	if(n==1)
	{
		printf("1\n1 1\n");
		return 0;
	}
	int m=(2*n-1+3-1)/3;
	int q=n-m;
	printf("%d\n",m);
	for(int i=1;i<=q;i++)
		printf("%d %d\n",m-i+1,m-q+i);
	for(int i=1;i<=q-1;i++)
		printf("%d %d\n",m-q-i+1,m-q-(q-1)+i);
	for(int i=1;i<=m-q-(q-1);i++)
		printf("%d %d\n",i,i);
	return 0;
}