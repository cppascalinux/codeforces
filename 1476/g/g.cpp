#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#define inf 0x7F7F7F7F
using namespace std;
int n,m,smop,smqy;
int s[100009];
int rep[100009],sor[100009];
int st[100009],ed[100009];
int bel[100009];
int pos[100009],opr[100009],inv[100009];
int ans[100009];
struct node
{
	int l,r,t,k,id;
	bool operator<(const node &p)const
	{
		if(bel[l]!=bel[p.l])
			return bel[l]<bel[p.l];
		if(bel[r]!=bel[p.r])
			return bel[r]<bel[p.r];
		return t<p.t;
	}
}qry[100009];
struct pii
{
	int v,c;
}ks[100009];
void init()
{
	int len=2154;
	for(int i=1;i<=n;i++)
		bel[i]=(i-1)/len+1;
}
int ask(int k)
{
	if(st[0]-1<k)
		return -1;
	int tp=0;
	for(int i=sor[1];i;i=sor[ed[i]+1])
		ks[++tp]=pii{i,ed[i]-st[i]+1}/* ,printf("i:%d st:%d ed:%d\n",i,st[i],ed[i]) */;
	int lp=1,sm=0,ans=inf;
	for(int i=1;i<=tp;i++)
	{
		sm+=ks[i].c;
		while(lp<i&&sm-ks[lp].c>=k)
			sm-=ks[lp].c,lp++;
		// printf("i:%d lp:%d sm:%d\n",i,lp,sm);
		if(sm>=k)
			ans=min(ans,ks[lp].v-ks[i].v);
	}
	return ans;
}
void add(int x)
{
	int &t=rep[x];
	if(ed[t+1]>=st[t+1])
		ed[t+1]++;
	else
		st[t+1]=ed[t+1]=st[t];
	sor[st[t]]++;
	st[t]++;
	t++;
		// for(int i=1;i<=6;i++)
		// 	printf("i:%d st:%d ed:%d\n",i,st[i],ed[i]);
		// printf("\n");
}
void del(int x)
{
	int &t=rep[x];
	if(ed[t-1]>=st[t-1])
		st[t-1]--;
	else
		st[t-1]=ed[t-1]=ed[t];
	sor[ed[t]]--;
	ed[t]--;
	t--;
		// for(int i=1;i<=6;i++)
		// 	printf("i:%d st:%d ed:%d\n",i,st[i],ed[i]);
		// printf("\n");
}
void solve()
{
	for(int i=100000;i>=1;i--)
		st[i]=1,ed[i]=0;
	st[0]=1,ed[0]=n+1;
	sort(qry+1,qry+smqy+1);
	int pl=1,pr=0,pt=smop;
	for(int i=1;i<=smqy;i++)
	{
		node t=qry[i];
		while(pl>t.l)
			add(s[--pl]);
		while(pr<t.r)
			add(s[++pr]);
		while(pl<t.l)
			del(s[pl++]);
		while(pr>t.r)
			del(s[pr--]);
		while(pt<t.t)
		{
			pt++;
			int p=pos[pt];
			s[p]=opr[pt];
			if(p>=t.l&&p<=t.r)
				del(inv[pt]),add(opr[pt]);
		}
		while(pt>t.t)
		{
			int p=pos[pt];
			s[p]=inv[pt];
			if(p>=t.l&&p<=t.r)
				del(opr[pt]),add(inv[pt]);
			pt--;
		}
		// for(int i=1;i<=n;i++)
		// 	printf("%d ",s[i]);
		// printf("\n");
		// printf("pl:%d pr:%d\n",pl,pr);
		// for(int i=1;i<=6;i++)
		// 	printf("i:%d st:%d ed:%d\n",i,st[i],ed[i]);
		// for(int i=1;i<=3;i++)
		// 	printf("%d ",sor[i]);
		// printf("\n");
		ans[t.id]=ask(t.k);
	}
	for(int i=1;i<=smqy;i++)
		printf("%d\n",ans[i]);
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",s+i);
	init();
	for(int i=1,a,b,c,d;i<=m;i++)
	{
		scanf("%d%d%d",&a,&b,&c);
		if(a==1)
		{
			scanf("%d",&d);
			++smqy;
			qry[smqy]=node{b,c,smop,d,smqy};
		}
		else
		{
			pos[++smop]=b;
			opr[smop]=c;
			inv[smop]=s[b];
			s[b]=c;
		}
	}
	solve();
	return 0;
}