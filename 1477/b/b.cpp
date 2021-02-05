#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,q;
char s[200009],f[200009];
int ql[200009],qr[200009];
int sm[800009],tg[800009];
void build(int a,int l,int r)
{
	sm[a]=0;
	tg[a]=-1;
	if(l==r)
		return sm[a]=f[l],void();
	int mid=(l+r)>>1;
	build(a<<1,l,mid);
	build(a<<1|1,mid+1,r);
	sm[a]=sm[a<<1]+sm[a<<1|1];
}
void down(int a,int l,int r)
{
	int &v=tg[a];
	if(v==-1)
		return;
	int mid=(l+r)>>1;
	int la=a<<1,ra=a<<1|1;
	sm[la]=(mid-l+1)*v;
	sm[ra]=(r-mid)*v;
	tg[la]=tg[ra]=v;
	v=-1;
}
void add(int a,int l,int r,int ll,int rr,int v)
{
	if(l>rr||r<ll)
		return;
	if(l>=ll&&r<=rr)
		return sm[a]=(r-l+1)*v,tg[a]=v,void();
	down(a,l,r);
	int mid=(l+r)>>1;
	add(a<<1,l,mid,ll,rr,v);
	add(a<<1|1,mid+1,r,ll,rr,v);
	sm[a]=sm[a<<1]+sm[a<<1|1];
}
int ask(int a,int l,int r,int ll,int rr)
{
	if(l>rr||r<ll)
		return 0;
	if(l>=ll&&r<=rr)
		return sm[a];
	down(a,l,r);
	int mid=(l+r)>>1;
	return ask(a<<1,l,mid,ll,rr)+ask(a<<1|1,mid+1,r,ll,rr);
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&q);
		scanf("%s%s",s+1,f+1);
		for(int i=1;i<=n;i++)
			s[i]-='0',f[i]-='0';
		for(int i=1;i<=q;i++)
			scanf("%d%d",ql+i,qr+i);
		build(1,1,n);
		int fg=1;
		for(int i=q;i>=1;i--)
		{
			int ln=qr[i]-ql[i]+1,sz=ask(1,1,n,ql[i],qr[i]);
			if(sz*2==ln)
			{
				fg=0;
				break;
			}
			if(sz*2<ln)
				add(1,1,n,ql[i],qr[i],0);
			else
				add(1,1,n,ql[i],qr[i],1);
		}
		if(fg)
			for(int i=1;i<=n;i++)
				if(ask(1,1,n,i,i)!=s[i])
				{
					fg=0;
					break;
				}
		printf("%s\n",fg?"YES":"NO");
	}
	return 0;
}