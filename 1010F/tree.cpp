//cf1010f Tree 组合数+树链剖分+分治+fft
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#define vi vector<int>
#define pvv pair<vi,vi >
#define fi first
#define se second
#define ll long long
#define mod 998244353
using namespace std;
int n,tot,len;
ll val;
int hd[100009],eg[200009],nxt[200009];
int sz[100009],son[100009];
int ch[100009][2];
int rt[2][270009],mp[270009];
vector<vi > v[31];
void ins(int a,int b)
{
	eg[++tot]=b;
	nxt[tot]=hd[a];
	hd[a]=tot;
}
int qpow(int a,int b)
{
	int ans=1;
	for(;b;b>>=1,a=(ll)a*a%mod)
		if(b&1)
			ans=(ll)ans*a%mod;
	return ans;
}
void dfs1(int x,int fa)
{
	sz[x]=1;
	for(int i=hd[x];i;i=nxt[i])
		if(eg[i]!=fa)
		{
			dfs1(eg[i],x);
			sz[x]+=sz[eg[i]];
			if(sz[eg[i]]>sz[son[x]])
				son[x]=eg[i];
		}
	ch[x][0]=son[x];
	for(int i=hd[x];i;i=nxt[i])
		if(eg[i]!=fa&&eg[i]!=son[x])
			ch[x][1]=eg[i];
}
void init(int l)
{
	int bit=0;
	while(1<<bit<l)
		bit++;
	len=1<<bit;
	// printf("l:%d len:%d\n",l,len);
	rt[0][0]=rt[1][0]=1;
	rt[0][1]=qpow(3,(mod-1)/len);
	for(int i=2;i<len;i++)
		rt[0][i]=(ll)rt[0][i-1]*rt[0][1]%mod;
	for(int i=1;i<len;i++)
		rt[1][i]=rt[0][len-i];
	for(int i=1;i<len;i++)
		mp[i]=(mp[i>>1]>>1)|((i&1)<<(bit-1));
}
void fft(vi &s,int c)
{
	// s.resize(len);
	for(int i=0;i<len;i++)
		if(i<mp[i])
			swap(s[i],s[mp[i]]);
	for(int l=2;l<=len;l<<=1)
	{
		int sp=len/l,d=l>>1;
		for(int j=0;j<len;j+=l)
			for(int i=0;i<d;i++)
			{
				int t=(ll)rt[c][sp*i]*s[i+j+d]%mod;
				s[i+j+d]=(s[i+j]+mod-t)%mod;
				s[i+j]=(s[i+j]+t)%mod;
			}
	}
	if(c)
	{
		int inv=qpow(len,mod-2);
		for(int i=0;i<len;i++)
			s[i]=(ll)s[i]*inv%mod;
	}
}
vi mul(vi v1,vi v2)
{
	int siz=v1.size()+v2.size()-1;
	init(siz);
	v1.resize(len);
	v2.resize(len);
	fft(v1,0);
	fft(v2,0);
	for(int i=0;i<len;i++)
		v1[i]=(ll)v1[i]*v2[i]%mod;
	fft(v1,1);
	v1.resize(siz);
	// printf("fft: siz:%d v1: ",siz);
	// for(int i=0;i<(int)v1.size();i++)
	// 	printf("%d ",v1[i]);
	// printf("\n");
	return v1;
}
pvv cal(int l,int r,vector<vi > &vs)
{
	if(l==r)
	{
		// printf("l:%d r:%d-------------------------\nnp: ",l,r);
		vi vp,vq;
		vq=vs[l];
		vp=vs[l];
		vp[0]=(vp[0]+1)%mod;
		// printf("l:%d vpsz:%d vqsz:%d\n",l,vp.size(),vq.size());
		return pvv(vp,vq);
	}
	int mid=(l+r)>>1;
	pvv ls=cal(l,mid,vs),rs=cal(mid+1,r,vs);
	vi nq=mul(ls.se,rs.se);
	vi np=ls.fi;
	np[0]=(np[0]+mod-1)%mod;
	np=mul(np,rs.se);
	np.resize(max(np.size(),rs.fi.size()));
	for(int i=0;i<(int)rs.fi.size();i++)
		np[i]=(np[i]+rs.fi[i])%mod;
	// printf("l:%d r:%d-------------------------\nnp: ",l,r);
	// for(int i=0;i<(int)np.size();i++)
	// 	printf("%d ",np[i]);
	// printf("\nnq: ");
	// for(int i=0;i<(int)nq.size();i++)
	// 	printf("%d ",nq[i]);
	// printf("\nlq: ");
	// for(int i=0;i<(int)ls.se.size();i++)
	// 	printf("%d ",ls.se[i]);
	// printf("\nrq: ");
	// for(int i=0;i<(int)rs.se.size();i++)
	// 	printf("%d ",rs.se[i]);
	// printf("\n");
	return pvv(np,nq);
}
template<class T>
void clr(vector<T> &x)
{
	vector<T> tmp;
	tmp.swap(x);
}
void dfs2(int x,int id)
{
	vi vp;
	if(ch[x][0])
		dfs2(ch[x][0],id);
	if(ch[x][1])
	{
		dfs2(ch[x][1],id+1);
		vp=cal(0,v[id+1].size()-1,v[id+1]).fi;
		// v[id+1].~vector();
		clr(v[id+1]);
		// delete &v[id+1];
		vp.resize(sz[ch[x][1]]+2);
		for(int i=sz[ch[x][1]]+1;i>=1;i--)
			vp[i]=vp[i-1];
		vp[0]=0;
	}
	else
	{
		vp.push_back(0);
		vp.push_back(1);
	}
	v[id].push_back(vp);
}
void solve()
{
	// for(int i=0;i<v[1].size();i++)
	// {
	// 	for(int j=0;j<v[1][i].size();j++)
	// 		printf("i:%d j:%d v:%d\n",i,j,v[1][i][j]);
	// }
	vi vp=cal(0,v[1].size()-1,v[1]).fi;
	// for(int i=0;i<vp.size();i++)
	// 	printf("i:%d vp:%d\n",i,vp[i]);
	int cb=1,ans=0;
	for(int i=1;i<=n;i++)
	{
		ans=(ans+(ll)cb*vp[i])%mod;
		int ad=(i+val)%mod,inv=i;
		cb=(ll)cb*ad%mod*qpow(inv,mod-2)%mod;
		// printf("cb:%d\n",cb);
	}
	printf("%d",ans);
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
#endif
	scanf("%d%lld",&n,&val);
	for(int i=1,a,b;i<=n-1;i++)
	{
		scanf("%d%d",&a,&b);
		ins(a,b);
		ins(b,a);
	}
	dfs1(1,0);
	dfs2(1,1);
	solve();
	// printf("1");
	return 0;
}