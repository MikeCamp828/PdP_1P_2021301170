// PARTE 1 PROGRAMA 1
//MIGUEL ANGEL OCAMPO PORCAYO
//BOLETA 2021301170
//PARADIGMAS DE PROGRAMACION


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Definición de la estructura de un nodo de la pila
typedef struct Node {
    int data; //valor entero llamado data
    struct Node* next; //creamos un apuntador a registro llamado next
} Node; //lamamos el alias de nuestro nodo

// Definición de la estructura de la pila
typedef struct Stack {
    Node* top; //creamos un apuntador a nodo llamado top
} Stack; //llamamos al alias de la pila como Stack

// Inicializa una pila vacía
Stack* createStack() { //nos devuelve un auntador a pila
    Stack* stack = (Stack*)malloc(sizeof(Stack));//creamos un apuntador a pila llamado stack el cual guarda espacio para un registro Stack
    stack->top = NULL; //sellamos el apontador a otro nodo llamado top 
    return stack; //retornamos el apuntador a pila
}

// Comprueba si la pila está vacía
bool isEmpty(Stack* stack) { //Usando un retorno booleano nos daremos cuenta si la pila esta vacia
//ppide como parametro un apuntador a pila
    return stack->top == NULL; //si el nodo siguiente de la pila es nulo entonces la pila esta vacia y devolvera true de lo contrario
    //devolvera un false
}

// Crea un nuevo nodo con el valor dado
Node* createNode(int data) { //nos devolvera un apuntador a nodo y nos pedira el dato del mismo
    Node* newNode = (Node*)malloc(sizeof(Node)); //creamos un apuntador que se llamara newNode y le asignamos su espacio con malloc
    newNode->data = data; // el dato del nuevo nodo que hicimos se lo asignamos de el valor de parametro data
    newNode->next = NULL; //sellamos el valor siguiente del nuevo nodo
    return newNode; //retornamos el valor del nuevo nodo creado
}

// Agrega un elemento a la parte superior de la pila (push)
void push(Stack* stack, int data) { //no devuelve nada y pide de parametros  un apuntador a pila y un dato entero
    Node* newNode = createNode(data); //creamos un nuevo nodo para ahorrar codigo usamos la funcion anterior y le damos su valor
    newNode->next = stack->top; //hacemos el el valor donde apuntara new node sea el mismo al que apunta el siguiente de la lista
    stack->top = newNode; //el suiguente de la pila sera ahora apuntado a newNode con eso se hace la insercion de forma exitosa
}

// Elimina y devuelve el elemento en la parte superior de la pila (pop)
int pop(Stack* stack) { //lafuncion pop nos pedira el apuntador a pila como parametro y nos devolvera un valor entero
    if (isEmpty(stack)) { //si la pila esta vacia nos mandara mensaje y nos mandara un codigo de error
        printf("La pila está vacía.\n");
        return -1;
    }
    Node* temp = stack->top; //declaramos una variale auxiliar tipo apuntador a nodo el cual apuntara a el tope de la pila
    int data = temp->data;//declaramos una variable tipo entera que contendra el valor del tope de la pila
    stack->top = temp->next; //para eliminar el tope decimos que el apuntador a nodo de la pila sera ahora el next del apuntador al nodo de la pila
    //de esta forma al acabar la funcion, temp se eliminara y el tope de la pila se habra recorrido al penultimo
    free(temp); //borramos el espacio reservado por temp
    return data; //devolvemos el dato
}

// Devuelve el elemento en la parte superior de la pila sin eliminarlo 
int Top(Stack* stack) { //funcion que nos pide una pila como argumento y nos retornara un valor
    if (isEmpty(stack)) { //si la pila esta vacia nos devolvera un valor de error
        printf("La pila está vacía.\n");
        return -1;
    }
    //de lo contrario nos devolvera el valor del ultimo nodo en la pila sin borrarlo
    return stack->top->data;
}

