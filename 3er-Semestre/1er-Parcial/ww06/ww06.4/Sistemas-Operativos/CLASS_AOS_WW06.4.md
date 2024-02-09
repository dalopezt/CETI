# Notas de Arquitectura de Sistemas Operativos (02), Feb 7 2023 
Por David Alejandro López Torres.

## Resumen
- Definiciones básicas de sistemas operativos. 

## Notas
Un **Sistema Operativo** (SO) es el encargado de gestionar el software y el hardware de una compitadora, todos los demás programas forman parte del Software y se conocen como **aplicaciones**. La función principal del sistema operativo es proporcionar herramientas para poder controlar la copmputadora y poder hacer uso de ella de la forma más cómoda y sencilla posible, permitiendo la comunicación entre el usuario y el equipo. Las funciones básicas del sistema operativo son:
- Administrar recursos.
- Coordinar el hardware.
- Organizar archivos y directorios en los dispositivos de almacenamiento. 

Con esto, un S.O. puede dividirse en partes:
- Manejo de Procesos.
- Manejo de Memoria.
- Manejo de Archivo.
- Manejo de Dispositivos de I/O.
- Manejo de Redes.
- Intérprete de Comandos.

### Tipos de Sistemas Operativos
**En función a la administración de tareas**
- Sistemas Operativos Monotarea.
- Sistemas Operativos Multitarea.

**En función de la administración de usuarios**
- Sistema Monousuario.
- Sistema Multiusuario.

### Sistemas Operativos por lotes
Los sistemas operativos por lotes procesan una gran cantidad de trabajos con poca o ninguna interacción entre los usuarios y los programas en ejecución. 

### Sistemas Operativos en tiempo real
Son aquellos en donde no tiene importancia el usuario, sino los procesos. Son construidos para aplicaciones muy específicas que cambian rápidamente (muy poco tiempo de respuesta).

### Sistemas Operativos en tiempo compartido
Permiten la simulación de que el sistema y sus recursos son todos para cada usuario. El usuario hace una petición a la computadora, esta la procesa tan pronto como le es posible, y la respuesta aparecerá en la terminal del usuario.

### Sistemas Operativos distribuidos
Es una colección de procesadores conectados en red, la cual es imprescindible para su funcionamiento. Estos procesadores no comparten memoria entre sí, en lugar de eso, cada procesador tiene su propia memoria local.