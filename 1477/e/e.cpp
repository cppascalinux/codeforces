#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<set>
#define ll long long
#define inf 1000000
#define ninf 0x8080808080808080LL
#define pil pair<int,ll>
#define fi first
#define se second
using namespace std;
int n,m,q;
ll sma,smb;
int as[200009],bs[200009];
multiset<int> st,sa;
int ct[4000009];
ll sm[4000009];
pil operator+(pil a,pil b){return pil(a.fi+b.fi,a.se+b.se);}
void add(int a,int l,int r,int p,int v)
{
	ct[a]+=v,sm[a]+=v*p;
	if(l==r)
		return;
	int mid=(l+r)>>1;
	if(p<=mid)
		add(a<<1,l,mid,p,v);
	else
		add(a<<1|1,mid+1,r,p,v);
	// ct[a]=ct[a<<1]+ct[a<<1|1];
	// sm[a]=sm[a<<1]+sm[a<<1|1];
}
int kth(int a,int l,int r,int k)
{
	if(l==r)
		return l;
	int mid=(l+r)>>1;
	if(k<=ct[a<<1])
		return kth(a<<1,l,mid,k);
	return kth(a<<1|1,mid+1,r,k-ct[a<<1]);
}
int rnk(int a,int l,int r,int v)
{
	if(l==r)
		return 1;
	int mid=(l+r)>>1;
	if(v<=mid)
		return rnk(a<<1,l,mid,v);
	return rnk(a<<1|1,mid+1,r,v)+ct[a<<1];
}
pil getsm(int a,int l,int r,int ql,int qr)
{
	if(ql>qr||l>qr||r<ql)
		return pil(0,0);
	if(l>=ql&&r<=qr)
		return pil(ct[a],sm[a]);
	int mid=(l+r)>>1;
	return getsm(a<<1,l,mid,ql,qr)+getsm(a<<1|1,mid+1,r,ql,qr);
}
ll gsma(int t,int k,int mn)
{
	ll sm=(ll)(m-n)*(t-k)+(ll)(n-1)*max(0,t-k-mn);
	pil pp=getsm(1,0,inf,0,t-k);
	sm-=(ll)(t-k)*pp.fi-pp.se;
	return sm;
}
ll gsmb(int t,int k,int mn)
{
	ll sm=(ll)(m-n)*(t-k)+(ll)n*max(0,t-k-mn);
	pil pp=getsm(1,0,inf,0,t-k);
	sm-=(ll)(t-k)*pp.fi-pp.se;
	return sm;
}
ll cala(int k)
{
	ll ans=ninf;
	int mn=*st.begin();
	if(m<n)
	{
		int t=*sa.begin();
		ans=max(ans,gsma(t,k,mn));
	}
	int bd=0;
	if(m==1)
		bd=mn+k;
	else
		bd=kth(1,0,inf,m-1)+k;
	// printf("bd:%d\n",bd);
	// printf("ct2:%d sm2:%lld\n",ct[2],sm[2]);
	// for(int i=1;i<=m;i++)
	// 	printf("i:%d kth:%d\n",i,kth(1,0,inf,i));
	auto it=sa.lower_bound(bd);
	if(it!=sa.end())
	{
		// printf("qwq\n");
		int t=*it;
		// printf("t:%d\n",t);
		ans=max(ans,gsma(t,k,mn));
	}
	if(it!=sa.begin())
	{
		it--;
		int t=*it;
		// printf("t:%d\n",t);
		// printf("pwp %d\n",t);
		ans=max(ans,gsma(t,k,mn));
	}
	// printf("cala:%lld\n",ans);
	return ans;
}
ll calb(int k)
{
	ll ans=ninf;
	int mn=*st.begin();
	if(m<n)
	{
		int t=kth(1,0,inf,1);
		ans=max(ans,gsmb(t,k,mn));
	}
	int t=kth(1,0,inf,m);
	ans=max(ans,gsmb(t,k,mn));
	// printf("calb:%lld\n",ans);
	return ans;
}
int main()
{
	scanf("%d%d%d",&n,&m,&q);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",as+i);
		sma+=as[i];
		st.insert(as[i]);
		sa.insert(as[i]);
	}
	for(int i=1;i<=m;i++)
	{
		scanf("%d",bs+i);
		smb+=bs[i];
		st.insert(bs[i]);
		add(1,0,inf,bs[i],1);
	}
	for(int i=1,a,b,c;i<=q;i++)
	{
		scanf("%d%d",&a,&b);
		if(a==1)
		{
			scanf("%d",&c);
			st.erase(st.find(as[b]));
			st.insert(c);
			sa.erase(sa.find(as[b]));
			sa.insert(c);
			sma-=as[b];
			sma+=c;
			as[b]=c;
		}
		else if(a==2)
		{
			scanf("%d",&c);
			st.erase(st.find(bs[b]));
			st.insert(c);
			add(1,0,inf,bs[b],-1);
			add(1,0,inf,c,1);
			smb-=bs[b];
			smb+=c;
			bs[b]=c;
		}
		else
		{
			ll ans=max(cala(b),calb(b));
			// if(ans+sma-smb==-327268)
			// {
			// 	printf("k:%d\n",b);
			// 	for(int i=1;i<=n;i++)
			// 		printf("%d ",as[i]);
			// 	printf("\n");
			// 	for(int i=1;i<=m;i++)
			// 		printf("%d ",bs[i]);
			// }
			// if(n!=20||m!=20)
			printf("%lld\n",ans+sma-smb);
		}
	}
	return 0;
}