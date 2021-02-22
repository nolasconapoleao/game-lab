# Console Game
[![Build Status](https://travis-ci.org/nolasconapoleao/game-lab.svg?branch=develop)](https://travis-ci.org/nolasconapoleao/game-lab)

Simple game to train design patterns.<br/><br/>

## Getting Started
These instructions will get you a copy of the project up and running on your local machine for development and testing purposes.<br/><br/>

## Build dependencies
These are the dependencies for the compilation of all the targets
```
cmake
cmake-format
clang-format
doxygen
gcov
ccache
```
<br/>

# Build instructions for development
## Create make files for each target (via cmake)
Run the cmake command and output the make recipe in the build folder
```
mkdir -p build/debug
cd build/debug
cmake -DCMAKE_BUILD_TYPE=Debug ../..
```
<br/>

## Build the continuous integration targets
Supported targets for continuous integration include:

    - Documentation
    - Coverage
    - Automatic tests
    - Static code analysis
    - Dynamic code analysis
<br/>

Run the jobs by running
```
make Documentation
make Coverage
make all && make test
```
<br/>

## Run code linters locally 
In order to merge to master the code in the pull request should be formatted using the checks defined in the project.
```
clang-format -i $filename
cmake-format -i $filename
```
<br/>

Code formating compliance can also be checked via pre commit hook.
```
cd <project-path>
cp tools/pre-commit.sh .git/hooks/pre-commit
chmod +x .git/hooks/pre-commit
```
<br/><br/>

## Build and run game

1. Create game target in release mode
```
mkdir -p build/release
cd build/release
cmake -DCMAKE_BUILD_TYPE=Release ../..
```
Note : For windows build.
 - Install build toolchain with [MinGW](http://www.mingw.org/wiki/getting_started)
 - Set the cmake option for windows build DUNIX_COMPILATION=OFF
```
cmake -DCMAKE_BUILD_TYPE=Release -DUNIX_COMPILATION=OFF ../..
```

2. Build the game
```
make Console-Game
```

3. Run the game
```
(WINDOWS) double-click executable in bin/Console-Game.exe
(LINUX)   ./bin/Console-Game
```
<br/>

## Future work
- Add static code analysis targets
- Add dynamic code analysis targets
- Add contribution guidelines
<br/><br/>

## Authors
* **Nolasco Napoleao** - [nolasconapoleao](https://github.com/nolasconapoleao)
