#ifndef __PARSER_H__
#define __PARSER_H__

#define ETIQUETA 1
#define RETURN 2
#define SALTO 3
#define COMUN 4
#include "grafo.h"
#include <string>
#include <fstream>


class Parser {
    private:
        std::string archivo;
        void anidir_al_grafo(int instruccion_actual,int instruccion_anterior,std::string linea,Grafo* grafo) const;
    public:
      //Parser(const std::string &nombre_archivo);
      ~Parser();
      Parser(const std::string nombre_archivo) :
          archivo(nombre_archivo) {}
      Grafo run() const;
      int parsear_linea(const std::string linea) const;
};

#endif
