#include<bits/stdc++.h>
using namespace std;
int main()
{
	int ttt;
	scanf("%d",&ttt);
	while(ttt--)
	{
		int l,r;
		scanf("%d%d",&l,&r);
		int lp=r/2+1;
		if(l>lp)
			printf("%d\n",r-l);
		else
			printf("%d\n",r-lp);
	}
	return 0;
}