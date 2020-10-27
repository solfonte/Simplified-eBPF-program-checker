#include "parser.h"
#include <iostream>
#include <vector>
//cambiar los static a privados

Parser::Parser(){
  //this->archivo = nombre_archivo;
}

Parser::~Parser(){

}


static bool verifica_etiqueta(std::string linea){
  ssize_t pos_dos_puntos(linea.find(":"));
  if(pos_dos_puntos < -1){
    return true;
  }
  return false;
}

static bool verifica_return(std::string linea){
  ssize_t pos_return(linea.find("ret"));
  if(pos_return > -1){
    return true;
  }
  return false;
}
static bool verifica_salto(std::string linea){
  std::vector<std::string> saltos = {"jmp","ja","jeq","jneq","jne","jlt","jgt","jge","jset"};
  bool hay_salto = false;
  for (int i = 0; i < 9; i++){//capaz cambiar a while
    ssize_t pos_salto(linea.find(saltos[i]));
    if(pos_salto > -1){
      hay_salto = true;
    }
  }
  return hay_salto;
}

int Parser::parsear_linea(const std::string linea) const{
  ssize_t pos_return(linea.find("ret"));
    if (verifica_etiqueta(linea)){
      std::cout << "soy una etiqueta" << "\n";
      return ETIQUETA;
    }
    if (verifica_return(linea)){
      std::cout << "soy un return" << "\n";
      return RETURN;
    }else if (verifica_salto(linea)){
      std::cout << "soy un salto" << "\n";
      return SALTO;
    }else{
      std::cout << "soy comun" << "\n";
      return COMUN;
    }
}

/*void Parser::run() const{
  std::ifstream fs;
  fs.open(this->archivo);

  if(fs){
    std::string linea;
    while (std::getline(fs,linea,'\n')){
      if(linea.size() != 0){
        std::cout << linea << '\n';
        parsear_linea(linea);
      }

    }
  fs.close();
}
}*/
