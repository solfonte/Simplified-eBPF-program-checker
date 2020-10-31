#ifndef __CONTENEDOR_DE_DATOS_H__
#define __CONTENEDOR_DE_DATOS_H__

#include <list>
#include <string>
#include <mutex>

class Contenedor_de_datos{
  private:
    std::list<std::string> datos;
    std::mutex* mutex;
  public:
    bool empty() const;
    explicit Contenedor_de_datos(std::mutex* m);
    ~Contenedor_de_datos();
    void aniadir_dato(const std::string dato);//cappza devolver int
    std::string entregar_dato();
};

#endif
