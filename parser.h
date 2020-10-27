#ifndef __PARSER_H__
#define __PARSER_H__

#define ETIQUETA 1
#define RETURN 2
#define SALTO 3
#define COMUN 4
#include "parser.h"
#include <string>


class Parser {
    private:
        std::string archivo;

    public:
      //Parser(const std::string &nombre_archivo);
      ~Parser();
      Parser(/*const std::string nombre_archivo*/);
      int parsear_linea(const std::string linea) const;
};

#endif
