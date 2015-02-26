#ifndef __STU_POS_H__
#define __STU_POS_H__
#include<string.h>
#define NAME_LEN 32
#define ROW 8
#define COL 8
typedef struct tag_stu
{
	char m_name[NAME_LEN] ;
	int m_row ;
	int m_col ;
	struct tag_stu* m_rnext ;
	struct tag_stu* m_cnext ;
}STU, *pSTU;
typedef struct  tag_pos
{	
	pSTU m_row[ROW] ;
	pSTU m_col[ROW] ;
	struct tag_pos* m_this ;
	void (*m_traverse)(struct tag_pos* this);
	pSTU (*m_search_by_row)(struct tag_pos* this, int row);
	pSTU (*m_search_by_col)(struct tag_pos* this, int col);
	pSTU (*m_search_by_pos)(struct tag_pos* this, int row, int col);
	pSTU (*m_search_by_name)(struct tag_pos* this, char* name);
	
}POS, *pPOS ;
void init(pPOS pos,\
		void(*p_traverse)(struct tag_pos* p),\
		pSTU (*p_search_by_row)(struct tag_pos* this, int row),\
		pSTU (*p_search_by_col)(struct tag_pos* this, int col),\
		pSTU (*p_search_by_pos)(struct tag_pos* this, int row, int col),\
		pSTU (*p_search_by_name)(struct tag_pos* this, char* name)\
		);
#endif
