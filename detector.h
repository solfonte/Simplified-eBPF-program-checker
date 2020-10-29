
#ifndef __DETECTOR_H__
#define __DETECTOR_H__
#include "grafo.h"

class Detector{
  public:
    bool detecto_ciclos(Grafo& grafo);
    bool detecto_instrucciones_sin_utilizar(Grafo& grafo);
    Detector() = default;
};

#endif
