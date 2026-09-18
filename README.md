# Taller 1 - Gestión de Pacientes

## Integrantes

- Maximiliano Edhin Abd-El-Kader Góngora - 22.128.215-9 - GitHub: YovngKxder - Ingeniería Civil en Computación e Informática
- Fernando Antonio Herrera Castillo - 22.057.550-0 - GitHub: Feersitooo - Ingeniería Civil en Computación e Informática
- Matias Ignacio González Gomez - 22.350.340-3 - GitHub: matiasgonzalez15-sys - Ingeniería Civil en Computación e Informática

## Sobre el proyecto

En este taller hicimos un programa para gestionar los pacientes de un hospital.

Los pacientes se cargan desde `pacientes.txt` y quedan primero en una fila de espera. Al momento de atenderlos, se respeta el orden de llegada y cada paciente se manda al servicio que le corresponde.

También se guarda un historial de las personas que ya fueron atendidas.

## Estructuras de datos

Para realizar el programa usamos:

- **Cola:** para la fila de espera de los pacientes (FIFO).
- **Lista enlazada:** para guardar los servicios y los pacientes de cada servicio.
- **Pila:** para guardar el historial de atenciones (LIFO).

Los servicios que tiene el hospital son:

- Urgencias
- Medicina General
- Cardiologia
- Neurologia
- Traumatologia
- Cirugia
- Pediatria
- Hospitalizacion

## Programación Orientada a Objetos

Se creó una clase base llamada `ServicioMedico` y a partir de ella se hicieron las clases de los distintos servicios.

También se trabajó con punteros, memoria dinámica, constructores y destructores.

## Archivo "pacientes.txt"

Los pacientes se ingresan con este formato:

`ID;Nombre;Edad;Servicio`

Ejemplo:

`001;Juan Perez;25;Cardiologia`

El programa revisa que los datos estén correctos y que no existan pacientes repetidos o servicios que no correspondan.

## Menú

El programa permite:

1. Atender pacientes
2. Ver departamento
3. Revisar historial de atención
4. Buscar paciente
5. Salir

La opción de búsqueda permite encontrar pacientes tanto si siguen esperando como si ya fueron atendidos.

## Cómo ejecutar

El proyecto está hecho en C++ y fue desarrollado utilizando CLion y CMake.

Para ejecutarlo se debe abrir el proyecto en CLion, compilar y ejecutar el programa.

El archivo `pacientes.txt` debe estar disponible para que el programa pueda cargar los pacientes. TALLER-1-ESTRUCTURA-DE-DATOS
Taller creado por Matías Gonzales, Maximiliano Abd-El-Kader, Fernando Herrera
