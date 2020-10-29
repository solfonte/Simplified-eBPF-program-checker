#ifndef __DFS_H__
#define __DFS_H__

#include "grafo.h"

class Dfs{

  public:
    int realizar_recorrido(Grafo& grafo) const;
    Dfs() = default;
};

#endif
