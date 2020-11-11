#include "contenedor_de_datos.h"
#include <utility>
#include <iostream>

Contenedor_de_datos::Contenedor_de_datos(char** datos,int cantidad_datos){
  for (int i = 0; i < cantidad_datos; i++){
    this->aniadir_dato(datos[i]);
  }
}

Contenedor_de_datos::Contenedor_de_datos(){
  this->datos = std::list<std::string>();
}

Contenedor_de_datos::~Contenedor_de_datos(){
}

void Contenedor_de_datos::aniadir_dato(const std::string dato){
    this->mutex.lock();
    this->datos.push_back(dato);
    this->datos.sort();
    this->mutex.unlock();
}

std::string Contenedor_de_datos::entregar_dato_si_no_esta_vacio(){
  this->mutex.lock();
  std::string dato = "";
  if (!this->datos.empty()){
    dato = std::move(this->datos.front());
    this->datos.pop_front();
  }
  this->mutex.unlock();
  return dato;
}
//sacar esta funcion
bool Contenedor_de_datos::empty() const{
  return this->datos.empty();
}

void Contenedor_de_datos::imprimir_datos(){
  //capaz con lock
  while (!this->datos.empty()){
    std::string temporal = this->entregar_dato_si_no_esta_vacio();//sacar esta funcion
    std::cout << temporal<< '\n';
  }
}
