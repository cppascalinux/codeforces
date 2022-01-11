#include<bits/stdc++.h>
using namespace std;
int n,m;
int vis[1009],sm[1009];
vector<int> vp[1009];
int ask(int r,int c,int x1,int y1,int x2,int y2)
{
	printf("? %d %d %d %d %d %d\n",r,c,x1,y1,x2,y2);
	fflush(stdout);
	scanf("%d",&r);
	return r;
}
void out(int ans)
{
	printf("! %d\n",ans);
	fflush(stdout);
	exit(0);
}
void init()
{
	int l=1000;
	for(int i=2;i<=l;i++)
		if(!vis[i])
		{
			vp[i].push_back(i);
			for(int j=2*i;j<=l;j+=i)
				vis[j]=1,vp[j].push_back(i);
		}
	for(int i=1;i<=l;i++)
		for(int j=i;j<=l;j+=i)
			sm[j]++;
}
int test(int nr,int nc,int qr,int qc)
{
	if(qr)
	{
		if(nr<n)
			return ask(nr-qr,nc,1,1,nr+qr+1,1);
		if(nc<m)
			return ask(nr-qr,nc,1,1,qr+1,nc+1);
		if(nr==qr*2)
			return ask(nr-qr,nc,1,1,qr+1,1);
		int hf=(nr/qr)/2;
		return ask(hf*qr,nc,1,1,hf*qr+1,1)&&ask(hf*qr,nc,1,1,(hf+1)*qr+1,1);
	}
	else
	{
		if(nc<m)
			return ask(nr,nc-qc,1,1,1,nc+qc+1);
		if(nr<n)
			return ask(nr,nc-qc,1,1,nr+1,qc+1);
		if(nc==qc*2)
			return ask(nr,nc-qc,1,1,1,qc+1);
		int hf=(nc/qc)/2;
		return ask(nr,hf*qc,1,1,1,hf*qc+1)&&ask(nr,hf*qc,1,1,1,(hf+1)*qc+1);
	}
}
int main()
{
	scanf("%d%d",&n,&m);
	init();
	int qr=n,qc=m;
	while(qr>1)
	{
		int fg=0;
		for(int v:vp[qr])
		{
			if(test(qr,qc,qr/v,0))
			{
				qr/=v;
				fg=1;
				break;
			}
		}
		if(!fg)
			break;
	}
	while(qc>1)
	{
		int fg=0;
		for(int v:vp[qc])
		{
			if(test(qr,qc,0,qc/v))
			{
				qc/=v;
				fg=1;
				break;
			}
		}
		if(!fg)
			break;
	}
	out(sm[n/qr]*sm[m/qc]);
	return 0;
}