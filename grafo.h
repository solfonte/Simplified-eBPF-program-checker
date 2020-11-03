#ifndef __GRAFO_H__
#define __GRAFO_H__

#include <string>
#include <vector>

class Nodo{
  private:
    std::string instruccion;
    int orden;
    std::vector<Nodo*> aristas;
    bool visitado = false;
  public:
    std::string obtener_instruccion() const;
    void aniadir_vecino(Nodo* nodo);
    Nodo(const std::string &instruccion,const int &orden);
    bool fue_visitado();
    void visitar();
    std::vector<Nodo*>& obtener_adyacentes();
    int orden_topologico() const;
    ~Nodo();
    Nodo(Nodo&& nodo);
    Nodo(const Nodo& nodo);
};

class Grafo{
  public:
    bool realizar_recorrido_dfs();
    Grafo();
    Grafo(Grafo &&grafo);
    ~Grafo();
    void aniadir_arista(const int orden_nodo,const int orden_nodo_conectar);
    void aniadir_nodo(const std::string instruccion);
    int cantidad_nodos() const;
    Nodo& obtener_nodo_origen();
    std::vector<Nodo>& obtener_nodos();
    bool hay_nodos_sin_visitar();
  private:
    std::vector<Nodo> nodos;
    int buscar_nodo(std::string etiqueta) const;
};
#endif
