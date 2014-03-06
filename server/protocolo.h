#include <iostream>
#include <cstring>
using namespace std;
#define BLKSIZE 512
class Solicitud
{
	private:
		char tipo;
		char* nombre;
	public:
		Solicitud(int tipo,const char name[]){
			if(tipo == 1){
				this->tipo = 0x01;
				strcpy(this->nombre, name);
			}else if(tipo == 2){
				this->tipo = 0x02;
				strcpy(this->nombre, name);
			}
		}
		char getTipo(){
			return this->tipo;
		}
		char* getName(){
			return this->nombre;
		}
		void imprimir(){
			cout<< hex<< static_cast<int>(this->tipo) << '\n' << this->nombre <<'\n';
		}

};
/*
char nombre[15]="hola";
Solicitud Rqe(1,nombre);
*/


class Data
{
	public:
		Data(){
			this->tipo = 0x04;	
		}
		char getTipo(){
			return this->tipo;
		}
		void setBloque(char i){
			this->bloque=i;
		}
		char getBloque(){
			return this->bloque;
		}
	private:
		char tipo;
		char bloque;
		char datos;
};

class Ack
{
	public:
		Ack(){
			this->tipo = 0x08;	
		}
		char getTipo(){
			return this->tipo;
		}
		void setBloque(char i){
			this->numero=i;
		}
		char getBloque(){
			return this->numero;
		}
	private:
		char tipo;
		char numero;
};

class error
{
	public:
		error(){
			this->tipo = 0x16;	
		}
		char getTipo(){
			return this->tipo;
		}
	private:
		char tipo;
		char codigo;
		char mensaje;
};


/*
	Solicitud request(1);
	Solicitud req(2);
	char tipoRequest=request.getTipo();
	cout << "valor "<< hex<< static_cast<int>(tipoRequest) << '\n';
	tipoRequest=req.getTipo();
	cout << "valor "<< hex<< static_cast<int>(tipoRequest) << '\n';
	//DAtos
	Data datos;
	tipoRequest = datos.getTipo();
	cout << "valor "<< hex<< static_cast<int>(tipoRequest) << '\n';
	//Acuse
	Ack acuse;
	tipoRequest=acuse.getTipo();
	cout << "valor "<< hex<< static_cast<int>(tipoRequest) << '\n';
	//Error
	error err;
	tipoRequest=err.getTipo();
	cout << "valor "<< hex<< static_cast<int>(tipoRequest) << '\n';
	*/
	
	
/******************************************************************************/
class Transfer
{
   public:
      char tipo[];   
      char archivo[];  
      char modo[];   
	private:
		Solicitud trama;
};

void enviarAck(char *trama){
	//byte para numerar los paquetes
	char Bloque=0x01;
	//instaancie del paquete datos
	Ack acuse;
	// abrir el archivo en modo binario

	
	do{
			acuse.setBloque(Bloque);
			trama[0]=acuse.getTipo();
			trama[1]=acuse.getBloque();
			tx(trama,2);
		Bloque++;
	}while(Bloque >= 0x0f);
		
}
