# Instrucciones para mi (explicaciones)

## Ruta: 

Enlaces a utilizar: 

#### Programming reference for the Win32 API - Win32 apps | Microsoft Learn

Columna izquierda -> system services -> sysinfoapi.h 

Bibliografía: 

Los links son 

System Services - Win32 apps | Microsoft Learn 
-> 
System Information - Win32 apps | Microsoft Learn
->
System Information - Win32 apps | Microsoft Learn
-> 
About System Information - Win32 apps | Microsoft Learn
-> 
Hardware Configuration - Win32 apps | Microsoft Learn
->
(Para procesador): GetSystemInfo function (sysinfoapi.h) - Win32 apps | Microsoft Learn
-> 
(Para teclado): GetKeyboardType function (winuser.h) - Win32 apps | Microsoft Learn
-> 
(Para RAM): MEMORYSTATUSEX (sysinfoapi.h) - Win32 apps | Microsoft Learn
-> 
(Para Memoria de Video utilizar la librería de DirectX [dxdiag]): 


## Librerias a utilizar: 

### Para el procesador: 

<iostream> para poder generar instrucciones al sistema.
<windows.h> (API [win32]) para poder acceder al SO.

### Comandos a utilizar: 

GetSystemInfo [:  (para solicitar información sobre el hardware (procesador, memoria y tamaños))].

GetCurrentHwProfile:  Da información sobre el tipo de hardware (nos interesará el identificador único global GUID).

Opcionales:

GetKeyboardType: Da información sobre el tipo de teclado y número de teclas que tiene.  

## Parte 2 proyecto: Estructurar el código. 
 

### Estructura para consultar datos del procesador: 

1. Llamar a la estructura SYSTEM_INFO y nombrarla sysInfo;. Adicionalmente, llamar al GetSystemInfo (&sysInfo);


2. Posteriormente llamar los datos desde un std::cout << los datos solicitados. En este caso serán: dwProccesorType; dwPageSize; dwNumberOfProccesors;. 

3. El comando se escribirá llamando al std::cout<< “Variable a mostrar” << comando a solicitar (ver 2.) [en este caso se llamara al comando de la libreria <windows.h> mediante el prefijo “sysInfo”] << ‘/n’;. Por ejemplo:  std::cout<<"Tipo de procesador: " << sysInfo.dwNumberOfProcessors <<'\n'; 

4. Adicionalmente incluir el comando system(“wmic cpu get name, manufacturer”); mediante la library <cstdlib>.


### Estructura para consultar datos sobre la RAM: 

1. Llamar a la estructura: MEMORYSTATUSEX y nombrarla memoria. 

2. Asignarle el tamaño a bits con un .dwLength. Quedaría “memoria.Length”. Posteriormente se asignará a MEMORYSTATUSEX = sizeof(MEMORYSTATUSEX). Este proceso se realiza para que sea más fácil de leer.

3. Se llamará mediante un std::cout<< a las variables que se desee. En este caso serán: ullAvailPhys; ullTotalPhys; dwMemoryLoad (se agregará un “%” para representar el porcentaje utilizado).

4. quedarán escritos como “memoria.ullAvailPhys” . 

5. El escrito completo del comando será: “std::cout<<”La memoria física total (en mb) es: “ << memoria.ullTotalPhys << ‘/n’;.

6. Posteriormente al comando se le agrega una división que transformará el resultado en MB. “/ (1024 * 1024)”[1024 bytes al cuadrado da por resultado 1 MB].

7. Para dwMemoryLoad se agrega un “%” para explicitar que el resultado es un porcentaje.  

8. Finalmente el comando quedará escrito como: “std::cout<<”La memoria física total (en mb) es: “ << memoria.ullTotalPhys / (1024 * 1024) << “MB” << ‘/n’;” && “std::cout<<”El porcentaje de memoria utilizada es:  “ << memoria.dwMemoryLoad << “%” << ‘/n’;”. 
Además, se utilizará el comando: system("wmic memorychip get manufacturer") para solicitar información sobre el fabricante de las memorias. 

### Estructura para consultar datos sobre la memoria de video: 

1. Consultar a la libreria de DirectX: (dxdiag)

2. 

### Estructura para consultar datos sobre los periféricos: 

Parte 3: Generar una matriz que me permita almacenar los datos recopilados de los usuarios.


## Primeros resultados (09-05-2025)

Tipo de procesador: 8664
Número de procesadores: 12
Tamaño de la página: 4096
Datos del Fabricante del procesador: 44135
Memoria disponible: 2171491MB
Memoria física real: 0MB
Porcentaje de memoria en uso: 530%
El fabricante de las memorias RAM es: 0

##### observaciones 

Ver que pasó con el apartado de RAM y el tipo de procesador y los datos del fabricante del procesador. 