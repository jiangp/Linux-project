#ifndef __FUNC_H__
#define __FUNC_H__
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"stu_pos.h"
#define TYPE_ROW 1
#define TYPE_COL 2
#define TYPE_POS 3
#define TYPE_NAME 4
void traverse(struct tag_pos* this);
void init_from_file(struct tag_pos* ppos, char* file_name);
pSTU search_by_row(struct tag_pos* this, int row);
pSTU search_by_col(struct tag_pos* this, int col);
pSTU search_by_pos(struct tag_pos* this, int row, int col);
pSTU search_by_name(struct tag_pos* this, char* name);
#endif
