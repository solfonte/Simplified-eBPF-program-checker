#include "instruccion.h"

Instruccion::Instruccion(const Instruccion& instruccion){
  this->instruccion = instruccion.instruccion;
  this->contiene_etiqueta = instruccion.contiene_etiqueta;
}

std::string Instruccion::obtener_cadena() const{
  return this->instruccion;
}

Instruccion::Instruccion(){
}
Instruccion::~Instruccion(){
}
