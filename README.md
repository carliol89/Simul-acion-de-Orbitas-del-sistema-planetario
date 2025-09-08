# Simul-acion-de-Orbitas-del-sistema-planetario
# Simulación de Órbita Planetaria con Método de Runge–Kutta 4 (RK4)

Este programa en **C** simula el movimiento de un planeta alrededor del Sol usando el **método de integración numérica de Runge–Kutta de cuarto orden (RK4)** para resolver las ecuaciones diferenciales del problema gravitatorio de dos cuerpos.

## 📜 Descripción

El código integra las ecuaciones de movimiento bajo la **ley de gravitación universal de Newton** en dos dimensiones.  
Se inicializa la posición y velocidad de un planeta, y se calcula su trayectoria orbital durante un número determinado de períodos.

La salida se guarda en un archivo `solar1.dat` con:
- Tiempo (`t`)
- Posición en `x`
- Posición en `y`
- Energía cinética (`K`)

## ⚙️ Características

- Implementación del método **RK4** para alta precisión.
- Simulación configurable mediante:
  - Paso de integración `h`
  - Posición y velocidad inicial
  - Constante gravitacional `G`
- Salida lista para graficar con herramientas como **gnuplot**.

## 📂 Estructura del código

- **`main`** → Configura parámetros, inicializa condiciones y ejecuta el bucle de integración.
- **`fun`** → Calcula las derivadas del sistema (ecuaciones de movimiento).
- **`RK4`** → Implementa el método de Runge–Kutta de cuarto orden.

## 📊 Ecuaciones utilizadas

El sistema de ecuaciones diferenciales es:



\[
\frac{dx}{dt} = V_x
\]




\[
\frac{dV_x}{dt} = -\frac{G \cdot x}{r^3}
\]




\[
\frac{dy}{dt} = V_y
\]




\[
\frac{dV_y}{dt} = -\frac{G \cdot y}{r^3}
\]


donde:


\[
r = \sqrt{x^2 + y^2}
\]



## 🚀 Compilación y ejecución

```bash
# Compilar
gcc -o solar1 orbita1.c -lm



# Ejecutar
./orbita1



## Resultados
en la imagen trayectoriasPlanetas.jpg se calcularosn las trayectorias para diferentes planetas con diferentes condiciones iniciales, en unidades astronomícas UA. 
y[0]=9.6 Saturno ; y[0]=1 tierra, y[0]= 1.5 Marte, y[0]= 5.2 jupiter   
