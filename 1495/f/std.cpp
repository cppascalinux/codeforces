#include<set>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#define ch() getchar()
#define pc(x) putchar(x)
using namespace std;
template<typename T>void read(T&x){
	static char c;static int f;
	for(c=ch(),f=1;c<'0'||c>'9';c=ch())if(c=='-')f=-f;
	for(x=0;c>='0'&&c<='9';c=ch())x=x*10+(c&15);x*=f;
}
template<typename T>void write(T x){
	static char q[65];int cnt=0;
	if(x<0)pc('-'),x=-x;
	q[++cnt]=x%10,x/=10;
	while(x)
		q[++cnt]=x%10,x/=10;
	while(cnt)pc(q[cnt--]+'0');
}
const int maxn=200005;
int p[maxn],st[maxn],tp,pa[maxn][22],dp[maxn];
long long a[maxn],b[maxn],val[maxn],dis[maxn];
int lca(int x,int y){
	if(dp[x]<dp[y])x^=y^=x^=y;
	for(int t=dp[x]-dp[y],cn=0;t;t>>=1,++cn)
		if(t&1)x=pa[x][cn];
	if(x==y)return x;
	for(int t=20;t>=0;--t)
		if(pa[x][t]!=pa[y][t])
			x=pa[x][t],y=pa[y][t];
	return pa[x][0];
}
int vis[maxn],cnt[maxn];set<int>s;
long long sum;
long long dist(int x,int y){
	return dis[x]+dis[y]-2*dis[lca(x,y)];
}
set<int>::iterator it;
void ins(int x){
	it=s.insert(x).first;int l=*(--it);++it;++it;
	int r=((it==s.end())?*s.begin():*it);
	sum+=dist(l,x)+dist(x,r)-dist(l,r);
}
void del(int x){
	it=s.find(x);int l=*(--it);++it;++it;
	int r=((it==s.end())?*s.begin():*it);
	sum-=dist(l,x)+dist(x,r)-dist(l,r);
	--it;s.erase(it);
}
int main(){
	int n,q;read(n),read(q);
	for(int i=1;i<=n;++i){
		read(p[i]);
		while(tp&&p[st[tp]]<p[i])--tp;
		dp[i]=dp[pa[i][0]=st[tp]]+1;st[++tp]=i;
		for(int j=1;(1<<j)<=dp[i];++j)
			pa[i][j]=pa[pa[i][j-1]][j-1];
	}
	for(int i=1;i<=n;++i)read(a[i]),val[i]+=a[i];
	for(int i=1;i<=n;++i)read(b[i]),val[i]-=b[i],val[pa[i][0]]+=b[i];
	for(int i=n;i>=1;--i)dis[pa[i][0]]+=min(0ll,dis[i]+=val[i]),dis[i]-=min(0ll,dis[i]);
	dis[0]+=val[0];for(int i=1;i<=n;++i)dis[i]+=dis[pa[i][0]];cnt[0]=1;s.insert(0);
	while(q--){
		int x;read(x);
		if(vis[x]){
			vis[x]=false;
			if(!(--cnt[pa[x][0]]))
				del(pa[x][0]);
		}
		else{
			vis[x]=true;
			if(!(cnt[pa[x][0]]++))
				ins(pa[x][0]);
		}
		write(sum/2+dis[0]),pc('\n');
	}
	return 0;
}