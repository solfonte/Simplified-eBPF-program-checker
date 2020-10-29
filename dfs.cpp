#include "dfs.h"
#include <stack>
#include <iostream>

#define YA_VISITADO 1
#define NO_VISITADO 0



int visitar_nodo(Nodo& nodo){
  if(nodo.fue_visitado()){
    return YA_VISITADO;
  }else {
    nodo.visitar();
    return NO_VISITADO;
  }
}


int realizar_recorrido_rec(Grafo& grafo,Nodo& nodo,std::stack<Nodo*> nodos_visitados,int* ciclos){
  if(nodos_visitados.empty()){
    return 0;
  }
  std::vector<Nodo*> adyacentes = nodo.obtener_adyacentes();
  int cantidad_ady = adyacentes.size();
  std::cout << "tamanio de " <<cantidad_ady << "para "<<nodo.obtener_instruccion() << '\n';



  //std::vector<Nodo*>::iterator it = adyacentes.begin(); it != adyacentes.end(); ++it
  for (int i = 0; i < cantidad_ady; i++) {
    nodos_visitados.push(adyacentes[i]);
    int res_visitar = visitar_nodo(*adyacentes[i]);
    *ciclos += res_visitar;
    if(res_visitar != YA_VISITADO){
      realizar_recorrido_rec(grafo,*adyacentes[i],nodos_visitados,ciclos);
    }
    std::cout << "volvi" <<'\n';


        /*nodos_visitados.push(*it);
        *nodos_repetidos += visitar_nodo(**it);
        realizar_recorrido_rec(grafo,**it,nodos_visitados,nodos_repetidos);
        std::string nodocadena = nodo.obtener_instruccion();
        std::cout << "el nodoo" <<nodocadena << '\n';*/
    }
    nodos_visitados.pop();
    return 0;
}


int Dfs::realizar_recorrido(Grafo& grafo) const{
  Nodo& nodo = grafo.obtener_nodo_origen();
  int ciclos = 0;
  std::stack<Nodo*> nodos_visitados = std::stack<Nodo*>();
  nodos_visitados.push(&nodo);
  std::string nodocadena = nodo.obtener_instruccion();
  std::cout << "el nodoo" <<nodocadena << '\n';
  visitar_nodo(nodo);
  realizar_recorrido_rec(grafo,nodo,nodos_visitados,&ciclos);
  return ciclos;
}
