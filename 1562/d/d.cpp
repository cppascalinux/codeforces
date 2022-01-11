#include<bits/stdc++.h>
using namespace std;
int n,m;
char s[300009];
int sm[300009];
int mx[20][300009],mn[20][300009];
int lg[300009];
void init()
{
	for(int i=1;i<=n;i++)
		mx[0][i]=mn[0][i]=sm[i];
	for(int i=1;i<=18;i++)
		for(int j=1;j+(1<<i)-1<=n;j++)
		{
			mx[i][j]=max(mx[i-1][j],mx[i-1][j+(1<<(i-1))]);
			mn[i][j]=min(mn[i-1][j],mn[i-1][j+(1<<(i-1))]);
		}
	for(int i=2;i<=n;i++)
		lg[i]=lg[i>>1]+1;
}
int gt(int x)
{
	return x&1?1:-1;
}
int getmx(int l,int r)
{
	int sgn=gt(l);
	int bt=lg[r-l+1];
	if(sgn==1)
		return max(mx[bt][l],mx[bt][r-(1<<bt)+1])-sm[l-1];
	else
		return -(min(mn[bt][l],mn[bt][r-(1<<bt)+1])-sm[l-1]);
}
int getmn(int l,int r)
{
	int sgn=gt(l);
	int bt=lg[r-l+1];
	if(sgn==1)
		return min(mn[bt][l],mn[bt][r-(1<<bt)+1])-sm[l-1];
	else
		return -(max(mx[bt][l],mx[bt][r-(1<<bt)+1])-sm[l-1]);
}
int main()
{
	int ttt;
	scanf("%d",&ttt);
	while(ttt--)
	{
		scanf("%d%d",&n,&m);
		scanf("%s",s+1);
		for(int i=1;i<=n;i++)
			s[i]=s[i]=='+'?1:-1;
		for(int i=1;i<=n;i++)
			sm[i]=sm[i-1]+s[i]*gt(i);
		init();
		for(int i=1;i<=m;i++)
		{
			int l,r;
			scanf("%d%d",&l,&r);
			if((r-l+1)&1)
			{
				printf("1\n");
				int sgn=gt(l);
				int tv=(sm[r]-sm[l-1])*sgn;
				int hf=tv/2;
				// printf("tv:%d hf:%d\n",tv,hf);
				if(tv>0)
				{
					int bl=l-1,br=r;
					while(bl<br)
					{
						int mid=(bl+br+1)/2;
						if(getmx(l,mid)<=hf)
							bl=mid;
						else
							br=mid-1;
					}
					printf("%d\n",bl+1);
				}
				else
				{
					int bl=l-1,br=r;
					while(bl<br)
					{
						int mid=(bl+br+1)/2;
						if(getmn(l,mid)>=hf)
							bl=mid;
						else
							br=mid-1;
					}
					printf("%d\n",bl+1);
				}
			}
			else if(sm[r]-sm[l-1]==0)
				printf("0\n");
			else
			{
				printf("2\n");
				r--;
				int sgn=gt(l);
				int tv=(sm[r]-sm[l-1])*sgn;
				int hf=tv/2;
				if(tv>0)
				{
					int bl=l-1,br=r;
					while(bl<br)
					{
						int mid=(bl+br+1)/2;
						if(getmx(l,mid)<=hf)
							bl=mid;
						else
							br=mid-1;
					}
					printf("%d %d\n",bl+1,r+1);
				}
				else
				{
					int bl=l-1,br=r;
					while(bl<br)
					{
						int mid=(bl+br+1)/2;
						if(getmn(l,mid)>=hf)
							bl=mid;
						else
							br=mid-1;
					}
					printf("%d %d\n",bl+1,r+1);
				}
			}
		}
	}
	return 0;
}