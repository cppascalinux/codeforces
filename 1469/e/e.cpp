#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<set>
using namespace std;
#define pii pair<int,int>
#define ll long long
#define fi first
#define se second
#define bs 619
#define mod1 1000000007
#define mod2 1000000009
pii operator+(pii a,pii b){return pii((a.fi+b.fi)%mod1,(a.se+b.se)%mod2);}
pii operator-(pii a,pii b){return pii((a.fi-b.fi+mod1)%mod1,(a.se-b.se+mod2)%mod2);}
pii operator*(pii a,pii b){return pii((ll)a.fi*b.fi%mod1,(ll)a.se*b.se%mod2);}
pii operator*(pii a,int v){return pii((ll)v*a.fi%mod1,(ll)v*a.se%mod2);}
pii operator+(pii a,int v){return pii((a.fi+v)%mod1,(a.se+v)%mod2);}
int n,k;
set<pii> h;
char s[1000009];
int q[100009];
pii hs[1000009],mul[1000009];
int sa[1000009],t1[1000009],t2[1000009],c[1000009],rnk[1000009];
void init()
{
	h.clear();
	for(int i=1;i<=n;i++)
		hs[i]=hs[i-1]*bs+(1-s[i]);
	mul[0]=pii(1,1);
	for(int i=1;i<=n;i++)
		mul[i]=mul[i-1]*bs;
	for(int i=k;i<=n;i++)
		h.insert(hs[i]-hs[i-k]*mul[k]);
	// for(pii t:h)
	// 	printf("fi:%d se:%d\n",t.fi,t.se);
}
void solve()
{
	int bit=0;
	while(1<<bit<=n+1)
		bit++;
	bit=min(bit,k);
	// printf("bit:%d\n",bit);
	for(int i=0;i<1<<bit;i++)
	{
		pii t(0,0);
		for(int j=bit-1;j>=0;j--)
		{
			if(i>>j&1)
				q[j]=1;
			else
				q[j]=0;
			t=t*bs+q[j];
		}
		if(!h.count(t))
		{
			printf("YES\n");
			for(int j=1;j<=k-bit;j++)
				printf("0");
			for(int j=bit-1;j>=0;j--)
				printf("%d",q[j]);
			printf("\n");
			return;
		}
	}
	printf("NO\n");
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&k);
		scanf("%s",s+1);
		for(int i=1;i<=n;i++)
			s[i]-='0';
		init();
		solve();
	}
	return 0;
}