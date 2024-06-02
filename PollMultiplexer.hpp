//====< PollMultiplexer >==============================================
#ifndef __POLLMULTIPLEXER_HPP__
# define __POLLMULTIPLEXER_HPP__

# include <sys/poll.h>
# include <iostream>
# include <queue>

typedef std::queue<int>	FdQueue;
typedef long long	Time;

class	PollMultiplexer
{
	private:
		pollfd	mFdSet[OPEN_MAX];
		int	mMaxFd;
	public:
		PollMultiplexer(void);
		~PollMultiplexer(void);

		bool	fdSet(int fd, int mode);
		bool	fdUnset(int fd);
		FdQueue	getReadyFd(void);
		int	waitEvent(Time mTimeout_ms);
};

#endif /*__POLLMULTIPLEXER_HPP__*///==================================

