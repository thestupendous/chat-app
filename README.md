# Chat App


very simple peer to peer chat app written using boost.asio library in C++


## Learning Boost.Asio

- Import a HTML file and watch it magically convert to Markdown
- b:a:ip:udp:endpoint ENDPOINT ( ADDR, PORT );
- b:a:io_context - create session ya jobhi
- b:a:ip:udp:socket(ctx,endpoint); - socket banane ko
- socketObj.async_receive(char[] buff, func() )
- sockObj.async_send_to( b:a:buffer( string data, size ), endpoint, func() )
