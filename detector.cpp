#include "detector.h"
#include <iostream>
#include <vector>

bool Detector::detecto_ciclos(Grafo& grafo){
  int ciclos = grafo.realizar_recorrido_dfs();
  if (ciclos > 0){
    return true;
  }
  return false;
}

bool Detector::detecto_instrucciones_sin_utilizar(Grafo& grafo){
   return grafo.hay_nodos_sin_visitar();
}
