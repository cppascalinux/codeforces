#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n;
int s[30009];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		int sm[3];
		for(int i=0;i<3;i++)
			sm[i]=-n/3;
		for(int i=1;i<=n;i++)
			scanf("%d",s+i),s[i]%=3,sm[s[i]]++;
		int ans=0;
		for(int i=0;i<100;i++)
			if(sm[i%3]>0)
				ans+=sm[i%3],sm[(i+1)%3]+=sm[i%3],sm[i%3]=0;
		printf("%d\n",ans);
	}
	return 0;
}