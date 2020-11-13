#include "parser.h"
#include <iostream>
#include <utility>
#include <sstream>

Parser::Parser(const std::string& nombre_archivo){
  this->archivo = nombre_archivo;
}

Parser::~Parser(){
}

static bool verifica_etiqueta(const std::string& linea){
  ssize_t pos_dos_puntos(linea.find(":"));
  if (pos_dos_puntos > -1){
    return true;
  }
  return false;
}

static bool verifica_return(const std::string& linea){
  ssize_t pos_return(linea.find("ret"));
  if (pos_return > -1){
    return true;
  }
  return false;
}

static int contar_comas(const std::string& linea){
  int comas = 0;
  std::string aux(linea);
  int pos = 0;
  while (pos != -1){
    pos = aux.find(',');
    comas += (pos > -1? 1 : 0);
    aux.erase(0,pos + 1);
  }
  return comas;
}

static int verifica_salto(const std::string& linea){
  std::vector<std::string> saltos = {"jmp","ja","jeq","jneq","jne",
                                      "jlt","jgt","jge","jset"};
  bool hay_salto = false;
  int cantidad_comas = 0, retorno = 0;
  for (int i = 0; i < 9; i++){
    ssize_t pos_salto(linea.find(saltos[i]));
    if (pos_salto > -1){
      hay_salto = true;
    }
  }
  if (hay_salto){
    cantidad_comas = contar_comas(linea);
  }
  if (hay_salto && cantidad_comas == 0){
    retorno = SALTO_A_ETIQUETA;
  }else if (cantidad_comas == 1){
    retorno = SALTO_CON_UNA_ETIQUETA;
  }else if (cantidad_comas == 2){
    retorno = SALTO_CON_DOS_ETIQUETAS;
  }else{
    retorno = NO_HAY_SALTO;
  }

  return retorno;
}

static int parsear_linea(const std::string& linea){
  std::istringstream iss(linea);
	std::string tag, instruction, arg1, arg2;
  if (linea.find(':') != std::string::npos) {
  		std::getline(iss, tag, ':');
  	}
  	iss >> instruction;
  	iss >> arg1;
  	iss >> arg2;

  int tipo_salto = verifica_salto(linea);
    if (verifica_return(linea)){
      return RETURN;
    }else if (tipo_salto == SALTO_CON_UNA_ETIQUETA ||
      tipo_salto == SALTO_CON_UNA_ETIQUETA ||
      tipo_salto == SALTO_A_ETIQUETA){
      return tipo_salto;
    }else{
      return COMUN;
    }
}

static bool salta_a_etiqueta(std::string& instruccion,std::string& etiqueta){
  int pos = instruccion.find(etiqueta);
  if (pos == -1){
    return false;
  }
  std::string posible_etiqueta1 = instruccion.substr
                                  (pos,instruccion.size()-1);
  std::string posible_etiqueta2 = etiqueta + ',';
  int pos2 = instruccion.find(posible_etiqueta2);
  return (etiqueta == posible_etiqueta1 || pos2 > -1);
}

static void asociar_etiquetas(std::vector<std::string> instrucciones,
                      Grafo& grafo, int pos_etiqueta){
  std::string aux(instrucciones[pos_etiqueta]);
  int pos = aux.find(":");
  std::string etiqueta = aux.substr(0,pos);
  int cantidad_de_instrucciones = instrucciones.size();
  for (int i = 0; i <cantidad_de_instrucciones; i++){
    if (verifica_salto(instrucciones[i]) &&
      salta_a_etiqueta(instrucciones[i],etiqueta)&& i != pos_etiqueta){
        grafo.aniadir_arista(i,pos_etiqueta);
    }
  }
}

static void asociar_segun_instruccion(Grafo& grafo,
                                std::vector<std::string> instrucciones,
                                int pos_instruccion){
  int tipo_instruccion = parsear_linea(instrucciones[pos_instruccion]);
  int cantidad_inst = instrucciones.size();

  if (tipo_instruccion == COMUN && pos_instruccion < (cantidad_inst - 1)){
    grafo.aniadir_arista(pos_instruccion,pos_instruccion + 1);
  }else if (tipo_instruccion == SALTO_CON_UNA_ETIQUETA &&
            pos_instruccion < (cantidad_inst - 1)){
    grafo.aniadir_arista(pos_instruccion,pos_instruccion + 1);
  }
  if (verifica_etiqueta(instrucciones[pos_instruccion])){
    asociar_etiquetas(instrucciones,grafo,pos_instruccion);
  }
}

static void inicializar_grafo(Grafo& grafo,
                        const std::vector<std::string>& instrucciones){
  int cantidad_instrucciones = instrucciones.size();
  for (int i = 0; i < cantidad_instrucciones; i++){
    grafo.aniadir_nodo(instrucciones[i]);
  }
  for (int j = 0; j < cantidad_instrucciones; j++){
    asociar_segun_instruccion(grafo,instrucciones,j);
  }
}

bool Parser::run(Grafo& grafo) const{
  std::ifstream fs;
  fs.open(this->archivo);
  bool pude_abrir_archivo = 0;
  std::vector<std::string> instrucciones;
  if (fs){
    pude_abrir_archivo = true;
    std::string linea;
    while (std::getline(fs,linea,'\n')){
      if (linea.size() != 0){
        instrucciones.push_back(linea);
      }
    }
  fs.close();
}
  inicializar_grafo(grafo,instrucciones);
  return pude_abrir_archivo;
}
