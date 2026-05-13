cmake_minimum_required(VERSION 3.10)
project(PruebaLibrerias C)

# 1. Configuración de Build Type
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug)
endif()

# 2. Selección del Sistema Operativo
set(OS_DIR "linux")
if(WIN32)
    set(OS_DIR "win")
endif()

# 3. Definición de rutas base para evitar repetición
set(LIBS_BASE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/../Librerias")

# 4. Configuración de Headers (Target-based)
add_executable(Pruebas main.c)

target_include_directories(Pruebas PUBLIC
    "${LIBS_BASE_DIR}/comun"
    "${LIBS_BASE_DIR}/TDA_Pila"
    "${LIBS_BASE_DIR}/TDA_Cola"
    "${LIBS_BASE_DIR}/TDA_Lista"
    "${LIBS_BASE_DIR}/TDA_ListaCircular"
    "${LIBS_BASE_DIR}/TDA_ListaDoble"
)

# 5. Definición de Librerías Estáticas
set(COMUN  "${LIBS_BASE_DIR}/comun/lib/${OS_DIR}/libcomun.a")
set(LIB_PILA  "${LIBS_BASE_DIR}/TDA_Pila/lib/${OS_DIR}/libpila.a")
set(LIB_COLA  "${LIBS_BASE_DIR}/TDA_Cola/lib/${OS_DIR}/libcola.a")
set(LIB_LISTA "${LIBS_BASE_DIR}/TDA_Lista/lib/${OS_DIR}/liblista.a")
set(LIB_LISTACIRCULAR "${LIBS_BASE_DIR}/TDA_ListaCircular/lib/${OS_DIR}/liblistaCircular.a")
set(LIB_LISTADOBLE "${LIBS_BASE_DIR}/TDA_ListaDoble/lib/${OS_DIR}/liblistaDoble.a")

# 6. Validación y Linkeo
foreach(LIB_PATH IN ITEMS ${COMUN} ${LIB_PILA} ${LIB_COLA} ${LIB_LISTA} ${LIB_LISTACIRCULAR} ${LIB_LISTADOBLE})
    if(NOT EXISTS ${LIB_PATH})
        message(FATAL_ERROR "FATAL: No se encontró la librería en: ${LIB_PATH}")
    endif()
endforeach()

target_link_libraries(Pruebas PUBLIC
    ${LIB_PILA}
    ${LIB_COLA}
    ${LIB_LISTA}
    ${LIB_LISTACIRCULAR}
    ${LIB_LISTADOBLE}
    ${COMUN}
)
