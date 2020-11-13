#ifndef DFS_H
#define DFS_H
#include "grafo.h"

class Dfs{
  private:
    int cantidad_nodos_visitados = 0;
  public:
    bool realizar_recorrido(Grafo& grafo);
    int get_cantidad_nodos_visitados();
};

#endif
