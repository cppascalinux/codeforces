#include<bits/stdc++.h>
using namespace std;
int n,q;
char s[100009];
int sm[30][100009];
int main()
{
	scanf("%d%d",&n,&q);
	scanf("%s",s+1);
	for(int i=1;i<=n;i++)
	{
		s[i]-='a'-1;
		for(int j=1;j<=26;j++)
			sm[j][i]=sm[j][i-1];
		sm[s[i]][i]++;
	}
	for(int i=1;i<=q;i++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		int ans=0;
		for(int j=1;j<=26;j++)
		{
			int tl=sm[j][b]-sm[j][a-1];
			ans+=tl*j;
		}
		printf("%d\n",ans);
	}
	return 0;
}