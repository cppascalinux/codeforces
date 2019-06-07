#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n;
int s[200009],pos[200009];
void solve1()
{
	int ans=0;
	for(int i=2;i<=n;i++)
		ans=max(ans,pos[i]-i+1);
	printf("%d",ans+n);
}
void solve2()
{
	int fg=1,k=pos[1];
	for(int i=k;i<=n;i++)
		if(s[i]!=i-k+1)
			fg=0;
	for(int i=n-k+2;i<=n;i++)
		if(pos[i]>i-(n-k+1)-1)
			fg=0;
	if(fg)
		return printf("%d",pos[1]-1),void();
	for(int i=1;i<=n;i++)
		pos[i]=max(pos[i]-k,0);
	int ans=0;
	for(int i=2;i<=n;i++)
		ans=max(ans,pos[i]-i+1);
	printf("%d",k+ans+n);
}
int main()
{
#ifdef I_LOVE_KTY
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
#endif
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",s+i);
	for(int i=1;i<=n;i++)
		scanf("%d",s+i);
	for(int i=1;i<=n;i++)
		if(s[i])
			pos[s[i]]=i;
	if(!pos[1])
		solve1();
	else
		solve2();
	return 0;
}