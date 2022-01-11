#include<bits/stdc++.h>
using namespace std;
int n;
int p[100009];
int f[2][2][100009];// left/right, decrease/increase
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",p+i);
	for(int i=2;i<=n;i++)
		if(p[i-1]<p[i])
		{
			f[0][0][i]=f[0][0][i-1]+1;
			f[0][1][i]=0;
		}
		else
		{
			f[0][1][i]=f[0][1][i-1]+1;
			f[0][0][i]=0;
		}
	for(int i=n-1;i>=1;i--)
		if(p[i+1]<p[i])
		{
			f[1][0][i]=f[1][0][i+1]+1;
			f[1][1][i]=0;
		}
		else
		{
			f[1][1][i]=f[1][1][i+1]+1;
			f[1][0][i]=0;
		}
	multiset<int> s;
	for(int i=1;i<=n;i++)
	{
		if(f[0][0][i])
			s.insert(f[0][0][i]);
		if(f[1][0][i])
			s.insert(f[1][0][i]);
		// printf("i:%d 00:%d 10:%d 01:%d 11:%d\n",i,f[0][0][i],f[1][0][i],f[0][1][i],f[1][1][i]);
	}
	int ans=0;
	for(int i=1;i<=n;i++)
		if(f[0][0][i]&&f[1][0][i])
		{
			int a=f[0][0][i],b=f[1][0][i];
			s.erase(s.find(a)),s.erase(s.find(b));
			if(!s.empty()&&*s.rbegin()>=max(a,b))
			{
				s.insert(a),s.insert(b);
				continue;
			}
			s.insert(a),s.insert(b);
			if(a<b)
				swap(a,b);
			if(a&1)
				continue;
			if(a>b)
				continue;
			if(a==b)
				ans++;
		}
	printf("%d",ans);
	return 0;
}