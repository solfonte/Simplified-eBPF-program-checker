#include "contenedor_de_datos.h"

Contenedor_de_datos::Contenedor_de_datos(){
  this->datos = std::list<std::string>();
}

Contenedor_de_datos::~Contenedor_de_datos(){
}

void Contenedor_de_datos::aniadir_dato(const std::string dato){
    this->datos.push_back(dato);
}

std::string Contenedor_de_datos::entregar_dato(){
  std::string dato = std::move(this->datos.front());
  this->datos.pop_front();
  return dato;
}
