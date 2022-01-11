#include<bits/stdc++.h>
#define mod 998244353
#define ll long long
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;
int n,m,rt,cnt;
int mul[400009],inv[400009];
int vis[200009];
int qx[200009],qy[200009];
int ch[200009][2],id[200009],v[200009],lz[200009],sz[200009];
int qpow(int a,int b)
{
	int ans=1;
	for(;b;b>>=1,a=(ll)a*a%mod)
		if(b&1)
			ans=(ll)ans*a%mod;
	return ans;
}
void init()
{
	int r=400000;
	mul[0]=1;
	for(int i=1;i<=r;i++)
		mul[i]=(ll)mul[i-1]*i%mod;
	inv[r]=qpow(mul[r],mod-2);
	for(int i=r;i>=1;i--)
		inv[i-1]=(ll)inv[i]*i%mod;
}
int cb(int a,int b)
{
	if(b<0||b>a)
		return 0;
	return (ll)mul[a]*inv[b]%mod*inv[a-b]%mod;
}
void down(int x)
{
	if(ch[x][0])
		v[ch[x][0]]+=lz[x],lz[ch[x][0]]+=lz[x];
	if(ch[x][1])
		v[ch[x][1]]+=lz[x],lz[ch[x][1]]+=lz[x];
	lz[x]=0;
}
void update(int x)
{
	sz[x]=sz[ch[x][0]]+sz[ch[x][1]]+1;
}
int newnode(int il,int val)
{
	v[++cnt]=val;
	id[cnt]=il;
	lz[cnt]=0;
	sz[cnt]=1;
	ch[cnt][0]=ch[cnt][1]=0;
	return cnt;
}
pii split(int x,int val)
{
	if(!x)
		return pii(0,0);
	down(x);
	if(v[x]>=val)
	{
		pii t=split(ch[x][0],val);
		ch[x][0]=t.se;
		update(x);
		return pii(t.fi,x);
	}
	else
	{
		pii t=split(ch[x][1],val);
		ch[x][1]=t.fi;
		update(x);
		return pii(x,t.se);
	}
}
int mrg(int x,int y)
{
	if(!x||!y)
		return x+y;
	if(rand()%(sz[x]+sz[y])<sz[x])
	{
		down(x);
		ch[x][1]=mrg(ch[x][1],y);
		update(x);
		return x;
	}
	else
	{
		down(y);
		ch[y][0]=mrg(x,ch[y][0]);
		update(y);
		return y;
	}
}
int getv(int x,int p)
{
	if(!x)
		return 0;
	if(v[x]==p)
		return x;
	down(x);
	if(p<v[x])
		return getv(ch[x][0],p);
	else
		return getv(ch[x][1],p);
}
int main()
{
	init();
	int ttt;
	scanf("%d",&ttt);
	while(ttt--)
	{
		cnt=rt=0;
		scanf("%d%d",&n,&m);
		for(int i=1;i<=m;i++)
			vis[i]=0;
		for(int i=1;i<=m;i++)
			scanf("%d%d",qx+i,qy+i);
		for(int i=1;i<=m;i++)
		{
			vis[i]=1;
			pii t=split(rt,qy[i]);
			if(t.se)
				v[t.se]++,lz[t.se]++;
			int p=newnode(i,qy[i]);
			rt=mrg(t.fi,p);
			rt=mrg(rt,t.se);
			p=getv(rt,qy[i]-1);
			if(p)
				vis[id[p]]=0;
		}
		int cp=2*n-1;
		for(int i=1;i<=m;i++)
			if(vis[i])
				cp--;
		printf("%d\n",cb(cp,n));
	}
	return 0;
}