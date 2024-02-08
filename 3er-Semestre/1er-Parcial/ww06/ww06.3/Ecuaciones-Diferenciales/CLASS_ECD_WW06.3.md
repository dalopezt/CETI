# Notas de Ecuaciones Diferenciales (02), Feb 7 2023 
Por David Alejandro López Torres

## Resumen
- Ponderaciones
- Antecedentes: Derivadas e integrales
- Definiciones: Ecuación diferencial, Orden, Grado y Tipo
- Introducción al tema 1: Ecuaciones diferenciales en variables separables

## Notas
### Ponderaciones
| Rubro | Puntaje | 
| - | - |
| Examen presencial | 30 |
| Examen en linea [1] | 30 |
| Particiación, tareas, proyectos, entre otros | 40 |
| Trabajo adicional [2] | 20 |

[1] *Una semana antes de presentar el examen escrito se dará la liga en plataforma*.

[2] *Solo aplica en los primeros dos parciales. Consta de una actividad asiganda en un día sin aviso previo. Solo justificable por causas de fuerza mayor*.

### Anetecedentes
Como parte de los antecedentes, es necesario dominar todos los procesos y técnicas para derivar e integrar funciones. Se vieron algunos ejemplos como:

> **[Ejemplo 1]** Deriva: $y = e^{3x}\left(sin\left(4x\right)\right)^3\\$<br> **[Solución 1]**<br>$y' = 3e^{3x}\left(sin\left(4x\right)\right)^3 + 12e^{3x}\left(sin\left(4x\right)\right)^2\left(cos\left(4x\right)\right)$

> **[Ejemplo 2]** Integra: $\int{3x\sqrt{4x^2 + 7} dx}\\$<br> **[Solución 2]**<br> $\frac{1}{4}\left(4x^2 + 7\right)^{\frac{3}{2}} + C$

### Definiciones
Una **ecuación diferencial** es una ecuación que contiene derivadas o diferenciales. El **orden** de una ecuación diferencial es la derivada más alta (de orden mayor) que tenga la ecuación diferencial. El **grado** de una ecuación diferencial es el exponente al cual está elavado el término con la derivada más alta. El tipo de una ecuación diferencial puede ser *ordinal* (una función de una variable expresada en diferenciales totales), o *parcial* (una función de varias variables expresada en derivadas parciales). 

Algunos ejemplos vistos:
> **[Ejemplo 3]** Identifica Orden, Grado y Tipo de la Ecuación Diferencial: $x^2y'' + xy' + y = 0\\$<br> **[Solución 3]**<br> Orden 2, Grado 1, Ordinal.

> **[Ejemplo 4]** Identifica Orden, Grado y Tipo de la Ecuación Diferencial: $yy' + x = \sqrt{1 + y'}\\$<br> **[Solución 4]**<br> $(yy' + x)^2 = 1 + y' \\ y^2(y')^2 + 2xyy' + x^2 = 1 + y'\\$<br>Orden 1, Grado 2, Ordinal.

Las **soluciones** de una ecuación diferencial son las funciones que cumplen con la expresión, pueden ser **generales** (con constantes arbitrarias indicadas) o **particulares** (utilizando valores iniciales para determinar el valor de esas constantes); además la solución puede indicarse de **forma explítica**, esto es presentar la forma de $y(x)$, o bien de **forma impícita**, que sería dejar una expresión algebraica que ya no contenga derivadas que establezca la relaión entre las variables.

Para comprobar si una función es parte del conjunto solución de la ecuaciómn diferencial basta con sustituir en la expresión original y verificar que la igualdad se mantenga.
> **[Ejemplo 5]** Muestra que $y(x) = ce^x$ es solución de la ecuación diferencial:<br> $y' - y = 0\\$<br> **[Solución 5]**<br> $y = ce^x \implies y' = ce^x \implies y' - y = ce^x - ce^x = 0$<br>Mostrando así que es una solución.

### Tema 1: Ecuaciones diferenciales en variables seprables
Una ecuación diferencial está en variables separables cuando es posible llevarla mediante pura manipulación algebraica a la forma:

$n(y)dy = m(x)dx$

Con $m(x), n(y)$ funciones de sus variables indicadas. Una vez llevada a esta forma, basta con integrar ambos lados de la igualdad para encontrar la solución implícita de la ecuación diferencial:

$\int{n(y)dy} = \int{m(x)dx} \implies \boxed{N(y) = M(x) + C}$

Para dar con la forma explícita bastaría con despejar $y$ (no siempre es posible ni inmediato).

Algunos ejemplos vistos en la sesión:
> **[Ejemplo 6]** Resuelve la ecuación diferencial:<br>$\sin(x)\cos^2(y)dx - \cos(x)\sin(y)dy = 0\\$<br> **[Solución 6]**<br><br> $\frac{\sin(x)\cos^2(y)}{\cos^2(y)}dx - \frac{\cos(x)\sin(y)}{\cos^2(y)}dy = 0\\$<br>$\sin(x)dx - \cos(x)\frac{\sin(y)}{\cos(y)}\frac{1}{\cos(y)}\\$<br>$\sin(x)dx - \cos(x)\tan(y)\sec(y)dy\\$<br>$\frac{\sin(x)}{\cos(x)}dx - \frac{\cos(x)\sec(y)\tan(y)}{\cos(x)}dy = 0\\$<br>$\tan(x)dx - \sec(y)\tan(y)dy = 0\\$<br>$\tan(x)dx = \sec(y)\tan(y)dy\\$<br>Llegando así a la forma en variables separables. Ahora integrando ambos lados:<br>$\int{\tan(x)dx} = \int{\sec(y)\tan(y)dy}\\$<br>$\boxed{\ln(\sec(x)) = \sec(y) + C}$ siendo esta la solución implícita de la ecuación diferencial.

> **[Ejemplo 7]** Resuelve la ecuación diferencial:<br>$y' = \frac{y^2}{\sqrt{1-x^2}}\\$<br> **[Solución 7]**<br><br> $\frac{dy}{dx} = \frac{y^2}{\sqrt{1-x^2}}\\$<br>$\frac{dy}{y^2} = \frac{dx}{\sqrt{}{1-x^2}}$, llegando así a la forma separada. Integrando ambos lados:<br>$\int{\frac{dy}{y^2}} = \int{\frac{dx}{1 - x^2}}\\$<br>$\boxed{-\frac{1}{y} = \arcsin(x) + C}$ siendo esta la solución implíctia de la ecuación diferencial.
