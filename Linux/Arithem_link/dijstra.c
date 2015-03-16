/*************************************************************************
	> File Name: dijstra.c
	> Author: Arwen
	> Mail:745529725@qq.com 
	> Created Time: Sun 15 Mar 2015 06:05:44 PM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
const int MAXINT = 32767;
const int MAXNUM = 10;
int dist[MAXNUM];
int prev[MAXNUM];

int A[MAXNUM][MAXNUM];

void dijkstra(int v0)      //函数
{
	bool s[MAXNUM];     //判断是否以存入该点到s集和中
	int n = MAXNUM;
	for(int i = 1; i <= n; ++i)
	{
		dist[i] = A[v0][i];
		s[i] = false;       //初始都未用过的点
		if(dist[i] == MAXINT)
			prev[i] = -1;
		else
			prev[i] = v0;	
	}
	dist[v0] = 0;
	s[v0] = true;
	for(int i = 2; i <= n; ++i)
	{
		int mindist = MAXINT;
		int u = v0;             //找出当前未使用的点j的dist【j】最小值
		for(int j = 1;j <= n; ++j)
		{
			if((!s[j]) && dist[j] < mindist)
			{
				u = j;        //u保存当前邻接点中距离最小的点的号码
				mindist = dist[j];
			}
		}
		s[u] = true;
		for(int j = 1; j <= n; ++j)
		{
			if((!s[j]) && A[u][j] < dist[j])//判断
			{
				if(dist[u] + A[u][j] < dist[j]) //在通过新加入的u点的路经找到离v0点更短的路径
				{
					dist[j] = dist[u] + A[u][j];//更新dist
					prev[j] = u;//记录前驱顶点
		}
	}
}

// test 01
int main()
{
	dijkstra(0);
	return 0;
}
