#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n;
int p[300009],f[300009];
int ls[300009],ans[300009];
int st[300009];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d",p+i);
		int tp=0;
		for(int i=1;i<=n;i++)
		{
			f[i]=f[i-1];
			ls[i]=i-1;
			ans[i]=0;
			if(f[i-1]>=i&&f[i]<i+p[i])
				f[i]=i+p[i],ans[i]=1;
			int pos=lower_bound(f,f+i,i-p[i]-1)-f;
			if(pos!=i)
			{
				if(f[i]<i-1)
					f[i]=i-1,ans[i]=0,ls[i]=pos;
				int ns=lower_bound(st+1,st+tp+1,pos+1)-st;
				if(ns<=tp)
				{
					ns=st[ns];
					if(f[i]<ns+p[ns])
						f[i]=ns+p[ns],ans[i]=0,ls[i]=pos;
				}
			}
			// printf("i:%d f:%d ls:%d ans:%d pos:%d\n",i,f[i],ls[i],ans[i],pos);
			while(tp>0&&st[tp]+p[st[tp]]<=i+p[i])
				tp--;
			st[++tp]=i;
		}
		if(f[n]<n)
			printf("NO\n");
		else
		{
			printf("YES\n");
			for(int i=n;i;i=ls[i])
				for(int j=ls[i]+1;j<=i-1;j++)
					ans[j]=1;
			for(int i=1;i<=n;i++)
				printf("%c",ans[i]?'R':'L');
			printf("\n");
		}
	}
	return 0;
}