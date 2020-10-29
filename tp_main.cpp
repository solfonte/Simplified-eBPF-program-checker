#include <fstream>
#include <iostream>
#include <vector>
#include "parser.h"
#include "grafo.h"


int main(int argc, char** argv) {
  if(argc < 3){
    std::cout << " faltan argumentos " << '\n';
    return 0;
  }
  Parser parser = Parser(argv[2]);
  Grafo grafo = std::move(parser.run());
    return 0;

}
