# Raylib Pong

A simple implementation of Pong in raylib.

In case you want to change the game's settings:
- Windows:
    - Edit ```$PROJECTS/game-premake/game/src/config.h``` (See USAGE - Windows for details)
    - ```_bin/Debug/game-premake.exe``` 
- Linux:
    - Edit ```src/config.h```
    - Rerun with: ```./nobuild```(See USAGE - Linux for details)

## NOTE

Although the project source files have .cpp extensions the project is mainly
written in plain c, apart from the use of vectors and some algorithms,
so the structure is more c-like (which would exlpain no oop definition of the
game logic or other c++ norms).

# REQUIREMENTS - Linux/Windows

- Git:
  - Windows: ```winget install git.git```
  - Linux(ubuntu-based): ```sudo apt install git```

# USAGE - LINUX

- ```git clone https://github.com/GiorgosAthanasopoulos/raylib-pong```
- ```cd raylib-pong```
- ```chmod +x bootstrap.sh```
- ```./bootstrap.sh```(Will download dependencies using apt - change script accordingly for your package manger. Will also clone and build raylib - Comment corresponding lines if you already have raylib installed and in a discoverable by the compiler directory).

# USAGE - Windows (Just use linux, and make your life ez...Anyway here goes...)

- Lets call the directory that we will use to clone the repositories in ```$PROJECTS```.
- ```cd $PROJECTS```
- Start by cloning [raylib-pong](https://github.com/GiorgosAthanasopoulos/raylib-pong) (the actual game): ```git clone https://github.com/giorgosathanasopoulos/raylib-pong```
- We need a compiler - lets use [W64Devkit](https://github.com/skeeto/w64devkit/):
  - Download the w64devkit zip from the [W64Devkit Releases](https://github.com/skeeto/w64devkit/releases) page.
  - Extract the folder in $PROJECTS.
  - So far the $PROJECTS directory should contain: ```raylib-pong``` and ```w64devkit``` sub-directories.
- Finally we need the raylib library. To make everything easy we will use a raylib game template that comes with makefiles out of the box (and that will automatically download raylib):
  - ```git clone https://github.com/raylib-extras/game-premake```
- That's all for the dependencies. Our ```$PROJECTS``` directory should contain ```raylib-pong```, ```w64devkit``` and ```game-premake``` sub-directories.
Lets configure and build/run our project:
-  Run the executable ```$PROJECTS/w64devkit/w64devkit/w64devkit.exe```
In the new terminal run:
- ```cd $PROJECTS/game-premake```
- ```premake-mingw.bat``` (This will download raylib for us - along with creating a makefile for our project).
Now lets copy raylib-pong in the game-premake src directory:
- ```rm ./game/src/*```
- ```cp ../raylib-pong/src/* ./game/src/```
- ```cp ../raylib-pong/_build/game-premake.make ./_build/```
- ```make```(You should see the raylib library being compiled),
- ```_bin/Debug/game-premake.exe```
