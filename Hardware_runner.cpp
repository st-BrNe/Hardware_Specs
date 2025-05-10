#include <iostream> // libreria basica para utilizar comandos basicos como el cin y el cout
#include <windows.h> //libreria para acceder a funcionalidades del sistema operativo. Sirve para interactuar con el OS.
#include <thread>
#include <cstdlib> // libreria para obtener la informacion del fabricante del procesador.

int main (){


    // Obtener el numero de procesadores y la arquitectura de este.
    
    SYSTEM_INFO sysInfo;
    GetSystemInfo (&sysInfo);

    std::cout<<"Tipo de procesador: " << sysInfo.dwProcessorType <<'\n'; //Para mostrar el tipo de procesador 
    std::cout<<"Número de procesadores: " << sysInfo.dwNumberOfProcessors <<'\n'; // Para mostrar el numero de procesadores
    std::cout<<"Tamaño de la página: " << sysInfo.dwPageSize << '\n'; //Para mostrar el tamaño de la pantalla 
    std::cout<<"Datos del Fabricante del procesador: "<< system("wmic cput get name, manufacturer") <<'\n'; // Para mostrar los datos del fabricante. 

    // Obtener información sobre la memoria RAM.

    MEMORYSTATUSEX memoria;
    memoria.dwLength = sizeof(MEMORYSTATUSEX);

    std::cout<<"Memoria disponible: "<< memoria.ullAvailPhys / (1024 * 1024) << "MB" <<'\n';
    std::cout<<"Memoria física real: "<< memoria.ullTotalPhys / (1024 * 1024) << "MB"<<'\n';
    std::cout<<"Porcentaje de memoria en uso: "<< memoria.dwMemoryLoad<< "%" <<'\n';
    std::cout<<"El fabricante de las memorias RAM es: " << system("wmic memorychip get manufacturer") <<'\n';

    // Información sobre la Memoria de video.
    
    


    // std::cout<< "Fuiste analizado por el Verdadero Matatan, el Espermio Supremo, el mismisimo Brunaldinho Pereira tambien conocido como Sir Bruno Neira" << std::<<endl;.

    return 0; 

}