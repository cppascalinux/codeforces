#include<bits/stdc++.h>
using namespace std;
int n,m;
char s[100009];
int si[100009],sc[100009];
char st[100009];
int mat[1009][1009];
int nmat[1009][1009];
int ans[1009][1009];
void isft()
{
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			nmat[i][mat[i][j]]=j;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			mat[i][j]=nmat[i][j];
}
void csft()
{
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			nmat[mat[j][i]][i]=j;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			mat[i][j]=nmat[i][j];
}
void rsft(int x)
{
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			nmat[i][(j+x-1)%n+1]=mat[i][j];
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			mat[i][j]=nmat[i][j];
}
void dsft(int x)
{
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			nmat[(i+x-1)%n+1][j]=mat[i][j];
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			mat[i][j]=nmat[i][j];
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				scanf("%d",&mat[i][j]);
		scanf("%s",s+1);
		int p[4]={0,1,2,3};
		int ad[4]={0,0,0,0};
		for(int i=1;i<=m;i++)
		{
			if(s[i]=='I')
				swap(p[2],p[3]);
			else if(s[i]=='C')
				swap(p[1],p[3]);
			else if(s[i]=='R')
				ad[p[2]]++;
			else if(s[i]=='L')
				ad[p[2]]--;
			else if(s[i]=='D')
				ad[p[1]]++;
			else if(s[i]=='U')
				ad[p[1]]--;
		}
		for(int i=1;i<=3;i++)
			ad[i]=(ad[i]%n+n)%n;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
			{
				int t[4]={0,i,j,mat[i][j]};
				int a=(t[p[1]]+ad[p[1]]-1)%n+1;
				int b=(t[p[2]]+ad[p[2]]-1)%n+1;
				int c=(t[p[3]]+ad[p[3]]-1)%n+1;
				ans[a][b]=c;
			}
		// si[m+1]=sc[m+1]=0;
		// int rs=0,ds=0;//right shift,down shift
		// for(int i=m;i>=1;i--)
		// {
		// 	si[i]=si[i+1],sc[i]=sc[i+1];
		// 	if(s[i]=='I')
		// 		si[i]++;
		// 	else if(s[i]=='C')
		// 		sc[i]++;
		// 	else if(s[i]=='R'||s[i]=='L')
		// 		rs+=(s[i]=='R')^(si[i]&1)?1:-1;
		// 	else if(s[i]=='U'||s[i]=='D')
		// 		ds+=(s[i]=='D')^(sc[i]&1)?1:-1;
		// }
		// int tp=0;
		// for(int i=1;i<=m;i++)
		// 	if(s[i]=='I'||s[i]=='C')
		// 	{
		// 		if(tp&&s[i]==st[tp])
		// 			tp--;
		// 		else
		// 			st[++tp]=s[i];
		// 	}
		// for(int i=1;i<=m;i++)
		// 	if(s[i]=='I')
		// 		isft();
		// 	else if(s[i]=='C')
		// 		csft();
		// 	else if(s[i]=='R')
		// 		rsft(1);
		// 	else if(s[i]=='L')
		// 		rsft(n-1);
		// 	else if(s[i]=='D')
		// 		dsft(1);
		// 	else if(s[i]=='U')
		// 		dsft(n-1);
		// printf("tp:%d\n",tp);
		// // tp%=6;
		// for(int i=1;i<=tp;i++)
		// 	if(st[i]=='I')
		// 		isft();
		// 	else if(st[i]=='C')
		// 		csft();
		// rsft((rs%n+n)%n);
		// dsft((ds%n+n)%n);
		// printf("ans:\n");
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				printf("%d%c",ans[i][j],j==n?'\n':' ');
		// printf("\n");
	}
	return 0;
}