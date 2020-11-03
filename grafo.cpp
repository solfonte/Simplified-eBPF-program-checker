#include "grafo.h"
#include <utility>
#include <stack>

bool Grafo::realizar_recorrido_dfs(){
  Nodo& origen = this->nodos[0];
  bool hay_ciclo = false;
  std::stack<Nodo*> pila = std::stack<Nodo*>();
  origen.visitar();
  pila.push(&origen);
  while (!pila.empty()){
    Nodo* vertice = pila.top();
    pila.pop();
    std::vector<Nodo*> &adyacentes = vertice->obtener_adyacentes();
    int cantidad_ady = adyacentes.size();
    for (int i = 0; i < cantidad_ady; i++) {
      if ((vertice->orden_topologico() > adyacentes[i]->orden_topologico())
          && adyacentes[i]->fue_visitado()){
        hay_ciclo = true;
      }
      if (!adyacentes[i]->fue_visitado()){
        adyacentes[i]->visitar();
        pila.push(adyacentes[i]);
      }
    }
  }
  return hay_ciclo;
}

Grafo::Grafo(){
  nodos = std::vector<Nodo>();
}

Grafo::Grafo(Grafo &&grafo){
  this->nodos = std::move(grafo.nodos);
}

Grafo::~Grafo(){
}

int Grafo::cantidad_nodos() const{
  return this->nodos.size();
}

bool Grafo::hay_nodos_sin_visitar(){
  std::vector<Nodo> &nodos = this->nodos;
  bool hay_inst_no_usadas = false;
    for (std::vector<Nodo>::iterator it = nodos.begin(); it
        != nodos.end(); ++it) {
         if (!(*it).fue_visitado()){
           hay_inst_no_usadas = true;
         }
     }
     return hay_inst_no_usadas;
}

void Grafo::aniadir_arista(const int orden_nodo,
                          const int orden_nodo_conectar){
  Nodo& nodo_aniadir_arista = this->nodos[orden_nodo];
  Nodo& nodo_apuntar = this->nodos[orden_nodo_conectar];
  nodo_aniadir_arista.aniadir_vecino(&nodo_apuntar);
}

void Grafo::aniadir_nodo(const std::string instruccion){
  int orden_nodo = this->nodos.size();
  Nodo nodo(instruccion,orden_nodo);
  this->nodos.push_back(nodo);
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

std::string Nodo::obtener_instruccion() const{
  return this->instruccion;
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

Nodo::Nodo(const Nodo& nodo){
  this->orden = nodo.orden;
  this->instruccion = nodo.instruccion;
  this->aristas = nodo.aristas;
  this->visitado = nodo.visitado;
}
