# U3A3.-Clasificaci-n-de-Posici-n-en-un-Robot-Seguidor-de-L-nea-Usando-rbol-de-Decisi-n-

Este proyecto implementa un robot móvil tipo minisumo con sensores infrarrojos y ultrasónicos que ejecuta comportamientos basados en un árbol de decisión. Se emplea una Raspberry Pi Pico como unidad de control y el programa está escrito en MicroPython.

## Objetivo

Diseñar un sistema embebido para un robot que, mediante sensores de línea y proximidad, decida entre 8 rutinas de combate predefinidas. La elección de rutina se realiza al inicio mediante tres interruptores (SW1, SW2, SW3), y el robot inicia su comportamiento luego de una espera de 3 segundos.

## Funcionalidades principales

- **Detección de líneas:** Utiliza sensores de línea para identificar bordes del área de combate.
- **Detección de oponentes:** Mediante sensores ultrasónicos frontales y traseros para detectar la presencia de un oponente.
- **Árbol de decisión:** Elige acciones con base en tres posiciones posibles del enemigo:
  - Frente
  - Espaldas laterales
  - Espaldas

## Descripción del código

El código principal realiza lo siguiente:

1. **Inicialización de pines:**
   - Sensores ultrasónicos (`trig` y `echo`) para detectar obstáculos.
   - Motores controlados por pines PWM para avanzar, retroceder, girar, etc.
   - Sensores de línea para detectar límites.
   - Switches (`SW1`, `SW2`, `SW3`) para seleccionar la rutina.

2. **Lectura de sensores:**
   - Se leen los valores de los sensores ultrasónicos y se calculan distancias.
   - Se leen los sensores de línea para detectar si el robot está saliendo del área.

3. **Árbol de Decisión (Decision Tree):**
   - Se define una función `decision_tree()` que determina la acción a realizar dependiendo de la rutina seleccionada y la información de los sensores.
   - Las acciones posibles incluyen: avanzar, girar, retroceder, atacar directamente, entre otras.

4. **Rutinas de combate:**
   - 8 rutinas distintas, seleccionadas al encender el robot con combinaciones binarias de SW1, SW2 y SW3 (por ejemplo, 000 hasta 111).

5. **Lógica de combate:**
   - Basada en un análisis de la posición del oponente y el estado del entorno inmediato.
   - Si el enemigo está enfrente, el robot ataca directamente.
   - Si el enemigo está en un lateral o en la parte trasera, el robot se reposiciona para enfrentarlo.

## Hardware utilizado

- Raspberry Pi Pico
- 2 motores con driver de control (L298N o similar)
- 3 sensores de línea (IR)
- 2 sensores ultrasónicos (HC-SR04)
- 3 switches para selección de rutina
- Fuente de alimentación externa para motores

## Diagrama del Árbol de Decisión

El árbol de decisión parte de la detección de un oponente:
