#include "grafo.h"
#include <iostream>

Grafo::Grafo(){
  nodos = std::vector<Nodo>();
}

Grafo::Grafo(Grafo &&grafo){
  this->nodos = std::move(grafo.nodos);
}

Grafo::~Grafo(){
}

Nodo& Grafo::obtener_nodo_origen(){
  return this->nodos[0];
}

int Grafo::cantidad_nodos() const{
  return this->nodos.size();
}

void Grafo::aniadir_arista(const std::string instruccion,const std::string instruccion_conectar){
  int pos_nodo_agregar_arista = this->buscar_nodo(instruccion);
  int pos_nodo_apuntar = this->buscar_nodo(instruccion_conectar);
//  std::cout << pos_nodo_agregar_arista << '\n';
//  std::cout << pos_nodo_apuntar << '\n';
  Nodo& nodo_aniadir_arista = this->nodos[pos_nodo_agregar_arista];
  Nodo& nodo_apuntar = this->nodos[pos_nodo_apuntar];
  nodo_aniadir_arista.aniadir_vecino(&nodo_apuntar);
}

void Grafo::aniadir_nodo(const std::string cadena,bool es_etiqueta){
  std::cout << cadena << '\n';
  Instruccion instruccion = Instruccion(cadena,es_etiqueta);
  Nodo nodo(instruccion);
  this->nodos.push_back(nodo);
}

int Grafo::buscar_nodo(const std::string cadena) const{
  int cantidad_nodos = this->nodos.size();

  int posicion = -1;
  for (int i = 0; i < cantidad_nodos; i++){
    std::string instruccion_buscada = this->nodos[i].obtener_instruccion();

    if (instruccion_buscada == cadena || (instruccion_buscada.find(cadena) > -1)){
      posicion = i;
    }
  }
  return posicion;
}

Nodo::~Nodo(){

}

Nodo::Nodo(const Instruccion &instruccion){
  this->instruccion = Instruccion(instruccion);//std::move(instruccion);
  this->aristas = std::vector<Nodo*>();
}

std::string Nodo::obtener_instruccion() const{
  return this->instruccion.obtener_cadena();
}

void Nodo::aniadir_vecino(Nodo* nodo){
  this->aristas.push_back(nodo);
}

bool Nodo::fue_visitado(){
  return this->visitado;
}

void Nodo::visitar(){
  this->visitado = true;
  std::cout << "visite" << this->obtener_instruccion() << '\n';

}

std::vector<Nodo*> Nodo::obtener_adyacentes(){
  return this->aristas;
}
Nodo::Nodo(Nodo&& nodo){
  this->instruccion = std::move(nodo.instruccion);
  this->aristas = std::move(nodo.aristas);
}

Nodo::Nodo(const Nodo& nodo){
  this->instruccion = nodo.instruccion;
  this->aristas = nodo.aristas;
}