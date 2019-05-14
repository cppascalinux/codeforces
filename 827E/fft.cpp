//2019.05.13
//CF827E Rusty String FFT+循环节+枚举倍数+调和级数
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#define db double
#define pi 3.1415926535897932384626433832795
#define eps 1e-6
using namespace std;
struct cp
{
	db x,y;
	cp(){}
	cp(db a,db b){x=a,y=b;}
	cp operator +(cp p){return cp(x+p.x,y+p.y);}
	cp operator -(cp p){return cp(x-p.x,y-p.y);}
	cp operator *(cp p){return cp(x*p.x-y*p.y,x*p.y+y*p.x);}
	cp operator /(db v){return cp(x/v,y/v);}
};
int n,len,bit;
char s[500009];
cp rt[2][1050009];
int mp[1050009];
cp s1[1050009],s2[1050009];
int f[1050009];
void clr()
{
	memset(f,0,(n+1)<<2);
	for(int i=0;i<len;i++)
		s1[i]=s2[i]=cp(0,0);
}
int sgn(db x)
{
	return x>eps?1:(x<-eps?-1:0);
}
void init(int l)
{
	bit=0;
	while((1<<bit)<l)
		bit++;
	len=1<<bit;
	rt[0][0]=rt[1][0]=cp(1,0);
	for(int i=1;i<len;i++)
		rt[0][i]=cp(cos(2*pi/len*i),sin(2*pi/len*i));
	for(int i=1;i<len;i++)
		rt[1][i]=rt[0][len-i];
	for(int i=1;i<len;i++)
		mp[i]=(mp[i>>1]>>1)|((i&1)<<(bit-1));
}
void fft(cp *s,int c)
{
	for(int i=0;i<len;i++)
		if(i<mp[i])
			swap(s[i],s[mp[i]]);
	for(int l=2;l<=len;l<<=1)
	{
		int d=l>>1,sp=len/l;
		for(int j=0;j<len;j+=l)
			for(int i=0;i<d;i++)
			{
				cp t=s[i+j+d]*rt[c][sp*i];
				s[i+j+d]=s[i+j]-t;
				s[i+j]=s[i+j]+t;
			}
	}
	if(c)
		for(int i=0;i<len;i++)
			s[i]=s[i]/len;
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("fft.in","r",stdin);
	freopen("fft.out","w",stdout);
#endif
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%s",&n,s);
		// printf("n:%d\n",n);
		init(2*n-1);
		for(int i=0;i<n;i++)
			if(s[i]=='V')
				s1[i].x=1;
			else if(s[i]=='K')
				s2[n-1-i].x=1;
		fft(s1,0);
		fft(s2,0);
		for(int i=0;i<len;i++)
			s1[i]=s1[i]*s2[i];
		fft(s1,1);
		// for(int i=0;i<len;i++)
		// 	printf("i:%d x:%lf y:%lf\n",i,s1[i].x,s1[i].y);
		for(int i=1;i<=n-1;i++)
		{
			f[i]|=(sgn(s1[n-1-i].x)==1);
			f[i]|=(sgn(s1[n-1+i].x)==1);
		}
		for(int i=n-1;i>=1;i--)
			for(int j=i;j<=n-1;j+=i)
				f[i]|=f[j];
		int ans=0;
		for(int i=1;i<=n-1;i++)
			if(!f[i])
				ans++;
		printf("%d\n",ans+1);
		for(int i=1;i<=n-1;i++)
			if(!f[i])
				printf("%d ",i);
		printf("%d\n",n);
		clr();
	}
	return 0;
}