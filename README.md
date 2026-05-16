# Tic-Tac-Toe AI in C++

This is a fully functional Tic-Tac-Toe game with a smart AI opponent, built entirely from scratch in C++. 

## Features
* **Player vs AI Gameplay:** Play directly against the computer.
* **Smart AI:** The computer actively calculates moves to block the player from winning and looks for opportunities to win itself.
* **Cross-Platform Support:** Uses preprocessor directives to run flawlessly on Windows, Linux, and macOS.
* **Clean Interface:** Console-based grid display that dynamically clears the screen between turns for a smooth experience.

## Prerequisites
To compile and run this game, you will need a C++ compiler (like `g++` or MinGW) installed on your system.

## How to Compile and Run

### On Linux / macOS
1. Open your terminal and navigate to the folder containing the code.
2. Compile the code:
   g++ main.cpp -o tictactoe
3. Run the game:
   ./tictactoe

### On Windows
1. Open your Command Prompt or PowerShell and navigate to the folder.
2. Compile the code:
   g++ main.cpp -o tictactoe.exe
3. Run the game:
   .\tictactoe.exe

## How to Play
Once the game is running, you will play as 'X'. The game will ask you to enter a row number (1, 2, or 3) and a column number (1, 2, or 3). The grid updates automatically, and the AI will take its turn right after you.
