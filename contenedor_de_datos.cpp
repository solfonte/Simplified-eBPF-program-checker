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

void Contenedor_de_datos::aniadir_dato(const std::string& dato){
    std::lock_guard<std::mutex> lck(this->mutex);
    this->datos.push_back(dato);
    this->datos.sort();
}

std::string Contenedor_de_datos::entregar_dato_si_no_esta_vacio(){
  std::lock_guard<std::mutex> lck(this->mutex);
  std::string dato = "";
  if (!this->datos.empty()){
    dato = std::move(this->datos.front());
    this->datos.pop_front();
  }
  return dato;
}

void Contenedor_de_datos::imprimir_datos(){
  while (!this->datos.empty()){
    std::string temporal = this->entregar_dato_si_no_esta_vacio();
    std::cout << temporal<< '\n';
  }
}
