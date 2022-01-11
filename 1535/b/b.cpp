#include<bits/stdc++.h>
using namespace std;
int n;
int a[2009];
int gcd(int a,int b)
{
	return !a||!b?a+b:gcd(b,a%b);
}
int cmp(int a,int b)
{
	return a%2<b%2;
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d",a+i);
		sort(a+1,a+n+1,cmp);
		// for(int i=1;i<=n;i++)
		// 	printf("i:%d a:%d\n",i,a[i]);
		int ans=0;
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				if(gcd(a[i],2*a[j])>1)
					ans++;
		printf("%d\n",ans);
	}
	return 0;
}