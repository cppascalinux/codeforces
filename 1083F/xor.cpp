//2019.05.22
//CF1083F The Fair Nut and Amusing Xor 区间修改差分成两个点修改,化为若干条链,求出每条链的异或前缀和中0的个数,用分块维护
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;
int n,k,q,blk,cntb;
int sa[200009],sb[200009];
int s[200009],ns[200009],cpos[200009];//origin sequence, new seq, pos of org seq on new seq
int bl[509],br[509],bel[200009];
int lz[509],buc[509][17009];//bucket to store the numbers
int cl[200009],cr[200009];//the leftmost and rightmost of one chain on the new sequence
int xsm[200009],xcnt;//xor sum of each chain, number of illegal chains
void init()
{
	blk=sqrt(n+1),cntb=(n+1-1)/blk+1;
	for(int i=1;i<=n+1;i++)
		bel[i]=(i-1)/blk+1;
	for(int i=1;i<=cntb;i++)
		bl[i]=br[i-1]+1,br[i]=min(bl[i]+blk-1,n+1);

	int cur=0;
	for(int i=1;i<=k;i++)
	{
		cl[i]=cur+1;
		for(int j=i;j<=n+1;j+=k)
		{
			ns[++cur]=s[j]^s[j-1];
			if(j>i)
				ns[cur]^=ns[cur-1];
			cpos[j]=cur;
		}
		xsm[i]=ns[cur];
		xcnt+=xsm[i]>0;
		cr[i]=cur;
	}

	for(int i=1;i<=cntb;i++)
		for(int j=bl[i];j<=br[i];j++)
			buc[i][ns[j]]++;
}
int ask0()
{
	int ans=0;
	for(int i=1;i<=cntb;i++)
		ans+=buc[i][lz[i]];
	return ans;
}
void add(int l,int r,int val)
{
	if(!val)
		return;
	int idl=bel[l],idr=bel[r];
	if(idl==idr)
	{
		for(int i=l;i<=r;i++)
		{
			buc[idl][ns[i]]--;
			buc[idl][ns[i]^=val]++;
		}
		return;
	}
	for(int i=idl+1;i<=idr-1;i++)
		lz[i]^=val;
	for(int i=l;i<=br[idl];i++)
	{
		buc[idl][ns[i]]--;
		buc[idl][ns[i]^=val]++;
	}
	for(int i=r;i>=bl[idr];i--)
	{
		buc[idr][ns[i]]--;
		buc[idr][ns[i]^=val]++;
	}
}
void change(int p,int val)
{
	int dt=s[p]^val;
	int id=(p-1)%k+1;
	s[p]=val;
	xcnt-=xsm[id]>0;
	xsm[id]^=dt;
	xcnt+=xsm[id]>0;
	add(cpos[p],cr[id],dt);

	id=(p+1-1)%k+1;
	xcnt-=xsm[id]>0;
	xsm[id]^=dt;
	xcnt+=xsm[id]>0;
	add(cpos[p+1],cr[id],dt);

	printf("%d\n",xcnt?-1:n+1-ask0());
}
int main()
{
#ifdef I_LOVE_KTY
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
#endif
	scanf("%d%d%d",&n,&k,&q);
	for(int i=1;i<=n;i++)
		scanf("%d",sa+i);
	for(int i=1;i<=n;i++)
		scanf("%d",sb+i);
	for(int i=1;i<=n;i++)
		s[i]=sa[i]^sb[i];
	init();
	printf("%d\n",xcnt?-1:n+1-ask0());
	for(int i=1,a,b;i<=q;i++)
	{
		char typ[2];
		scanf("%s%d%d",typ,&a,&b);
		int ns=0;
		if(typ[0]=='a')
			ns=(sa[a]=b)^sb[a];
		else
			ns=sa[a]^(sb[a]=b);
		change(a,ns);
	}
	return 0;
}