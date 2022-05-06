#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int n;
int s[100009];
int main()
{
	int tt;
	scanf("%d",&tt);
	while(tt--)
	{
		scanf("%d",&n);
		int sm=0;
		for(int i=1;i<=n;i++)
			scanf("%d",s+i),sm+=(s[i]<0);
		for(int i=1;i<=sm;i++)
			s[i]=-abs(s[i]);
		for(int i=sm+1;i<=n;i++)
			s[i]=abs(s[i]);
		int fl=0;
		for(int i=2;i<=n;i++)
			if(s[i]<s[i-1])
				fl=1;
		printf("%s\n",fl?"NO":"YES");
	}
	return 0;
}