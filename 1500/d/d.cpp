#include<bits/stdc++.h>
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;
int n,q,sm;
int mat[1509][1509];
int vis[2250009];
int ans[1509];
short rnx[1509][1509],rny[1509][1509];
struct myv
{
	char tp=0;
	short s[12];
	int size(){return tp;}
	void pop_back(){tp--;}
	void insert(int x){for(int i=tp;i>=1;i--)s[i]=s[i-1];s[0]=x;tp++;}
	void erase(int p){for(int i=p;i+1<tp;i++)s[i]=s[i+1];tp--;}
};
myv cx[1509][1509],cy[1509][1509],dx[1509][1509],dy[1509][1509];
void init()
{
	for(int i=1;i<=n;i++)
	{
		unordered_map<int,int> mp;
		for(int j=1;j<=n;j++)
			rnx[i][j]=(mp[mat[i][j]]+=1);
	}
	for(int j=1;j<=n;j++)
	{
		unordered_map<int,int> mp;
		for(int i=1;i<=n;i++)
			rny[i][j]=(mp[mat[i][j]]+=1);
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			cx[i][j]=cx[i][j-1];
			for(int k=0;k<cx[i][j].tp;k++)
				if(mat[i][cx[i][j].s[k]]==mat[i][j])
				{
					cx[i][j].erase(k);
					break;
				}
			cx[i][j].insert(j);
			if(cx[i][j].size()>q+1)
				cx[i][j].pop_back();
		}
		for(int j=n;j>=1;j--)
		{
			dx[i][j]=dx[i][j+1];
			for(int k=0;k<dx[i][j].tp;k++)
				if(mat[i][dx[i][j].s[k]]==mat[i][j])
				{
					dx[i][j].erase(k);
					break;
				}
			dx[i][j].insert(j);
			if(dx[i][j].size()>q+1)
				dx[i][j].pop_back();
		}
	}
	for(int j=1;j<=n;j++)
	{
		for(int i=1;i<=n;i++)
		{
			cy[i][j]=cy[i-1][j];
			for(int k=0;k<cy[i][j].tp;k++)
				if(mat[cy[i][j].s[k]][j]==mat[i][j])
				{
					cy[i][j].erase(k);
					break;
				}
			cy[i][j].insert(i);
			if(cy[i][j].size()>q+1)
				cy[i][j].pop_back();
		}
		for(int i=n;i>=1;i--)
		{
			dy[i][j]=dy[i+1][j];
			for(int k=0;k<dy[i][j].tp;k++)
				if(mat[dy[i][j].s[k]][j]==mat[i][j])
				{
					dy[i][j].erase(k);
					break;
				}
			dy[i][j].insert(i);
			if(dy[i][j].size()>q+1)
				dy[i][j].pop_back();
		}
	}
	// for(int i=1;i<=n;i++)
	// 	for(int j=1;j<=n;j++)
	// 	{
	// 		printf("i:%d j:%d-----------------\n",i,j);
	// 		printf("cx:");
	// 		for(int v:cx[i][j])
	// 			printf("%d ",v);
	// 		printf("\n");
	// 		printf("dx:");
	// 		for(int v:dx[i][j])
	// 			printf("%d ",v);
	// 		printf("\n");
	// 		printf("rnx:%d\n",rnx[i][j]);
	// 	}
}
int addx(int x,int ly,int ry)
{
	if(x<1||x>n||ly>ry)
		return 1;
	int nsm=sm;
	int tmp1[12],tmp2[12],tp=0,tot=0;
	for(int i=0;i<cx[x][ry].tp;i++)
	{
		int v=cx[x][ry].s[i];
		int sv=mat[x][v];
		int rep=0;
		for(int j=0;j<dx[x][ly].tp;j++)
		{
			int u=dx[x][ly].s[j];
			if(sv==mat[x][u])
				rep+=(rnx[x][v]-rnx[x][u]+1);
		}
		tot+=rep;
		// printf("x:%d v:%d ly:%d ry:%d rep:%d\n",x,v,ly,ry,rep);
		if(rep)
		{
			if(!vis[sv])
				nsm++;
			tp++;
			tmp1[tp]=sv;
			tmp2[tp]=rep;
		}
	}
	if(nsm>q||tot<ry-ly+1)
		return 0;
	for(int i=1;i<=tp;i++)
		vis[tmp1[i]]+=tmp2[i];
	sm=nsm;
	return 1;
}
void delx(int x,int ly,int ry)
{
	if(x<1||x>n||ly>ry)
		return;
	int nsm=sm;
	int tmp1[12],tmp2[12],tp=0;
	for(int i=0;i<cx[x][ry].tp;i++)
	{
		int v=cx[x][ry].s[i];
		int sv=mat[x][v];
		int rep=0;
		for(int j=0;j<dx[x][ly].tp;j++)
		{
			int u=dx[x][ly].s[j];
			if(sv==mat[x][u])
				rep+=(rnx[x][v]-rnx[x][u]+1);
		}
		// printf("x:%d v:%d ly:%d ry:%d rep:%d\n",x,v,ly,ry,rep);
		if(rep)
		{
			if(vis[sv]<=rep)
				nsm--;
			tp++;
			tmp1[tp]=sv;
			tmp2[tp]=rep;
		}
	}
	for(int i=1;i<=tp;i++)
		vis[tmp1[i]]-=tmp2[i];
	sm=nsm;
}
int addy(int lx,int rx,int y)
{
	// printf("addy %d %d %d\n",lx,rx,y);
	if(y<1||y>n||lx>rx)
		return 1;
	int nsm=sm;
	int tmp1[12],tmp2[12],tp=0,tot=0;
	for(int i=0;i<cy[rx][y].tp;i++)
	{
		int rep=0;
		int v=cy[rx][y].s[i];
		int sv=mat[v][y];
		for(int j=0;j<dy[lx][y].tp;j++)
		{
			int u=dy[lx][y].s[j];
			if(sv==mat[u][y])
				rep+=(rny[v][y]-rny[u][y]+1);
		}
		tot+=rep;
		// printf("addy y:%d lx:%d rx:%d v:%d rep:%d\n",y,lx,rx,v,rep);
		if(rep)
		{
			if(!vis[sv])
				nsm++;
			tp++;
			tmp1[tp]=sv;
			tmp2[tp]=rep;
		}
	}
	if(nsm>q||tot<rx-lx+1)
		return 0;
	for(int i=1;i<=tp;i++)
		vis[tmp1[i]]+=tmp2[i];
	sm=nsm;
	return 1;
}
void dely(int lx,int rx,int y)
{
	if(y<1||y>n||lx>rx)
		return;
	int nsm=sm;
	int tmp1[12],tmp2[12],tp=0;
	for(int i=0;i<cy[rx][y].tp;i++)
	{
		int rep=0;
		int v=cy[rx][y].s[i];
		int sv=mat[v][y];
		for(int j=0;j<dy[lx][y].tp;j++)
		{
			int u=dy[lx][y].s[j];
			if(sv==mat[u][y])
				rep+=(rny[v][y]-rny[u][y]+1);
		}
		if(rep)
		{
			if(vis[sv]<=rep)
				nsm--;
			tp++;
			tmp1[tp]=sv;
			tmp2[tp]=rep;
		}
	}
	for(int i=1;i<=tp;i++)
		vis[tmp1[i]]-=tmp2[i];
	sm=nsm;
}
void solve()
{
	for(int i=1;i<=n;i++)
	{
		int lp=1;
		for(int j=1;j<=n;j++)
		{
			int fg=0;
			if(i-(j-lp)>=1&&addx(i-(j-lp),lp,j-1))
				fg=1;
			if(!fg)
			{
				dely(i-(j-lp)+1,i,lp);
				lp++;
			}
			while(lp<=j)
			{
				if(addy(i-(j-lp),i,j))
					break;
				delx(i-(j-lp),lp,j-1);
				dely(i-(j-lp)+1,i,lp);
				lp++;
			}
			// printf("i:%d j:%d lp:%d fg:%d sm:%d\n",i,j,lp,fg,sm);
			ans[j-lp+1]++;
		}
		int tx=i-(n-lp);
		for(int j=lp;j<=n;j++)
			dely(tx,i,j);
	}
	for(int i=n;i>=1;i--)
		ans[i-1]+=ans[i];
	for(int i=1;i<=n;i++)
		printf("%d\n",ans[i]);
}
int main()
{
	scanf("%d%d",&n,&q);
	int tp=0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
		{
			scanf("%d",&mat[i][j]);
		}
	init();
	solve();
	return 0;
}