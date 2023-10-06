# APv - Autómata con pila (acceptación por vaciamiento de pila)
Realizado por: Jorge González Delgado (alu0101330105@ull.edu.es)
## Introducción
Este programa recrea el funcionamiento de un autómata con pila con el condicional de aceptación de vaciado de pila, es decir para aceptar una palabra no requiere finalizar en un estado de finalización, sino que requiere que tanto la palabra de entrada como la pila están vacías en el mismo momento.

## Funcionamiento
Mi implementación utiliza las clases propias `Transition`, `State` y `PushdownAutomata`.

### Transition
La forma en la que un objeto del tipo `Transition` funciona, es el mismo que si tubiéramos la transición escrita en una cadena pero de forma que podamos acceder a cada elemento de esta de manera sencilla sin preocuparnos de índices.

La clase contiene los atributos privados:

- `origin`: donde se guarda la cadena correspondiente al estado de origen, o dicho de otra forma, el estado al que pertenece la transición.
- `destiny`: igual que el atributo `origin` pero para el estado de destino.
- `symbol`: símbolo que requiere la transición.
- `stackSymbol`: símbolo que requiere estar en la parte superior de la pila.
- `newStackSymbol`: nuevo simbolo que se insertará en la pila.

Los métodos que contiene la clase sirven para obtener o modificar dichos atributos, además de un método `toString()` que formatea los atributos para su visualización por pantalla.

### State
Simboliza un estado del autómata, contiene atributos para almacenar su nombre, sus transiciones y si es un estado inicial y/ final, pero este último no se utiliza por la naturaleza del autómata.

### PushdownAutomata
Clase principal del autómata, contiene atributos para almacenar toda la informacón de su configuración y hace uso de las clase `Transition` y `State`. El método `isAccepted` es el que pone a funcionar el autómata para reconocer la cadena dada.

## Uso
Para utilizar este programa es necesario tener instalado `cmake` > 3.14 y googleTest

```sh
$ sudo apt install cmake;
$ sudo apt install googletest;
```

- Situarse dentro de la carpeta build (si no hay, se puede crear usando `mkdir build`)
  ```bash
  $ cd build
  ```
- Precompilar con `cmake`
  ```sh
  $ cmake ..
  ```
- Compilar el ejecutable
  ```sh
  $ make
  ```
- El ejecutable se encuentra dentro de la carpeta `bin` con el nombre `main`.

El archivo ejecutable puede tomar 2 argomentos:

```sh
$ ./main <archivo de entrada> <traza [0, 1]>
```

Si no se especifica, la traza estará deshabilitada por defecto.

### Comentarios
No se ha realizado Testing en esta practica porque aún no estoy familiarizado del todo con googletest.