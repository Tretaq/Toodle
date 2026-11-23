#Toodle

A Doodle Jump clone without some funcs still in doing. written in C++ with SFML 3

Written for Terra <3 Theme: Peak(couse u know u reach the peak in this)

## Features 

- Endless generated platforms, with spacing made from players jump 
- Four platform types: normal, moving, breakable, and disappearing
- Spring  platform for a boost in jump. 
- Jetpack pickup that lest yuou fly through everythoing for a few seconds.
- Scrolling camera 
- Score by height, game over screen, and a high score save
- death by getting out of vievs reach

## Controls

| Key | Action |
|---|---|
| `A` / `Left Arrow` | Move left |
| `D` / `Right Arrow` | Move right |
| `Space` | Restart after game over |

Players wraps around edges and jump automaticly.

## Building

### Requirements

- C++17 Compiler
- Cmake 3.16
- SFML 3

### Build and run

```shell
git clone https://github.com/Tretaq/Toodle
cd Toodle 
cmake -B build -DCMAKE_BUILD_TYPE=Release
cmake --build build
cd build
./Toodle
```
Run th game from the folder that contains the exec. Cmake copies assets
## To do 
- Graphics well theres no graphics since this project took me so much time that i spend debugging 
- Enemies same reason if only i had more time... 
- Sound

# Credit
Font: GeistPixel-Regular-VariableFont_ELSH