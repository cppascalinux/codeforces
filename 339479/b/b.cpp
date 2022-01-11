#include<bits/stdc++.h>
#define ll long long
#define db double
#define mod 1000000007
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;
int n,m;
char s[1009];
int main()
{
	int ttt;
	scanf("%d",&ttt);
	while(ttt--)
	{
		scanf("%d",&n);
		scanf("%s",s+1);
		for(int i=1;i<=n;i++)
			s[i]=s[i]=='?'?-1:s[i]=='B'?0:1;
		int lp=0;
		for(int i=1;i<=n;i++)
		{
			if(!lp&&s[i]>=0)
				lp=i;
			if(lp&&s[i]==-1)
				s[i]=s[i-1]^1;
		}
		if(lp==0)
			lp=n+1;
		s[n+1]=0;
		for(int i=lp-1;i>=1;i--)
			s[i]=s[i+1]^1;
		for(int i=1;i<=n;i++)
			printf("%c",s[i]?'R':'B');
		printf("\n");
	}
	return 0;
}