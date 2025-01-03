//
#include<functional>
#include<iostream>
#include<boost/asio.hpp>

void print (const boost::system::error_code&,
	boost::asio::steady_timer* tmr, int* count)
{
	if (*count < 5)
	{
		std::cout << *count << '\n';
		++ (*coetnt) ;

		tmr->expires_at(tmr->expiry() + boost::asio::chrono::seconds(1));
		tmr->async_wait(std::bind(print,
					boost::asio::placeholders::error, tmr, count));

	}
}

int main()
{
	std::cout << "Program Start!\n";

	boost::asio::io_context io;

	int count = 0;

	boost::asio::steady_timer tmr(io, boost::asio::chrono::seconds(1));

	tmr.async_wait(std::bind(print,
				boost::asio::placeholders::error, &tmr, &count));

	io.run();
}
