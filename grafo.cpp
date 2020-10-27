#include "grafo.h"
#include "parser.h"
#include <fstream>
#include <iostream>

void Grafo::verificar_nodos(int instruccion_actual,int instruccion_anterior,std::string linea){
  if(instruccion_actual == COMUN){
    this->aniadir_nodo(linea);

  }
}

void Grafo::inicializar_nodos(const std::string archivo){
  Parser parser = Parser();
  std::ifstream fs;
  fs.open(archivo);
  int instruccion_actual,instruccion_anterior = -1;
  if(fs){
    std::string linea;
    while (std::getline(fs,linea,'\n')){
      if(linea.size() != 0){
        instruccion_actual = parser.parsear_linea(linea);
        this->verificar_nodos(instruccion_actual,instruccion_anterior,linea);
        instruccion_anterior = instruccion_actual;
      }
    }
  fs.close();
  }
}


Grafo::Grafo(const std::string archivo){
  this->nodos = std::list<std::list<std::string>>();
  this->inicializar_nodos(archivo);
}
Grafo::~Grafo(){
}
void Grafo::aniadir_nodo(const std::string instruccion){
  std::string nodo_agregar(instruccion);
  if(this->nodos.size() != 0){
    this->nodos.back().push_back(nodo_agregar);
  }
  this->nodos.push_back(std::list<std::string>());
  this->nodos.back().push_back(nodo_agregar);
  std::cout << "agrego " <<nodo_agregar << '\n';
}
