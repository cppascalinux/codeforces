#include<bits/stdc++.h>
using namespace std;
int n,k;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&k);
		if((n-k)%2==0)
		{
			for(int i=1;i<=k-2;i++)
				printf("1 ");
			printf("%d %d\n",(n-(k-2))/2,(n-(k-2))/2);
		}
		else
		{
			for(int i=1;i<=k-3;i++)
				printf("1 ");
			int rm=n-(k-3);
			if(rm%4==0)
				printf("%d %d %d\n",rm/4,rm/4,rm/2);
			else
				printf("%d %d %d\n",2,(rm-2)/2,(rm-2)/2);
		}
	}
	return 0;
}