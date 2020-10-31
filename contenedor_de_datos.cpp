#include "contenedor_de_datos.h"
#include <utility>

Contenedor_de_datos::Contenedor_de_datos(std::mutex* m){
  this->mutex = m;
  this->datos = std::list<std::string>();
}

Contenedor_de_datos::~Contenedor_de_datos(){
}

void Contenedor_de_datos::aniadir_dato(const std::string dato){
    this->mutex->lock();
    this->datos.push_back(dato);
    this->mutex->unlock();
}

std::string Contenedor_de_datos::entregar_dato(){
  this->mutex->lock();
  std::string dato = std::move(this->datos.front());
  this->datos.pop_front();
  this->mutex->unlock();
  return dato;
}

bool Contenedor_de_datos::empty() const{
  return this->datos.empty();
}
