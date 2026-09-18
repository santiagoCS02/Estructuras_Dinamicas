# Información del proyecto

## Ejercicio Pila (Stack) — lista enlazada genérica en C++

Este es un ejercicio de implementación de la estructura de datos **Stack**
(Pila) en C++ usando una lista enlazada simple y templates genéricos (`T`),
para poder apilar cualquier tipo de dato, usando el paradigma de la programación orientada a objetos.

```
Estructuras_Dinamicas/
├── CMakeLists.txt
├── README.md
├── include/
│   ├── Node.hpp
│   ├── Node.tpp     
│   ├── Stack.hpp   
│   └── Stack.tpp
└── src/
    └── main.cpp 
```

Los templates son **header-only**: `Node.hpp` incluye `Node.tpp` y
`Stack.hpp` incluye `Stack.tpp` al final, que es la práctica estándar en
C++ para plantillas (en vez de incluir un `.cpp` con la implementación).

# Instalación de dependencias — C++ con CMake

## Linux

### Fedora based (Fedora, Nobara, RHEL...)

```bash
sudo dnf install gcc-c++ cmake gdb
```

### Debian based (Debian, Ubuntu, Mint...)

```bash
sudo apt update
sudo apt install build-essential cmake gdb
```

`build-essential` incluye `g++`, `gcc` y `make`.

### Arch based (Arch, Manjaro, EndeavourOS...)

```bash
sudo pacman -S base-devel cmake gdb
```

`base-devel` incluye `g++`, `gcc` y `make`.

## Windows

Dos caminos posibles:

**Opción A — MSYS2 (recomendada, entorno tipo Linux)**

1. Instalar [MSYS2](https://www.msys2.org/)
2. Desde la terminal de MSYS2:
```bash
pacman -S mingw-w64-x86_64-gcc mingw-w64-x86_64-cmake mingw-w64-x86_64-gdb
```
3. Agregar `C:\msys64\mingw64\bin` al PATH del sistema.

**Opción B — Visual Studio**

Instalar Visual Studio con el workload **"Desarrollo de escritorio con C++"**,
que trae su propio compilador (MSVC) y CMake integrado.

## Mac

```bash
xcode-select --install
brew install cmake
```

`xcode-select --install` instala el compilador (`clang`, equivalente a
`g++`). `gdb` en Mac tiene configuración extra por temas de firma de código;
para depurar se suele usar `lldb`, que ya viene con las Command Line Tools.

## Verificar instalación (cualquier SO)

```bash
g++ --version
cmake --version
```

# Compilar y correr el proyecto

Mismo comando en cualquier SO con terminal tipo Unix (Linux, Mac, o MSYS2 en
Windows):

```bash
mkdir -p build
cd build
cmake ..
make
./StackApp
```

Si agregás un archivo `.cpp` nuevo, o cambiás el `CMakeLists.txt`, hay que
volver a correr `cmake ..` antes de `make`.

Si el build queda en un estado raro (errores de configuración a medio
camino):

```bash
rm -rf build
mkdir build && cd build
cmake ..
make
```
