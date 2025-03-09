# Conway's Nodes

Conway's Nodes is an implementation of Conway's Game of Life in C++ using the SDL2 library for graphical rendering. In this project, a grid of cells evolves according to the classic rules of cellular automata. The simulation advances one generation at a time by pressing the **Space** key.

## Table of Contents

- [Description](#description)
- [Features](#features)
- [Requirements](#requirements)
- [Build and Run](#build-and-run)
- [Screenshots](#screenshots)
- [Contribution](#contribution)
- [License](#license)
- [Cloning the Repository](#cloning-the-repository)

## Description

Conway's Game of Life is a cellular automaton where each cell on a grid is either alive or dead. The state of each cell evolves based on a set of simple rules that take into account the status of neighboring cells. **Conway's Nodes** is a straightforward implementation designed to demonstrate that the concept can be realized quickly. In this version, each generation is manually triggered by pressing the **Space** key.

## Features

- **Simulation of Conway's Game of Life:** Implements the classic rules of cellular automata.
- **Manual Control:** Advance the simulation generation by generation by pressing the **Space** key.
- **Graphical Output:** Uses the **SDL2** library to display the evolving grid of cells.

## Requirements

- **CMake:** For configuring and generating build files.
- **SDL2:** Library for handling graphics.
- A C++ compiler that supports modern C++ standards.

## Build and Run

Follow these steps to compile and run the project. You can copy and paste the following commands into your terminal:

```bash
# Clone the repository (if you haven't already)
git clone https://github.com/ThibaultPND/Noeud2Conway.git

# Navigate to the project directory
cd Noeud2Conway

# Create a build directory and navigate into it
mkdir build
cd build

# Generate the build files using CMake
cmake ..

# Compile the project
make

# Run the executable
./ConwaysNodes
```
Once the program is running, press the **Space** key to advance to the next generation.

## Screenshots
Below there are screenshots of the  in action.

![Exemple Screenshot](/assets/screen1.png)