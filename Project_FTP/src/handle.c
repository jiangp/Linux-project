/*************************************************************************
	> File Name: handle.c
	> Author: Arwen
	> Mail:745529725@qq.com 
	> Created Time: Mon 02 Mar 2015 04:49:19 PM CST
 ************************************************************************/

#include<stdio.h>
void child_main(int fd_client)
{

	int epoll_fd;
	MY_ASSERT((epoll_fd = epoll_create(1024)) != -1, "epoll create");//epoll_create
	struct epoll_event my_event, my_events[1024];
	char buf[1024] = "0";
	int ready_events, index=0;

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
				//	printf("ls\n");
					scan_dir(argv[1], 1);


				}
				else if(strncmp(buf,"gets",4) == 0)
				{
					printf("gets\n");

				}
				else if(strncmp(buf, "puts",4) == 0)
				{
					printf("puts\n");


				}
				else if(strncmp(buf,"cd",2) ==0 )
				{
					printf("cd\n");


				}
				else if(strncmp(buf,"pwd",3) == 0)
				{
					printf("pwd\n");


				}else if(strncmp(buf,"remove",6) == 0)
				{
					do_remove();
				}
				else{
					printf("error command!\n");

				}

			}
		}

	}
}

