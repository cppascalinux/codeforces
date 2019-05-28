//2019.05.28
//CF407E k-d-sequence 等价于寻找max(l,r)-min(l,r)-(r-l)<=k的最长区间,用单调栈维护前缀最大值,最小值,
//用线段树维护区间最小值,每次左端点左移,将值放入单调栈,并在线段树中区间加,查询最靠右的<=k的值
#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<map>
#define inf 0x7F7F7F7F
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;
int n,k,d,ansl,ansr=-1;
int s[200009],s1[200009];
int ps[200009];
int mn[800009],lz[800009];
int sr[200009];
pii st1[200009],st2[200009];//st1:max st2:min
void solve0()
{
	int ml=1,ans=1,ansl=1;
	s[n+1]=2000000001;
	for(int i=2;i<=n+1;i++)
		if(s[i]!=s[i-1])
		{
			if(i-ml>ans)
				ans=i-ml,ansl=ml;
			ml=i;
		}
	printf("%d %d",ansl,ansl+ans-1);
}
void build(int a,int l,int r)
{
	mn[a]=lz[a]=0;
	if(l<r)
	{
		int mid=(l+r)>>1;
		build(a<<1,l,mid);
		build(a<<1|1,mid+1,r);
	}
}
void down(int a)
{
	mn[a<<1]+=lz[a];
	mn[a<<1|1]+=lz[a];
	lz[a<<1]+=lz[a];
	lz[a<<1|1]+=lz[a];
	lz[a]=0;
}
void add(int a,int l,int r,int ll,int rr,int val)
{
	if(l>rr||r<ll)
		return;
	if(l>=ll&&r<=rr)
		return mn[a]+=val,lz[a]+=val,void();
	down(a);
	int mid=(l+r)>>1;
	add(a<<1,l,mid,ll,rr,val);
	add(a<<1|1,mid+1,r,ll,rr,val);
	mn[a]=min(mn[a<<1],mn[a<<1|1]);
}
int ask(int a,int l,int r,int ll,int rr)
{
	if(ll>rr||mn[a]>k||l>rr||r<ll)
		return 0;
	if(l>=ll&&r<=rr)
	{
		if(l==r)
			return l;
		down(a);
		int mid=(l+r)>>1;
		int t=ask(a<<1|1,mid+1,r,ll,rr);
		return t?t:ask(a<<1,l,mid,ll,rr);
	}
	down(a);
	int mid=(l+r)>>1;
	int t=ask(a<<1|1,mid+1,r,ll,rr);
	return t?t:ask(a<<1,l,mid,ll,rr);
}
int dbg(int a,int l,int r,int ll,int rr)
{
	if(l>rr||r<ll)
		return inf;
	if(l>=ll&&r<=rr)
		return mn[a];
	down(a);
	int mid=(l+r)>>1;
	return min(dbg(a<<1,l,mid,ll,rr),dbg(a<<1|1,mid+1,r,ll,rr));
}
void solve(int *s,int m,int stid)
{
	// printf("m:%d\n",m);
	// memset(mn,0,sizeof(mn));
	// memset(lz,0,sizeof(lz));
	build(1,1,m);
	map<int,int> mp;
	sr[m+1]=m;
	for(int i=m;i>=1;i--)
	{
		sr[i]=sr[i+1];
		if(mp.count(s[i]))
			sr[i]=min(sr[i],mp[s[i]]-1);
		mp[s[i]]=i;
	}
	// for(int i=1;i<=m;i++)
	// 	printf("i:%d sr:%d\n",i,sr[i]);
	int tp1=0,tp2=0;
	for(int i=m;i>=1;i--)
	{
		// printf("i:%d-------------------------------\n",i);
		add(1,1,m,i+1,m,-1);
		int mxr=i;
		while(tp1&&s[i]>=st1[tp1].fi)
		{
			add(1,1,m,mxr+1,st1[tp1].se,s[i]-st1[tp1].fi);
			mxr=st1[tp1--].se;
		}
		st1[++tp1]=pii(s[i],mxr);

		mxr=i;
		while(tp2&&s[i]<=st2[tp2].fi)
		{
			add(1,1,m,mxr+1,st2[tp2].se,st2[tp2].fi-s[i]);
			mxr=st2[tp2--].se;
		}
		st2[++tp2]=pii(s[i],mxr);
		// for(int j=i;j<=m;j++)
		// 	printf("j:%d min:%d\n",j,dbg(1,1,m,j,j));
		// printf("mn3:%d lz3:%d\n",mn[3],lz[3]);
		// for(int j=1;j<=tp1;j++)
		// 	printf("1j:%d fi:%d se:%d\n",j,st1[j].fi,st1[j].se);
		// for(int j=1;j<=tp2;j++)
		// 	printf("2j:%d fi:%d se:%d\n",j,st2[j].fi,st2[j].se);
		int rpos=ask(1,1,m,i,sr[i]);
		// printf("i:%d rpos:%d\n",i,rpos);
		if(!rpos)
			continue;
		if(rpos-i==ansr-ansl?i+stid<ansl:rpos-i>ansr-ansl)
			ansl=i+stid,ansr=rpos+stid;
	}
}
int main()
{
#ifdef I_LOVE_KTY
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
#endif
	scanf("%d%d%d",&n,&k,&d);
	for(int i=1;i<=n;i++)
		scanf("%d",s+i),s[i]+=1000000000;
	if(d==0)
		return solve0(),0;
	for(int i=1;i<=n;i++)
		s1[i]=s[i]%d,s[i]/=d;
	s1[n+1]=2000000001;
	int pl=1;
	for(int i=2;i<=n+1;i++)
		if(s1[i]!=s1[i-1])
		{
			solve(s+pl-1,i-pl,pl-1);
			pl=i;
		}
	printf("%d %d",ansl,ansr);
	return 0;
}