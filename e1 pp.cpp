// PARTE 1 PROGRAMA 1
//MIGUEL ANGEL OCAMPO PORCAYO
//BOLETA 2021301170
//PARADIGMAS DE PROGRAMACION


#include <stdio.h> //directiva de salida y entraba standar
#include <malloc.h>//directiva que tiene manejo de memeoria

//se declara un registro llamado nodo
struct nodo
{
//se declara un enetero en el registro llamado elem
   int elem;
//se declara en el registro un aountador a registro llamado sig
   struct nodo * sig;
};
//asigmanos un alios para  desde ahora llamar a nuestro apuntador a registro como STACK
typedef struct nodo * STACK;
//declaro una funcion que nos va a devolver un entero y nos dira si la pila esta vacia
int isemptystack(STACK pili)
{
//si se cumple la condicion de que el apuntador esta vacio devolvera un 1 lo cual nosindica que si esta vacia la pila
//de lo contrario nos ha de devolver un 0 ya que hay mas enlaces en la pila y por lo tanot no esta vacia
   return(pili -> sig == NULL);
}

//declafro una funcion que devuelve un apuntador y nos va a permitir crear una nueva pila
STACK newstack()
{
	//declaro un apuntador a registro llamado ancla
   STACK ancla;
   //reservo espacio para un apuntador a registro, uso el casting para forzar la conversion a apuntador de registro
   //despues con malloc pido se reserve la memoria del taaño que nos devuelva el calculador de tamaño de un registro
   ancla =(struct nodo *) malloc(sizeof(struct nodo));
   //si ancla es nula o en otras palabras, no tiene nada de nada esque poco probable
   if(ancla == NULL)
   //decimos que la memoria esta llena
      puts("Problema grave en pila nueva. Memoria agotada.");
   else
   //sino cerramos el apuntador siguiente de nuetsro nodo apuntado por ancla
      ancla -> sig = NULL;
	//y retornamos el apuntador para que sea guardado en el main 
   return(ancla);
}

//declaramos una funcion que elimina el elemento que esta en el tope de la pila nos devuelve un puntero 
//nos pide como argumento el apuntador a la pila
STACK pop(STACK pili)
{

   //el tope de la pila ahora sera el tope del tope, es decir el tope sera el siguinete nodo, lo que elimina el tope actual
      pili = pili -> sig;
    //retornamos la pila para cualquier uso
   return(pili);
   
}
//declaramos  una funcion llamada push la cual agregara un valor a la pila
//pide como parametros, la pila, y el valor entero a agregar
STACK push(STACK pili, int val)
{
	//declaramos un apuntador a pila llamado agrega
   STACK agrega;
   //reservamos el espacio que ocupa un nodo usando malloc y lo calculamos con sizeof, usando el casting forzamos la conversion a 
   //apuntador, y lo guardamos en nuestro apuntador
   agrega =(struct nodo *) malloc(sizeof(struct nodo));
   //es poco probable que pase pero si se acaba la memoria mandara mensaje de error
   if(agrega == NULL)
   {
      puts("Problema grave en push. Memoria agotada.");
      return(pili);
   }
   //nuestro elemento lo guardaremos en la pila que creamos 
   agrega -> elem = val;
   //agrega y pili  apuntan al mismo lugar  (pili sig) para poder hacer la insercion sin perder la memoria
   agrega -> sig = pili -> sig;
   //finalmente pili sig apuntara a agrega, de esta forma se termina de insertar el valor en el tope de la pila
   //pili sig apunta a agrega y agrega apunta a lo que era el anterior pili sig.
   pili -> sig = agrega;
   //retornamos la pila
   return(pili);
}

//declaramos una funcion llamada min la cual nos mostrara el valor minimo de la pila
void min(STACK pila)
{
	if (pila==NULL) //si la pila esta vacia
		printf("la pila esta vacia ");//imprimimos que esta vacia
		//de lo contrario
	else
	{
		//declaramos un numero que sera igual al elemento del tope de la pila
		int minimo = pila -> elem;
		//mientras la pila no sea nula
		while (pila != NULL)
		 {
		 	//si el elemento de la pila es menor que el minimo
	        if (pila->elem < minimo) 
			{
				//minimo sera ahora ese valor que tiene el tope acutal de la pila
	            minimo = pila->elem;
	        }
	        //pop a la pila 
	        pila = pila->sig;
    	}	
    	//mostramos el elemento que nos queda del bucle que tiene que ser el menor
		printf("elemento menor = %d ",minimo)	;
	}
}
//funcion principal
int main()
{
	//declaramos una pila mediante un apuntador a estructura
   STACK pila;
   //declaramos variables de uso comun
   int n,nn;
   //abrimos una nueva pila
   pila=newstack();
   //preguntamos cuantos numeros seran  y lo guardamos en n
   puts("cuantos numeros seran?");
   scanf("%d",&n);
   //hacemos un ciclo que se repetira n veces para hacer push a la pila
   for(int i=0; i<n; i++)
   {
   	//pedimos los numeros para pusharlos en la pila
   	printf("numero %d : ",i+1);
   	scanf("%d",&nn);
   	push(pila,nn);
   }
   //ejecutamos la funcion que nos dira el elemento menor de la pila
   min(pila);
}

