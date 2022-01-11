#include<bits/stdc++.h>
#define ll long long
#define inf 0x7F7F7F7F7F7F7F7FLL
using namespace std;
int n,k;
int s[500009];
int ml[500009];
int main()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
		scanf("%d",s+i);
	sort(s+1,s+n+1,greater<int>());
	// if(k==0)
	// {
	// 	ll ans=0;
	// 	for(int i=1;i<=n;i++)
	// 		ans+=(ll)(n-i)*s[i];
	// 	return printf("%lld",ans),0;
	// }
	int pos=0;
	ll ansp=0,smp=0;
	for(int i=1;i<=n;i++)
		if(s[i]>=0)
			pos=i;
	for(int i=1;i<=pos;i++)
		ansp+=(ll)(pos-i)*s[i],smp+=s[i];
	// printf("ansp:%lld smp:%lld\n",ansp,smp);
	for(int i=n;i>=pos;i--)
		ml[i]=(n-i)/(k+1);
	ml[n+1]=-1;
	ll tsm=0,ans=-inf,pf=0;
	int q=ml[pos+1]+1;
	for(int i=pos+1;i<=n;i++)
		tsm+=(ll)ml[i]*s[i];
	ans=max(ans,tsm+(ll)q*smp+ansp);
	// printf("q:%d tsm:%lld\n",q,tsm);
	for(int i=pos+1;i<=n;i++)
	{
		pf+=s[i];
		if(ml[i]==ml[i+1])
		{
			tsm+=pf;
			q++;
			// printf("i:%d q:%d pf:%lld tsm:%lld\n",i,q,pf,tsm);
			ans=max(ans,tsm+(ll)q*smp+ansp);
		}
	}
	printf("%lld",ans);
	return 0;
}