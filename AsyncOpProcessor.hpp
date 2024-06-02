#ifndef __ASYNCOPPROCESSOR_HPP__
# define __ASYNCOPPROCESSOR_HPP__

# include "PollMultiplexer.hpp"
# include <sys/socket.h>

class	IHandler;

typedef std::queue<IHandler *>	HandlerQueue;

class	AsyncOpProcessor
{

	private:
		HandlerQueue		Handlers;
		PollMultiplexer		*mux;

	public:
		AsyncOpProcessor(void);
		AsyncOpProcessor(PollMultiplexer *mux);
		~AsyncOpProcessor(void);

		bool		asyncOpInit(FdQueue fdq);

		HandlerQueue	getComplitedHandler(void);
};

#endif /*__ASYNCOPPROCESSOR_HPP__*/

