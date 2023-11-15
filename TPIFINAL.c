/*Integrantes: 
Garcia, Nair
Rambado, Matías
Ramirez Diaz, Carlos*/

#include <stdio.h> //Biblioteca  de entrada y salida de datos como printf y scanf.
#include <stdlib.h> //Blibioteca de funciones y operaciones básicas.
#include <string.h> //biblioteca que permite la manipulación de cadenas de caracteres.

float deposito(float *saldo, int clienteActual); //Función para realizar depósitos y el "*saldo" lo usamos para poder modificar el valor original y no una copia del mismo.
float extraccion(float *saldo, int clienteActual); //Función para realizar una extracción y el "*saldo" lo usamos para poder modificar el valor original y no una copia del mismo.
float transferencia(float *saldo, int clienteActual); //Función para realizar una transferencia y el "*saldo" lo usamos para poder modificar el valor original y no una copia del mismo.

int main()// Función principal.
{
    // Inicializar los datos de los clientes
    int numeroCuenta[10] = {100, 200, 300, 400, 500, 600, 700, 800, 900, 999}; //El valor entre corchetes representa la cantidad de elementos que posee el array.
    char contrasenia[10][20] = {"pass1", "pass2", "pass3", "pass4", "pass5", "pass6", "pass7", "pass8", "pass9", "pass99"}; //El valor del primer corchete representa la cantidad de elementos del array y el valor del segundo corchete es la cantidad maxima de caracteres que se pueden almacenar en cada elemento del array.
    char nombres[10][50] = {"Matias Rambado", "Nair Gracia", "Carlos Ramirez Diaz", "Valeria Perez", "Marcelo Denis", "Nicolas Canil", "Cristian Rodriguez", "Celeste Plano", "Leonela Oricain", "Anita Zapata"};//El valor del primer corchete representa la cantidad de elementos del array y el valor del segundo corchete es la cantidad maxima de caracteres que se pueden almacenar en cada elemento del array.
    float saldo[10] = {450000.0, 598000.0, 700000.0, 999000.0, 190000.0, 267000.0, 350987.0, 123000.0, 98000.0, 568098.0};//El valor entre corchetes representa la cantidad de elementos que posee el array.
    char estadoCuenta[10][10] = {"Activo", "Activo", "Activo", "Activo", "Activo", "Activo", "Activo", "Activo", "Activo", "Activo"};//El valor del primer corchete representa la cantidad de elementos del array y el valor del segundo corchete es la cantidad maxima de caracteres que se pueden almacenar en cada elemento del array.

    // Declaracion de variables
    int clienteActual; //Es la variable en la cual vamos a ir guardando los datos que ingresamos y los comparamos con los de los arrays.
    int intentosMaximos; //Intentos maximos antes que se bloquee la cuenta.
    int operacionesRealizadas = 0; //Es un contador para las opereciones que realiza el cliente.
    float saldoActual;
    int opcion;
    char contraseniaIngresada[20]; //El valor entre corchetes es el valor maximo de caracteres que puede poseer esta variable.
    int intentosFallidos[10]; //El valor entre corchetes es el mismo que la cantidad de cuentas, para ir guardando en cada posision el numero de intestos fallidos. 

    // Mostrar mensaje de bienvenida
    printf("Bienvenido al Cajero Autom%ctico\n", 160);

    // Solicitar número de cuenta
    printf("Ingrese su n%cmero de cuenta: ", 163);
    scanf("%d", &clienteActual);

    // Solicitar contraseña
    printf("Ingrese su contrase%ca: ", 164);
    scanf("%s", &contraseniaIngresada);

    // Verificar credenciales
    if (clienteActual >= 100 && clienteActual <= 999)
    {
        clienteActual = (clienteActual / 100) - 1;
    }
    //Si clienteActual es verdadero, los que hacemos en la siguiente línea es dividirlo por 100 y restarle 1. Para que el resultado nos de la posición en el array. Por ejemplo numero de cuenta 100, dividido 100, da 1, menos 1, da "0". Por ende la  posición en el array de la cuenta 100 es 0.
    if (strcmp(contrasenia[clienteActual - 100], contraseniaIngresada) && strcmp(estadoCuenta[clienteActual - 100], "Activo")) //La función strcmp compara las cadenas de caracteres. Si las cadenas son iguales, devuelve el valor = 0. Si la primer cadena es menor que la segúnda devuelve un valor menor a 0, y en caso contrario un valor mayor a 0.
    {
        printf("Inicio de sesi%cn exitoso. Bienvenido, %s.\n", 162, nombres[clienteActual]);
        intentosMaximos = 3;
        intentosFallidos[clienteActual - 100] = 0;

        do //Comienza la estructura de control dentro del if, una vez validado los datos de ingreso. En caso que los datos no sean correctos, se salta esta estructura y va directamente al else del if anteriormente mensionado.
        {
            // Mostrar el menú
            printf("1. Realizar un Dep%csito\n", 162);
            printf("2. Realizar una Extracci%cn\n", 162);
            printf("3. Consultar el Saldo de la Cuenta\n");
            printf("4. Realizar una Transferencia entre Cuentas\n");
            printf("5. Mostrar cantidad de Operaciones Realizadas y Saldo Actual\n");
            printf("6. Salir de la Sesi%cn\n", 162);
            printf("Ingrese la opci%cn deseada: ", 162);
            scanf("%d", &opcion);

            switch (opcion)
            {
            case 1:
                // Realizar un depósito
                deposito(saldo, clienteActual); //Función deposito se le asignan dos argumento el saldo y clienteActual.
                break;

            case 2:
                // Realizar una extracción
                extraccion(saldo, clienteActual); //Función extracción se le asignan dos argumento el saldo y clienteActual.
                break;

            case 3:
                // Consultar el saldo de la cuenta
                printf("Su saldo actual es: %.2f\n", saldo[clienteActual]); //No hizo falta realizar una función ya que en este caso solo se debe mostrar el saldo actual de la cuenta.
                break;

            case 4:
                // Realizar una transferencia
                transferencia(saldo, clienteActual); //Función transferencia se le asignan dos argumento el saldo y clienteActual.
                break;

            case 5:
                // Mostrar cantidad de operaciones realizadas y saldo actual
                printf("Operaciones realizadas: %d\n", operacionesRealizadas); //No hizo falta realizar una función ya que en este caso solo se debe mostrar la cantidad de operaciones realizadas de la cuenta. La cual se va contando con el contador que se encuentra al finalizar el switch.
                printf("Saldo actual: %.2f\n", saldo[clienteActual]); //No hizo falta realizar una función ya que en este caso solo se debe mostrar el saldo actual de la cuenta.
                break;

            case 6:
                // Salir de la sesión
                printf("Sesi%cn finalizada. Gracias por utilizar nuestro cajero autom%ctico.\n", 162, 160); // Cuando el usuario ingrese un valor igual a 6 la estructura do while finaliza y cierra la sesion.
                break;
            default:
                // Opción no válida
                printf("Opci%cn no v%clida. Int%cntelo de nuevo.\n", 162, 160, 130); //Cuando el usuario ingrese un valor que se enncuentre fuera del rango de 1 a 6, aparecerá este mensaje por pantalla. Ya que en el switch especifica que los valores aceptables son del 1 al 6.
                break;
            }

            // Sumador de operaciones realizadas se va incrementando en 1 cada vez que el usuario ingrese una opcion del menú de opciones.
            operacionesRealizadas++; 

            // Límite de operaciones, cuando el contador oprecionesRealizadas llegue a 10 se mostrará el siguiente mensaje
            if (operacionesRealizadas >= 10)
            {
                printf("Ha alcanzado el l%cmite de operaciones. Gracias.\n", 161);
            }
        } while (opcion != 6); // Condicion para salir del bucle
    }
    else
    {
        printf("N%cmero de cuenta o contrase%ca incorrecta.\n", 163, 164); //En este paso se van contando los intentos fallidos al tratar de ingresar al sistema.
        intentosFallidos[clienteActual - 100]++;

        // Límite de intentos fallidos 
        if (intentosFallidos[clienteActual - 100] >= intentosMaximos)
        {
            printf("No se permiten m%cs intentos. Su cuenta ha sido bloqueada; comun%cquese con la entidad bancaria.\n", 160, 161);
            strcpy(estadoCuenta[clienteActual - 100], "Bloqueado"); // La funcón strcpy copia el contenido de una cadena de caracteres a otra
        }
    }
    system("pause");
    return 0;
}

