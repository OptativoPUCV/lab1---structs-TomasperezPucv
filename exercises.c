#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
//#include "exercises.h"

//ejercicios de punteros y arreglos

/*
Ejercicio 1.
Programe la función void swap(int *a, int *b), la cual
intercambia los valores de las variables apuntadas por a y b.
*/
void swap(int *a, int *b) {
  int aux= *a;
  *a= *b;
  *b= aux;
  

}

/*
Ejercicio 2.
Programe la función void arrayMaxMin(int *a, int n, int *max, int *min),
la cual encuentra el máximo y el mínimo valor del arreglo a y los
almacena en las variables apuntadas por max y min.
*/
int cmp (const void *pivote, const void *element)
{
  int *ptrpivote = (int*)pivote;
  int *ptrelemen = (int*)element;

  if(*ptrpivote > *ptrelemen)
  {
    return 1;
  }
  return 0;
}

void arrayMaxMin(int *a, int n, int *max, int *min) {
  qsort(a,n,sizeof(int),cmp);
  *min=a[0];
  *max=a[n-1];
}


/*
Ejercicio 3.
Considerando la estructura Persona, programe la función
crearPersona(...), la cual crea una nueva persona con 
los datos ingresados como parámetros y retorna un puntero 
al dato recién creado.
*/
typedef struct {
  char nombre[30];
  char rut[11];
  int edad;
} Persona;


Persona* crearPersona(char nombre[], char rut[], int edad) {
   Persona * p = (Persona *) malloc(sizeof(Persona));
   //asignar valores de entrada a los campos de p
  strcpy(p->nombre,nombre);
  strcpy(p->rut, rut);
  p-> edad= edad;

   return p;
}

/*
Ejercicio 4.
Considerando la estructura "Vector", escriba 
la función Vector* crearVector(int n), la cual crea 
un vector con capacidad `n`, reserva la memoria 
correspondiente para el arreglo con `n` datos 
inicializados en 0 y luego retorna el vector creado.
*/
typedef struct {
   int *datos; // arreglo dinámico
   int capacidad; // capacidad del arreglo
} Vector;

Vector * crearVector(int n) {
  Vector *v = (Vector*)malloc(sizeof(Vector));
  
  if(v==NULL) exit(1);
  v-> datos= (int*)calloc(n,sizeof(int));
  v->capacidad=n;
  return v;
}

/*
Ejercicio 5a.
Programe la función void asignarValor(Vector * v, int i, int valor), 
la cual asigna el valor a la posición i del vector v.
*/
void asignarValor(Vector * v, int i, int valor) {
  v->datos[i] = valor;
}

/*
Ejercicio 6.
Programe la función int obtenerValor(Vector * v, int i), 
la cual retorna el valor en la posición i del vector v.
*/
int obtenerValor(Vector * v, int i) {
  
   return v->datos[i];
}

/*
Ejercicio 7.
Función que suma los vectores `a` y `b` y 
actualiza el vector `c` con el resultado de la suma.
*/
void sumaV(Vector * a, Vector * b, Vector * c) {
  for(int i=0; i<c->capacidad; i++)
    {
      c->datos[i]= a->datos[i]+ b->datos[i]; 
    }
}

/*
Ejercicio 8.
Use las operaciones implementadas de vectores para 
sumar (a1,a2)+(b1,b2). Almacene el resultado en el vector c.
*/
void sumaV2(int a1, int a2, int b1, int b2, Vector *c){
  Vector *a =crearVector(2);
  
  asignarValor(a, 0 , a1);
  asignarValor(a, 1 , a2);
  Vector *b =crearVector(2);
  
  asignarValor(b, 0 , b1);
  asignarValor(b, 1 , b2);
  sumaV(a , b ,c);
}
