#include <fstream>
#include <iostream>
#include <vector>
#include "parser.h"


int main(int argc, char** argv) {
  if(argc < 3){
    std::cout << " faltan argumentos " << '\n';
    return 0;
  }
  Parser parser = Parser(argv[2]);
  parser.run();

  return 0;

}
