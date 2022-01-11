#include<bits/stdc++.h>
using namespace std;
int n,q;
int s[100009];
int main()
{
	scanf("%d%d",&n,&q);
	int sm=0;
	for(int i=1;i<=n;i++)
		scanf("%d",s+i),sm+=(s[i]==1);
	for(int i=1;i<=q;i++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		// printf("a:%d b:%d\n",a,b);
		if(a==1)
		{
			if(s[b]==1)
				sm--;
			else
				sm++;
			s[b]^=1;
		}
		else
			printf("%d\n",b>sm?0:1);
	}
	return 0;
}