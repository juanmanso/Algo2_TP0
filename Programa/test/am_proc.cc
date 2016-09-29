
#include <iostream>
#include <string>
#include <stdlib.h>
#include "complejo.h"

#include "am_proc.h"

using namespace std;

void
am_proc(istream *is, ostream *os, const size_t& n_decimator){
	
	bool eof_flag=false;
	size_t i;
	complejo c, aux; // c tendrá la suma y aux será el que recibe el complejo del stream


	// Si entra un archivo vacio (primero lee EOF), corta el for y luego el while, devolviendo un vacio

	while(!eof_flag){
		
		//  Se suman los primeros 'n_decimator' números hasta que corte
		for(i=1; i<=n_decimator && ((*is)>>aux); i++)
			c += aux;
	
		// Compruebo si se llegó a EOF
		if(is->eof())
			eof_flag=true;

		if(is->bad()){ 
		// El for terminó por no puder guardar el caracter en x
			cerr	<< "Error: Cannot read complex on input stream"
				<< endl;
			exit(1);
		}		

		// Realizo el promedio móvil
		c=c / n_decimator;
			
		// Imprimo el valor absoluto
		*os << c.abs()<<endl;
	}
	
	if(os->bad()){
		cerr	<< "Error: Cannot write output file"
			<< endl;
		exit(1);
	}

}
