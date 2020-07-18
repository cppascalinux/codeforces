#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define INF 0x7F7F7F7F
using namespace std;
int n;
char s[200009];
int sm[27][200009];
int f[27][200009];
void dp()
{
	int mx=0;
	for(int i=0;i<=18;i++)
		if(n>>i&1)
			mx=i;
	// printf("n:%d mx:%d\n",n,mx);
	for(int i=1;i<=n;i++)
		f[0][i]=(s[i]==mx+1?0:1);
	for(int i=1;i<=mx;i++)
		for(int j=1;j<=n;j+=(1<<i))
			f[i][j]=min(f[i-1][j]+(1<<(i-1))-(sm[mx-i+1][j+(1<<i)-1]-sm[mx-i+1][j+(1<<(i-1))-1]),
						f[i-1][j+(1<<(i-1))]+(1<<(i-1))-(sm[mx-i+1][j+(1<<(i-1))-1]-sm[mx-i+1][j-1]));
	printf("%d\n",f[mx][1]);
}
int main()
{
#ifdef I_LOVE_KTY
	freopen("d.in","r",stdin);
	freopen("d.out","w",stdout);
#endif
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		scanf("%s",s+1);
		for(int i=1;i<=n;i++)
			s[i]-='a'-1;
		for(int i=1;i<=26;i++)
			for(int j=1;j<=n;j++)
				sm[i][j]=sm[i][j-1]+(s[j]==i);
		dp();
	}
	return 0;
}