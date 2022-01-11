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
		int n,sm=0;
		int s[109],f[209];
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d",s+i),sm+=s[i];
		for(int i=1;i<=sm;i++)
			f[i]=0;
		f[0]=1;
		for(int i=1;i<=n;i++)
			for(int j=sm;j>=s[i];j--)
				f[j]|=f[j-s[i]];
		if(sm%2==0&&f[sm/2])
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}