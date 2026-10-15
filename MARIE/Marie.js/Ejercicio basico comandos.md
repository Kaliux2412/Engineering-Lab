![[Pasted image 20260825213851.png]]
Básicamente 
- Input:  es para que en la parte derecha escribamos los inputs que necesite el programa
- Output: lo que el programa imprime
- ORG: para inicializar en que memoria se correrá el programa
- Store: Para almacenar datos.
- Halt: Para terminar el programa (como un return)
- Jump: Para pasar a otra instrucción si no se cumple la primera.
Los 7 instrucciones o programas de MARIE:
- AC: Es el acumulador, es el que manda el resultado de las operaciones que le mandamos 
- MAR: memory address register
- MBR: Memory buffer register
- PC: este es el contador de programa, es el que hace que una vez que se acaba una instrucción continua con la otra.
- IR: Instruction register.
- InREG: Un ventana para poner los datos en la consola.
- Output
Hasta el final se declaran las variables y DEC significa que es decimal.

ISA de MARIE:
Consiste en 13 instrucciones.
No son 16 ya que hay 4  obligatorias que son: Output, Halt e input y ac y son necesarias para el programa.
Si no pones Halt antes de las variables (Ya que las variables van hasta abajo), el programa piensa que como en la imagen de arriba "Num1" es una instrucción y no una variable que tu asignaste. Estos son algunos ejemplos de las instrucciones que usa MARIE y además cada una tiene ya valores especificos asignados en la memoria:
![[Pasted image 20260827222329.png|415]]


Ejemplo de suma de 3 números:
No se necesita declarar 3 variables para cada número, con una es suficiente porque se va acumulando en el AC.
![[Pasted image 20260827083815.png]]


![[Pasted image 20260831083149.png]]