// Ordena la pila de manera que los elementos más pequeños estén en la parte superior
void sortStack(Stack* stack) { //nos pide como argumento un apuntador a pila
    Stack* auxStack = createStack(); //creamos unapuntador a pila que mediente la funcion de crear pila sera nuestra pila auxiliar
//mientras no este vacia la pila
    while (!isEmpty(stack)) {
    	//guardamos el ultimo valor en la pila en temp y le hacemos pop a la pila
        int temp = pop(stack);
        //mientras la pila auxiliar no este vacia y el valor del tope de la pila axiliar sea mayor que el valor que
        //el valor al que le hicimos pop anteriormente 
        while (!isEmpty(auxStack) && Top(auxStack) > temp) {
        	//le agregamos a la pila principal lo que devuelva un pop de la pila auxiliar de esta forma podremos 
        	//asegurarnos que el el valor se ordenara, usando una especie de algoritmo burbuja aplicado a las pilas
            push(stack, pop(auxStack));
        }
        //ahora se le vuleve agregar a la pila auxiliar el valor del temp eliminado de la pila principal 
        //para que a volver en el while se vayan agregando valores solamente ordenados a la misma
        push(auxStack, temp);
    }

    // Copia los elementos ordenados desde la pila auxiliar a la pila original
    while (!isEmpty(auxStack)) { //mientras la pila no este vacia
        push(stack, pop(auxStack)); //devolveremos mediante push todos los valores a la pila principal y mientras borraremos la pila 
        //auxiliar
    }

    free(auxStack); //finalmente liberamos el espacio de la pila auxiliar mediente la fincion free
}

// Imprime el contenido de la pila
void peek(Stack* stack) {//la pila nos solicita como parametro un apuntador a pila y no retorna nada
    if (isEmpty(stack)) {//condicional donde si la pila esta vacia
        printf("La pila está vacía.\n");//mandar un mesaje en la pantalla que diga que la pila esta vacia
        return; //cierra la ejecucion de la funcion ya que no se puede continuar
    }
    Node* current = stack->top; //se declara un apuntador a nodo que se llama current que se le asignara el nodo de a pila principal
    printf("Contenido de la pila: ");//imprimir en pantalla el contenido de la pila
    while (current != NULL) { //bucle de mientras el apuntador a nodo current sea diferente de vacio
        printf("%d ", current->data); //imprimimos en pantalla la data del nodo copia de esta forma la pila principal no se altera
        current = current->next; //recorremos el contenido de la pila al asignar la nueva direecion del apuntador a la siguiente
    }
    printf("\n"); //imprimimos un salto de linea 
}

// Ejemplo de uso del programa
int main() {//comenzamos la funcion principal
    Stack* stack = createStack(); //creamos un apuntador a pila que sera nuestra pila y le asignamos la pila que cree la funcion de creacion de pilas
//declaramos variables de uso comun
	int n,nn;
	//preguntamos cuantos numeros seran  y lo guardamos en n
   puts("cuantos numeros seran?");
   scanf("%d",&n);
   
//hacemos un ciclo que se repetira n veces para hacer push a la pila
   for(int i=0; i<n; i++)
   {
   	//pedimos los numeros para pusharlos en la pila
   	printf("numero %d : ",i+1); // imprime en panalla el numero  enecimmo que se va a escribir
   	scanf("%d",&nn);//guarda el numeor en la variable de uso nn
   	push(stack,nn); //introduce a la pila stack la variable leida
   }

    printf("Pila original:\n");//imprimimos en pantalla la pila principal
    peek(stack);//usando peek mostramos el contenido de la pila

    sortStack(stack);//usamos la funcion sortStacl para ordenar la pila mandandola como argumento

    printf("Pila ordenada:\n");//imprimimos la pila ordenada
    peek(stack);//mostramos el contenido de la pila ordenada mediente peek y le mandamos como argumento la pila stack

    return 0;//cerramos el prograa de manera exitosa
}
