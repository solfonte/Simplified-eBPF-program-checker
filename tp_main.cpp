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
  Grafo grafo(argv[2]);
  //Parser parser = Parser(argv[2]);
  //parser.run();
  std::cout << "corooo " << '\n';

  return 0;
}
