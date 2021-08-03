CESE 15Co2021

# Programación de microprocesadores
## Practica 4

Repositorio para la cuarta práctica de la materia Programación de Microcontroladores.

Autores: Martin Rios jrios@fi.uba.ar - Lucas Zalazar lucas.zalazar6@gmail.com

### Resumen
Implementar mediante el modelo de Máquina de Estados Finitos el antirrebote de teclas y la lógica de funcionamiento de un semáforo.

#### Condiciones de funcionamiento
###### Dependencias externas:
 - sAPI.h;
 - Usar delay no bloqueantes;

#### Modularización
![](https://github.com/lucascsd/practicoDos/blob/main/image/Capas%20Ejercicio%202.svg)

###### Archivos de modularización
| File name | hearders                    |
| ------------- | ------------------------------ |
| [ejercicio4.c](https://github.com/martinjrios/Practica2/blob/main/src/ejercicio2.c)|[ejercicio4.h](https://github.com/martinjrios/Practica2/blob/main/inc/ejercicio2.h)|
| [secuencias.c](https://github.com/martinjrios/Practica2/blob/main/src/secuencias.c)|[secuencias.h](https://github.com/martinjrios/Practica2/blob/main/inc/secuencias.h)|
| [led.c](https://github.com/martinjrios/Practica2/blob/main/src/led.c)|[led.h](https://github.com/martinjrios/Practica2/blob/main/inc/led.h)|
| [teclas.c](https://github.com/martinjrios/Practica2/blob/main/src/teclas.c)|[teclas.h](https://github.com/martinjrios/Practica2/blob/main/inc/teclas.h)|

### Notas de compilación
Seleccionar el punto del ejercicio a compilar comentando o descomentando la macro correspondiente en el archivo [ejercicio4.h](https://github.com/martinjrios/Practica2/blob/main/inc/ejercicio.h) 

