# Información del proyecto

## Ejercicio Pila (Stack) — arquitectura en capas

Este es un ejercicio de la implementación de la estructura de datos **Stack**
(Pila) en C++, organizado en **capas** para separar responsabilidades:

```
MyStack/
├── CMakeLists.txt
├── README.md
├── include/
│   ├── domain/
│   │   ├── Node.hpp          # nodo interno de la lista enlazada
│   │   └── Stack.hpp         # estructura de datos Pila (push/pop/peek)
│   ├── application/
│   │   └── StackService.hpp  # casos de uso sobre la Pila (sin excepciones
│   │                         # hacia afuera: tryPop/tryPeek devuelven optional)
│   └── presentation/
│       └── ConsoleMenu.hpp   # interfaz de consola
├── src/
│   ├── main.cpp
│   └── ConsoleMenu.cpp
└── tests/
    └── StackTests.cpp        # tests de la capa de dominio (sin dependencias externas)
```

- **Dominio** (`domain`): la Pila en sí, con manejo correcto de memoria
  (destructor, constructor/operador de copia y de movimiento) y errores
  reportados con excepciones (`std::underflow_error` en `pop()`/`peek()`
  sobre una pila vacía).
- **Aplicación** (`application`): envuelve al dominio y ofrece una API más
  cómoda para quien la consume (`tryPop`, `tryPeek`, `drainToVector`), sin
  obligarlo a manejar excepciones para el caso esperable de "pila vacía".
- **Presentación** (`presentation`): un menú de consola que solo conoce la
  capa de aplicación, nunca el dominio directamente.

Cada capa solo conoce a la capa inmediatamente inferior, lo que permite
cambiar la implementación interna de la Pila (por ejemplo, pasar de lista
enlazada a un arreglo dinámico) sin tocar la capa de presentación.

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
./MyStack
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

# Correr los tests

El `CMakeLists.txt` genera un segundo ejecutable, `MyStackTests`, con
pruebas de la capa de dominio (push/pop en orden LIFO, `peek`, tamaño,
copia profunda, excepción al hacer `pop`/`peek` sobre una pila vacía):

```bash
cd build
./MyStackTests
```

También se puede correr vía `ctest`:

```bash
cd build
ctest --output-on-failure
```

# Qué cambió respecto a la versión original

- **Sin memory leaks**: la Pila original no tenía destructor; ahora libera
  todos los nodos al destruirse.
- **Regla de cinco completa**: constructor/operador de copia (copia
  profunda) y de movimiento, para que copiar o mover una `Stack` no
  produzca comportamiento indefinido (doble `delete`, punteros colgantes).
- **Errores explícitos**: `pop()`/`peek()` sobre una pila vacía lanzan
  `std::underflow_error` en vez de devolver un valor por defecto en
  silencio.
- **`push` ya no devuelve `bool`**: siempre "tenía éxito" salvo que fallara
  la asignación de memoria (en cuyo caso ya lanza `std::bad_alloc` sola),
  así que ese valor de retorno no aportaba información real.
- **Sin `#include` de archivos `.cpp`**: los templates ahora son
  *header-only* (`.hpp`), que es la práctica estándar en C++ para plantillas,
  en vez de incluir implementaciones `.cpp` directamente.
- **Arquitectura en capas real**: dominio, aplicación y presentación
  separados, con tests de la capa de dominio incluidos.
