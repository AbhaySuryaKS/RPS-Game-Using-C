
# Rock Paper Scissors Game in C

A simple terminal-based **Rock-Paper-Scissors** game implemented in C, featuring:

* Single Game mode
* Best of 3 mode
* Infinite Game mode with live score tracking
* Scoreboard display
* User-friendly input validation

---

##  Project Structure

```
RPS-Game-Using-C/
│
├── code.c    # Main C source code
└── README.md                # Project documentation
```

---

## Requirements

* GCC compiler or any C compiler
* Terminal/command prompt

---

## Game Modes

###  Single Game

Play one round against the computer.

###  Best of 3

First to win **2 rounds** out of 3.

###  Infinite Game

Play unlimited rounds until you decide to stop.

---

##  Features

*  Custom player name input
*  Random computer moves
*  Scoreboard after each round
*  Input validation for choices and prompts
*  Input buffer cleared to avoid infinite loops

---

##  Sample Output

```
===== Rock Paper Scissors Game =====

Enter Player Name: Abhay
Welcome Abhay

Choose your option:
1. Single game
2. Best of 3
3. Infinite game
4. Exit
Enter your choice (1-4): 2

You chose Best of 3.

Enter your choice:
1. Rock
2. Paper
3. Scissors
Please enter your choice (1-3): 2

Abhay chose: Paper
Computer chose: Rock
Abhay wins!

-------------------
| Player  | Score |
-------------------
| Abhay   | 1     |
| Computer| 0     |
-------------------

Enter your choice:
1. Rock
2. Paper
3. Scissors
Please enter your choice (1-3): 1

Abhay chose: Rock
Computer chose: Scissors
Abhay wins!

-------------------
| Player  | Score |
-------------------
| Abhay   | 2     |
| Computer| 0     |
-------------------
Abhay wins the best of 3!
===============================================

Choose your option:
1. Single game
2. Best of 3
3. Infinite game
4. Exit
Enter your choice (1-4): 4

Exiting the game.

===============================================


```

---

## Notes

* Uses `rand()` for computer choices, seeded by current time (`srand(time(NULL))`).
* Score is maintained and displayed using a flexible-width scoreboard.
* Newline characters in name input are handled using `strcspn()`.

---

## Author

**Abhay Surya K.S.**
New Horizon College of Engineering
CSE Department, Batch 2024–28

---

## License

This project is open-source and available for learning and personal use.

---

Let me know if you’d like this exported as a downloadable file or want enhancements like color output or difficulty levels!
