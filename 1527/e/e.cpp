#include<bits/stdc++.h>
#define inf 0x3F3F3F3F
using namespace std;
int f[109][35009];
int s[35009];
int n,k;
int mn[140009],lz[140009];
int lst[35009],pos[35009];
void down(int a)
{
	int la=a*2,ra=a*2+1;
	mn[la]+=lz[a],mn[ra]+=lz[a];
	lz[la]+=lz[a],lz[ra]+=lz[a];
	lz[a]=0;
}
void addv(int a,int l,int r,int ll,int rr,int v)
{
	if(l>rr||r<ll)
		return;
	if(l>=ll&&r<=rr)
		return mn[a]+=v,lz[a]+=v,void();
	down(a);
	int mid=(l+r)/2;
	addv(a*2,l,mid,ll,rr,v);
	addv(a*2+1,mid+1,r,ll,rr,v);
	mn[a]=min(mn[a*2],mn[a*2+1]);
}
int ask(int a,int l,int r,int ll,int rr)
{
	if(l>rr||r<ll)
		return inf;
	if(l>=ll&&r<=rr)
		return mn[a];
	down(a);
	int mid=(l+r)/2;
	return min(ask(a*2,l,mid,ll,rr),ask(a*2+1,mid+1,r,ll,rr));
}
int main()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",s+i);
		lst[i]=pos[s[i]];
		pos[s[i]]=i;
	}
	memset(f,0x3F,sizeof(f));
	f[0][0]=0;
	for(int i=1;i<=k;i++)
	{
		memset(mn,0x3F,sizeof(mn));
		memset(lz,0,sizeof(lz));
		addv(1,0,n,i-1,i-1,-inf+f[i-1][i-1]);
		for(int j=i;j<=n;j++)
		{
			if(lst[j])
				addv(1,0,n,0,lst[j]-1,j-lst[j]);
			f[i][j]=ask(1,0,n,0,j-1);
			// printf("i:%d j:%d f:%d\n",i,j,f[i][j]);
			addv(1,0,n,j,j,-inf+f[i-1][j]);
		}
	}
	printf("%d",f[k][n]);
	return 0;
}