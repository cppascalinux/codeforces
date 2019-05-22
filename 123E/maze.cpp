//2019.05.22
//CF123E Maze 考虑每条边对于答案的贡献,然后推式子,再套个乘法分配率
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#define li long long
#define db double
#define ldb long double
using namespace std;
int n,tot,cntx,cnty;
ldb ans;
int hd[100009],nxt[200009],eg[200009];
int sz[100009];
int vx[100009],vy[100009];
int smx[100009],smy[100009];
struct node
{
	int sz,sx,sy;
	node(){}
	node(int a,int b,int c){sz=a,sx=b,sy=c;}
};
void ins(int a,int b)
{
	eg[++tot]=b;
	nxt[tot]=hd[a];
	hd[a]=tot;
}
void dfs(int x,int fa)
{
	sz[x]=1;
	smx[x]=vx[x],smy[x]=vy[x];
	vector<node> p;
	for(int i=hd[x];i;i=nxt[i])
		if(eg[i]!=fa)
		{
			dfs(eg[i],x);
			p.push_back(node(sz[eg[i]],smx[eg[i]],smy[eg[i]]));
			sz[x]+=sz[eg[i]];
			smx[x]+=smx[eg[i]];
			smy[x]+=smy[eg[i]];
		}
	if(fa)
		p.push_back(node(n-sz[x],cntx-smx[x],cnty-smy[x]));
	p.push_back(node(0,vx[x],0));
	int tmpx=cntx,tmpy=cnty-vy[x];
	for(int i=0;i<(int)p.size();i++)
	{
		node u=p[i];
		ans+=(ldb)(n-u.sz)*u.sx/cntx*(tmpy-u.sy)/cnty;
		ans-=(ldb)u.sz*u.sy/cntx*(tmpx-u.sx)/cnty;
	}
}
int main()
{
#ifdef I_LOVE_KTY
	freopen("maze.in","r",stdin);
	freopen("maze.out","w",stdout);
#endif
	scanf("%d",&n);
	for(int i=1,a,b;i<=n-1;i++)
	{
		scanf("%d%d",&a,&b);
		ins(a,b),ins(b,a);
	}
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",vx+i,vy+i);
		cntx+=vx[i],cnty+=vy[i];
	}
	dfs(1,0);
	printf("%.12lf",(db)ans);
	return 0;
}