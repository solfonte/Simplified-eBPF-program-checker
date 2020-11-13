#ifndef __THREAD_H__
#define __THREAD_H__

#include "contenedor_de_datos.h"
#include "parser.h"
#include "grafo.h"
#include <thread>

class Thread{
  private:
    std::thread thread;
  public:
    virtual void run() = 0;
    void start();
    void join();
    Thread(){}
    virtual ~Thread(){}
    Thread(const Thread& thread) = delete;
    Thread(Thread&& other) = delete;
};

#endif
