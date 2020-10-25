#include <cstdio>
#define TAMANIO_INSTRUCCION 20

int verificar_etiqueta(char* instruccion, int tamanio){
  int i = 0;
  int posicion_a_parsear = 0;
  int termine = false, es_etiqueta = false;
  while (i < tamanio && !termine){
    if (instruccion[i] == ':'){
      es_etiqueta = true;
    } else if (es_etiqueta && instruccion[i] != ' '){
      posicion_a_parsear = i;
    }
  }
  return posicion_a_parsear;
}

bool verificar_instruccion_jump(char* instruccion, int tamanio,int posicion_a_parsear){
  int i = 0;
  bool verifique = false;
  char* aux_instruccion = instruccion + posicion_a_parsear;
  char instrucciones_jump = {"jmp","ja","jeq","jneq","jne","jlt","jgt","jge","jset"};
  while(i < 9 && !verifique){
    if(strstr(aux_instruccion,instrucciones_jump[i]) != NULL){
      verifique = true;
    }
  }
  i++;
  return verifique;
}

bool verificar_instruccion_ret(char* buffer,int leido,int posicion_a_parsear){
  int i = 0;
  bool verifique = false;
  char* aux_instruccion = instruccion + posicion_a_parsear;
  if(strstr("ret",instrucciones_jump[i]) != NULL){
    return true;
  }
  return false;
}

void parsear_archivo(const char* nombre_archivo){
  FILE* file = fopen(nombre_archivo,"r");
  if (file == NULL){
    /*devolver error capaz*/
    return;
  }
  char buffer[TAMANIO_INSTRUCCION];
  while(!feof(file)){
    int leido = fscanf(file,"[^\n]\n",buffer);//tengno que tener en cuenta las tabulaciones?
    int posicion_a_parsear = verificar_etiqueta(buffer,leido);
    if (verificar_instruccion_jump(buffer,leido, posicion_a_parsear)){
      printf("soy una instruccion de salto\n");
      /*van con dos aristas*/
    }else if (verificar_instruccion_ret(buffer,leido,posicion_a_parsear)){
      printf("soy una instruccion ret\n");
      /*van sin arista*/
    }else{
      printf("soy una instruccion comun\n");
      /*solo son nodos y tener en cuenta la posicion a parsear*/
    }
  }
}

int main(int argc, char const *argv[]) {
  /*
  a partir de argv[2] me llegan nombres de archivos;
  */

  for(int i = 2; i < argc; i++){
    parsear_archivo(argv[i]);
  }
  return 0;
}
