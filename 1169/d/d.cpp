#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define li long long
using namespace std;
int n;
char s[300009];
int main()
{
#ifdef I_LOVE_KTY
	freopen("d.in","r",stdin);
	freopen("d.out","w",stdout);
#endif
	scanf("%s",s+1);
	n=strlen(s+1);
	li ans=0;
	int rmn=n+1;
	for(int i=n;i>=1;i--)
	{
		for(int j=1;i+2*j<=n;j++)
		{
			if(s[i]==s[i+j]&&s[i+j]==s[i+2*j])
			{
				rmn=min(rmn,i+2*j);
				break;
			}
		}
		ans+=n-rmn+1;
	}
	cout<<ans;
	return 0;
}