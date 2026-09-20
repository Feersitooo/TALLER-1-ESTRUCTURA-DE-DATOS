Sistema de gestión de pacientes para un hospital, desarrollado en C++ para el Taller 01 de la asignatura Estructura de Datos.

El programa permite cargar pacientes desde un archivo de texto, administrarlos mediante una cola de espera, atenderlos y derivarlos a los distintos servicios del hospital. Además, permite consultar los pacientes de cada servicio, buscar pacientes por ID y revisar el historial de atención.

## Integrantes

- Maximiliano Edhin Abd-El-Kader Góngora (YovngKxder) - 22.128.215-9 - Ingeniería Civil en Computación e Informática
- Fernando Antonio Herrera Castillo (Feersitooo) - 22.057.550-0 - Ingeniería Civil en Computación e Informática
- Matias Ignacio González Gomez (matiasgonzalez15-sys) - 22.350.340-3 - Ingeniería Civil en Computación e Informática

## Estructuras implementadas

El sistema utiliza estructuras de datos implementadas manualmente mediante punteros y memoria dinámica:

- **Cola de pacientes:** administra a los pacientes pendientes de atención siguiendo el principio FIFO.
- **Lista enlazada de servicios:** administra los diferentes servicios disponibles en el hospital.
- **Lista enlazada de pacientes:** cada servicio mantiene los pacientes que han sido derivados a él.
- **Pila de historial:** registra las atenciones realizadas siguiendo el principio LIFO.

## Funcionalidades

El programa permite:

- Cargar pacientes desde `pacientes.txt`.
- Mostrar los pacientes pendientes de atención.
- Atender una cantidad determinada de pacientes.
- Derivar cada paciente al servicio correspondiente.
- Consultar los pacientes de cada servicio.
- Revisar el historial de atención.
- Buscar un paciente mediante su ID.
- Validar datos incorrectos provenientes del archivo de entrada.
- Controlar entradas inválidas y estructuras vacías.

## Formato del archivo de entrada

Los pacientes deben almacenarse en el archivo `pacientes.txt` utilizando el siguiente formato:

ID;Nombre;Edad;Servicio

## Ejemplo

001;Juan Perez;25;Cardiologia
002;Maria Soto;67;Urgencias
003;Pedro Rojas;43;Cirugia

## Compilacion

Para compilar el programa utilizando g++, ejecutar desde la carpeta raíz del proyecto:

g++ -std=c++20 -Wall -Wextra -pedantic *.cpp -o hospital

## Ejecución

En Windows:

.\hospital.exe

El archivo pacientes.txt debe encontrarse en la misma carpeta desde la cual se ejecuta el programa.

## Servicios disponibles

El hospital cuenta con los siguientes servicios:

- Urgencias
- Medicina General
- Cardiología
- Neurología
- Traumatología
- Cirugía
- Pediatría
- Hospitalización 

```text

