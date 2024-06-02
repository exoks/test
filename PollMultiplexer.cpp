# include "PollMultiplexer.hpp"

//====< constructor >==========================================================
PollMultiplexer::PollMultiplexer(void) : mMaxFd(0)
{
}

//====< destructor >===========================================================
PollMultiplexer::~PollMultiplexer(void)
{
}

//====< fdSet >================================================================
bool	PollMultiplexer::fdSet(int aFd, int events)
{
	if (aFd < 0 || aFd > OPEN_MAX)
		return (false);
	mFdSet[aFd].fd = aFd;
	mFdSet[aFd].events = events;
	mMaxFd = (aFd > mMaxFd) ? aFd : mMaxFd;
	return (true);
}

//====< fdUnset >==============================================================
bool	PollMultiplexer::fdUnset(int aFd)
{
	if (aFd == -1 || aFd > mMaxFd || aFd > OPEN_MAX)
		return (false);
	mFdSet[aFd].fd = -1;
	return (true);
}

//====< getReadyFd >===========================================================
FdQueue	PollMultiplexer::getReadyFd(void)
{
	FdQueue	aFdQueue;

	for (int fd = 0; fd < mMaxFd + 1; fd++)
	{
		if (mFdSet[fd].fd > -1 && mFdSet[fd].revents > 0)
			aFdQueue.push(fd);
	}
	return (aFdQueue);
}

//====< waitEvent >============================================================
int	PollMultiplexer::waitEvent(Time aTimeout_ms)
{
	return (::poll(mFdSet, mMaxFd + 1, aTimeout_ms));	
}
