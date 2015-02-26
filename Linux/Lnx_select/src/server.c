/*************************************************************************
  > File Name: ../src/server.c
  > Author: Arwen
  > Mail:745529725@qq.com 
  > Created Time: Mon 02 Feb 2015 10:00:37 AM CST
 ************************************************************************/

#include"sv_hd.h"
int main(int argc,char *argv[ ])
{
	int fd_listen;
	char path_name[ 128] = "";
	char fifo_name[ 128];
	char msg[ 1024];

	char client_stat[ 5] = "";
	int client_pid ;
	sprintf(path_name, "%s/%s",PIPE_PATH,PIPE_NAME);

	mkfifo(path_name,0666);

	printf("mkfifo over!\n");

	fd_listen = open(path_name,O_RDONLY);
	if(fd_listen ==-1)
	{
		printf("open server_fifo fail!\n");
		exit (1);
	}
	pCLIENT plist = NULL,pcur,pnew,ppre;

	fd_set rd_sets,bak_sets;
	FD_ZERO(&rd_sets);
	FD_ZERO(&bak_sets);

	FD_SET(fd_listen,&rd_sets);
	while(1)
	{
		bak_sets = rd_sets;
		printf("selecting...\n");
		select(1024,&bak_sets,NULL,NULL,NULL);
		if(FD_ISSET(fd_listen,&bak_sets))
		{
			memset(msg,0,1024);
			if(read(fd_listen,msg,1024) == 0)
			{
				printf("no clients!\n");
				continue;
			}
			//

			memset(client_stat,0,sizeof(client_stat));
			sscanf(msg,"%d%s",&client_pid,client_stat);

			if(strncmp("on",client_stat,2) == 0)//client on"pid on\n"
			{// pid_r.fifo(c_r -s_w)     pid_w.fifo(c_w - s_r)
              printf("client:%d on\n",client_pid);
              memset(fifo_name,0,128);
			  sprintf(fifo_name,"%d_r.fifo",client_pid);

			  memset(path_name,0,128);
			  sprintf(path_name,"%s/%s",PIPE_PATH,fifo_name);
               



			}else//client off "pid off\n"
			{
				printf("client: %d off\n",client_pid);
				ppre = NULL;
				pcur =plist;
				while(pcur && pcur->m_id !=client_pid);
				{
					ppre = pcur;
					pcur = pcur ->m_next;
				}
				if(pcur == NULL)
				{

				}else
				{

				}

			}

		}

		pcur = plist;
		while(pcur)
		{
			if(FD_ISSET(pcur ->m_recv,&bak_sets))//translate
			{
				memset(msg,0,1024);
				read(pcur ->m_recv,msg,1024);

				dispatch_msg(plist,msg);
			}
			pcur = pcur ->m_next;
		}

	}
	return 0;
}
