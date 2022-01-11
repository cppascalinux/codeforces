#include<bits/stdc++.h>
#define ll long long
#define db double
#define mod 1000000007
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;
int n,m;
int s[10009];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",s+i);
	for(int i=1;i<=n-1;i++)
		if(s[i]==0&&s[i+1]==1)
		{
			for(int j=1;j<=i;j++)
				printf("%d ",j);
			printf("%d ",n+1);
			for(int j=i+1;j<=n;j++)
				printf("%d ",j);
			return 0;
		}
	s[0]=1,s[n+1]=0;
	for(int i=0;i<=n;i++)
		if(s[i]==1&&s[i+1]==0)
		{
			for(int j=i+1;j<=n;j++)
				printf("%d ",j);
			printf("%d ",n+1);
			for(int j=1;j<=i;j++)
				printf("%d ",j);
			return 0;
		}
	return 0;
}