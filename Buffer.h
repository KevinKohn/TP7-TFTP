#ifndef BUFFER_H
#define BUFFER_H


#include <cstdlib>
#include <cstdint>


template <typename T> class Buffer //buffer circular
{
private:
    T * start;
	uint16_t size;      //Numero de elementos que se puede contener en el mismo
    uint16_t write;     //Fin de la cola
    uint16_t read;      //Comienzo de la cola
    uint16_t nWritten;  //Numero de elementos presentes en la cola  

public:
	Buffer(uint16_t nElements = 1000);// Recibe el numero de elementos que va a tener el buffer
	~Buffer();

	bool write(T lastIn);
	//Recibe el elemento que se desea agregar al buffer
	//De no encontrarse lleno el buffer, lo guarda al final de 
	//la cola y devuelve true.
	//De lo contrario, devuelve false

	T read(bool * couldRead = NULL);
	//Si hay aun cosas por leer en el buffer, devuelve lo primero en la cola y 
	//TRUE en el indicador de error.
	//De lo contrario, indica error con FALSE (el valor devuelto no tendra ningun
	//significado). 

	bool isFull();	//devuelve true solo si el buffer esta completamente lleno
	bool isEmpty();	//devuelve true solo si el buffer esta completamente vacio
};


template <typename T> Buffer<T> :: Buffer (uint16_t nElements)
{
    size=n_elements;
	n_written=0;
	read=0;
	write=0;
    //Inicializa el nuevo buffer con el tamano recibido, e indica que se encuen-
    //tra vacio actualmente. Read y write se deben inicializar obligatoriamente
    //en la misma posicion, aunque es indistinto en cual. 
    
	if (nElements > 0) {
		try {
			start = new T[nElements];		//Reserva memoria para el buffer. T debe tener constructor por defecto!
		}
		catch (bad_alloc& error) {
			start = NULL;					//si esto queda en null no se van a hacer operaciones con el buffer
		}
	}
	else {
		start = NULL;					//nElements recibido no es valido
	}
}


template <typename T> Buffer<T> :: ~Buffer ()
{
    delete [] start;    //Libera la memoria utilizada
	start=NULL;			//Borra el valor anterior del puntero
}


template <typename T> bool Buffer<T> :: write (T lastIn)
{
    bool couldWrite;
    
    if (start == NULL || !this->isFull()) {  //Verifica que quede lugar para escribir
        start[write]= lastIn;  //Escribe en el final de la cola
        nWritten++;                //Indica que se escribio un char mas
        
        if (write==size) {  
            cb->write=0;    //Si se llego al final del buffer, vuelve al comienzo
        }
        else {
            write++;    //De lo contrario, avanza a la sig posicion
        }
         
		couldWrite=true;         //Indica que no hubo error
    }
    else {
		couldWrite=FALSE;    //Si la condicion inicial es falsa: error
    }
    
	return couldWrite;
}



template <typename T> Buffer<T> :: read (bool * couldRead)
{
    T nextElement;

    if (nWritten != 0 || start == NULL) { //Verifica que haya algo nuevo para leer
        nextElement = start[read]; //Lee desde el principio de la cola
        nWritten--;                //Indica que queda un char menos por leer
        
        if (read == size) {
            read = 0;  //Si se llego al final del buffer, vuelve al comienzo
        }
        else {
            read++;   //De lo contrario, avanza a la siguiente posicion
        }
    
        *couldRead=true;      //Indica que no hubo error
    }    
    else {
        *couldRead=false;   //Si no se cumple la condicion inicial: error
    }
    
    return T;
}


template <typename T> bool Buffer<T> :: isFull()
{
    //Condicion para que el buffer este lleno: el numero de caracteres que se ha
    //escrito es igual al tamano del buffer completo
    if (nWritten == size) 
		return true;
    else
		return false;
}


template <typename T> bool Buffer<T> :: isEmpty()
{
	if (nWritten == 0)
		return true;
	else
		return false;
}


#endif //BUFFER_H
