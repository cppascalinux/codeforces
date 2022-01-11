#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,mod;
int cb[509][509],mul[509];
int f[509][125009],sm[509][125009],psm[130009],qsm[130009];
int ans[509],diff[509];
void init()
{
	for(int i=0;i<=n;i++)
		cb[i][i]=cb[i][0]=1;
	for(int i=2;i<=n;i++)
		for(int j=1;j<=i-1;j++)
			cb[i][j]=(cb[i-1][j]+cb[i-1][j-1])%mod;
	mul[0]=1;
	for(int i=1;i<=n;i++)
		mul[i]=(ll)mul[i-1]*i%mod;
}
void solve()
{
	f[1][0]=sm[1][0]=1;
	for(int i=2;i<=n;i++)
	{
		int ts=i*(i-1)/2,lsm=(i-1)*(i-2)/2;
		for(int j=0;j<=ts;j++)
		{
			int lp=max(0,j-(i-1));
			int rp=min(lsm,j);
			f[i][j]=sm[i-1][rp];
			if(lp>0)
				f[i][j]=(f[i][j]-sm[i-1][lp-1]+mod)%mod;
			// printf("i:%d j:%d f:%d\n",i,j,f[i][j]);
		}
		sm[i][0]=f[i][0];
		for(int j=1;j<=ts;j++)
			sm[i][j]=(sm[i][j-1]+f[i][j])%mod;
	}
	ans[1]=0;
	diff[1]=0;
	for(int i=2;i<=n;i++)
	{
		for(int j=1;j<=i-1;j++)
			ans[i]=(ans[i]+(ll)cb[i][j]*mul[j]%mod*diff[i-j])%mod;
		int lsm=(i-1)*(i-2)/2;
		memset(psm,0,sizeof(psm));
		memset(qsm,0,sizeof(qsm));
		for(int j=lsm;j>=0;j--)
			psm[j]=(psm[j+1]+f[i-1][j])%mod;
		for(int j=lsm;j>=0;j--)
		{
			qsm[j]=(qsm[j+1]+(ll)(lsm-j)*psm[j])%mod;
			psm[j]=(psm[j+1]+psm[j])%mod;
		}
		for(int j=0;j<=lsm-2;j++)
		{
			int rp=(j+2-lsm+i-1)%mod;
			rp=(rp+mod)%mod;
			int sm1=(qsm[j+2]-qsm[j+2+i-1]+mod)%mod;
			int sm2=(psm[j+2]-psm[j+2+i-1]+mod)%mod;
			int ad=(sm1+(ll)rp*sm2)%mod;
			// if(i==4)
				// printf("i:%d j:%d sm1:%d sm2:%d rp:%d ad:%d\n",i,j,sm1,sm2,rp,ad);
			diff[i]=(diff[i]+(ll)ad*f[i-1][j])%mod;
		}
		(ans[i]+=diff[i])%=mod;
		// printf("i:%d diff:%d ans:%d\n",i,diff[i],ans[i]);
	}
	printf("%d",ans[n]);
}
int main()
{
	scanf("%d%d",&n,&mod);
	init();
	solve();
	return 0;
}