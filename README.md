# HosPOOtal

Sistema de gestión hospitalaria implementado en C++ para la clase de POO.

## Descripción
Este proyecto implementa un sistema de jerarquía de clases para un hospital, incluyendo:
- Clase base `Humano`
- Clase `Personal` que hereda de `Humano`
  - Clases `Doctor` y `Enfermero` que heredan de `Personal`
- Clase `Paciente` que hereda de `Humano`
  - Clases `Terminal` y `NoTerminal` que heredan de `Paciente`

## Compilación y Ejecución
Para compilar y ejecutar el proyecto en Windows:
1. Asegúrate de tener instalado un compilador de C++ (como MinGW)
2. Ejecuta el archivo `compile.bat`

O manualmente:
```
g++ -o hospital main.cpp
./hospital
```

## Estructura de la Jerarquía
```
           Humano
         /       \
   Personal     Paciente
   /     \      /      \
Doctor Enfermero Terminal NoTerminal
```