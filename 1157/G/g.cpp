#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,m;
int mat[209][209];//origin value
int nxt[209][209];//expected value
int sol[209][209],out[209][209];//
int ix[209],iy[209];
void getout0()
{
	memset(ix,0,sizeof(ix));
	memset(iy,0,sizeof(iy));
	for(int i=1;i<=m;i++)
		if(sol[1][i])
			iy[i]=1;
	for(int i=2;i<=n;i++)
		for(int j=1;j<=m;j++)
			if(ix[i]^iy[j]^sol[i][j])
				ix[i]^=1;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			out[i][j]=mat[i][j]^ix[i]^iy[j];
}
void getout1()
{
	memset(ix,0,sizeof(ix));
	memset(iy,0,sizeof(iy));
	ix[1]=1;
	for(int i=1;i<=m;i++)
		if(!sol[1][i])
			iy[i]=1;
	for(int i=2;i<=n;i++)
		for(int j=1;j<=m;j++)
			if(ix[i]^iy[j]^sol[i][j])
				ix[i]^=1;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			out[i][j]=mat[i][j]^ix[i]^iy[j];
}
int solve0()
{
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			nxt[i][j]=1;
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
			for(int k=1;k<=m;k++)
				sol[j][k]=mat[j][k]^nxt[j][k];
		int fg=1;
		getout0();
		for(int j=1;j<=n;j++)
			for(int k=1;k<=m;k++)
				if(out[j][k]!=nxt[j][k])
					fg=0;
		if(fg)
			return 1;

		fg=1;
		getout1();
		for(int j=1;j<=n;j++)
			for(int k=1;k<=m;k++)
				if(out[j][k]!=nxt[j][k])
					fg=0;
		if(fg)
			return 1;
		nxt[1][i]=0;
	}
	return 0;
}
int solve1()
{
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			nxt[i][j]=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
			nxt[i][j]=0;
		for(int j=1;j<=n;j++)
			for(int k=1;k<=m;k++)
				sol[j][k]=mat[j][k]^nxt[j][k];
		int fg=1;
		getout0();
		for(int j=1;j<=i;j++)
			for(int k=1;k<=m;k++)
				if(out[j][k])
					fg=0;
		for(int j=i+2;j<=n;j++)
			for(int k=1;k<=m;k++)
				if(!out[j][k])
					fg=0;
		for(int j=2;j<=m;j++)
			if(out[i][j]<out[i][j-1])
				fg=0;
		if(fg)
			return 1;

		fg=1;
		getout1();
		for(int j=1;j<=i;j++)
			for(int k=1;k<=m;k++)
				if(out[j][k])
					fg=0;
		for(int j=i+2;j<=n;j++)
			for(int k=1;k<=m;k++)
				if(!out[j][k])
					fg=0;
		for(int j=2;j<=m;j++)
			if(out[i][j]<out[i][j-1])
				fg=0;
		if(fg)
			return 1;
	}
	return 0;
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("g.in","r",stdin);
	freopen("g.out","w",stdout);
#endif
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			scanf("%d",&mat[i][j]);
	if(solve0())
	{
		printf("YES\n");
		for(int i=1;i<=n;i++)
			printf("%d",ix[i]);
		printf("\n");
		for(int i=1;i<=m;i++)
			printf("%d",iy[i]);
		return 0;
	}
	if(solve1())
	{
		printf("YES\n");
		for(int i=1;i<=n;i++)
			printf("%d",ix[i]);
		printf("\n");
		for(int i=1;i<=m;i++)
			printf("%d",iy[i]);
		return 0;
	}
	printf("NO");
	return 0;
}