#ifndef __GRAFO_H__
#define __GRAFO_H__

#include <string>
#include <vector>

class Nodo{
  private:
    std::string instruccion;
    std::vector<Nodo*> aristas;
    bool visitado = false;
  public:
    std::string obtener_instruccion() const;
    void aniadir_vecino(Nodo* nodo);
    Nodo(const std::string &instruccion);
    ~Nodo();
};

class Grafo{
  public:
    Grafo();
    Grafo(const Grafo &&grafo);
    ~Grafo();
    void aniadir_arista(const std::string instruccion,const std::string instruccion_conectar);
    void aniadir_nodo(const std::string instruccion);
    int cantidad_nodos() const;
  private:
    std::vector<Nodo> nodos;
    int buscar_nodo(std::string etiqueta) const;
};
#endif
