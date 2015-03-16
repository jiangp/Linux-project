/*************************************************************************
	> File Name: Floyd.c
	> Author: Arwen
	> Mail:745529725@qq.com 
	> Created Time: Sun 15 Mar 2015 10:29:42 PM CST
 ************************************************************************/
//Floyd 算法  最短路径问题
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define VertexNum  3;
#define maxv 3;
struct M
{
	int vertex[VertexNum]; //顶点表
	int edges[VertexNum][VertexNum];   //邻接矩阵，可看作边表
	int n, e;               //图中的顶点数 和边数
};

void Floyd(M g)
{
	int A[maxv][maxv];
	int path[maxv][maxv];
	int i,j,k,n=g.n;
	for(i = 0; i < n; ++i)
	{
		for(j = 0; j < n; ++j)
		{
			A[i][j] = g.edges[i][j];
			path[i][j] = -1;
		}
	}
	for(k = 0; k < n; ++k)
	{
		for(i = 0; i < n; ++i)
		{
			for(j = 0; j < n; ++j)
			{
				if(A[i][j] > A[i][k] + A[k][j])
				{
					A[i][j] = A[i][k] + A[k][j];
					path[i][j] = k;
				}
			}
		}
	}
}
