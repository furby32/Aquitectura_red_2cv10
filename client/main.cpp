#include <iostream>
#include <fstream>
#include <string>       
#include <bitset>
#include <cstring>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "canal.h"
#include "protocolo.h"


using namespace std;



int main(int argc, char *argv[])
{
	//Trama a transmitir
	char trama[9];
	//contador
	/*	    
	inicializar();
	enviarAck(trama);
	enviarData(trama);
	terminar();
 */
 char a = 0x02;
 cout <<hex<< static_cast<int>(a)<< '\n';
 char b = a << 1;
 	
 	cout <<hex<< static_cast<int>(b)<< '\n';
    system("PAUSE");
    return EXIT_SUCCESS;
}
