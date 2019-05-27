#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,q;
int s[300009];
int f[300009][21];
int mn[21][21];
void init()
{
	memset(mn,0x7F,sizeof(mn));
	memset(f,0x7F,sizeof(f));
	for(int i=n;i>=1;i--)
		for(int j=0;j<=18;j++)
		{
			if((s[i]>>j)&1)
				f[i][j]=i;
			else
			{
				for(int k=0;k<=18;k++)
					if((s[i]>>k)&1)
						f[i][j]=min(f[i][j],mn[k][j]);
			}
			for(int k=0;k<=18;k++)
				if((s[i]>>k)&1)
					mn[k][j]=min(mn[k][j],f[i][j]);
		}
	// for(int i=1;i<=n;i++)
	// 	for(int j=0;j<=18;j++)
	// 		printf("i:%d j:%d f:%d\n",i,j,f[i][j]);
}
int main()
{
#ifdef I_LOVE_KTY
	freopen("e.in","r",stdin);
	freopen("e.out","w",stdout);
#endif
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++)
		scanf("%d",s+i);
	init();
	for(int i=1,a,b;i<=q;i++)
	{
		scanf("%d%d",&a,&b);
		int ans=0;
		for(int j=0;j<=18;j++)
			if((s[b]>>j)&1)
				ans|=f[a][j]<=b;
		printf("%s\n",ans?"Shi":"Fou");
	}
	return 0;
}