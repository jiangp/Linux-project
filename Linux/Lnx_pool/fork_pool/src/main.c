/*************************************************************************
	> File Name: ./src/main.c
	> Author: Arwen
	> Mail:745529725@qq.com 
	> Created Time: Thu 19 Mar 2015 09:45:48 PM CST
 ************************************************************************/

#include"head.h"
int main(int argc, char *argv[])
{
	if(argc != 4)
	{
		printf("EXE IP PORT NCHILD ! \n");
		exit(1);
	}
	int nchild = atoi(argv[3]);
	int index;
	pchild_t parr = (pchild_t)calloc(nchild, sizeof(child_t));//申请内存
	make_child(parr, nchild);
	//socket
	int fd_listen;
	if((fd_listen = socket(AF_INET, SOCK_STREAM, 0)) == -1)
	{
		perror(" socket ");
		exit(1);
	}
	//bin
	struct sockaddr_in server_addr;
	memset(server_addr, 0, sizeof(server_addr));
	server_addr.sin_family = AF_INET ;
	server_addr.sin_port = htons( atoi(argv[2]));
	server_addr.sin_addr.s_addr = inet_addr(argv[1]);
	if(-1 == bind(fd_listen,(const struct sockaddr*)&server_addr,sizeof(server_addr)))
	{
		perror(" bind ");
		exit(1);
	}
	//listen
	if(-1 == listen(fd_listen, 10))
	{
		perror("listen");
		close(fd_listen);
		exit(1);
	}
	//selset
	fd_set rds, tmps ;
	FD_ZERO(&rds);
	FD_ZERO(&tmps);
	FD_SET(fd_listen, &rds);
	for(index = 0; index < nchild; ++index)
	{
		FD_SET(parr[index].ch_fd, &rds);
	}
	//accept
	while()
	{
		tmps = rds;
		select(1024, &tmps, NULL ,NULL, NULL);
		if(FD_ISSET(fd_listen, &tmps))
		{
			int fd_client =accept(fd_listen, NULL, NULL);
			for(index = 0; index < nchild ; ++index)
			{
				if(parr[index].ch_busy == 0)//判断是否有空闲parr
				{
					break;
				}
			}
			if(index == nchild)//没有空闲parr
			{
				continue;
			}
			send_fd(parr[index].ch_fd, fd_client);//发送
		}
		for(index = 0; index < nchild; ++index)
		{
			if(FD_ISSET(parr[index].ch_fd, &tmps))//释放空间
			{
				parr[index].ch_bush = 0;
			}
		}
	}
	//close
	close(fd_listen);
	return 0;
}
