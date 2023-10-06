# APv - Autómata con pila (acceptación por vaciamiento de pila)

## Introducción
Este programa recrea el funcionamiento de un autómata con pila con el condicional de aceptación de vaciado de pila, es decir para aceptar una palabra no requiere finalizar en un estado de finalización, sino que requiere que tanto la palabra de entrada como la pila están vacías en el mismo momento.

## Funcionamiento
Mi implementación utiliza las clases propias `Transition`, `State` y `PushDownAutomata`.

### Transition
La forma en la que un objeto del tipo `Transition` funciona, es el mismo que si tubiéramos la transición escrita en una cadena pero de forma que podamos acceder a cada elemento de esta de manera sencilla sin preocuparnos de índices.

La clase contiene los atributos privados:

- `origin`: donde se guarda la cadena correspondiente al estado de origen, o dicho de otra forma, el estado al que pertenece la transición.
- `destiny`: igual que el atributo `origin` pero para el estado de destino.
- `symbol`: símbolo que requiere la transición.
- `stackSymbol`: símbolo que requiere estar en la parte superior de la pila.
- `newStackSymbol`: nuevo simbolo que se insertará en la pila.

Los métodos que contiene la clase sirven para obtener o modificar dichos atributos, además de un método `toString()` que formatea los atributos para su visualización por pantalla.