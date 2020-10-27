#ifndef __PARSER_H__
#define __PARSER_H__

#include "parser.h"
#include <string>


class Parser {
    private:
        std::string archivo;

    public:
      //Parser(const std::string &nombre_archivo);
      //~Parser();
      Parser(const std::string nombre_archivo) :
          archivo(nombre_archivo) {}
      void run() const;
};

#endif
