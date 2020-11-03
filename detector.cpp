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
/*  std::vector<Nodo> &nodos = grafo.obtener_nodos();
  bool hay_inst_no_usadas = false;
  for (std::vector<Nodo>::iterator it = nodos.begin(); it
      != nodos.end(); ++it) {
       if (!(*it).fue_visitado()){
         hay_inst_no_usadas = true;
       }
   }
   return hay_inst_no_usadas;*/
   return grafo.hay_nodos_sin_visitar();
}
