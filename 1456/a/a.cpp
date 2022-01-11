#include<bits/stdc++.h>
#define inf 0x7F7F7F7F
using namespace std;
int n,p,k,x,y;
char s[100009];
int sm[100009];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d%d",&n,&p,&k);
		scanf("%s",s+1);
		scanf("%d%d",&x,&y);
		for(int i=1;i<=n;i++)
			s[i]-='0';
		for(int i=n;i>=1;i--)
		{
			sm[i]=s[i]^1;
			if(i+k<=n)
				sm[i]+=sm[i+k];
		}
		int ans=inf;
		for(int i=1;i<=n-p+1;i++)
		{
			ans=min(ans,(i-1)*y+sm[i+p-1]*x);
		}
		printf("%d\n",ans);
	}
	return 0;
}