#ifndef __THREAD_H__
#define __THREAD_H__

#include "contenedor_de_datos.h"
#include "parser.h"
#include "grafo.h"
#include "detector.h"
#include <thread>

class Thread{
  private:
    std::thread thread;
    Contenedor_de_datos* archivos;
    Contenedor_de_datos* resultados;
  public:
    void procesar_archivo();
    Thread(Contenedor_de_datos* archivos, Contenedor_de_datos* resultados);
    ~Thread();
    Thread(const Thread& thread) = delete;
    Thread(Thread&& thread);
};

#endif
