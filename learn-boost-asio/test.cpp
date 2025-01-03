#ifdef _WIN32
#define _WIN32_WINNT 0x0A00
#endif
#include<iostream>
#include<boost/asio.hpp>
#include<string>
#include<string_view>

const boost::asio::ip::udp::endpoint SERVER_ENDPOINT
(
    boost::asio::ip::make_address("127.0.0.1"), 5005
);
//g++ -o test test.cpp -I/path/to/boost/include -L/path/to/boost/lib -lboost_system -lws2_32
void Server()
{
    using namespace boost::asio;

    io_context ctx;

    ip::udp::socket serverSocket(ctx,SERVER_ENDPOINT);


    char data[1024];
    serverSocket.async_receive(
        buffer(data,1024),
        [&](const std::error_code ec, size_t bytesReceived)
        {
            if (!ec && bytesReceived > 0)
            {
                std::cout << "Received: " << std::string_view(data,bytesReceived) << std::endl;
            }
            else
            {
                std::cout << "Error! : " << ec.message() << std::endl;
            }
        }
    );

    ctx.run();
}

void Client()
{
    using namespace boost::asio;
    
    io_context ctx;

    ip::udp::socket clientSocket(ctx,ip::udp::endpoint(ip::udp::v4(),0));

    std::string message = "raam Raam server";
    clientSocket.async_send_to(
        buffer(message.data(),message.size()), SERVER_ENDPOINT,
        [](std::error_code ec, size_t sendBytes)
        {
            if (!ec && sendBytes > 0)
            {
                std::cout << "Message sent to server" << std::endl;
            }
            else
            {
                std::cout << "Error! : " << ec.message() << std::endl;
            }
        }
    );

    ctx.run();
}

int main(int argc, char **argv)
{

    if (argc ==2 )
    {
        std::string appName = argv[1];
        if (appName == "server")
        {
            Server();
        }
        else if (appName == "client")
        {
            Client();
        }
        else
        {
            std::cerr << "usage: [server/client]" << std::endl;
        }
    }

}
