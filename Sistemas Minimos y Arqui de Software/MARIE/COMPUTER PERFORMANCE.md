
Este depende del procesador y la memoria..

Ley de Moore, reto de doblar los circuitos cada año.

Para hacer que el sistema memoria mejore, debemos usar jerarquías de memoria en donde tendremos diferentes tipos de memoria:
- Rápida
- Barata
- Grande
Solo se pueden escoger dos, si es rápida y barata será muy grande, por ejemplo.

**Jerarquía de Memoria:**
La mas cercana al CPU es la caché y es parte del procesador --> luego la main memory o la RAM  --> y por ultimo el Disco Duro.

El ultimo se usa para almacenar mucha información y la RAM se encarga de elegir cuales son los datos mas relevantes para mandarlos a la caché.
La cache es una tecnología estática, lo que significa que no se le necesita hacer refresh.

Para los Accesos se utilizan dos cosas:
- **Temporal locality, Locality in time,** se refiere a que nosotros guardaremos los datos que guardamos recientemente. Se hace exploit de los datos mas recientes, poniendolo en los niveles de memoria mas alto.
- **Spatial Locality, Locality in space**, si nosotros utilizamos un dato, lo mas probable es que vaya a acceder a datos cercanos a ese.

Para saber que tan buena es la memoria:
- Hit: Cuando encontramos el dato en la memoria,    valores dentro / valores de loads o stores
- Miss: Cuando no lo encontramos y tenemos que pasar al siguiente nivel
- mm = main memory
- vm = virtual memory o Disco duro

AMAT (Average time for processor to access data)
Formula: t$cache$ + MR$cache$[tmm+MRrm(tvm)]

Cache:
Normalmente se accede un dato por un ciclo de reloj, guarda los datos mas recientes.
Que datos son guardados? => los mas recientes

**Terminología**
- Capacidad: num de bytes que podemos guardar en la cache
- Number of blocks: Capacidad entre numero de bytes disponibles por cada acceso.
- Degree of associativity: cuando tiene varios bloques o bancos para almacenar bytes o num de bloques en un set.

Como se encuentran los datos?
En el cache se organiza todo en S sets, cada memoria esta mapeada por exactamente un set.

Direct Mapped Cache:
Todos los que contenga cierta estructura de bits ej, 100 se guardara en la MM en los lugares donde se contenga 100 al igual que cache.

CACHE MULTINIVEL:
Larger caches have lower miss rates, longer access time.
El nivel mas bajo el L3 de cache