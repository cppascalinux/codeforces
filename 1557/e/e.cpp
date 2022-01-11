#include<bits/stdc++.h>
using namespace std;
char s[20];
int vis[10][10],tmp[10][10];
int dx=0,dy=0,tx=0,ty=0,cx=0,cy=0;
void print(int x,int y)
{
	printf("%d %d\n",x,y);
	fflush(stdout);
	scanf("%s",s);
}
int upd()
{
	if(!strcmp(s,"Done"))
		return 1;
	if(!strcmp(s,"Right"))
		dx=0,dy=1;
	else if(!strcmp(s,"Left"))
		dx=0,dy=-1;
	else if(!strcmp(s,"Up"))
		dx=-1,dy=0;
	else if(!strcmp(s,"Down"))
		dx=1,dy=0;
	else if(!strcmp(s,"Down-Right"))
		dx=1,dy=1;
	else if(!strcmp(s,"Down-Left"))
		dx=1,dy=-1;
	else if(!strcmp(s,"Up-Left"))
		dx=-1,dy=-1;
	else
		dx=-1,dy=1;
	memset(tmp,0,sizeof(tmp));
	for(int i=1;i<=8;i++)
		for(int j=1;j<=8;j++)
			if(vis[i-dx][j-dy])
				tmp[i][j]=1;
	memcpy(vis,tmp,sizeof(vis));
	for(int i=1;i<=8;i++)
		for(int j=1;j<=8;j++)
			if(i==cx||j==cy||i+j==cx+cy||i-j==cx-cy)
				vis[i][j]=0;
	tx+=dx,ty+=dy;
	return 0;
}
int main()
{
	int ttt;
	scanf("%d",&ttt);
	while(ttt--)
	{
		memset(vis,0,sizeof(vis));
		for(int i=1;i<=8;i++)
			for(int j=1;j<=8;j++)
				vis[i][j]=1;
		// for(int i=1;i<=8;i++)
		// 	for(int j=1;j<=8;j++)
		// 		if(i==4||j==4||i==j||i+j==8)
		// 			vis[i][j]=0;
		cx=cy=4;
		print(cx,cy);
		upd();
		while(1)
		{
			for(int i=1;i<=8;i++)
				for(int j=1;j<=8;j++)
					if(vis[i][j])
						tx=i,ty=j;
			// printf("tx:%d ty:%d\n",tx,ty);
			if(tx<=4)
			{
				if(cx!=tx+1)
				{
					cx=tx+1;
					print(cx,cy);
					if(upd())
						break;
					if(!vis[tx][ty])
						continue;
				}
				int fg=0,cp=0;
				while(1)
				{
					if(!fg&&cx==tx+1)
					{
						fg=1;
						cy=ty;
					}
					else if(!fg)
						cx=tx+1;
					else
						cx--,cy+=dy;
					print(cx,cy);
					if(upd())
					{
						cp=1;
						break;
					}
					if(!vis[tx][ty])
						break;
				}
				if(cp)
					break;
			}
			else
			{
				if(cx!=tx-1)
				{
					cx=tx-1;
					print(cx,cy);
					if(upd())
						break;
					if(!vis[tx][ty])
						continue;
				}
				int fg=0,cp=0;
				while(1)
				{
					if(!fg&&cx==tx-1)
					{
						fg=1;
						cy=ty;
					}
					else if(!fg)
						cx=tx-1;
					else
						cx++,cy+=dy;
					print(cx,cy);
					if(upd())
					{
						cp=1;
						break;
					}
					if(!vis[tx][ty])
						break;
				}
				if(cp)
					break;
			}
		}
	}
	return 0;
}