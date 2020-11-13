#include <fstream>
#include <iostream>
#include <vector>
#include "parser.h"
#include "grafo.h"
#include "detector.h"
#include "contenedor_de_datos.h"
#include "bpfProcessor.h"
#define POSICION_ARCHIVOS 2
#define POSICION_CANT_HILOS 1

int main(int argc, char** argv) {
  if (argc < 3){
    std::cout << " faltan argumentos " << '\n';
    return 0;
  }
  int cantidad_de_hilos = std::stoi(argv[POSICION_CANT_HILOS]);
  if (cantidad_de_hilos <= 0){
    std::cout << " La cantidad de hilos debe ser mayor o igual a uno\n";

    return 0;
  }
  Contenedor_de_datos archivos(&(argv[POSICION_ARCHIVOS]),
                              argc - POSICION_ARCHIVOS);
  Contenedor_de_datos resultados;
  std::vector<Thread*> threads;

  for (int i = 0; i < cantidad_de_hilos; i++){
    threads.emplace_back(new BpfProcessor(archivos, resultados));
    threads.back()->start();
  }

  for (int i = 0; i < cantidad_de_hilos; i++){
    threads[i]->join();
    delete threads[i];
  }

  resultados.imprimir_datos();

    return 0;
}
