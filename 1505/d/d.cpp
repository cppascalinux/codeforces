#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,m;
	int mat[10][10];
	char s[10];
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%s",s+1);
		for(int j=1;j<=m;j++)
			if(s[j]=='*')
				mat[i][j]=1;
			else
				mat[i][j]=0;
	}
	int ans=0;
	int curx=1,cury=1;
	if(mat[1][1])
		ans++;
	while(1)
	{
		int nx=n,ny=m;
		for(int i=curx;i<=n;i++)
			for(int j=cury;j<=m;j++)
				if(mat[i][j]&&(i!=curx||j!=cury))
				{
					if(i-curx+j-cury<nx-curx+ny-cury)
						nx=i,ny=j;
				}
		curx=nx,cury=ny;
		if(mat[curx][cury])
			ans++;
		if(curx==n&&cury==m)
			break;
	}
	printf("%d",ans);
	return 0;
}