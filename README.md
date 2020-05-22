# Game Laboratory

Game source code using C++ and Cmake for testing ideas and experimenting with game development.

At the moment the game does not support graphics, it's only a text game, check these pictures:
![Game_v1-menu](/demo/Demo1.png)
![Game_v1-inventory](/demo/Demo2.png)
![Game_v1-talk](/demo/Demo3.png)

## Getting Started

These instructions will get you a copy of the project up and running on your local machine for development and testing purposes.

### Prerequisites

What things you need to install the software and how to install them

```
clang-format
cmake
doxygen
gcov
lcov
```

### Building

1. Run the cmake project and output the make recipe in the build folder
```
mkdir build
cd build
cmake ..
```

2. Build the library and all the executables defined in the Cmake 
```
make all
```

3. Run the game in the console
```
./Game_v1
```

### Contributing
To contribute feel free to clone or fork the repository and check the board to see what needs doing.
Help is needed in code architecture and definition of game concept.
https://trello.com/b/CERrFOYJ/text-game

### And coding style tests

In order to merge to master the code in the pull request should be formatted using the checks defined in <project>/.clang-format. To run the clang-format use:
```
clang-format -i $file
```

Another way is to use automatic formatting.
```
cd <project-path>
cp tools/pre-commit.sh .git/hooks/pre-commit
chmod +x .git/hooks/pre-commit
```

## Authors

* **Nolasco Napoleao** - *Initial work* - [nolasconapoleao](https://github.com/nolasconapoleao)
