#ifndef __INSTRUCCION_H__
#define __INSTRUCCION_H__
#include <string>

class Instruccion{
  private:
   std::string instruccion;
   bool contiene_etiqueta;
  public:
    Instruccion();
    Instruccion(const Instruccion& instruccion);
    Instruccion(const std::string instruccion,const bool contiene_etiqueta):
    instruccion(instruccion),
    contiene_etiqueta(contiene_etiqueta)
   {
   }
    ~Instruccion();
    std::string obtener_cadena() const;
};

#endif
