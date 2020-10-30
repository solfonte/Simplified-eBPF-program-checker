#ifndef __CONTENEDOR_DE_DATOS_H__
#define __CONTENEDOR_DE_DATOS_H__

#include <list>
#include <string>

class Contenedor_de_datos{
  private:
    std::list<std::string> datos;
  public:
    Contenedor_de_datos();
    ~Contenedor_de_datos();
    void aniadir_dato(const std::string dato);//cappza devolver int
    std::string entregar_dato();
};

#endif
