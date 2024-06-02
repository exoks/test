# include "AsyncOpProcessor.hpp"

//====< AsyncOpProcessor >======================================================
AsyncOpProcessor::AsyncOpProcessor(PollMultiplexer *mux)
{
	this->mux = mux;
}

//====< AsyncOpProcessor >======================================================
AsyncOpProcessor::~AsyncOpProcessor(void)
{
	delete mux;
}

//====< asyncOpInit >===========================================================
bool	AsyncOpProcessor::asyncOpInit(FdQueue fdq)
{
	while (!fdq.empty() && !listen(fdq.front(), 20))
	{
		mux->fdSet(fdq.front(), POLLIN);
		fdq.pop();
	}
	return (fdq.empty() == true);
}

//====< getComplitedHandler >===================================================
std::queue<IHandler *>	AsyncOpProcessor::getComplitedHandler(void)
{
	std::queue<IHandler *>	complitedHandler;
	std::queue<int>		aFdQueue;

	//================
	while (true)
	{
		if (mux->waitEvent(1000) > 0)
		{
			// eventManager();
			aFdQueue = mux->getReadyFd();
		}
	}
	return (std::queue<IHandler *>());
}
