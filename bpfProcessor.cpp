#include "bpfProcessor.h"

void BpfProcessor::run(){
  std::string archivo_procesado =
  this->archivos.entregar_dato_si_no_esta_vacio();
  while (archivo_procesado.size() > 1){
    Parser parser = Parser(archivo_procesado);
    Grafo grafo = Grafo();
    bool pude_inicializar = parser.run(grafo);
    if (grafo.cantidad_nodos() == 0 || !pude_inicializar){
      return;
    }
    Detector detector = Detector();
    std::string resultado(archivo_procesado);
    if (detector.detecto_ciclos(grafo)){
      resultado += " FAIL: cycle detected";
      this->resultados.aniadir_dato(resultado);
    }else if (detector.detecto_instrucciones_sin_utilizar(grafo)){
      resultado += " FAIL: unused instructions detected";
      this->resultados.aniadir_dato(resultado);
    }else{
      resultado += " GOOD";
      this->resultados.aniadir_dato(resultado);
    }
    archivo_procesado =
    this->archivos.entregar_dato_si_no_esta_vacio();
  }
}
