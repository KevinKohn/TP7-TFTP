#pragma once
#include <iostream>
#include <boost/asio.hpp>
#include <boost/function.hpp>
#include <boost/bind.hpp>
#include <boost/timer/timer.hpp>
#include <cstdint>


class client
{
public:
	client();
	~client();
	void ConectToServer(const char* ipServer="localhost", const char* portNumber="12345");
	bool sendData(char * dataToSend_t, unsigned int sizeData);
	bool receiveDataFromServidor(char * buffer_t, int bufferSize);
	uint16_t nonBlockinReceiveDataForServer(char * buffer_t, int bufferSize);
	void writeCompletitionCallback(const boost::system::error_code & error, std::size_t transfered_bytes);
private:
	boost::asio::ip::tcp::resolver* clientResolver;
	boost::asio::ip::tcp::socket* clientSocket;
	boost::asio::ip::tcp::resolver::iterator endpoint;
	boost::asio::io_service* ioClient;
};

