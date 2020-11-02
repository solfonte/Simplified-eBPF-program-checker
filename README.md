# TP2-taller

**Descripcion general del trabajo realizado**  
Para el desarrollo del trabajo practico se implementaron distintas clases con el fin de encapsular los distintos comportamientos. Se implemento la clase grafo, junto con el metodo de busqueda DFS, la logica del parseo de las instrucciones del programa, entre otras. Para cada hilo creado, en funcion de la cantidad de hilos pedidos por el usuario, cada hilo pide un archivo, este se parsea, se inicializa un grafo y luego un detector verifica si hay problemas con el programa procesado, mostrando por pantalla los resultados de cada hilo.

**Parseo de instrucciones**
Las instrucciones primero se leen, se agregan al grafo, y una vez hecho esto se relacionan entre si segun cada tipo de instruccion. El tipo de instruccion y la condicion de etiqueta se tratan como casos separados.

**Disenio del grafo**  
El grafo se implemento como una lista de adyacencia y cada nodo contiene su orden topologico el cual se les asigna al insertarlos dentro del grafo en orden. Se utiliza el orden topologico para la busqueda de ciclos dentro del programa. Si un nodo dentro del grafo, ya fue visitado durante el recorrido DFS y su orden topologico es mayor que uno de sus adyacentes, entonces estamos ante un ciclo.  

**Deteccion de ciclos e instrucciones sin usar**
Tanto para la deteccion de ciclos y la deteccion de instrucciones sin utilizar se usa el recorrido DFS. Este recorre los nodos partiendo desde el nodo origen, o sea, el nodo que se aniadio primero. Se parte de este nodo ya que es la primer instruccion del programa y se sabe que por la naturaleza de los programas, la primer instruccion que se ejecuta es la primera de todo el programa. Sabiendo esto, partimos entonces de esta intruccion y dentro del recorrido de DFS se marcan como visitados los nodos que contienen instrucciones que se podrian ejecutar. Previamente se menciono la deteccion de ciclos, pero para la deteccion de instrucciones sin utilizar solo basta con verificar cuales instrucciones no fueron visitadas durante el recorrido DFS. 

**objetos compartidos**  
Se implemento una clase contenedora de datos, la cual se instancia para guardar los archivos y para guardar los resultados, debido a que no habia una diferencia significativa en cuanto al comportamiento del objeto que contiene los archivos y el que contiene los resultados, y se decidio generalizar el comportamiento para poder crear la clase que sirve tanto para un objeto como para otro.  

**Diagrama de clases**  
