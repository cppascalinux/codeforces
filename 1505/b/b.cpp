#include<bits/stdc++.h>
using namespace std;
char s[1000009];
int main()
{
	int a;
	scanf("%d",&a);
	while(1)
	{
		int x=a,sm=0;
		while(a)
			sm+=a%10,a/=10;
		a=sm;
		if(a/10==0)
			break;
	}
	printf("%d",a);
	return 0;
}