#include "grafo.h"
#include <utility>
#include <stack>

Nodo& Grafo::get_nodo_origen(){
  return this->nodos[0];
}


Grafo::Grafo(){
}

Grafo::Grafo(Grafo &&grafo){
  this->nodos = std::move(grafo.nodos);
}

Grafo::~Grafo(){
}

int Grafo::cantidad_nodos() const{
  return this->nodos.size();
}

void Grafo::aniadir_arista(const int orden_nodo,
                          const int orden_nodo_conectar){
  Nodo& nodo_aniadir_arista = this->nodos[orden_nodo];
  Nodo& nodo_apuntar = this->nodos[orden_nodo_conectar];
  nodo_aniadir_arista.aniadir_vecino(&nodo_apuntar);
}

void Grafo::aniadir_nodo(const std::string& instruccion){
  int orden_nodo = this->nodos.size();
  Nodo nodo(instruccion,orden_nodo);
  this->nodos.push_back(std::move(nodo));
}

Nodo::~Nodo(){
}

int Nodo::orden_topologico() const{
  return this->orden;
}

Nodo::Nodo(const std::string &instruccion,const int &orden){
  this->orden = orden;
  this->instruccion = std::move(instruccion);
  this->aristas = std::vector<Nodo*>();
}

void Nodo::aniadir_vecino(Nodo* nodo){
  this->aristas.push_back(nodo);
}

bool Nodo::fue_visitado(){
  return this->visitado;
}

void Nodo::visitar(){
  this->visitado = true;
}

std::vector<Nodo*>& Nodo::obtener_adyacentes(){
  return this->aristas;
}

Nodo::Nodo(Nodo&& nodo){
  this->orden = std::move(nodo.orden);
  this->instruccion = std::move(nodo.instruccion);
  this->aristas = std::move(nodo.aristas);
  this->visitado = std::move(nodo.visitado);
}

Nodo& Nodo::operator=(Nodo&& other){
  this->orden = std::move(other.orden);
  this->instruccion = std::move(other.instruccion);
  this->aristas = std::move(other.aristas);
  this->visitado = std::move(other.visitado);
  return *this;
}
int Grafo::cantidad_nodos(){
  return this->nodos.size();
}
