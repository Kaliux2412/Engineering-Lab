***==Para el SKIPCOND existen 4 condicionales:==***
 - 000: Skip si AC < 0 (Si es negativo, menor a 0)
 - 400: Skip si AC = 0
 - 800: Skip si AC > 0 (si es positivo o 1)
 - 0C00: Skip si AC ≠ 0 (si AC es diferente de 0, mientras no sea 0 continua, puede ser tanto negativo como positivo)

*==**Para una multiplicación en MARIE**==* no existen operadores para multiplicar entonces lo que se hace es sumar A un total de B veces dentro de un bucle
Inicio,   LOAD B         / Carga el multiplicador
          SUBT Uno       / Resta 1 (vamos a usar B como contador)
          SKIPCOND 000   / Si B < 0 (es decir, el contador llegó a -1), termina
          JUMP Multiplicar
          JUMP Mostrar

Multiplicar, STORE B     / Actualiza el contador B
          LOAD Resultado
          ADD A          / Suma A al Resultado
          STORE Resultado
          JUMP Inicio    / Repite el bucle

Mostrar,  LOAD Resultado
          OUTPUT         / Muestra 12
          HALT

/ --- DATOS ---
A,        DEC 4          / Número a multiplicar
B,        DEC 3          / Multiplicador (contador)
Resultado, DEC 0
Uno,      DEC 1

*==**Punteros: Guardar y Modificar Direcciones de Memoria***==
MARIE puede acceder a posiciones dinámicas de memoria (como recorrer un arreglo), haciendo uso de LOADI y STOREI
 - LOADI caja: Lee la dirección almacenada dentro de caja y trae a AC  el dato de esa ubicación.
 - Para continuar con la siguiente dirección de memoria se usa solo LOAD caja por ejemplo y se le suma 1: 
 / --- Leer un dato usando un puntero y avanzar ---
          LOADI Ptr      / Lee el contenido almacenado en la dirección 100
          OUTPUT         / Imprime ese dato
          
          / Avanzar la dirección del puntero
          LOAD Ptr
          ADD Uno        / Ptr = Ptr + 1
          STORE Ptr      / Ahora Ptr apunta a la dirección 101
          HALT

/ --- DATOS ---
Ptr,      HEX 100        / Variable puntero que guarda una dirección (100)
Uno,      DEC 1

Como aquí, Ptr es la dirección de memoria y se necesita uno para que se pueda mover a la dirección 101 y terminar el programa.

Existe algo llamado **==*JNS (Jump and Store Instruction Pointer)*==** que es lo que nos ayuda a acceder a la memoria en lo que podemos decir como vector o matriz, o saltar a la dirección X para después ir a la X+1, esta ayuda bastante para crear funciones bloques de código dentro de MARIE como lo hicimos en este caso: 
![[Pasted image 20260903164113.png]]

Para analizar strings:

![[Pasted image 20260903214531.png]]

Basicamente la estructura para acceder a varias posiciones de memoria primero se debe de hacer una rutina de Inicio la cual siempre accedera a punteros de memoria osea LoadI ptr, despues se evalua con Skipcond y abajo de este se lleva a la rutina que se cumple mientras el ciclo se cumpla y si no salta automaticamente a finish, finish es la otra subrutina en donde es recomendable poner el output y halt


![[Pasted image 20260904003952.png]]
![[Pasted image 20260904004003.png]]


LA DIFERENCIA CLAVE ENTRE DIRECTO E INDIRECTO ES:
- Directo: Load x / Store x, opera directamente con el contenido guardado en la variable x, si x = 2 entonces en el AC se mandará  un 2.
- Indirecto: LoadI x / StoreI x, Usa la etiqueta x como un puntero (Osea direccion de memoria). No da el valor o dato dentro de x, si no la direccion escrita en X.
Explicado por Gemini con ejemplo:
![[Pasted image 20260905181018.png]]

Load carga la direccion mientras que LoadI va a la direccion y muestra el valor que guarda esa direccion.