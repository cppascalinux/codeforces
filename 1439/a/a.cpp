#include<bits/stdc++.h>
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;
struct node
{
	int x1,y1,x2,y2,x3,y3;
	node(){}
	node(int a,int b,int c,int d,int e,int f):x1(a),y1(b),x2(c),y2(d),x3(e),y3(f){}
};
int n,m;
int mat[109][109];
char s[1009];
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
			for(int j=1;j<=m;j++)
				mat[i][j]=s[j]-'0';
		}
		vector<node> ans;
		if(n&1)
		{
			for(int i=1;i<=m;i++)
				if(mat[n][i])
				{
					mat[n][i]^=1,mat[n-1][i]^=1;
					if(i==m)
						ans.emplace_back(n,i,n-1,i,n-1,i-1),mat[n-1][i-1]^=1;
					else
						ans.emplace_back(n,i,n-1,i,n-1,i+1),mat[n-1][i+1]^=1;
				}
			n--;
		}
		if(m&1)
		{
			for(int i=1;i<=n;i++)
				if(mat[i][m])
				{
					mat[i][m]^=1,mat[i][m-1]^=1;
					if(i==n)
						ans.emplace_back(i,m,i,m-1,i-1,m-1),mat[i-1][m-1]^=1;
					else
						ans.emplace_back(i,m,i,m-1,i+1,m-1),mat[i+1][m-1]^=1;
				}
			m--;
		}
		for(int i=1;i<=n;i+=2)
			for(int j=1;j<=m;j+=2)
			{
				int sm=0;
				for(int k=0;k<=1;k++)
					for(int l=0;l<=1;l++)
						sm+=mat[i+k][j+l];
				if(!sm)
					continue;
				else if(sm==4)
				{
					ans.emplace_back(i,j,i+1,j,i,j+1);
					ans.emplace_back(i,j,i,j+1,i+1,j+1);
					ans.emplace_back(i,j,i+1,j,i+1,j+1);
					ans.emplace_back(i+1,j,i,j+1,i+1,j+1);
				}
				else if(sm==3)
				{
					vector<pii> tmp;
					for(int k=0;k<=1;k++)
						for(int l=0;l<=1;l++)
							if(mat[i+k][j+l])
								tmp.emplace_back(i+k,j+l);
					ans.emplace_back(tmp[0].fi,tmp[0].se,tmp[1].fi,tmp[1].se,tmp[2].fi,tmp[2].se);
				}
				else if(sm==2)
				{
					vector<pii> tmp;
					for(int k=0;k<=1;k++)
						for(int l=0;l<=1;l++)
							if((!mat[i+k][j+l])^(mat[i][j]==mat[i+1][j+1]))
								tmp.emplace_back(k,l);
					for(pii t:tmp)
						ans.emplace_back(i+t.fi,j+t.se,i+1-t.fi,j+t.se,i+t.fi,j+1-t.se);
				}
				else
				{
					vector<pii> tmp;
					for(int k=0;k<=1;k++)
						for(int l=0;l<=1;l++)
							if(!mat[i+k][j+l])
								tmp.emplace_back(k^1,l^1);
					for(pii t:tmp)
						ans.emplace_back(i+t.fi,j+t.se,i+1-t.fi,j+t.se,i+t.fi,j+1-t.se);
				}
			}
		printf("%d\n",(int)ans.size());
		for(node t:ans)
			printf("%d %d %d %d %d %d\n",t.x1,t.y1,t.x2,t.y2,t.x3,t.y3);
	}
	return 0;
}