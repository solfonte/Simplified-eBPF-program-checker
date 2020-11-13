#ifndef BPFPROCESSOR_H
#define BPFPROCESSOR_H
#include "thread.h"
#include <string>

class BpfProcessor: public Thread{
  private:
    Contenedor_de_datos& archivos;
    Contenedor_de_datos& resultados;
  public:
    void run() override;
    BpfProcessor(Contenedor_de_datos& archivos,
                 Contenedor_de_datos& resultados):
    archivos(archivos),resultados(resultados){}
};

#endif
