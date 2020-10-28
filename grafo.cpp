#include "grafo.h"
#include <iostream>

Grafo::Grafo(){
  nodos = std::vector<Nodo>();
}

Grafo::Grafo(const Grafo &grafo){
  this->nodos = grafo.nodos;
}

Grafo::~Grafo(){
}

void Grafo::aniadir_arista(const std::string instruccion,const std::string instruccion_conectar){
  //Nodo nodo(instruccion_conectar);
  std::cout << instruccion << '\n';
  std::cout << instruccion_conectar << '\n';

  int pos_nodo_agregar_arista = this->buscar_nodo(instruccion);
  int pos_nodo_apuntar = this->buscar_nodo(instruccion_conectar);
  std::cout << pos_nodo_agregar_arista << '\n';
  std::cout << pos_nodo_apuntar << '\n';
  Nodo& nodo_aniadir_arista = this->nodos[pos_nodo_agregar_arista];
  Nodo& nodo_apuntar = this->nodos[pos_nodo_apuntar];
  nodo_aniadir_arista.aniadir_vecino(&nodo_apuntar);
}

void Grafo::aniadir_nodo(const std::string instruccion){
  std::cout << instruccion << '\n';

  Nodo nodo(instruccion);
  this->nodos.push_back(nodo);
}

int Grafo::buscar_nodo(const std::string cadena) const{
  int cantidad_nodos = this->nodos.size();

  int posicion = -1;
  for (int i = 0; i < cantidad_nodos; i++){
    std::string instruccion_buscada = this->nodos[i].obtener_instruccion();

    if (instruccion_buscada == cadena || (instruccion_buscada.find(cadena) > -1)){
      std::cout << "encontre "<< i  <<  cadena << '\n';
      posicion = i;
    }
  }
  return posicion;
}

Nodo::~Nodo(){

}

Nodo::Nodo(const std::string &instruccion){
  this->instruccion = instruccion;
  this->aristas = std::vector<Nodo*>();
}

std::string Nodo::obtener_instruccion() const{
  return this->instruccion;
}

void Nodo::aniadir_vecino(Nodo* nodo){
  this->aristas.push_back(nodo);
}
