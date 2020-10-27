#include "grafo.h"
#include <iostream>

Grafo::Grafo(){
  nodos = std::vector<std::vector<std::string>>();
}
Grafo::Grafo(const Grafo &grafo){
  this->nodos = grafo.nodos;
}
Grafo::~Grafo(){

}

void Grafo::aniadir_arista(const std::string instruccion){
  std::string nodo_agregar(instruccion);
  this->nodos.back().push_back(nodo_agregar);
}

void Grafo::aniadir_nodo(const std::string instruccion){
  std::string nodo_agregar(instruccion);
  this->nodos.push_back(std::vector<std::string>());
  this->nodos.back().push_back(nodo_agregar);
}
void Grafo::aniadir_nodo_en_posicion(int posicion,std::string instruccion){
  std::string nodo_agregar(instruccion);
  this->nodos.at(posicion).push_back(nodo_agregar);
}
int Grafo::buscar_posicion_nodo(std::string etiqueta)const{
  int elementos = this->nodos.size();
  int pos_buscada = -1;
  for(int i = 0; i < elementos; i++){
    pos_buscada = this->nodos.at(i).at(0).find(etiqueta);
    std::cout << this->nodos.at(i).at(0) <<'\n';

  }
  return pos_buscada;
}
