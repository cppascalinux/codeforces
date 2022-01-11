#include<bits/stdc++.h>
using namespace std;
int n,m;
int s[100009];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		for(int i=0;i<=m;i++)
			s[i]=0;
		for(int i=1;i<=n;i++)
		{
			int a;
			scanf("%d",&a);
			s[a%m]++;
		}
		int ans=0;
		for(int i=0;i<=m/2;i++)
		{
			int b=(m-i)%m;
			if(b==i)
			{
				if(s[i])
					ans++;
			}
			else if(s[i]||s[b])
			{
				if(abs(s[i]-s[b])<=1)
					ans++;
				else
					ans+=abs(s[i]-s[b]);
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}