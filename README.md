# 7542 - Taller-Pages

## Nicolás Riedel

## Padrón : 102130

### Repositorio : https://github.com/RiedelNicolas/7542-Taller-Pages



## Trabajo :

## Desarrollar una aplicación servidor que atienda petitorios HTTP, mediante los cuales puede acceder y dar de alta recursos de los mismo.



## Clases desarrolladas :

## Client

Maneja la lógica del cliente: recibe un petitorio HTTP mediante STDIN; hace la consulta con un servidor;espera la respuesta y luego la muestra por pantalla.

## Lock

Contiene una referencia  a una instancia de  [mutex](http://www.cplusplus.com/reference/mutex/mutex/) , se utiliza como bloqueante para proteger los objetos compartidos.

## Socket

Implementacion de Socket en c++.

## Thread

Implementacion de TDA Thread, fuertemente infulenciado por el del tutorial interactivo de la catedra. Se utiliza como clase abstracta. 

## ClientHandler

Clase encargada de manejar los nuevos clientes que se conectan al servidor. Es una clase derivada de **Thread**, esto nos permite hacer uso de concurrencia y manejar multiples clientes desde un único servidor.

## PetitionProcessor

Encargada de esconder la lógica de los petitorios. Contiene una  **PetitionLogic**, a la cual delega las responsabilidades. 

## PetitionLogic

Clase abstracta, sus derivados implementan la logica de los distintos tipos de petitorios que tiene el trabajo. Estos son : 

- PetitionGet :  Busca el recurso deseado.
- PetitionPost : Da de alta el recurso especificado.
- PetitionInvalid : Es el caso donde se recibe un petitorio invalido, no aplica cambios pero notifica al cliente.

## 





## 