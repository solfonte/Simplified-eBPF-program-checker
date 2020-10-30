#include <fstream>
#include <iostream>
#include <vector>
#include "parser.h"
#include "grafo.h"
#include "dfs.h"
#include "detector.h"
#include "contenedor_de_datos.h"
#define POSICION_ARCHIVOS 2

int main(int argc, char** argv) {
  if(argc < 3){
    std::cout << " faltan argumentos " << '\n';
    return 0;
  }
  Contenedor_de_datos archivos = Contenedor_de_datos();
  for(int i = POSICION_ARCHIVOS; i < argc; i++){
    archivos.aniadir_dato(argv[i]);
  }
  Parser parser = Parser(archivos.entregar_dato());
  Grafo grafo = std::move(parser.run());
  Detector detector = Detector();
  Contenedor_de_datos resultados = Contenedor_de_datos();

  /**************************************/
  if(detector.detecto_ciclos(grafo)){
    std::string resultado = "archivo";
    resultado += " FAIL: cycle detected\n";
    resultados.aniadir_dato(resultado);
  }else if(detector.detecto_instrucciones_sin_utilizar(grafo)){
    std::string resultado = "archivo";
    resultado += " FAIL: unused instructions detected\n";
    resultados.aniadir_dato(resultado);
  }else{
    std::string resultado = "archivo";
    resultado += " GOOD\n";
    resultados.aniadir_dato(resultado);

  }
  std::cout << resultados.entregar_dato()<< '\n';
  /**************************************/


    return 0;

}
