#include <iostream>
#include <boost/asio.hpp>

int main()
{
	boost::asio::io_context io;

	std::cout << "program start!\n" ;

	boost::asio::steady_timer tmr(io, boost::asio::chrono::seconds(5));

	tmr.wait();

	std::cout << "raam raam ! " << '\n';

	return 0;
}
