# include "Proactor.hpp"
# include <netinet/ip.h>

int	createServerSocket(int port);

int	main(void)
{
	std::queue<int>	srvs;

	Proactor	proactor(new PollMultiplexer());

	std::cout << "=========== Set =============" << std::endl;
	srvs.push(createServerSocket(8080));

	std::cout << "========= Acceptor ==========" << std::endl;

	proactor.init(srvs);

	return (EXIT_SUCCESS);
}


int	createServerSocket(int port)
{
	sockaddr_in	addr;	
	int		serverSocket;

	serverSocket = socket(AF_INET, SOCK_STREAM, 0);
	if (serverSocket == -1)
		return (-1);
	addr.sin_family = AF_INET;
	addr.sin_port = htons(port);
	addr.sin_addr.s_addr = INADDR_ANY;
	int re = bind(serverSocket, (sockaddr *) &addr, sizeof(addr));
	std::cout << " bind re : " << re << std::endl;
	return (serverSocket);
}
