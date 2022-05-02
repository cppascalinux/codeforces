#include<bits/stdc++.h>
using namespace std;
int n;
int s[1000009];
int gcd(int a,int b)
{
	return b?gcd(b,a%b):a;
}
int main()
{
	scanf("%d",&n);
	int mx=0;
	for(int i=1;i<=n;i++)
	{
		int a;
		scanf("%d",&a);
		s[a]=1;
		mx=max(mx,a);
	}
	// mx=1000000;
	int ans=0;
	for(int i=1;i<=mx;i++)
	{
		if(s[i])
			continue;
		int g=0;
		for(int j=2,k=2*i;k<=mx;j++,k+=i)
			if(s[k])
			{
				g=gcd(j,g);
				if(g==1)
				{
					ans++;
					break;
				}
			}
	}
	printf("%d",ans);
	return 0;
}