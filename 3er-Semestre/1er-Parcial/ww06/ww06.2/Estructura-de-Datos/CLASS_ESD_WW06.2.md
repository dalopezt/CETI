# Notas de Estructura de Datos (01), Feb 6 2023 
Por David Alejandro López Torres.
## Resumen
- Plática breve con relación al curso
- Repaso breve kde estrucras de datos vistas en POO.
- Explicación de tipos genéricos.

## Notas
Es posible indicar tipos de datos genéricos como atributos de una clase, permitiendo así abstraer el comportamiento de una clase independientemente del tipo de dato con el que va a operar. Para hacer esto en ```C++``` se sigue de la siguiente forma:
```cpp
template<class T>
class ClassName 
{
    T t;
};
```
En el ejemplo anterior se indica que el atributo ```t``` de la clase ```ClassName``` será de un tipo cualquiera ```T```, el cual debe de ser indicado al momento de instanciar la clase de la siguiente forma:
```cpp
ClassName<int> obj;
```
Entre las ```<>``` debe de indicarse el tipo de dato con el que se trabajará, en este caso ```int```. Este recurso es de suma ayuda para generar estructuras de datos que sean utilizables para diferentes tipos de datos.

## Ejercicios de clase
Durante la clase se dejaron dos ejercicios para realizarse de tarea:
### 1. Cuadro que gira (repaso de coding)
Se debe de realizar un programa que imprima en consola un cuadrado de dimensiones ```n x m``` (hardcodeadas en ```main```) con el carácter ```*```. La opción de si está relleno o no también debe estar hardcodeada en ```main```. Dicho cuadrado, además, debe de moverse en la consola produciendo una pequeña animación. Debe de realizarse con al menos dos clases (una para el cuadrado y otra para cada punto del cuadrado). El lenguaje es libre. 

*Encontrar Anexo en CODE_01*
### 2. Lista enlazada simple con nodos genéricos
Se debe de realizar un programa en ```C++``` para implementar una lista enlazada simple formada por nodos cuyo valor debe de ser de tipo genérico (como lo visto en clase).

*Encontrar Anexo en CODE_02*
