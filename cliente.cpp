
#include "client.h"

client::client()
{
	ioClient = new boost::asio::io_service();
	clientSocket = new boost::asio::ip::tcp::socket(*ioClient);
	clientResolver = new boost::asio::ip::tcp::resolver(*ioClient);
}

client::~client()
{
	clientSocket->close();
	delete ioClient;
	delete clientSocket;
	delete clientResolver;
}

//ConectToServer()
//metodo bloqueante que espera a conectarse con un servidor
//recive como paramteros 2 string. el primero, ipserver, es la ip del servidor
//y el segundo string, portnumber, es el numero del puerto en el cual el servidor
//esta escuchando
void client::ConectToServer(const char * ipServer, const char * portNumber)
{
	try 
	{
		endpoint = clientResolver->resolve(boost::asio::ip::tcp::resolver::query(ipServer, portNumber));
		boost::asio::connect(*clientSocket, endpoint);
		clientSocket->non_blocking(true);

	}
	catch (std::exception a)
	{
		std::cout << "Error al conectarse con el servidor, recuerde que este deve estar escuchando el puerto" << std::endl;
		exit(4);
	
	}
	
}
 
//sendData()
//recive un arreglo de char, que son lo elementos que mandara. tambien recive
//un int con la cantidad de elementos que se necesitan enviar
//

bool client::sendData(char * dataToSend_t, unsigned int sizeData)
{
	char DataToSend[900];
	
	for (size_t i = 0; i < sizeData; i++)
	{
		DataToSend[i] = dataToSend_t[i];
	}
	std::cout << DataToSend[0];

	boost::function<void(const boost::system::error_code&, std::size_t)> handler(
		boost::bind(&client::writeCompletitionCallback, this,
			boost::asio::placeholders::error,
			boost::asio::placeholders::bytes_transferred));
	
	boost::asio::async_write(*clientSocket, boost::asio::buffer(DataToSend), handler);

	return true;

}

void client::writeCompletitionCallback(const boost::system::error_code& error, std::size_t transfered_bytes) {
	std::cout << std::endl << "Write Callback called" << std::endl;
}

//receiveDataForClient
//previamente se deve llamar a waitforcleinte()
//recive como paramteros un arreglo de char(buffer) y una int,
//con la cantidad de elementos de dicho arreglo.
//si se puedo recivir toda la informacion devuelve un true, caso contrario
//devuelve un false.
bool client::receiveDataFromServidor(char * buffer_t, int bufferSize)
{
	uint16_t longitudDelMensaje = 0;
	boost::system::error_code error;
	char bufferTemp[900];
	boost::timer::cpu_timer timer;
	timer.start();
	boost::timer::cpu_times pastTime = timer.elapsed();
	double elapsedSeconds = 0.0;
	do
	{
		longitudDelMensaje = clientSocket->read_some(boost::asio::buffer(bufferTemp), error);//recive la informacion del client y la guarda en bufferTemp
		boost::timer::cpu_times currentTime = timer.elapsed(); //copy

		if ((currentTime.wall - pastTime.wall) > 1e9)
		{
			elapsedSeconds += (currentTime.wall - pastTime.wall) / 1e9;
			pastTime = currentTime;
			std::cout << "Pasaron " << elapsedSeconds << " segundos." << std::endl;
		}

		if (!error)
			bufferTemp[longitudDelMensaje] = '\0';		//paste

	} while (error.value() == WSAEWOULDBLOCK); 

	if (error != boost::asio::error::eof)
	{
		if (longitudDelMensaje <= bufferSize)
		{
			for (size_t i = 0; i < bufferSize; i++)//transfiero la informacion de un buffer al otro
			{
				buffer_t[i] = bufferTemp[i];
			}
			return true;
		}
		else// en caso que el buffer enviado por el usuario sea muy chico envio false
		{
			for (size_t i = 0; i < bufferSize; i++)//transfiero la informacion de un buffer al otro
			{
				buffer_t[i] = bufferTemp[i];
			}
			return false;
		}

	}
	else
	{
		return false;
	}



}



void cpychar_c(char * a, char * b, int size)
{
	for (size_t i = 0; i < size; i++)
	{
		a[i] = b[i];
	}

}

bool charcomp_c(char * a, char * b, int size)
{
	for (size_t i = 0; i < size; i++)
	{
		if (a[i] != b[i])
		{
			return false;
		}

	}
	return true;
}


//previamente se deve llamar a waitforcleinte()
//recive como paramteros un arreglo de char(buffer) y una int,
//con la cantidad de elementos de dicho arreglo.
//devuelve: true, si se recivio algo. false, si no se recivio nada
//nota: NO ES BLOQUEANTE!!!!!!!!!!!!!!!!!!!!!!!!
uint16_t client::nonBlockinReceiveDataForServer(char * buffer_t, int bufferSize)
{

	uint16_t msgSize = 0;
	boost::system::error_code error;
	char bufferTemp[900];
	char bufferToTest[900];
	cpychar_c(bufferTemp, bufferToTest, 900);


	boost::function<void(const boost::system::error_code&, std::size_t)> handler(
		boost::bind(&client::writeCompletitionCallback, this,
			boost::asio::placeholders::error,
			boost::asio::placeholders::bytes_transferred));

	boost::asio::async_read(*clientSocket, boost::asio::buffer(bufferTemp), handler);
	//ServerSocket->async_read_some(boost::asio::buffer(bufferTemp), handler);

	for (msgSize = 0; msgSize<900 && msgSize<bufferSize && bufferToTest[msgSize] != bufferTemp[msgSize]; msgSize++)
	{
		buffer_t[msgSize] = bufferTemp[msgSize];
	}

	return msgSize;
}
