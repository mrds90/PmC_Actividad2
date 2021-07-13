# Actividad 2

Modularizar en funciones, archivos y capas, un proyecto de controlador de leds. Implementar un programa que controle la lógica de funcionamiento de una secuencia arbitraria de LEDs de la EDU-CIAA-NXP.


## Descripción

Utiliza la lectura de las teclas para tomar decisiones.
El comportamiento del firmware está definido por la siguiente tabla de verdad

| Tecla  |           Resultado             |
|--------|---------------------------------|
|  TEC1  |       Sentido incremental       |
|  TEC2  |          Modo Semaforo          |
|  TEC3  |                -                |
|  TEC4  |       Sentido decremental       |

## Dependencias

* Utiliza la librería sapi.h de firmware v3

El firmware tiene 4 capas dividio en 4 archivos .h y .c.

Las capas, en orden decremental son:
* Main
* Teclas
* Secuencia
* Led

### Main
Es la capa de la aplicación que se ejecuta. En esta solo se utiliza la función de interpretar Tecla

### Teclas
En esta capa estan cargadas las opciones del programa. Cada tecla tiene un vector con una secuencia asociada (Nro de LED y Tiempos). En esta capa se utilizan los servicios de la capa secuencia.

### Secuencias
Esta capa se encarga de llevar el control de las conmutaciones dentro de una secuencia. Ofrece la posibilidad de configurar una secuencia y luego se encarga de gestionar el recorrido de la misma a los tiempos configurados.
Esta misma capa enciende los led correspondientes, en funcion de la secuencia configurada.

### Led
Gestiona el encendido o apagado de los Leds que se le solicita conmutar.

## Descarga
Abrir una terminal en la carpeta donde carga los proyectos dentro de firmware v3 y escribir
```
git clone https://github.com/mrds90/PmC_Actividad2.git
```
## Compilacion

* Abrir la terminal del CIAA launcher e ir a la ruta del firmware v3.
* Seleccionar el programa con el comando
```
make select_program
```
* Elegir la carpeta del repositorio descargado (PmC_Actividad2)
* Compilar el programa el programa en la misma terminal con:
```
make all
```
##  Descargar programa en edu_cia_nxp

* En la misma terminal y con la edu_ciaa_nxp conectada escribir

```
make download
```

## Help

Puede no tener seleccionado la placa correcta. Para corregir esto escriba
```
make select_board
```
y seleccione la edu_ciaa_nxp

Siempre debe estar en la ruta raiz de la carpeta clonada "firmware_v3" con la terminal de CIAA Launcher si desea usar los comandos.

## Autor

Marcos Dominguez
[@mrds90](https://github.com/mrds90)

Mario Aguilar
