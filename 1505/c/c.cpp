#include<bits/stdc++.h>
using namespace std;
int main()
{
	char s[20];
	scanf("%s",s+1);
	int n=strlen(s+1);
	for(int i=1;i<=n;i++)
		s[i]-='A';
	if(n<=2||(s[1]+s[2])%26==s[3])
		printf("YES");
	else
		printf("NO");
	return 0;
}