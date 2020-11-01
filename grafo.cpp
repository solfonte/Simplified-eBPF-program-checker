#include "grafo.h"
#include <utility>
#include <stack>

bool Grafo::realizar_recorrido_dfs(){
  Nodo& origen = this->obtener_nodo_origen();
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

Nodo& Grafo::obtener_nodo_origen(){
  return this->nodos[0];
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

void Grafo::aniadir_nodo(const std::string instruccion){
  int orden_nodo = this->nodos.size();
  Nodo nodo(instruccion,orden_nodo);
  this->nodos.push_back(nodo);
}

int Grafo::buscar_nodo(const std::string cadena) const{
  int cantidad_nodos = this->nodos.size();

  int posicion = -1;
  for (int i = 0; i < cantidad_nodos; i++){
    std::string instruccion_buscada = this->nodos[i].obtener_instruccion();
    ssize_t pos = instruccion_buscada.find(cadena);
    if (instruccion_buscada == cadena || pos > -1){
      posicion = i;
    }
  }
  return posicion;
}

std::vector<Nodo>& Grafo::obtener_nodos(){
  return this->nodos;
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
  this->visitado = bool(true);
}

std::vector<Nodo*>& Nodo::obtener_adyacentes(){
  return this->aristas;
}
Nodo::Nodo(Nodo&& nodo){
  this->orden = nodo.orden;
  this->instruccion = std::move(nodo.instruccion);
  this->aristas = std::move(nodo.aristas);
  this->visitado = nodo.visitado;
}

Nodo::Nodo(const Nodo& nodo){
  this->orden = nodo.orden;
  this->instruccion = nodo.instruccion;
  this->aristas = nodo.aristas;
  this->visitado = nodo.visitado;
}
