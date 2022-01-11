#include<bits/stdc++.h>
using namespace std;
int s1[109],s2[109];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		if(a>b)
		{
			printf("NO\n");
			continue;
		}
		int tp1=0,tp2=0;
		for(int i=0;i<=30;i++)
			if(a>>i&1)
				s1[++tp1]=i;
		for(int i=0;i<=30;i++)
			if(b>>i&1)
				s2[++tp2]=i;
		if(tp1<tp2)
		{
			printf("NO\n");
			continue;
		}
		int fg=1;
		for(int i=1;i<=tp2;i++)
			if(s1[i]>s2[i])
				fg=0;
		printf("%s\n",fg?"YES":"NO");
	}
	return 0;
}