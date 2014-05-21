#include <cstdio>
#include <cstring>
#include <queue>

#define INF 10000
#define MAX 40

class pos
{
	public:
	pos()
	{
		x=0;
		y=0;
	}
	pos(int _x,int _y)
	{
		x = _x;
		y = _y;
	}
	int x;
	int y;
};

int bfs(char fd[MAX][MAX+1], int w, int h)
{
	int i,j;
	int vx[4]={-1,1,0,0};
	int vy[4]={0,0,-1,1};
	pos s,e,p,n;
	int map[MAX][MAX];
	queue<pos> que;
	memset(map,0,sizeof(map));
	for(i=0;i<h;i++)
	for(j=0;j<w;j++)
	{
		if(fd[i][j]=='S')
		{
			map[i][j]=1;
			s.x=j;
			s.y=i;
			que.push(s);
		}
		else if(fd[i][j]=='E')
		{
			map[i][j]=INF;
			e.x=j;
			e.y=i;
		}
		else
		{
			map[i][j]=INF;
		}
	}
	while(que.size())
	{
		p = que.front();que.pop();
		if(p.x==e.x && p.y==e.y)break;
		for(i=0;i<4;i++)
		{
			n.x=p.x+vx[i];
			n.y=p.y+vy[i];
			if(n.x>=0&&n.x<w&&n.y>=0&&n.y<h&&fd[n.y][n.x]!='#' && map[n.y][n.x]==INF)
			{
				que.push(pos(n.x,n.y));
				map[n.y][n.x]=map[p.y][p.x]+1;
			}
		}
	}
	return map[e.y][e.x];
}

int main(void)
{
	int n,w,h,i;
	char fd[MAX][MAX+1];
	
	while(scanf("%d",&n)!=EOF)
	{
		while(n--)
		{
			scanf("%d %d",&w,&h);
			for(i=0;i<h;i++)
			{
				scanf("%s",fd[i]);
			}
			printf("%d\n",bfs(fd,w,h));
		}
		
	}
	return 0;
}
