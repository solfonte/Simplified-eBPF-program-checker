#include "thread.h"
#include <iostream>
#include <utility>
#include <string>

void Thread::procesar_archivo(){
  std::string archivo_procesado = this->archivos->entregar_dato();
  Parser parser = Parser(archivo_procesado);
  Grafo grafo = std::move(parser.run());
  Detector detector = Detector();
  std::string resultado(archivo_procesado);
  if (detector.detecto_ciclos(grafo)){
    resultado += " FAIL: cycle detected";
    this->resultados->aniadir_dato(resultado);
  }else if (detector.detecto_instrucciones_sin_utilizar(grafo)){
    resultado += " FAIL: unused instructions detected";
    this->resultados->aniadir_dato(resultado);
  }else{
    resultado += " GOOD";
    this->resultados->aniadir_dato(resultado);
  }
}

Thread::Thread(Contenedor_de_datos* archivos, Contenedor_de_datos* resultados){
  this->archivos = archivos;
  this->resultados = resultados;
}

Thread::Thread(Thread&& thread){
  this->archivos = thread.archivos;
  this->resultados = thread.resultados;
}


Thread::~Thread(){
}
