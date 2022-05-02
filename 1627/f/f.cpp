#include<bits/stdc++.h>
#define inf 0x3F3F3F3F
using namespace std;
struct node
{
	int x,y,l;
	node(){}
	node(int a,int b,int c):x(a),y(b),l(c){}
	bool operator<(const node &o)const{return l>o.l;}
};
int n,k;
int id[509][509];
int banx[509][509],bany[509][509];
int vis[509][509],dis[509][509];
int d[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
void dij()
{
	priority_queue<node>pq;
	dis[k/2+1][k/2+1]=0;
	pq.emplace(k/2+1,k/2+1,0);
	while(!pq.empty())
	{
		node a=pq.top();
		pq.pop();
		if(vis[a.x][a.y])
			continue;
		vis[a.x][a.y]=1;
		for(int i=0;i<4;i++)
		{
			int nx=a.x+d[i][0],ny=a.y+d[i][1];
			if(nx>=1&&nx<=k+1&&ny>=1&&ny<=k+1&&!vis[nx][ny])
			{
				int nl=0;
				if(i==0||i==1)
					nl=banx[min(nx,a.x)][ny];
				else
					nl=bany[nx][min(ny,a.y)];
				if(dis[nx][ny]>a.l+nl)
				{
					dis[nx][ny]=a.l+nl;
					pq.emplace(nx,ny,dis[nx][ny]);
				}
			}
		}
	}
	int ans=0;
	for(int i=1;i<=k+1;i++)
		for(int j=1;j<=k+1;j++)
		{
			if(i==1||i==k+1||j==1||j==k+1)
				ans=max(ans,n-dis[i][j]);
		}
	printf("%d\n",ans);
}
int main()
{
	int ttt;
	scanf("%d",&ttt);
	while(ttt--)
	{
		scanf("%d%d",&n,&k);
		for(int i=1;i<=k+1;i++)
			for(int j=1;j<=k+1;j++)
			{
				id[i][j]=(i-1)*(k+1)+j;
				banx[i][j]=bany[i][j]=0;
				vis[i][j]=0;
				dis[i][j]=inf;
			}
		for(int i=1;i<=n;i++)
		{
			int x1,y1,x2,y2;
			scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
			if(x1==x2)
			{
				banx[x1][max(y1,y2)]++;
				banx[k+1-x1][k+2-max(y1,y2)]++;
			}
			else
			{
				bany[max(x1,x2)][y1]++;
				bany[k+2-max(x1,x2)][k+1-y1]++;
			}
		}
		dij();
	}
	return 0;
}