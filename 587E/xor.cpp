//cf587e Duff as a Queen 差分+线段树维护线性基
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,q;
int v[200009];
int l[800009],r[800009],bs[800009][31];
int cx[200009];
void addc(int x,int val)
{
	for(int i=x;i<=n+1;i+=i&-i)
		cx[i]^=val;
}
int askc(int x)
{
	int ans=0;
	for(int i=x;i;i-=i&-i)
		ans^=cx[i];
	return ans;
}
void ins(int *b,int x)
{
	if(!x)
		return;
	for(int i=30;i>=0;i--)
		if(x&(1<<i))
		{
			if(b[i])
				x^=b[i];
			else
			{
				for(int j=0;j<i;j++)
					if(x&(1<<j))
						x^=b[j];
				for(int j=i+1;j<=30;j++)
					if(b[j]&(1<<i))
						b[j]^=x;
				b[i]=x;
				break;
			}
		}
}
void merge(int *dst,int *s1,int *s2)
{
	memset(dst,0,31<<2);
	for(int i=0;i<=30;i++)
		ins(dst,s1[i]);
	for(int i=0;i<=30;i++)
		ins(dst,s2[i]);
}
void build(int a,int ll,int rr)
{
	l[a]=ll;
	r[a]=rr;
	if(ll==rr)
	{
		ins(bs[a],v[ll]);
		return;
	}
	int mid=(ll+rr)>>1;
	build(a<<1,ll,mid);
	build(a<<1|1,mid+1,rr);
	merge(bs[a],bs[a<<1],bs[a<<1|1]);
}
void add(int a,int x,int val)
{
	if(l[a]==r[a])
	{
		memset(bs[a],0,sizeof(bs[a]));
		ins(bs[a],val);
		return;
	}
	if(x<=r[a<<1])
		add(a<<1,x,val);
	else
		add(a<<1|1,x,val);
	merge(bs[a],bs[a<<1],bs[a<<1|1]);
}
void ask(int a,int ll,int rr,int *dst)
{
	if(l[a]>rr||r[a]<ll)
		return;
	if(l[a]>=ll&&r[a]<=rr)
	{
		// printf("a:%d l:%d r:%d\n",a,l[a],r[a]);
		for(int i=0;i<=30;i++)
			ins(dst,bs[a][i]);
		return;
	}
	ask(a<<1,ll,rr,dst);
	ask(a<<1|1,ll,rr,dst);
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
#endif
	scanf("%d%d",&n,&q);
	int now,lst=0;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&now);
		v[i]=now^lst;
		lst=now;
		addc(i,v[i]);
	}
	v[n+1]=now;
	// for(int i=1;i<=n;i++)
	// 	printf("i:%d v:%d\n",i,v[i]);
	build(1,1,n+1);
	for(int i=1,a,b,c,d;i<=q;i++)
	{
		scanf("%d",&a);
		if(a==1)
		{
			scanf("%d%d%d",&b,&c,&d);
			v[b]^=d;
			v[c+1]^=d;
			// for(int i=1;i<=n;i++)
			// 	printf("i:%d v:%d\n",i,v[i]);
			add(1,b,v[b]);
			add(1,c+1,v[c+1]);
			addc(b,d);
			addc(c+1,d);
		}
		else
		{
			scanf("%d%d",&b,&c);
			int dst[31],sm=0;
			memset(dst,0,sizeof(dst));
			ask(1,b+1,c,dst);
			// for(int j=0;j<=30;j++)
			// 	printf("j:%d before:%d\n",j,dst[j]);
			int k=askc(b);
			// printf("k:%d\n",k);
			ins(dst,k);
			// for(int j=0;j<=30;j++)
			// 	printf("j:%d after:%d\n",j,dst[j]);
			for(int i=0;i<=30;i++)
				sm+=(dst[i]>0);
			printf("%d\n",1<<sm);
		}
	}
	return 0;
}