#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define inf 0x7F7F7F7F
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;
int n,m;
char s[200009];
int sm[200009];
int mx[20][200009],mn[20][200009];
int lg[200009];
void init()
{
	for(int i=1;i<=n;i++)
		mx[0][i]=mn[0][i]=sm[i];
	for(int i=1;i<=18;i++)
		for(int j=1;j+(1<<i)-1<=n;j++)
		{
			mx[i][j]=max(mx[i-1][j],mx[i-1][j+(1<<(i-1))]);
			mn[i][j]=min(mn[i-1][j],mn[i-1][j+(1<<(i-1))]);
		}
	for(int i=2;i<=n;i++)
		lg[i]=lg[i>>1]+1;
}
pii qry(int l,int r)//min,max
{
	if(l>r)
		return pii(inf,-inf);
	int ln=lg[r-l+1];
	int an=min(mn[ln][l],mn[ln][r-(1<<ln)+1]);
	int ax=max(mx[ln][l],mx[ln][r-(1<<ln)+1]);
	return pii(an,ax);
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		scanf("%s",s+1);
		for(int i=1;i<=n;i++)
			sm[i]=s[i]=='+'?sm[i-1]+1:sm[i-1]-1;
		// for(int i=1;i<=n;i++)
		// 	printf("i:%d sm:%d\n",i,sm[i]);
		init();
		for(int i=1;i<=m;i++)
		{
			int l,r;
			scanf("%d%d",&l,&r);
			if(l==1&&r==n)
			{
				printf("1\n");
				continue;
			}
			int tsm=sm[r]-sm[l-1];
			int mn=0,mx=0;
			if(l>1)
			{
				pii t=qry(1,l-1);
				mn=min(mn,t.fi);
				mx=max(mx,t.se);
			}
			if(r<n)
			{
				pii t=qry(r+1,n);
				mn=min(mn,t.fi-tsm);
				mx=max(mx,t.se-tsm);
			}
			printf("%d\n",mx-mn+1);
		}
	}
	return 0;
}