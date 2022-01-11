#include<bits/stdc++.h>
#define inf 0x7F7F7F7F
using namespace std;
int n;
int s[100009];
int up[100009];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",s+i);
		s[i]^=s[i-1];
	}
	if(n>=100)
		return printf("1"),0;
	int ans=inf;
	for(int i=0;i<=n;i++)
		for(int j=i+1;j<=n;j++)
			for(int k=j+1;k<=n;k++)
				if((s[i]^s[j])>(s[j]^s[k]))
					ans=min(ans,k-i-2);
	printf("%d",ans==inf?-1:ans);
	return 0;
}