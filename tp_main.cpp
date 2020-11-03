#include <fstream>
#include <iostream>
#include <vector>
#include "parser.h"
#include "grafo.h"
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
  if (cantidad_de_hilos <= 0){
    std::cout << " La cantidad de hilos debe ser mayor o igual a uno\n";

    return 0;
  }
  std::mutex m;
  Contenedor_de_datos archivos = Contenedor_de_datos(&m);
  Contenedor_de_datos resultados = Contenedor_de_datos(&m);
  std::vector<Thread> threads;

  for (int i = POSICION_ARCHIVOS; i < argc; i++){
    archivos.aniadir_dato(argv[i]);
  }

  for (int i = 0; i < cantidad_de_hilos; i++){
    Thread thread = Thread(&archivos,&resultados);
    threads.push_back(std::move(thread));
  }

  int i = 0;
  while (!archivos.empty()){
    threads[i].procesar_archivo();
    i++;
    if (i == cantidad_de_hilos) i = 0;
  }

  while(!resultados.empty()){
    std::string temporal = resultados.entregar_dato();
    std::cout << temporal<< '\n';
  }/*
  for (int i = 0; i < (argc - POSICION_ARCHIVOS); i++){
    //mejor con while not empty
    std::string temporal = resultados.entregar_dato();
    std::cout << temporal<< '\n';
  }*/

    return 0;
}
