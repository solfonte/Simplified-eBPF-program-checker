#include "parser.h"
#include <iostream>
#include <vector>
//cambiar los static a privados

Parser::Parser(const std::string nombre_archivo){
  this->archivo = nombre_archivo;
}
Parser::~Parser(){
}
static bool verifica_etiqueta(std::string linea){
  ssize_t pos_dos_puntos(linea.find(":"));
  if(pos_dos_puntos > -1){
    return true;
  }
  return false;
}

static bool verifica_return(std::string linea){
  ssize_t pos_return(linea.find("ret"));
  if(pos_return > -1){
    return true;
  }
  return false;
}

int contar_comas(const std::string& linea){
  int tamanio_linea = linea.size() - 1;
  int comas = 0;
  int pos = -1;
  std::string aux(linea);
  while((pos = aux.find(',')) != std::string::npos){
    comas = comas + 1;
    aux.erase(0,pos + 1);
  }
  std::cout << "cantidad de comas" << comas << "\n";
  return comas;
}

static int verifica_salto(std::string linea){
  std::vector<std::string> saltos = {"jmp","ja","jeq","jneq","jne","jlt","jgt","jge","jset"};
  bool hay_salto = false;
  int cantidad_comas = 0, retorno = 0;
  for (int i = 0; i < 9; i++){//capaz cambiar a while
    ssize_t pos_salto(linea.find(saltos[i]));
    if(pos_salto > -1){
      hay_salto = true;
    }
  }
  if(hay_salto){
    cantidad_comas = contar_comas(linea);
  }
  if(hay_salto && cantidad_comas == 0){
    retorno = SALTO_A_ETIQUETA;
  }else if (cantidad_comas == 1){
    retorno = SALTO_CON_UNA_ETIQUETA;
  }else if(cantidad_comas == 2){
    retorno = SALTO_CON_DOS_ETIQUETAS;
  }else{
    retorno = NO_HAY_SALTO;
  }
  return retorno;
}

int parsear_linea(const std::string linea){
  //ssize_t pos_return(linea.find("ret"));
  int tipo_salto = verifica_salto(linea);
    if (verifica_return(linea)){
      std::cout << "soy un return" << "\n";
      return RETURN;
    }else if (tipo_salto == SALTO_CON_UNA_ETIQUETA || tipo_salto == SALTO_CON_UNA_ETIQUETA || tipo_salto == SALTO_A_ETIQUETA){
      std::cout << "soy un salto" << "\n";
      return tipo_salto;
    }else{
      std::cout << "soy comun" << "\n";
      return COMUN;
    }
}
void asociar_etiquetas(std::vector<std::string> instrucciones,Grafo& grafo, int pos_etiqueta){
  std::string aux(instrucciones[pos_etiqueta]);
  int pos = aux.find(":");
  std::string etiqueta = aux.substr(0,pos);
//  int pos_instruccion = aux.find_first_not_of(" ",pos + 1);
  //std::string instruccion = aux.substr(pos_instruccion, aux.size()-1);
  int cantidad_de_instrucciones = instrucciones.size();
  for(int i = 0; i <cantidad_de_instrucciones; i++){
    int pos = instrucciones[i].find(etiqueta);
    if(verifica_salto(instrucciones[i]) && (pos > -1) && i != pos_etiqueta){
      std::cout << "asocio "<< instrucciones[i]<< "con "<<etiqueta <<"\n";
      grafo.aniadir_arista(instrucciones[i],instrucciones[pos_etiqueta]);
    }
  }
}

void asociar_segun_instruccion(Grafo& grafo,std::vector<std::string> instrucciones,int pos_instruccion){
  int tipo_instruccion = parsear_linea(instrucciones[pos_instruccion]);
  if (tipo_instruccion == COMUN && (instrucciones.size() > pos_instruccion)){
    std::cout << "agrego comun" << "\n";
    grafo.aniadir_arista(instrucciones[pos_instruccion],instrucciones[pos_instruccion + 1]);
  }else if (tipo_instruccion == SALTO_CON_UNA_ETIQUETA){
    grafo.aniadir_arista(instrucciones[pos_instruccion],instrucciones[pos_instruccion + 1]);
  }
  if(verifica_etiqueta(instrucciones[pos_instruccion])){
    asociar_etiquetas(instrucciones,grafo,pos_instruccion);
  }

}

Grafo Parser::crear_grafo(const std::vector<std::string>instrucciones) const{
  Grafo grafo = Grafo();
  int cantidad_instrucciones = instrucciones.size();
  for (int i = 0; i < cantidad_instrucciones; i++){
    if(verifica_etiqueta(instrucciones[i])){
      grafo.aniadir_nodo(instrucciones[i],true);
    }else{
      grafo.aniadir_nodo(instrucciones[i],false);
    }
  }
  for (int j = 0; j < cantidad_instrucciones; j++){
    asociar_segun_instruccion(grafo,instrucciones,j);
  }

  return grafo;
}

Grafo Parser::run() const{
  std::ifstream fs;
  int instruccion_actual,instruccion_anterior = -1;
  fs.open(this->archivo);
  std::vector<std::string> instrucciones;
  if(fs){
    std::string linea;
    while (std::getline(fs,linea,'\n')){
      if(linea.size() != 0){
        instrucciones.push_back(linea);
      }
    }
  fs.close();
}
  Grafo grafo = std::move(this->crear_grafo(instrucciones));


  return grafo;
}
