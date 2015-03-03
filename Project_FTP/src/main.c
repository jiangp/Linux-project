/*************************************************************************
  > File Name: main.c
  > Author: Arwen
  > Mail:745529725@qq.com 
  > Created Time: Mon 2 mar 2015 09:41:29 AM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<arpa/inet.h>
#include<netinet/in.h>
#include<sys/epoll.h>
#include<sys/stat.h>
#include<dirent.h>
#include<fcntl.h>
#define SER_IP "192.168.1.124"

#define SER_PORT 1234
#define ADDR "/home/arwen/project/Project_FTP/file/addr.txt"
#define MY_ASSERT(flag, msg) do{flag || (printf("%s\n",msg), exit(1), 0);}while(0)
void child_main(int fd_client);
void do_ls(char* dir, int num,int fd_client);
void do_pwd(char *dir,int len,int fd_client);
void do_gets(char *dir ,int fd_client);
void do_puts(char* dir, int fd_client);
int do_remove(char *dir ,int fd_client);
int send_buf(int sfd, char* buf, int len);
int recv_buf(int sfd, char* buf, int len);

//main
int main(int argc ,  char *argv[])
{
	int fd_listen ,epoll_fd;
	int fd_client;
	MY_ASSERT((fd_listen = socket(AF_INET,SOCK_STREAM ,0))!=-1 ,"listen socket init");//socket

	struct sockaddr_in seraddr,clientaddr;
	socklen_t sock_len = sizeof(clientaddr);
	memset(&seraddr, 0, sizeof(seraddr));
	seraddr.sin_family = AF_INET;
	seraddr.sin_port = htons(SER_PORT);
	seraddr.sin_addr.s_addr = inet_addr(SER_IP);
	MY_ASSERT(bind(fd_listen, (struct sockaddr*)&seraddr, sizeof(seraddr))==0, "bind");//bind

	MY_ASSERT(listen(fd_listen, 5) == 0, "listen");//listen


	while(1)
	{
		sock_len =sizeof(clientaddr);
		memset(&clientaddr, 0 ,sock_len);
		fd_client = accept(fd_listen , (struct sockaddr*)&clientaddr ,&sock_len );
		printf("client %s:%d connect!\n",inet_ntoa(clientaddr.sin_addr),ntohs(clientaddr.sin_port));
        if(fork() == 0)
		{
			close(fd_listen);
			child_main(fd_client);
			close(fd_client);
			exit(1);

		}
		close(fd_client);
 
	}
}


//fork  handle
void child_main(int fd_client)
{
	FILE* fp_config;
	char line[128] = "0"; 
    
	fp_config = fopen(ADDR,"r");
	if(fp_config == NULL)
	{
		printf("open addrfile fail!\n");
		exit(1);
	}
	memset(&line ,0, 128);
	fgets(line, 128, fp_config);
    line[strlen(line)-1] = '\0';
	int epoll_fd;
	MY_ASSERT((epoll_fd = epoll_create(1024)) != -1, "epoll create");//epoll_create
	struct epoll_event my_event, my_events[1024];
	char buf[1024] = "0";
	int ready_events, index=0,len;

	my_event.events = EPOLLIN;
	my_event.data.fd = fd_client;
	MY_ASSERT(epoll_ctl(epoll_fd, EPOLL_CTL_ADD, fd_client, &my_event) == 0, "epoll  client"); // epoll_ctl events
	while(1)
	{
		memset(&my_events, 0 ,sizeof(my_events));
		ready_events = epoll_wait(epoll_fd, my_events, 1024, -1);//epoll_wait
		if(my_events[index].events & EPOLLIN)//  events
		{

			memset(buf, 0 ,1024);
			if(recv(my_events[index].data.fd, buf, sizeof(buf), 0) == 0) //if events  or  over
			{
				printf("one client exit.\n");

				MY_ASSERT(epoll_ctl(epoll_fd, EPOLL_CTL_DEL, my_events[index].data.fd, NULL) == 0, "epoll over!");//over one people
				break ;
			}else
			{	
				if(strncmp(buf,"ls",2) == 0)
				{
					printf("ls\n");
					do_ls(line, 5,fd_client);
				

				}
				else if(strncmp(buf,"gets",4) == 0)
				{
				
					do_gets(line, fd_client);

				}
				else if(strncmp(buf, "puts",4) == 0)
				{
				
					do_puts(line, fd_client);


				}
				else if(strncmp(buf,"cd",2) ==0 )
				{
					printf("cd\n");

		     		do_cd(&line, fd_client,buf,strlen(buf));

				}
				else if(strncmp(buf,"pwd",3) == 0)
				{
					len = sizeof(ADDR);
					do_pwd(line,len,fd_client);
				}else if(strncmp(buf,"remove",6) == 0)
				{
				
					do_remove(line, fd_client);
				}
				else
				{
					printf("error command!\n");

				}

			}
		}

	}
}

//do_ls
void do_ls(char* dir, int num,int fd_client)
{
	DIR *pdir = opendir(dir);
	char name[128] = "0";
	char buf[128] = "0" ;
	if(pdir == NULL)
	{
	perror("opendir\n");
	exit(1);
	}
int k;
	struct dirent* pent;
	struct stat mystat;
	while((pent = readdir(pdir)) != NULL)
	{
    	if(strcmp(".",pent->d_name) == 0||strcmp("..",pent->d_name) == 0)
    	{
			continue;
		}
		memset(name, 0, 128);
		sprintf(name, "%s/%s", dir, pent->d_name);
	    memset(&mystat, 0, sizeof(mystat));

    	if(lstat(name, &mystat) == -1)
		{
	    	perror("error");
			break;
		}
		else
		{
		
			memset(&buf, 0 ,sizeof(buf));
			sprintf(buf, "%s %c %lu",pent->d_name,pent->d_type,mystat.st_size);
	    	send(fd_client, buf, strlen(buf),0);
			sleep(1);
     	

		}
	}
	memset(&buf,0 ,strlen(buf));
	strcpy(buf,"OK");
	send(fd_client,buf,strlen(buf),0);
	closedir(pdir);
									
}
//do_pwd
void do_pwd(char *dir,int len ,int fd_client)
{
   send(fd_client,dir,len,0);
}

//do_cd
int do_cd(char *dir, int fd_client, char* buf,int len)
{
	char str[128]= "0";
	printf("%s\n",dir);
	printf("%s\n",buf);
//	strcpy(str,getcwd);
    getcwd(str,128);
	printf("%s\n",str);
	buf[strlen(buf) - 1 ] ='\0';
	if(strcmp(buf,"cd ..") == 0)
	{
		system("cd ..");
		memset(&str, 0 ,128);
		getwd(str);
		printf("%s\n",str);


	}else if(strcmp(buf,"cd ..")>0)
	{
	}else{
		printf("command error!\n");
	}

	return 0;
}

//remove
int do_remove(char *dir ,int fd_client)
{
	int recv_len ;
	char name[128] = "0";
	char file_name[128] = "0";
	recv_buf(fd_client, (char*)&recv_len, 4);
	recv_buf(fd_client, file_name, recv_len);

	sprintf(name,"%s/%s",dir,file_name);
	name[strlen(name)-1] = '\0';

	remove(name);
	recv_buf(fd_client,(char*)&recv_len, 4);
	if(recv_len == 0)
	{
		return 0;
	}

	
}
//do_gets
void do_gets(char *dir ,int fd_client)
{
	int recv_len;
	int send_len;
	char file_name[128]="0";
	char name[128] ="0";
	char msg[1024];
	memset(&file_name, 0 , 128);
	recv_buf(fd_client, (char*)&send_len, 4);
	recv_buf(fd_client, file_name, send_len);
//	printf("%s\n",file_name);
	sprintf(name,"%s/%s",dir, file_name);
//	printf("%s\n",name);
	name[strlen(name) - 1] = '\0';
	int fd_file = open(name,O_RDONLY);
	if(fd_file == -1)
	{
		perror("fd_file\n");
		exit(1);
	}
	while(memset(&msg,0,1024), (send_len = read(fd_file, msg, 1024) )!= 0)
	{
		if(send_len ==-1)
		{
			perror("read\n");
			exit(1);
		}
	//	printf("%d\n",send_len);	
		send_buf(fd_client, (char*)&send_len,4);
		send_buf(fd_client,msg,send_len);
	}
	send_len = 0;
	send_buf(fd_client, (char*)&send_len,4);

}
//do_puts
void do_puts(char* dir, int fd_client)
{
	int recv_len ;
	char name[128] = "0" ;
	char msg[1024] = "0" ;
	char file_name[128] = "0";
	memset(&file_name, 0, 128);
	recv_buf(fd_client, (char*)&recv_len,4);
	recv_buf(fd_client, file_name, recv_len);
//	printf("%s\n",file_name);
	sprintf(name ,"%s/%s",dir ,file_name);
	name[strlen(name) - 1] = '\0';
	int fd_file = open(name,O_WRONLY | O_CREAT,0666);
	if(fd_file == -1)
	{
		perror("error open\n");
		exit(1);
	}
	int recv_sum = 0;
	while(1)
	{
		memset(msg, 0 , 1024);
		recv_buf(fd_client, (char*)&recv_len, 4);
		if(recv_len == 0)
		{
			close(fd_file);
			break;
		}
		recv_sum += recv_buf(fd_client, msg, recv_len);
		write(fd_file, msg, recv_len );
		system("clear");
		printf("downloading...%.2fkbs\n",(double)recv_sum /1024);
	}
	printf("recv complient!\n");

}
// send_buf
int send_buf(int sfd, char* buf, int len)
{
	int send_sum = 0;
	int send_ret ;
	while(send_sum<len)
	{
		send_ret = send(sfd, buf + send_sum, len - send_sum, 0);
		send_sum += send_ret ;
	}
	return send_sum;
}
//recv_buf
int recv_buf(int sfd, char* buf, int len)
{
	int recv_sum = 0;
	int recv_ret ;
	while(recv_sum<len)
	{
		recv_ret = recv(sfd, buf + recv_sum, len - recv_sum, 0);
		recv_sum += recv_ret ;
	}
	return recv_sum;
}


