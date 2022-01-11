#include<bits/stdc++.h>
using namespace std;
int n,tot;
int mat[509][509];
struct node
{
	int s,u,v;
	bool operator<(const node &p)const{return s<p.s;}
}p[250009];
int f[1009];
int ans[1009],anc[1009];
int mr[1009],pr[1009],org[1009];
int fnd(int x)
{
	return x==f[x]?x:f[x]=fnd(f[x]);
}
int fgd(int x)
{
	return x==mr[x]?x:mr[x]=fgd(mr[x]);
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			scanf("%d",mat[i]+j);
	for(int i=1;i<=n;i++)
		ans[i]=mat[i][i];
	int tp=0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<i;j++)
			p[++tp]=node{mat[i][j],i,j};
	// p[++tp]=node{2,1,2};
	// p[++tp]=node{2,3,4};
	// p[++tp]=node{2,1,3};
	for(int i=1;i<=2*n;i++)
		f[i]=i,mr[i]=i;
	sort(p+1,p+tp+1);
	tot=n;
	for(int i=1;i<=tp;i++)
	{
		node t=p[i];
		int fu=fnd(t.u),fv=fnd(t.v);
		if(fu==fv)
			continue;
		if(ans[fv]==ans[fu]&&ans[fv]==t.s)
		{
			f[fv]=fu;
			mr[fgd(fv)]=fgd(fu);
			continue;
		}
		if(ans[fv]==t.s)
			swap(fu,fv);
		if(ans[fu]==t.s)
		{
			anc[fv]=fu;
			f[fv]=fu;
			continue;
		}
		int a=++tot;
		f[fu]=f[fv]=a;
		ans[a]=t.s;
		anc[fu]=anc[fv]=a;
	}
	int nt=0;
	for(int i=1;i<=tot;i++)
	{
		if(fgd(i)==i)
		{
			pr[++nt]=i;
			org[i]=nt;
		}
	}
	// printf("tot:%d\n",tot);
	printf("%d\n",nt);
	for(int i=1;i<=nt;i++)
		printf("%d ",ans[pr[i]]);
	int rt=0;
	for(int i=1;i<=tot;i++)
		if(fgd(i)==i&&!anc[i])
			rt=org[i];
	printf("\n%d\n",rt);
	for(int i=1;i<=tot;i++)
		if(fgd(i)==i&&anc[i])
			printf("%d %d\n",org[i],org[fgd(anc[i])]);
	return 0;
}