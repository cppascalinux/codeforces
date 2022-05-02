#include<bits/stdc++.h>
using namespace std;
int n;
char s[200009];
int sm[200009];
int main()
{
	int tt;
	scanf("%d",&tt);
	while(tt--)
	{
		scanf("%s",s+1);
		n=strlen(s+1);
		for(int i=1;i<=n;i++)
			sm[i]=sm[i-1]+s[i]-'a'+1;
		if(n%2==0)
		{
			printf("Alice %d\n",sm[n]);
		}
		else
		{
			int mn=min(sm[1],sm[n]-sm[n-1]);
			int as=sm[n]-mn,bs=mn;
			if(as>bs)
				printf("Alice %d\n",as-bs);
			else
				printf("Bob %d\n",bs-as);
		}
	}
	return 0;
}