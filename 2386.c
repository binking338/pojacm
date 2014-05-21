#include <stdio.h>
#define MAX 100

void dfs(char field[MAX][MAX+1], int m, int n)
{
	int i,j;
	field[n][m]='N';
	for(i=-1;i<=1;i++)
	for(j=-1;j<=1;j++)
	{
		if(n+i>=0 && m+j>=0 && n+i<MAX && m+j<MAX && field[n+i][m+j]=='W')
		{
			dfs(field,m+j,n+i);
		}
	}
}


int main(void)
{
	int N,M,n,m,c;
	char field[MAX][MAX+1];
	
	while(scanf("%d%d", &N, &M)!=EOF)
	{
		for(n=0;n<N;n++)
			scanf("%s",field[n]);
		c=0;
		for(n=0;n<N;n++)
		for(m=0;m<M;m++)
		{
			if(field[n][m]=='W')
			{
				dfs(field,m,n);
				c++;
			}
		}
		printf("%d\n",c);
	}
	return 0;
}
