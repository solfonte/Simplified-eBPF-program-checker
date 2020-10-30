#include "dfs.h"
#include <stack>

#define YA_VISITADO 1
#define NO_VISITADO 0

#include <iostream>
bool Dfs::realizar_recorrido(Grafo& grafo) const{
  Nodo& origen = grafo.obtener_nodo_origen();
  bool hay_ciclo = false;
  std::stack<Nodo*> pila = std::stack<Nodo*>();
  origen.visitar();
  pila.push(&origen);
  while(!pila.empty()){
    Nodo* vertice = pila.top();
    pila.pop();
    std::vector<Nodo*> &adyacentes = vertice->obtener_adyacentes();
    int cantidad_ady = adyacentes.size();
    for (int i = 0; i < cantidad_ady; i++) {
      if(!adyacentes[i]->fue_visitado()){
        adyacentes[i]->visitar();
        pila.push(adyacentes[i]);
      }
      int j = vertice->orden_topologico();
      int k = adyacentes[i]->orden_topologico();
      if(vertice->orden_topologico() > adyacentes[i]->orden_topologico()){
        hay_ciclo = true;
      }
    }
  }
  return hay_ciclo;
}
