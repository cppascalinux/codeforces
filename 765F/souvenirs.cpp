//2019.05.22
//CF765F Souvenirs 把所有询问按右端点从小到大排序,用线段树去存储所有左端点的答案,每次在权值线段树上查询[x,(x+y)/2)中
//最大的坐标,去更新答案,每次y都会/2,更新次数不会超过log次,时间复杂度nlog^2n
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define inf 0x7F7F7F7F
using namespace std;
struct node
{
	int l,r,id;
	node(){}
	node(int a,int b,int c){l=a,r=b,id=c;}
	bool operator <(const node &p) const{return r<p.r;}
};
int n,m,cnt,rt;
int s[100009];
node q[300009];
int ans[300009];
int mn[400009];//segment tree 1
int lp[3500009],rp[3500009],mx[3500009];//segment tree 2
void add1(int a,int l,int r,int al,int ar,int val)
{
	if(l>ar||r<al)
		return;
	if(l>=al&&r<=ar)
		return mn[a]=min(mn[a],val),void();
	int mid=(l+r)>>1;
	add1(a<<1,l,mid,al,ar,val);
	add1(a<<1|1,mid+1,r,al,ar,val);
}
int ask1(int a,int l,int r,int pos)
{
	if(l==r)
		return mn[a];
	int mid=(l+r)>>1;
	if(pos<=mid)
		return min(mn[a],ask1(a<<1,l,mid,pos));
	return min(mn[a],ask1(a<<1|1,mid+1,r,pos));
}
void add2(int &a,int l,int r,int pos,int val)
{
	if(!a)
		a=++cnt;
	mx[a]=max(mx[a],val);
	if(l==r)
		return;
	int mid=(l+r)>>1;
	if(pos<=mid)
		add2(lp[a],l,mid,pos,val);
	else
		add2(rp[a],mid+1,r,pos,val);
}
int ask2(int a,int l,int r,int ql,int qr)
{
	if(!a||ql>qr||l>qr||r<ql)
		return 0;
	if(l>=ql&&r<=qr)
		return mx[a];
	int mid=(l+r)>>1;
	return max(ask2(lp[a],l,mid,ql,qr),ask2(rp[a],mid+1,r,ql,qr));
}
void solve()
{
	memset(mn,0x7F,sizeof(mn));
	memset(mx,0,sizeof(mx));
	memset(lp,0,sizeof(lp));
	memset(rp,0,sizeof(rp));
	sort(q+1,q+m+1);
	int cur=0;
	for(int i=1;i<=m;i++)
	{
		while(cur<q[i].r)
		{
			int x=s[++cur],y=inf;
			while(1)
			{
				int np=ask2(rt,0,1000000000,x,y==inf?1000000000:(x+y-1)/2);
				if(!np)
					break;
				y=s[np];
				// printf("y:%d\n",y);
				add1(1,1,n,1,np,y-x);
			}
			add2(rt,0,1000000000,s[cur],cur);
		}
		ans[q[i].id]=min(ans[q[i].id],ask1(1,1,n,q[i].l));
	}
}
int main()
{
#ifdef I_LOVE_KTY
	freopen("souvenirs.in","r",stdin);
	freopen("souvenirs.out","w",stdout);
#endif
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",s+i);
	scanf("%d",&m);
	for(int i=1,a,b;i<=m;i++)
	{
		scanf("%d%d",&a,&b);
		q[i]=node(a,b,i);
	}
	memset(ans,0x7F,sizeof(ans));
	solve();
	reverse(s+1,s+n+1);
	for(int i=1;i<=m;i++)
	{
		swap(q[i].l,q[i].r);
		q[i].l=n+1-q[i].l;
		q[i].r=n+1-q[i].r;
	}
	solve();
	for(int i=1;i<=m;i++)
		printf("%d\n",ans[i]);
	return 0;
}