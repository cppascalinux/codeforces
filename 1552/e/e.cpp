#include<bits/stdc++.h>
using namespace std;
int n,k;
int s[10009];
int pos[109],lst[10009];
int vis[109];
int rep[109];
int ansl[109],ansr[109];
int main()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n*k;i++)
	{
		scanf("%d",s+i);
		lst[i]=pos[s[i]];
		pos[s[i]]=i;
	}
	int d=n/(k-1);
	int r=n%(k-1);
	int cur=1,sm=0;
	for(int i=1;i<=n*k;i++)
	{
		rep[s[i]]++;
		if(!vis[s[i]]&&rep[s[i]]==2)
		{
			sm++;
			vis[s[i]]=1;
			ansl[s[i]]=lst[i];
			ansr[s[i]]=i;
		}
		int curm=d+(cur<=r);
		// printf("i:%d sm:%d curm:%d\n",i,sm,curm);
		if(sm>=curm)
		{
			sm=0;
			cur++;
			for(int j=1;j<=n;j++)
				rep[j]=0;
		}
	}
	for(int i=1;i<=n;i++)
		printf("%d %d\n",ansl[i],ansr[i]);
	return 0;
}