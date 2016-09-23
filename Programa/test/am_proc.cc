
#include <iostream>
#include <string>
#include <stdlib.h>
#include "complejo.h"

#include "am_proc.h"

using namespace std;

void am_proc(istream *is, ostream *os, const size_t& n_decimator){
	
	bool eof_flag=false;
	size_t i;
	complejo c, aux; // aux_c tendrá la suma y aux_x será el que recibe el complejo del stream


	// Si entra un archivo vacio (primero lee EOF), corta el for y luego el while, devolviendo un vacio
	
	while(!eof_flag){
		
		//  Se suman los primeros 'n_decimator' números hasta que corte
		for(i=1; i<=n_decimator && !(*is>>aux); i++)
			c += aux;
	
		// Compruebo si se llegó a EOF
		if(is->eof())
			eof_flag=true;

		else{ 
		// El for terminó por no puder guardar el caracter en aux_x
			cerr	<< "Error: Cannot find EOF on input stream"
				<< endl;
			exit(1);
		}		

		// Realizo el promedio móvil
		c=c / n_decimator;
			
		// Imprimo el valor absoluto
		*os << c.abs();
	}
	
	if(os->bad()){
		cerr	<< "Error: Cannot write output file"
			<< endl;
		exit(1);
	}

	if(is->bad()){
		cerr	<< "Error: Cannot read input file"
			<< endl;
		exit(1);
	}

}
