#include <fstream>
#include <iostream>
#include <vector>
#include "parser.h"
#include "grafo.h"
#include "dfs.h"
#include "detector.h"
#include "contenedor_de_datos.h"
#include "thread.h"
#define POSICION_ARCHIVOS 2
#define POSICION_CANT_HILOS 1

int main(int argc, char** argv) {

  if (argc < 3){
    std::cout << " faltan argumentos " << '\n';
    return 0;
  }
  int cantidad_de_hilos = atoi(argv[POSICION_CANT_HILOS]);
  std::mutex m;
  Contenedor_de_datos archivos = Contenedor_de_datos(&m);//ver si se esta coopiando
  Contenedor_de_datos resultados = Contenedor_de_datos(&m);
  std::vector<Thread> threads; // no se inicializa?

  /*encapsular en el constructor de archivos*/
  for (int i = POSICION_ARCHIVOS; i < argc; i++){
    archivos.aniadir_dato(argv[i]);
  }


  for (int i = 0; i < cantidad_de_hilos; i++){
    Thread thread = Thread(&archivos,&resultados);
    threads.push_back(std::move(thread));//capaz le tengo que mandar los punteros
  }

  int i = 0;
  while(!archivos.empty()){
    threads[i].procesar_archivo();
    i++;
    if (i == cantidad_de_hilos) i = 0;
  }
/*

  Parser parser = Parser(archivos.entregar_dato());
  Grafo grafo = std::move(parser.run());
  Detector detector = Detector();
*/

  /**************************************
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
  **************************************/


    return 0;

}
