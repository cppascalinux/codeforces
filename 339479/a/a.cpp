#include<bits/stdc++.h>
#define ll long long
#define db double
#define mod 1000000007
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;
int n,m;
int s[100009];
int main()
{
	int ttt;
	scanf("%d",&ttt);
	while(ttt--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d",s+i);
		int ans=0;
		for(int i=0;i<=30;i++)
		{
			int t=1<<i;
			int fg=1;
			for(int j=1;j<=n;j++)
				if(!(t&s[j]))
					fg=0;
			if(fg)
				ans+=t;
		}
		printf("%d\n",ans);
	}
	return 0;
}