// Función deposito
float deposito(float *saldo, int clienteActual)
{
    printf("Ingrese la cantidad a depositar: ");
    float cantidadDeposito;
    scanf("%f", &cantidadDeposito);
    saldo[clienteActual] += cantidadDeposito;// cantidadDeposito lo sumamos al saldo que posee el cliente actual.
    return saldo[clienteActual]; //Devuelve el saldo del cliente modificado.
}

// Funcion extracción
float extraccion(float *saldo, int clienteActual)
{
    printf("Ingrese la cantidad a extraer: ");
    float cantidadExtraccion;
    scanf("%f", &cantidadExtraccion);
    if (cantidadExtraccion > saldo[clienteActual])
    {
        printf("Saldo insuficiente. Operaci%cn cancelada.\n", 162);
    }
    else
    {
        saldo[clienteActual] -= cantidadExtraccion; //La cantidadExtraccion es restada del saldo del cliente actual.
    }
}

// Función transferencia
float transferencia(float *saldo, int clienteActual)
{
    printf("Ingrese el n%cmero de cuenta destino: ", 163);
    int cuentaDestino;
    scanf("%d", &cuentaDestino);

    // Verificar si la cuenta destino es válida
    if (cuentaDestino >= 100 && cuentaDestino <= 999 && cuentaDestino != clienteActual + 100)
    {
        printf("Ingrese la cantidad a transferir: ");
        float cantidadTransferir;
        scanf("%f", &cantidadTransferir);

        // Verificar si hay suficiente saldo en la cuenta actual
        if (cantidadTransferir <= saldo[clienteActual])
        {
            // Realizar la transferencia, primero se resta el monto de la cuenta origen para luego sumarlo en la cuenta destino.
            saldo[clienteActual] -= cantidadTransferir;
            saldo[cuentaDestino - 100] += cantidadTransferir;
            printf("Transferencia exitosa a la cuenta %d.\n", cuentaDestino);
        }
        else
        {
            printf("Saldo insuficiente para realizar la transferencia.\n");
        }
    }
    else
    {
        printf("N%cmero de cuenta destino no v%clido.\n", 163, 160);
    }
}