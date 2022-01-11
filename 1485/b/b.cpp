#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;
int main()
{
	int n,q,k;
	scanf("%d%d%d",&n,&q,&k);
	static int s[100009];
	for(int i=1;i<=n;i++)
		scanf("%d",s+i);
	for(int i=1;i<=q;i++)
	{
		int l,r;
		scanf("%d%d",&l,&r);
		printf("%d\n",k-(r-l+1)+(s[r]-s[l]+1)-(r-l+1));
	}
	return 0;
}