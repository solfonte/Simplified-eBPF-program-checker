#ifndef __GRAFO_H__
#define __GRAFO_H__

#include <string>
#include <vector>

class Grafo{
  public:
    Grafo();
    Grafo(const Grafo &grafo);
    ~Grafo();
    void aniadir_arista(const std::string instruccion);
    void aniadir_nodo(const std::string instruccion);
    void aniadir_nodo_en_posicion(int posicion,std::string instruccion);
    int buscar_posicion_nodo(std::string etiqueta)const;
  private:
    std::vector<std::vector<std::string>> nodos;
};
#endif
