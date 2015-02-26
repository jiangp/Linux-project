/*************************************************************************
	> File Name: ./src/my_pos.c
	> Author: Comst
	> Mail:750145240@qq.com 
	> Created Time: Mon 26 Jan 2015 08:54:13 PM CST
 ************************************************************************/
#include"stu_pos.h"

void init(pPOS pos,\
		void(*p_traverse)(struct tag_pos* p),\
		pSTU (*p_search_by_row)(struct tag_pos* this, int row),\
		pSTU (*p_search_by_col)(struct tag_pos* this, int col),\
		pSTU (*p_search_by_pos)(struct tag_pos* this, int row, int col),\
		pSTU (*p_search_by_name)(struct tag_pos* this, char* name)\
		)
{
	memset(pos ->m_row, 0, sizeof(pos ->m_row));
	memset(pos ->m_col, 0, sizeof(pos ->m_col));
	pos ->m_traverse = p_traverse ;
	pos ->m_search_by_row = p_search_by_row ;
	pos ->m_search_by_col = p_search_by_col ;
	pos ->m_search_by_pos = p_search_by_pos ;
	pos ->m_search_by_name = p_search_by_name;
}

