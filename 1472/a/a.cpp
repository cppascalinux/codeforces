#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int w,h,n;
		scanf("%d%d%d",&w,&h,&n);
		int sm1=1,sm2=1;
		while(w%2==0)
			sm1*=2,w/=2;
		while(h%2==0)
			sm2*=2,h/=2;
		printf("%s\n",sm1*sm2>=n?"YES":"NO");
	}
	return 0;
}