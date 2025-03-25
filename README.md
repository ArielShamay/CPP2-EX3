# Settlers of Catan - C++ Implementation

### Ariel Shamay
**Email:** [arielsh49@gmail.com](mailto:arielsh49@gmail.com)  
**LinkedIn:** [https://www.linkedin.com/in/ariel-shamay-78011a2b0](https://www.linkedin.com/in/ariel-shamay-78011a2b0)

---

## Overview

This project is a C++ implementation of the popular board game **"Settlers of Catan"**. It encapsulates the main features of the original game, including board setup, resource management, development cards, and player interactions. The codebase follows object-oriented design principles to ensure modularity and readability.

---

## Project Structure

- **`Board.cpp / Board.hpp`**: Implements the game board, managing tiles, vertices, and edges.
- **`Game.cpp / Game.hpp`**: Contains game logic, turn management, and gameplay rules.
- **`Player.cpp / Player.hpp`**: Defines player behaviors, resource handling, and scoring.
- **`Tile.cpp / Tile.hpp`**: Represents the individual tiles of the board, each producing specific resources.
- **`Vertex.cpp / Vertex.hpp`** and **`Edge.cpp / Edge.hpp`**: Represent buildable locations for settlements, cities, and roads.
- **`DevelopmentCard.cpp / DevelopmentCard.hpp`**: Implements functionality related to development cards.
- **`Resource.cpp / Resource.hpp`**: Manages resource types and their distribution.
- **`Demo.cpp`**: Demonstrates gameplay scenarios.
- **`Test.cpp / TestCounter.cpp`**: Contains unit tests to validate game mechanics.

---

## Setup and Run Instructions

### Clone Repository

```bash
git clone https://github.com/ArielShamay/SettlersOfCatan.git
```

### Navigate to Project Directory

```bash
cd SettlersOfCatan
```

### Build the Project

Use the provided Makefile to compile:

```bash
make
```

### Run the Game Demo

Execute the demo to experience gameplay:

```bash
./CatanGame
```

### Run Tests

Run the unit tests to verify correctness:

```bash
make test
./Test
```

Tests output results for verification of correctness of game logic.

### Clean Build Files

Remove compiled files using:

```bash
make clean
```

---

## Features Implemented

- **Resource Generation and Management**
- **Building Settlements, Cities, and Roads**
- **Development Card Mechanics**
- **Turn-Based Gameplay Logic**
- **Player Interaction and Trade Dynamics**

---

## Technologies & Concepts

- **Languages:** C++
- **Tools:** Makefile, g++, Doctest (for unit testing)
- **Concepts:** Object-Oriented Programming, Game Logic, Data Structures

---

## Notes

Ensure `g++` compiler is installed and available in your system PATH to build and run this project.

