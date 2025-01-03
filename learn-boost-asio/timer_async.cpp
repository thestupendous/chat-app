//needs to be supplied completion token - server band kab karna hai uske liye
#include<iostream>
#include<boost/asio.hpp>

void print (const boost::system::error_code& )
{
	std::cout << "raam raam bhai \n";
}

int main()
{
	std::cout << "Program Start!\n";

	boost::asio::io_context io;

	boost::asio::steady_timer tmr(io, boost::asio::chrono::seconds(5));

	tmr.async_wait(&print);

	io.run();
}
