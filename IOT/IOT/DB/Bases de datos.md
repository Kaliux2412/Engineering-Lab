#### Entidades: representan algún aspecto físico o conceptual del mundo real. 
	Se representan como tablas ej. Cliente, Proveedores, Inventario.
	- Entidades débiles: dependen de otra entidad para existir.
	- Entidades fuertes (kernels): Son entidades que pueden existir por si sola.
- Relaciones: Representan asociaciones entre entidades.
- Las entidades se representan con **rectángulos.**
	Las entidades tienen ATRIBUTOS, como id, edad, nombre, etc. Se representan con **óvalos.**
	-  Atributos, llave primaria, Primary Key (PK), ids, números de control.
	- Atributos Multivaluados, son aquellos que se componen de un conjunto predefinido de valores, ejemplo: grado académico.
	- Atributos Derivados: son atributos que se pueden inferir a partir de otros.
	- Los Atributos tienen DOMINIOS, números enteros, cadena de caracteres, enteros
	- Llaves foráneas, se representan en rombos, ej. en dos tablas existe el id_nombre por ejemplo, y con eso se relacionan.

#### **Relaciones:** 
- Cardinalidad: relación que es de 1 a 1
- Uno a muchos y se usa un rombo que dentro dice "tiene".
- Muchos a muchos se usa M a M.
- Unaria: Empleado supervisa varios empleados un empleado es supervisado por un empleado.
	- Es RECURSIVA
	![[Pasted image 20260929073903.png]]
- Ternaria: Un maestro imparte uno o varios cursos, Maestro imparte una o varioas clases especifica de un curso.
![[Pasted image 20260929073725.png]]

#### Operaciones en una base de datos:
**C**reate
**R**ead
**U**pdate
**D**elete

DATO: Para leer relaciones siempre se inicia del lado izquierdo y siempre hay que usar el **un** maestro imparte **un** curso.

Propiedades de las tablas:
- Nombre único
- No hay tuplas duplicadas
- los valores de las columnas son atómicos.
- No se permiten operaciones con diferentes tipos de datos
- Cada atributo tiene un nombre diferente
- La secuencia de columnas y filas es irrelevante.
Reglas de integridad:
- Restringe los posibles valores que pueden tomar los atributos. como true o false.
- Toda la tabla debe tener una llave primaria y no puede ser nulo.
- Una llave foránea debe corresponder a una llave primaria y ser del mismo tipo de dato.
- Integridad del negocio: Como un curso puede ser tomado por 30 estudiantes, ciertos parámetros que se deben cumplir.
- Dominio, Entidad, Referencial y negocio.

-Grado de una tabla significa la cantidad de atributos.

Diagramas: a base de tablas, atributos dentro de la tabla y muestra el tipo de dato. Modelo relacional ese es el tipo de diagrama
