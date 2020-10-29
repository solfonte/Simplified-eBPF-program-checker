#ifndef __PARSER_H__
#define __PARSER_H__

#define ETIQUETA 1
#define RETURN 2
#define SALTO_A_ETIQUETA 3
#define SALTO_CON_UNA_ETIQUETA 4
#define SALTO_CON_DOS_ETIQUETAS 5
#define NO_HAY_SALTO 6
#define COMUN 7
#include "grafo.h"
#include <string>
#include <fstream>


class Parser {
    private:
        std::string archivo;
        void anidir_al_grafo(int instruccion_actual,int instruccion_anterior,std::string linea,Grafo* grafo) const;
    public:
      Parser(const std::string nombre_archivo);
      ~Parser();
    /*  Parser(const std::string nombre_archivo) :
          archivo(nombre_archivo) {}*/
      Grafo run() const;
      Grafo crear_grafo(const std::vector<std::string>instrucciones) const;

};

#endif