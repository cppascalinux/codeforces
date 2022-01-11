#include<bits/stdc++.h>
using namespace std;
int n;
char s[5009];
int t1[5009],t2[5009],sa[5009],c[5009];
int rnk[5009],h[5009];
int lcp[5009][5009];
int f[5009][5009];
void geth()
{
	for(int i=1;i<=n;i++)
		rnk[sa[i]]=i;
	int p=0;
	for(int i=1;i<=n;i++)
	{
		if(p)
			p--;
		int np=sa[rnk[i]-1];
		while(s[i+p]==s[np+p])
			p++;
		h[rnk[i]]=p;
	}
}
void init()
{
	for(int i=1;i<=n;i++)
	{
		int l=n-sa[i]+1;
		lcp[i][i]=l;
		for(int j=i+1;j<=n;j++)
		{
			l=min(l,h[j]);
			lcp[i][j]=lcp[j][i]=l;
		}
	}
}
void getsa()
{
	int *x=t1,*y=t2;
	int m=26;
	memset(c,0,(m+1)<<2);
	for(int i=1;i<=n;i++)
		c[x[i]=s[i]]++;
	x[n+1]=y[n+1]=0;
	for(int i=1;i<=m;i++)
		c[i]+=c[i-1];
	for(int i=1;i<=n;i++)
		sa[c[x[i]]--]=i;
	for(int k=1;k<=n;k<<=1)
	{
		int p=0;
		for(int i=n-k+1;i<=n;i++)
			y[++p]=i;
		for(int i=1;i<=n;i++)
			if(sa[i]>=k+1)
				y[++p]=sa[i]-k;
		memset(c,0,(m+1)<<2);
		for(int i=1;i<=n;i++)
			c[x[i]]++;
		for(int i=1;i<=m;i++)
			c[i]+=c[i-1];
		for(int i=n;i>=1;i--)
			sa[c[x[y[i]]]--]=y[i];
		p=0;
		for(int i=1;i<=n;i++)
			y[sa[i]]=x[sa[i]]==x[sa[i-1]]&&x[sa[i]+k]==x[sa[i-1]+k]?p:++p;
		swap(x,y);
		m=p;
		if(m>=n)
			break;
	}
}
int main()
{
	int ttt;
	scanf("%d",&ttt);
	while(ttt--)
	{
		scanf("%d",&n);
		scanf("%s",s+1);
		// if(ttt==90)
		// 	printf("%s\n",s+1);
		for(int i=1;i<=n;i++)
			s[i]-='a'-1;
		getsa();
		geth();
		init();
		int ans=0;
		for(int i=1;i<=n;i++)
		{
			int p=rnk[i];
			int lp=1,cp=i-1;
			for(int j=i;j<=n;j++)
			{
				if(j>i)
					f[i][j]=f[i][j-1]+1;
				else
					f[i][j]=1;
				int l=j-i+1;
				while(lp<p&&lcp[lp][p]<l)
				{
					if(sa[lp]<i)
						f[i][j]=max(f[i][j],f[sa[lp]][n]+1);
					lp++;
				}
				while(cp>0&&lcp[p][rnk[cp]]<l-1)
					cp--;
				if(cp>0&&l>1)
					f[i][j]=max(f[i][j],f[cp][cp+l-2]+1);
				ans=max(ans,f[i][j]);
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}