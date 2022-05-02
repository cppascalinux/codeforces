#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int mod=1000000007;
int n;
int b,q,y,c,r,z;
int main()
{
	int tt;
	scanf("%d",&tt);
	while(tt--)
	{
		scanf("%d%d%d%d%d%d",&b,&q,&y,&c,&r,&z);
		if(r%q!=0)
		{
			puts("0");
			continue;
		}
		ll frb=b,lsb=b+(ll)(y-1)*q;
		ll frc=c,lsc=c+(ll)(z-1)*r;
		if(frc<frb||lsc>lsb)
		{
			puts("0");
			continue;
		}
		if((frc-frb)%q!=0)
		{
			puts("0");
			continue;
		}
		if(frc-r<frb||lsc+r>lsb)
		{
			puts("-1");
			continue;
		}
		int ans=0;
		for(int i=1;i*i<=r;i++)
			if(r%i==0)
			{
				int x=i;
				if((ll)q*x==(ll)r*__gcd(q,x))
				{
					ans=(ans+(ll)r/x*r/x)%mod;
				}
				if(i*i!=r)
				{
					x=r/i;
					if((ll)q*x==(ll)r*__gcd(q,x))
					{
						ans=(ans+(ll)r/x*r/x)%mod;
					}
				}
			}
		printf("%d\n",ans);
	}
	return 0;
}