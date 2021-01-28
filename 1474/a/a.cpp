#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n;
char s[100009];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%s",&n,s+1);
		int lans=0;
		for(int i=1;i<=n;i++)
		{
			s[i]-='0';
			if(s[i]+1!=lans)
				lans=s[i]+1,printf("1");
			else
				lans=s[i],printf("0");
		}
		printf("\n");
	}
	return 0;
}