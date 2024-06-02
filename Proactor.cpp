# include "Proactor.hpp"

//====< proactor >==============================================================
Proactor::Proactor(PollMultiplexer *mux) : aop(mux)
{
}

//====< destructor >============================================================
Proactor::~Proactor(void)
{
}

//====< init >==================================================================
bool	Proactor::init(const FdQueue aFdQueue)
{
	return (aop.asyncOpInit(aFdQueue));
}

//====< handleComplitedEvent >==================================================
bool	Proactor::handleComplitedEvents(void)
{
	return (true);
}
