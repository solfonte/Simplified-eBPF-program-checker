#ifndef __CONTENEDOR_DE_DATOS_H__
#define __CONTENEDOR_DE_DATOS_H__

#include <list>
#include <string>
#include <mutex>

class Contenedor_de_datos{
  private:
    std::list<std::string> datos;
    std::mutex mutex;
  public:
    bool empty() const;
    Contenedor_de_datos(char** datos,int cantidad_datos);
    Contenedor_de_datos();
    ~Contenedor_de_datos();
    void aniadir_dato(const std::string dato);
    std::string entregar_dato_si_no_esta_vacio();
    void imprimir_datos();
};

#endif
