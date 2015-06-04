/*************************************************************************
  > File Name:User_init.
  > Author: Arwen
  > Mail:745529725@qq.com 
  > Created Time: Mon 27 Apr 2015 12:44:18 PM CST
 ************************************************************************/

#ifndef USER_INIT_H
#define YSER_INIT_H
#include<stdio.h>
#include<stdlib.h>
#include"FTP_server.h"

/*the account infor*
typedef struct account
{
	char m_name[128];
	char m_passwd[128];
	int m_role;
	struct account *m_next;
}ACCOUNT, *pACCOUNT;

*the user's information*
typedef struct user_infor
{
	char m_name[128];
	char m_passwd[128];
	char m_path[128];
	struct user_infor *m_next;
}USER, *pUSER;*/



#endif
int User_init(pACCOUNT *phead_acc, int fd_client)
{
	int cnt = 0;
	pACCOUNT pcur, ppre;
	char role[8] = "0";
	char user_name[128] = "0";
	char user_passwd[128] = "0";
	recv(fd_client, role, sizeof(role), 0);

	if(strncmp(role, "login", 5) == 0){
		while(cnt < 3)
		{
			recv_buf(fd_client, user_name, sizeof(user_name));
			recv_buf(fd_client, user_passwd, sizeof(user_passwd));
			printf("%s:%s\n", user_name, user_passwd);
			pcur = *phead_acc;
			while(pcur){
				if(strcmp(user_name, pcur->m_name) == 0 && strcmp(user_passwd, pcur->m_passwd) ==0)
					break;
				pcur = pcur->m_next;
			}
			if(pcur){
				send(fd_client, "success", 8, 0);
			
				return (pcur->m_role);
			}else{
				send(fd_client, "fail", 8, 0);
				cnt++;
				printf("fail\n");
			}
		}
	}else if(strncmp(role, "enroll", 6) == 0)
	{
		while(1){
	    	recv(fd_client, user_name, sizeof(user_name), 0);
	        recv(fd_client, user_passwd, sizeof(user_passwd), 0);
			printf("%s:%s\n", user_name, user_passwd);
    		pcur = *phead_acc;
    		while(pcur){
		    	if(strcmp(user_name, pcur->m_name) == 0){
		     		send(fd_client, "fail", 8, 0);
					break;
				}
				pcur = pcur->m_next;
				if(pcur == NULL){
					pACCOUNT pnew = (pACCOUNT)calloc(1, sizeof(ACCOUNT));
					strcpy(pnew->m_name, user_name);
					strcpy(pnew->m_passwd, user_passwd);
					pnew->m_role = 2;
				
					pcur = *phead_acc;
					ppre = NULL;
					while(pcur && strcmp(pcur->m_name, pnew->m_name) < 0){
						ppre = pcur;
						pcur = pcur->m_next;
					}
					if(ppre == NULL){
						pnew->m_next = *phead_acc;
						*phead_acc = pnew;
					}else{
						pnew->m_next = pcur;
						ppre->m_next = pnew;
					}

					send(fd_client, "success", 8, 0);
					return (pnew->m_role);
				}
	    	}
		}
	}
	return -1;
}
