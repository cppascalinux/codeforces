//cf1010f Tree 组合数+树链剖分+分治+fft
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#define ll long long
#define mod 998244353
using namespace std;
int n,tot,len;
ll val;
int hd[100009],eg[200009],nxt[200009];
int sz[100009],son[100009];
int ch[100009][2];
int rt[2][270009],mp[270009];
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
	rt[0][0]=rt[1][0]=1;
	rt[0][1]=qpow(3,(mod-1)/len);
	for(int i=2;i<len;i++)
		rt[0][i]=(ll)rt[0][i-1]*rt[0][1]%mod;
	for(int i=1;i<len;i++)
		rt[1][i]=rt[0][len-i];
	for(int i=1;i<len;i++)
		mp[i]=(mp[i>>1]>>1)|((i&1)<<(bit-1));
}
void fft(vector<int> &s,int c)
{
	for(int i=0;i<len;i++)
		if(s[i]<s[mp[i]])
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
void dfs2();
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
	return 0;
}