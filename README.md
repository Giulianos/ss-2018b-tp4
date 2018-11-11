# Instrucciones
En este documento se detallan los pasos para compilar y correr
el proyecto.

## Compilación
Se debe contar con CMake > 3.7 (en macOS: `brew install cmake`, en debian-like: `sudo apt install cmake`) y un compilador
de `C++ 11` (en macOS basta con tener las devtools de xcode, en debian-like `sudo apt install g++`).
Para compilar el proyecto basta correr:

```bash
$ ./compile.sh
```

Si la compilación fue satisfactoria, el archivo ejecutable
debería haber quedado en `build/ss_tp4`.

## Ejecución
Una vez compilado el proyecto (siguiendo los pasos de la sección
anterior), se puede correr el proyecto ejecutando:

```bash
$ ./build/ss_tp4 <parámetros>
```

Donde **<parámetros>** es el nombre del archivo con los parámetros de la simulación. Ver sección **Archivo de parámetros** para conocer el formato y los parámetros necesarios en cada caso.

## Archivo de parametros
Los archivos de parámetros permiten indicar como se va a correr el programa. En estos archivos se describen configuraciones como el nombre de los archivos de salida, pasos temporales, integradores a usar, sistema a simular entre otras cosas.

### Formato
El formato del archivo especifica las entradas con el estilo `clave=valor` donde las distintas entradas se delimitan por el fin de línea.

Ejemplo:
```
parametro1=valor1
parametro2=valor2
```

### Parámetros disponibles
  - Sistema a simular (**system**): indica que sistema se desea simular. Valores posibles:
    - `space`: Se simula la trayectoria del Voyager 1
    - `spring`: Se simula el resorte (integración numerica)
    - `real_spring`: Se simula el resorte (solución analítica)
  - Paso de tiempo (**dt**): indica el paso de tiempo para la simulación en segundos (obligatorio para `system=space` y `system=spring`)
  - Integrador (**integrator**): indica que integrador se va a usar. Si no se especifica y se necesita un integrador se usa Beeman por defecto. Valores posibles:
    - `beeman`
    - `gear_predictor_corrector`
    - `verlet`
  - Tiempo total (**total_time**): tiempo total de simulación en segundos.
  - Nombre de archivo para la salida OVITO (**ovito_output_filename**)
  - Nombre de archivo para la salida de distancias (**min_dist_filename**)

Ademas, para el caso de la simulación de la trayectoria del Voyager 1 (`system=space`), se debe indicar las condiciones iniciales de la sonda. Para esto se usan los siguientes parámetros:

  - Módulo de la velocidad incial (**v0**): valor en metros por segundo
  - Altura orbital (**L**): valor en metros