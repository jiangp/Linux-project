/*************************************************************************
	> File Name: SocketIO.cpp
	> Author: Arwen
	> Mail:745529725@qq.com 
	> Created Time: Sat 28 Mar 2015 07:33:52 PM CST
 ************************************************************************/

#include"SocketIO.h"

ssize_t SocketIO::readn(char *buf, size_t count)
{
	size_t nleft = count;
	int  nread;
	char *bufp = (char*)buf;

	while(nleft > 0)
	{
		nread = ::read(m_sockfd, bufp, nleft);
		if(-1 == nread)
		{
			if(nread == errno)
				continue;

			fprintf(stderr, "read error\n");
			exit(EXIT_FAILURE);
		}else if(nread == 0)
		{
			break;
		}
		nleft -= nread;
		bufp += nread;
	}
	return (count - nleft);
}
ssize_t SocketIO::writen(const char *buf, size_t count)
{
	size_t nright = count;
	int nwrite;
	const char *bufp = buf;

	while(nright > 0)
	{
		nwrite = ::write(m_sockfd, bufp, nright);
		if(-1 == nwrite)
		{
			if(nwrite == errno)
				continue;
			return -1;
		}else if(0 == nwrite)
			break;
		nright -= nwrite;
		bufp += nwrite;
	}
	return (count - nright);
}

ssize_t SocketIO::recv_peek(char *buf, size_t len)
{
	int nread;
	do
	{
		nread = ::recv(m_sockfd, buf, len, MSG_PEEK);
	}
	while(nread == -1 && errno == EINTR);

	return nread;
}

ssize_t SocketIO::readline(char *usrbuf, size_t count)
{
	size_t nleft = count - 1;
	char *bufp = usrbuf;
	size_t total = 0;
	ssize_t nread;
	while(nleft > 0)
	{
		nread = recv_peek(bufp, nleft);
		if(nread <= 0)
			return nread;

		int i;
		for(i = 0; i < nread; ++i)
		{
			if(bufp[i] == '\n')
			{
				size_t nsize = i + 1;
				if(readn(bufp, nsize) != static_cast<ssize_t>(nsize))
					return -1;
				bufp += nsize;
				total += nsize;
				*bufp = 0;
				return total;
			}
		}
		if(readn(bufp, nread) != nread)
			return -1;
		bufp += nread;
		total += nread;
		nleft -= nread;
	}
	*bufp = 0;
	return (count -1);

}
