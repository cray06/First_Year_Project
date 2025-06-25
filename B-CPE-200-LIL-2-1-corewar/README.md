# Corewar

Corewar is a game where programs (called "champions") fight in a virtual machine. Each champion is written in a specific assembly language and competes for control of the memory space.

## Description

Corewar is a game where programs written in a specific assembly language (called "champions") fight in a virtual machine. The goal is to be the last program running. Each champion is loaded into the memory space and executes its instructions. The last champion alive wins.

The project includes a bonus visualizer that shows the battle in real-time using ncurses.

## Features

- Virtual machine that executes champion programs
- Support for multiple champions
- Real-time visualization of the battle (bonus)
- Color-coded display of champion memory spaces
- Live instruction execution tracking
- Memory scrolling
- Detailed game statistics

## Requirements

- GCC compiler
- Make
- ncurses library (for bonus)

## Installation

1. Clone the repository:
```bash
git clone [repository-url]
cd corewar
```

2. Install ncurses (for bonus):
```bash
# On Ubuntu/Debian
sudo apt-get install libncurses5-dev

# On macOS
brew install ncurses
```

3. Build the project:
```bash
# Build main program
make

# Build with bonus visualizer
make bonus
```

## Usage

### Main Program
```bash
./corewar [-dump nbr_cycle] [[-n prog_number] [-a load_address] prog_name] ...
```

Options:
- `-dump nbr_cycle`: Dumps memory after nbr_cycle cycles
- `-n prog_number`: Sets the program number
- `-a load_address`: Sets the load address
- `prog_name`: The champion program to load

### Bonus Visualizer
```bash
./corewar_bonus [-n prog_number] [-a load_address] prog_name ...
```

The visualizer provides:
- Real-time memory display
- Color-coded champion memory spaces
- Current instruction execution tracking
- Game statistics
- Memory scrolling with arrow keys
- Press 'q' to quit

## Controls (Bonus Visualizer)

- `↑`: Scroll up in memory
- `↓`: Scroll down in memory
- `q`: Quit the visualizer

## Champion Programs

Champions are written in a specific assembly language and compiled into bytecode. They can:
- Execute instructions
- Read/write to memory
- Create new processes
- Declare themselves as alive

## Memory Space

The virtual machine has a circular memory space of 6*1024 bytes. Champions are loaded into this space and can:
- Read from any memory location
- Write to any memory location
- Execute instructions from any memory location

## Visualizer Features

The bonus visualizer provides:
1. Memory Display:
   - Hex representation of memory
   - Color-coded champion memory spaces
   - Current instruction execution tracking
   - Memory addresses

2. Information Display:
   - Current cycle count
   - Cycle to die
   - Number of lives
   - Champion information:
     - Player number
     - Champion name
     - Lives count
     - Program counter
     - Cycles count

## Author

Gabriel Decloquement

## License

This project is part of the Epitech curriculum. 