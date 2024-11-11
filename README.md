# XO Game

## Overview

**XO Game** is a command-line-based Tic-Tac-Toe game developed in C. It offers both single-player and multiplayer modes, tracks player statistics through a leaderboard, and maintains a history of all games played. The single-player mode includes both easy and hard difficulty levels, with the hard mode leveraging the Minimax algorithm for optimal gameplay.

## Features

- **Single Player Mode**
  - **Easy:** The computer makes random moves.
  - **Hard:** The computer uses the Minimax algorithm for strategic moves.
  
- **Multiplayer Mode**
  - Play against another human player.

- **Leaderboard**
  - Tracks and displays statistics for both single-player and multiplayer games.

- **Game History**
  - Records all game outcomes, including player names and results.

- **Persistent Storage**
  - Saves game state, leaderboard, and game history to CSV files for continuity between sessions.

## Installation

### Prerequisites

- **C Compiler:** Ensure you have `gcc` installed on your system.
  
  - **macOS:**
    ```bash
    brew install gcc
    ```
  
  - **Ubuntu/Debian:**
    ```bash
    sudo apt-get update
    sudo apt-get install build-essential
    ```
  
- **Make:** Required to compile the project using the provided Makefile.
  
  - **macOS:**
    ```bash
    brew install make
    ```
  
  - **Ubuntu/Debian:**
    ```bash
    sudo apt-get install make
    ```

### Clone the Repository

```bash
git clone https://github.com/yourusername/xo_game.git
cd xo_game
```

## Compilation

Use the provided Makefile to compile the project.

```bash
make
```

This command will generate an executable named `xo_game` in the project directory.

### Cleaning Up

To remove compiled object files:

```bash
make clean
```

To remove both object files and the executable:

```bash
make fclean
```

To rebuild the project from scratch:

```bash
make re
```

## Usage

Run the executable from the terminal:

```bash
./xo_game
```

### Gameplay Options

Upon running, you will see the following menu:

```
******************************************
*            Welcome to XO Game          *
******************************************

Select an option:
1. Single Player (Easy)
2. Single Player (Hard)
3. Multiplayer
4. View Leaderboard
5. Exit

Enter your choice:
```

#### 1. Single Player (Easy)

- Play against the computer.
- The computer makes random moves.

#### 2. Single Player (Hard)

- Play against the computer.
- The computer uses the Minimax algorithm for optimal moves.

#### 3. Multiplayer

- Play against another human player.

#### 4. View Leaderboard

- Displays the current leaderboard with player statistics.

#### 5. Exit

- Saves the current game state and exits the game.

### Making a Move

- When prompted, enter the number corresponding to the position on the game board where you want to place your mark (1-9).

## Dependencies

This project uses only standard C libraries. No external dependencies are required beyond a C compiler (`gcc`).

- **Standard C Libraries:**
  - `stdio.h`
  - `string.h`
  - `stdlib.h`
  - `time.h`

## File Structure

- `main.c`: Entry point of the program.
- `game_init.c`: Initializes and displays the game board.
- `game_logic.c`: Contains game logic, including checking for winners.
- `player_actions.c`: Handles player and computer moves, including the Minimax algorithm.
- `display.c`: Manages displays such as the home page, leaderboard, and game history.
- `save_load.c`: Handles saving and loading game board, leaderboard, and game history.
- `main.h`: Header file containing structure definitions, global variables, and function prototypes.
- `Makefile`: Instructions for compiling the project.
- `game_board.csv`: Saves the current state of the game board.
- `leaderboard.csv`: Stores player statistics for single and multiplayer modes.
- `game_history.csv`: Records the history of all games played.

## Data Files

- **`game_board.csv`**
  - Stores the current state of the game board.
  
- **`leaderboard.csv`**
  - Contains statistics for both single-player and multiplayer games, including wins and computer wins.
  
- **`game_history.csv`**
  - Logs all games played, detailing game type, player names, and results.

These files are automatically created and updated in the project directory when you run the game.

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.

## Contributing

Contributions are welcome! Please follow these steps to contribute:

1. Fork the repository.
2. Create a new branch for your feature or bugfix.
3. Commit your changes with descriptive messages.
4. Submit a pull request detailing your changes.

## Contact

For any questions or suggestions, please contact [your-email@example.com](mailto:your-email@example.com).
