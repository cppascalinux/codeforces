#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		y=min(x-1,y);
		ll ans=0;
		int bl=1,br=y+1;
		while(bl<br)
		{
			int mid=(bl+br)>>1;
			if(mid-1>=x/(mid+1))
				br=mid;
			else
				bl=mid+1;
		}
		ans+=(ll)(bl-1)*(bl-2)/2;
		// printf("i:%d bl;%d\n",t,bl);
		for(int l=bl+1,r;l<=y+1;l=r+1)
		{
			r=min(x/(x/l),y+1);
			if(r>=l)
				ans+=(ll)(r-l+1)*(x/l);
		}
		printf("%lld\n",ans);
	}
	return 0;
}