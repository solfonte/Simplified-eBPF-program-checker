#include <fstream>
#include <iostream>
#include <vector>
//void open (const string& filename,ios_base::openmode mode = ios_base::in | ios_base::out);


bool verifica_etiqueta(std::string linea){
  ssize_t pos_dos_puntos(linea.find(":"));
  if(pos_dos_puntos < -1){
    return true;
  }
  return false;
}

bool verifica_return(std::string linea){
  ssize_t pos_return(linea.find("ret"));
  if(pos_return > -1){
    return true;
  }
  return false;
}
bool verifica_salto(std::string linea){
  std::vector<std::string> saltos = {"jmp","ja","jeq","jneq","jne","jlt","jgt","jge","jset"};
  bool hay_salto = false;
  for (int i = 0; i < 9; i++){//capaz cambiar a while
    ssize_t pos_salto(linea.find(saltos[i]));
    if(pos_salto > -1){
      hay_salto = true;
    }
  }
  return hay_salto;
}

void parsear_linea(std::string linea){//podria devolver un nodo
  ssize_t pos_return(linea.find("ret"));

    if (verifica_etiqueta(linea)){
      std::cout << "soy una etiqueta" << "\n";
    }
    if (verifica_return(linea)){
      std::cout << "soy un return" << "\n";
    }else if (verifica_salto(linea)){
      std::cout << "soy un return" << "\n";
    }else{
      std::cout << "soy comun" << "\n";
    }
}


int main(int argc, char const *argv[]) {
//hay que usar cin?
  std::ifstream fs;
  if(argc < 3){
    std::cout << " faltan argumentos " << '\n';
    return 0;
  }
  fs.open(argv[2]);
  if(fs){
    std::string etiqueta,instruccion,dosPuntos(":"),argumento1,linea;
    char salto;
    while (std::getline(fs,linea,'\n')){
      if(linea.size() != 0){
        std::cout << linea << '\n';
        parsear_linea(linea);
      }

  }
  fs.close();
  return 0;
}
}
