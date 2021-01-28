#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#define ll long long
using namespace std;
int n,m;
int w[200009];
int s[3][200009],tp[3];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		ll sm=0;
		for(int i=1;i<=n;i++)
			scanf("%d",w+i),sm+=w[i];
		tp[1]=tp[2]=0;
		for(int i=1,a;i<=n;i++)
			scanf("%d",&a),s[a][++tp[a]]=w[i];
		sort(s[1]+1,s[1]+tp[1]+1);
		sort(s[2]+1,s[2]+tp[2]+1);
		reverse(s[1]+1,s[1]+tp[1]+1);
		reverse(s[2]+1,s[2]+tp[2]+1);
		// printf("tp1:%d tp2:%d\n",tp[1],tp[2]);
		// for(int i=1;i<=tp[1];i++)
		// 	printf("%d ",s[1][i]);
		int rp=tp[2];
		if(sm<m)
		{
			printf("-1\n");
			continue;
		}
		while(rp>=1&&sm-s[2][rp]>=m)
			sm-=s[2][rp--];
		// printf("sm:%lld rp:%d\n",sm,rp);
		int ans=tp[1]+rp*2;
		for(int i=tp[1]-1;i>=0;i--)
		{
			sm-=s[1][i+1];
			while(sm<m&&rp<tp[2])
				sm+=s[2][++rp];
			// printf("i:%d sm:%lld rp:%d",i,sm,rp);
			if(sm<m)
				break;
			ans=min(ans,i+2*rp);
		}
		printf("%d\n",ans);
	}
	return 0;
}