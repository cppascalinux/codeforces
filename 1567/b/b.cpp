#include<bits/stdc++.h>
using namespace std;
int n,m;
int sm[300009];
int main()
{
	int ttt;
	scanf("%d",&ttt);
	for(int i=1;i<=300000;i++)
		sm[i]=sm[i-1]^i;
	while(ttt--)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		if((sm[a-1]^b)==0)
			printf("%d\n",a);
		else if((sm[a-1]^b)!=a)
			printf("%d\n",a+1);
		else
			printf("%d\n",a+2);
	}
	return 0;
}