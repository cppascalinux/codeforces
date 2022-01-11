#include<bits/stdc++.h>
using namespace std;
int n;
char s[100009];
int main()
{
	int ttt;
	scanf("%d",&ttt);
	while(ttt--)
	{
		scanf("%d",&n);
		scanf("%s",s+1);
		for(int i=1;i<=n;i++)
			s[i]-='0';
		int ps=0;
		for(int i=1;i<=n;i++)
			if(s[i]==0)
				ps=i;
		if(ps==0)
		{
			int hf=n/2;
			printf("%d %d %d %d\n",1,2*hf,1,hf);
		}
		else if(ps<=n/2)
			printf("%d %d %d %d\n",ps,n,ps+1,n);
		else
			printf("%d %d %d %d\n",1,ps,1,ps-1);
	}
	return 0;
}