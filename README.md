# Tower of Hanoi Visualizer (C++)

A colorful and interactive C++ implementation of the classic Tower of Hanoi puzzle using recursion and stacks. The project visually simulates disk movements between rods, includes a menu-driven interface, animated transitions, and calculates the minimum required moves.

---

## Features
- Recursive Tower of Hanoi solution
- Visual rod and disk representation
- ANSI color-based terminal UI
- Animated disk movement simulation
- Menu-driven interface
- Displays total and expected moves
- Uses C++ STL stacks and vectors

---

## Concepts Used
- Recursion
- Stack Data Structure
- Vectors
- Function Calls
- Algorithm Design
- Console Animation


## How It Works
The program solves the Tower of Hanoi puzzle by recursively moving disks between three rods:
- **A** → Source Rod
- **B** → Auxiliary Rod
- **C** → Destination Rod

### Rules
1. Only one disk can be moved at a time.
2. A larger disk cannot be placed on a smaller disk.
3. All disks must be moved from the source rod to the destination rod.

The simulation visually displays every move step-by-step.

## Menu
1. Start Simulation
2. Show Expected Moves
3. Exit

## Technologies Used
1. C++
2. STL (stack, vector)
3. ANSI Escape Codes