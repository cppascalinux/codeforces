#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;
int n,m,tcl;
int mat[1009][1009];
int vis[1009],st[1009],ins[1009];
int cl[1009],deg[1009];
char s[1009];
void dfs(int x,int d)
{
	vis[x]=1;
	st[d]=x;
	ins[x]=d;
	for(int i=1;i<=n&&!tcl;i++)
		if(mat[x][i]==1&&!vis[i]&&!tcl)
			dfs(i,d+1);
		else if(mat[x][i]==1&&ins[i]&&!tcl)
		{
			for(int j=ins[i];j<=d;j++)
				cl[++tcl]=st[j];
			break;
		}
	ins[x]=0;
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++)
		{
			scanf("%s",s+1);
			for(int j=1;j<=n;j++)
				if(i!=j)
					mat[i][j]=s[j]-'a'+1;
		}
		if(m%2==1)
		{
			printf("YES\n");
			for(int i=1;i<=m+1;i++)
				printf("%d ",i%2+1);
			printf("\n");
			continue;
		}
		int fi=0,fj=0;
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				if(mat[i][j]==mat[j][i])
				{
					fi=i,fj=j;
					break;
				}
		if(fi)
		{
			printf("YES\n");
			printf("%d ",fi);
			for(int i=1;i<=m;i++)
			{
				swap(fi,fj);
				printf("%d ",fi);
			}
			printf("\n");
			continue;
		}
		if(n==2)
		{
			printf("NO\n");
			continue;
		}
		for(int i=1;i<=n;i++)
			vis[i]=ins[i]=0;
		tcl=0;
		for(int i=1;i<=n;i++)
			if(!vis[i])
				dfs(i,1);
		if(tcl)
		{
			// printf("loop");
			printf("YES\n");
			for(int i=1;i<=m+1;i++)
				printf("%d ",cl[(i-1)%tcl+1]);
			printf("\n");
			continue;
		}
		// printf("qwq");
		printf("YES\n");
		for(int i=1;i<=n;i++)
			deg[i]=0;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				if(mat[i][j]==1)
					deg[j]++;
		int bg=0,ed=0,md=1;
		for(int i=1;i<=n;i++)
			if(deg[i]==0)
				bg=i;
			else if(deg[i]==n-1)
				ed=i;
		for(int i=1;i<=n;i++)
			if(i!=bg&&i!=ed)
				md=i;
		// printf("bg:%d md:%d ed:%d\n",bg,md,ed);
		int f1=bg,f2=md,hf=m/2;
		if(hf%2==0)
			swap(f1,f2);
		printf("%d ",f1);
		for(int i=1;i<=hf;i++)
		{
			swap(f1,f2);
			printf("%d ",f1);
		}
		f2=ed;
		for(int i=1;i<=hf;i++)
		{
			swap(f1,f2);
			printf("%d ",f1);
		}
		printf("\n");
	}
	return 0;
}