#ifndef __GRAFO_H__
#define __GRAFO_H__

#include "parser.h"
#include <cstring>
#include <list>

class Grafo{
  public:
    Grafo(const std::string archivo);
    ~Grafo();
    void aniadir_nodo(const std::string instruccion);
  private:
    std::list<std::list<std::string>> nodos;
    void inicializar_nodos(const std::string archivo);
    void verificar_nodos(int instruccion_actual,int instruccion_anterior,std::string linea);
};
#endif
