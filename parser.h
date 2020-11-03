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
#include <vector>

class Parser {
    public:
      explicit Parser(const std::string nombre_archivo);
      ~Parser();
      bool run(Grafo& grafo) const;
};

#endif
