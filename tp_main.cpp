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
  Contenedor_de_datos archivos = Contenedor_de_datos(&m);//verSi se estaCopiando
  Contenedor_de_datos resultados = Contenedor_de_datos(&m);
  std::vector<Thread> threads; // no se inicializa?

  /*encapsular en el constructor de archivos*/
  for (int i = POSICION_ARCHIVOS; i < argc; i++){
    archivos.aniadir_dato(argv[i]);
  }

  for (int i = 0; i < cantidad_de_hilos; i++){
    Thread thread = Thread(&archivos,&resultados);
    threads.push_back(std::move(thread));//capazLe tengo que mandar los punteros
  }

  int i = 0;
  while (!archivos.empty()){
    threads[i].procesar_archivo();
    i++;
    if (i == cantidad_de_hilos) i = 0;
  }
    return 0;
}
