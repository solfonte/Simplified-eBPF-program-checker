# TP2-taller

**Descripcion general del trabajo realizado**  
Para el desarrollo del trabajo practico se implementaron distintas clases con el fin de encapsular los distintos comportamientos. Se implemento la clase grafo, junto con el metodo de busqueda DFS, la logica del parseo de las instrucciones del programa, entre otras. Para cada hilo creado, en funcion de la cantidad de hilos pedidos por el usuario, cada hilo pide un archivo, este se parsea, se inicializa un grafo y luego un detector verifica si hay problemas con el programa procesado, mostrando por pantalla los resultados de cada hilo. 

**Parseo de instrucciones**
Las instrucciones primero se leen, se agregan al grafo, y una vez hecho esto se relacionan entre si segun cada tipo de instruccion. El tipo de instruccion y la condicion de etiqueta se tratan como casos separados. 

**Disenio del grafo**  
El grafo se implemento como una lista de adyacencia y cada nodo contiene su orden topologico el cual se les asigna al insertarlos dentro del grafo en orden. Se utiliza el orden topologico para la busqueda de ciclos dentro del programa. Si un nodo dentro del grafo, ya fue visitado durante el recorrido DFS y su orden topologico es mayor que uno de sus adyacentes, entonces estamos ante un ciclo.  

**Diagrama de clases**  
