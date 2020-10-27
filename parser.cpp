#include "parser.h"
#include <iostream>
#include <vector>
//cambiar los static a privados

/*Parser::Parser(){
  this->archivo = nombre_archivo;
}
*/
Parser::~Parser(){

}

void Parser::anidir_al_grafo(int instruccion_actual,int instruccion_anterior,std::string linea,Grafo* grafo) const{
  int pos = linea.find(":");
  if(pos > -1){
    std::string etiqueta = linea.substr(0,linea.find(":"));
    int posicion = grafo->buscar_posicion_nodo(etiqueta);//ahora lo hago como si fuese s0lo un llamado
    if(posicion > -1){
      grafo->aniadir_nodo_en_posicion(posicion,linea);
      std::cout << "enconte una etiqueta"  << '\n';
    }
  }
  if(instruccion_actual == RETURN){
    grafo->aniadir_arista(linea);
    grafo->aniadir_nodo(linea);
  }
  if(instruccion_actual == SALTO){
    grafo->aniadir_arista(linea);
    grafo->aniadir_nodo(linea);
  }
}

static bool verifica_etiqueta(std::string linea){
  ssize_t pos_dos_puntos(linea.find(":"));
  if(pos_dos_puntos > -1){
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
      //return ETIQUETA;
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

Grafo Parser::run() const{
  std::ifstream fs;
  int instruccion_actual,instruccion_anterior = -1;
  fs.open(this->archivo);
  Grafo grafo = Grafo();
  if(fs){
    std::string linea;
    while (std::getline(fs,linea,'\n')){
      if(linea.size() != 0){
        std::cout << linea << '\n';
        instruccion_actual = parsear_linea(linea);
        this->anidir_al_grafo(instruccion_actual,instruccion_anterior,linea,&grafo);
      }
    }
  fs.close();
}
  return grafo;
}
