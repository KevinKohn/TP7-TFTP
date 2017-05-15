#pragma once
#ifndef FILELIB_H
#define FILELIB_H
#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>
#include "boost\asio.hpp"
#include "boost\filesystem.hpp"

using namespace std;

string filetostring(string s);		//este programa transforma el archivo txt que le escribas (onda filetostring("pepito.txt")) en un string para mandarlo por boost
string filetostring();				//este hace exactamente lo mismo que el anterior pero el input es por teclado
ofstream createfile(string pos,string name);	//este es el programa que usa boost para hacer carpetas nuevas, en pos(posicion) la idea es ponerle donde hacer la carpeta
void stringtofile(string pos,string s);		//este programa usa el createfile y recibe UNICAMENTE strings de los mandados por filetostring para hacerlos archivos y guardarlos
#endif
/*en createfile y en stringtofile tienen lo que dice string pos. Este string recibe cosas del estilo de "c:\\carpeta1"
asi, pone como objetivo la carpeta1 en el disco c y, en caso de que no exista, la crea (nota aparte:no le pongan cosas
como c:\\carpeta1\\carpeta2 sin tener ni carpeta1 ni carpeta2 porque no te crea 2 carpetas de esta forma, habria que ha_
cer carpeta1 primero por separado y DESPUES hacer carpeta2)*/