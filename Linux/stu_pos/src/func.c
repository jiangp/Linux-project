/*************************************************************************
	> File Name: ./src/func.c
	> Author: Comst
	> Mail:750145240@qq.com 
	> Created Time: Mon 26 Jan 2015 08:57:34 PM CST
 ************************************************************************/
#include"func.h"
static void replace_comma(char*buf)
{
	int index ;
	for(index = 0; buf[index] != '\0'; index ++)
	{
		if(buf[index] == ',')
		{
			buf[index] = ' ' ;
		}
	}
}
void traverse(struct tag_pos* this)
{
	int row ;
	pSTU pcur ;
	for(row = 0; row < ROW; row ++)
	{
		pcur = this ->m_row[row] ;
		while(pcur)
		{
			printf("%s(%d,%d)%*s", pcur ->m_name, pcur -> m_row, pcur ->m_col, 8-strlen(pcur ->m_name)," ");
			pcur = pcur ->m_cnext ;
		}
		printf("\n");
	}
}
void init_from_file(struct tag_pos* ppos, char* file_name)
{
	char line[1024];
	FILE* fp_conf = fopen(file_name, "r");
	FILE* fp_in ;
	pSTU pnew, pcur, ppre ;
	if(fp_conf == NULL)
	{
		printf("open failed! \n");
		exit(1);
	}
	while(memset(line, 0, 1024), fgets(line, 1024, fp_conf)!=NULL)
	{
		line[strlen(line) - 1] = '\0' ;
		if(line[0] == 0)
		{
			continue ;
		}
		fp_in = fopen(line, "r");
		while(memset(line, 0, 1024), fgets(line, 1024, fp_in) != NULL)
		{
			replace_comma(line);///////////////
			pSTU pnew = (pSTU)calloc(1, sizeof(STU)) ;
			sscanf(line, "%s%d%d", pnew ->m_name, &pnew ->m_row, &pnew ->m_col);
			pcur = ppos ->m_row[ pnew ->m_row ] ;
			ppre = NULL ;
			while(pcur && pnew ->m_col  > pcur ->m_col)
			{
				ppre = pcur ;
				pcur = pcur ->m_cnext ;
			}
			if(ppre == NULL)
			{
				pnew ->m_cnext = ppos ->m_row[pnew ->m_row] ;
				ppos ->m_row[pnew ->m_row] = pnew ;

			}else
			{
				pnew ->m_cnext = pcur ;
				ppre ->m_cnext = pnew ;
			}
			
			pcur = ppos ->m_col[pnew ->m_col] ;
			ppre = NULL ;
			while(pcur && pnew ->m_row > pcur ->m_row)
			{
				ppre = pcur ;
				pcur = pcur ->m_rnext ;
			}
			if(ppre == NULL)
			{
				pnew ->m_rnext = ppos ->m_col[pnew -> m_col] ;
				ppos ->m_col[pnew -> m_col] = pnew ;
			}else
			{
				pnew -> m_rnext = pcur ;
				ppre ->m_rnext = pnew ;
			}

		}
		fclose(fp_in);
	

	}
	fclose(fp_conf);

}
pSTU search_by_row(struct tag_pos* this, int row)/////////////
{
	return this ->m_row[row - 1] ;
}
pSTU search_by_col(struct tag_pos* this, int col)///////////////////
{
	return this ->m_col[col - 1];
}
pSTU search_by_pos(struct tag_pos* this, int row, int col)////////////////
{
	pSTU pres = this ->m_row[row - 1] ;
	int cnt = 1 ;
	while(pres && cnt != col)
	{
		pres = pres ->m_cnext ;
		cnt ++ ;
	}
	return pres ;
}
pSTU search_by_name(struct tag_pos* this, char* name)
{
	int row ;
	pSTU pcur ;
	for(row = 0; row < ROW; row ++)
	{
		pcur = this ->m_row[row] ;
		while(pcur)
		{
			if(strcmp(pcur ->m_name, name) == 0)
			{
				return pcur ;
			}
			pcur = pcur ->m_cnext ;
		}
	}
	return NULL ;
}

