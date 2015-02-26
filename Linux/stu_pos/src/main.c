/*************************************************************************
	> File Name: ./src/main.c
	> Author: Comst
	> Mail:750145240@qq.com 
	> Created Time: Mon 26 Jan 2015 08:21:00 PM CST
 ************************************************************************/
#include"func.h"
int main(int argc, char* argv[])
{
	POS my_pos ;
	int type;
	int row, col ;
	char buf[NAME_LEN] ;
	pSTU pres;
	
	init(&my_pos, &traverse, &search_by_row, &search_by_col, &search_by_pos, &search_by_name);
	printf("init over ! \n");
	init_from_file(&my_pos,argv[1]);
	printf("init from_file_over! \n");
	printf("ready:\n");
	while( scanf("%d",&type) == 1 && type >= 1 && type <= 4)
	{
		switch(type)
		{
			case TYPE_ROW:
				scanf("%d", &row) ;
				system("clear");
				pres =( *(my_pos.m_search_by_row) )(&my_pos, row);
				printf("res: \n");
				while(pres)
				{
		     		printf("%s(%d,%d) ", pres ->m_name, pres->m_row, pres ->m_col);
					pres = pres ->m_cnext ;
				}
				printf("\n");

				break ;
			case TYPE_COL:
				scanf("%d", &col) ;
				system("clear");
				pres =( *(my_pos.m_search_by_col) )(&my_pos, col);
				printf("res: \n");
				while(pres)
				{
					printf("%s(%d,%d) ", pres ->m_name, pres->m_row, pres ->m_col);
					pres = pres ->m_rnext ;
				}
				printf("\n");

				break ;
			case TYPE_POS:
				scanf("%d%d", &row, &col);
				pres =( *(my_pos.m_search_by_pos) )(&my_pos, row, col);
				system("clear");
				printf("res: \n, %s(%d, %d)\n", pres ->m_name, pres ->m_row, pres ->m_col);
				
				break ;
			case TYPE_NAME:
				scanf("%s",buf );
				pres =( *(my_pos.m_search_by_name) )(&my_pos,buf);
				system("clear");
				printf("res: \n, %s(%d, %d)\n", pres ->m_name, pres ->m_row, pres ->m_col);
				
				break;
		}
	}
	return 0 ;
}

