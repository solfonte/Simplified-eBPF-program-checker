#include <fstream>
#include <iostream>
#include <vector>
#include "parser.h"
#include "grafo.h"
#include "dfs.h"
/*
void mostrar_grafo(Grafo& grafo){
  Nodo& nodo = grafo.obtener_nodo_origen();
  std::vector<Nodo*> adyldh = nodo.obtener_adyacentes();
  std::string cadenaa = nodo.obtener_instruccion();
  std::cout << cadenaa<< "osea andaaa" << '\n';
  std::vector<Nodo*> adyjne = adyldh[0]->obtener_adyacentes();
  std::string jne = adyldh[0]->obtener_instruccion();
  std::cout << jne<< "osea andaaa" << '\n';

  std::string ret1 = adyjne[0]->obtener_instruccion();
  std::cout << ret1<< "osea andaaa" << '\n';
//  std::string ret0 = adyjne[1]->obtener_instruccion();
//  std::cout << ret0<< "osea andaaa" << '\n';
}
*/

int main(int argc, char** argv) {
  if(argc < 3){
    std::cout << " faltan argumentos " << '\n';
    return 0;
  }
  Parser parser = Parser(argv[2]);
  Grafo grafo = std::move(parser.run());
  Dfs recorrido = Dfs();
  Nodo& nodo = grafo.obtener_nodo_origen();
  //mostrar_grafo(grafo);
//  std::string cadenaa = nodo.obtener_instruccion();
  //std::cout << cadenaa<< "osea andaaa" << '\n';
  int ciclos = recorrido.realizar_recorrido(grafo);
  std::cout << "hubo" << ciclos << " ciclos "<< '\n';

    return 0;

}
