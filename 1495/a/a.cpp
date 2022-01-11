#include<bits/stdc++.h>
#define db double
using namespace std;
int n;
int s1[100009],s2[100009];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		int tp1=0,tp2=0;
		for(int i=1;i<=2*n;i++)
		{
			int x,y;
			scanf("%d%d",&x,&y);
			if(x)
				s1[++tp1]=abs(x);
			else
				s2[++tp2]=abs(y);
		}
		sort(s1+1,s1+n+1);
		sort(s2+1,s2+n+1);
		db ans=0;
		for(int i=1;i<=n;i++)
			ans+=sqrt((db)s1[i]*s1[i]+(db)s2[i]*s2[i]);
		printf("%.12lf\n",ans);
	}
	return 0;
}