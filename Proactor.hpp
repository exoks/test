//====< Proactor >=============================================================
#ifndef __PROACTOR_HPP__
# define __PROACTOR_HPP__

# include "AsyncOpProcessor.hpp"

class	Proactor
{
	private:
		AsyncOpProcessor	aop;
	
	public:
		Proactor(PollMultiplexer *mux);
		~Proactor(void);

		bool	init(const FdQueue fdq);

		bool	handleComplitedEvents(void);

};

#endif /*__PORACTOR_HPP__*///==================================================
