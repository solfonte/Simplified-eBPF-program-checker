#include "bpfProcessor.h"
#include "dfs.h"

void BpfProcessor::run(){
  std::string archivo_procesado =
  this->archivos.entregar_dato_si_no_esta_vacio();
  while (archivo_procesado != ""){
    Parser parser = Parser(archivo_procesado);
    Grafo grafo = Grafo();
    bool pude_inicializar = parser.run(grafo);
    if (grafo.cantidad_nodos() == 0 || !pude_inicializar){
      return;
    }
    std::string resultado(archivo_procesado);
    Dfs dfs = Dfs();
    bool hay_ciclo = dfs.realizar_recorrido(grafo);
    int nodos_visitados = dfs.get_cantidad_nodos_visitados();
    int cantidad_nodos = grafo.cantidad_nodos();
    if (hay_ciclo){
      resultado += " FAIL: cycle detected";
      this->resultados.aniadir_dato(resultado);
    }else if (cantidad_nodos > nodos_visitados){
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
