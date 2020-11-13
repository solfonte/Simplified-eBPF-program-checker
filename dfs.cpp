#include "dfs.h"
#include <stack>
#include <vector>

bool Dfs::realizar_recorrido(Grafo& grafo){
  Nodo& origen = grafo.get_nodo_origen();
  bool hay_ciclo = false;
  std::stack<Nodo*> pila = std::stack<Nodo*>();
  origen.visitar();
  this->cantidad_nodos_visitados ++;
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
        this->cantidad_nodos_visitados ++;
        adyacentes[i]->visitar();
        pila.push(adyacentes[i]);
      }
    }
  }
  return hay_ciclo;
}

int Dfs::get_cantidad_nodos_visitados(){
  return this->cantidad_nodos_visitados;
}
