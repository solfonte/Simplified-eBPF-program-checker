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
    Nodo(const Nodo& nodo) = delete;
    Nodo& operator=(Nodo&& other);
};

class Grafo{
  public:
    Grafo();
    Grafo(Grafo &&grafo);
    ~Grafo();
    void aniadir_arista(const int& orden_nodo,const int& orden_nodo_conectar);
    void aniadir_nodo(const std::string& instruccion);
    int cantidad_nodos() const;
    Nodo& get_nodo_origen();
  private:
    std::vector<Nodo> nodos;
};
#endif
