<div align="center">
<h1 align="center">
<img src="https://raw.githubusercontent.com/PKief/vscode-material-icon-theme/ec559a9f6bfd399b82bb44393651661b08aaf7ba/icons/folder-markdown-open.svg" width="100" />
<br>philo
</h1>
<h3>◦ Unleash your inner philosopher with philo!</h3>
<h3>◦ Developed with the software and tools listed below.</h3>

<p align="center">
<img src="https://img.shields.io/badge/C-A8B9CC.svg?style&logo=C&logoColor=black" alt="C" />
</p>
<img src="https://img.shields.io/github/languages/top/hystb/philo?style&color=5D6D7E" alt="GitHub top language" />
<img src="https://img.shields.io/github/languages/code-size/hystb/philo?style&color=5D6D7E" alt="GitHub code size in bytes" />
<img src="https://img.shields.io/github/commit-activity/m/hystb/philo?style&color=5D6D7E" alt="GitHub commit activity" />
<img src="https://img.shields.io/github/license/hystb/philo?style&color=5D6D7E" alt="GitHub license" />
</div>

---

## 📒 Table of Contents
- [📒 Table of Contents](#-table-of-contents)
- [📍 Overview](#-overview)
- [⚙️ Features](#-features)
- [📂 Project Structure](#project-structure)
- [🧩 Modules](#modules)
- [🚀 Getting Started](#-getting-started)
- [🗺 Roadmap](#-roadmap)
---


## 📍 Overview

The "philo" project is a simulation of the dining philosophers problem, where the core functionality revolves around multiple philosophers trying to pick up forks to eat in a synchronized manner. The purpose of the project is to demonstrate synchronization and resource allocation using mutex locks, while also considering aspects like monitoring philosopher deaths and managing game settings. The value proposition lies in its ability to showcase the challenges and solutions of concurrent programming, helping developers gain a better understanding of synchronization problems and how to address them.

---

## ⚙️ Features

| Feature                | Description                           |
| ---------------------- | ------------------------------------- |
| **⚙️ Architecture**     | The codebase follows a modular architecture, separating functionalities into different files. The dining philosophers problem is solved using multithreading and synchronization with mutexes. |
| **📖 Documentation**   | The codebase includes a header file with extensive comments, providing clear explanations of the program structure, function prototypes, and constants. The code itself is well-commented, aiding understanding. |
| **🔗 Dependencies**    | The codebase relies on standard C libraries and does not have any external dependencies. |
| **🧩 Modularity**      | The codebase organizes the project into separate files, with each file handling a specific aspect of the simulation, such as error handling, game logic, initialization, and utility functions. This modular approach enhances code readability and maintainability. |
| **✔️ Testing**          | The codebase does not explicitly include tests. However, the simulation aspect allows manual validation by observing the expected behavior of the philosophers and their actions. |
| **⚡️ Performance**      | The codebase efficiently handles synchronization and resource allocation through the use of mutexes, ensuring proper coordination among the philosophers. It also utilizes multithreading to run the simulation concurrently. |
| **🔐 Security**        | The codebase does not focus on security measures as the primary goal is to simulate the dining philosophers problem. However, it correctly manages shared resources and ensures proper synchronization to prevent race conditions. |
| **🔀 Version Control** | The codebase uses Git for version control, allowing collaboration, tracking changes, and maintaining the project's history. |
| **🔌 Integrations**    | The codebase does not have any direct integrations with external systems or services. |
| **📶 Scalability**     | The codebase does not explicitly address scalability. However, it can handle multiple philosophers and forks efficiently due to its multithreaded implementation. To handle significant scalability, further design considerations may be required. |

---


## 📂 Project Structure


```bash
repo
└── philo
    ├── control_death.c
    ├── error.c
    ├── fork.c
    ├── game.c
    ├── init.c
    ├── log
    ├── main.c
    ├── Makefile
    ├── philo.h
    └── utils.c

1 directory, 10 files
```

---

## 🧩 Modules

<details closed><summary>Philo</summary>

| File                                                                              | Summary                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                       |
| ---                                                                               | ---                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                           |
| [game.c](https://github.com/hystb/philo/blob/main/philo/game.c)                   | The provided code snippet is a part of a game simulation in the "philo" program. It includes functionalities like checking if a philosopher has died, counting their eating attempts, allowing them to eat using forks, starting the actions for each philosopher, and running the game with multithreading.                                                                                                                                                                                                                                                                                                                                                                  |
| [philo.h](https://github.com/hystb/philo/blob/main/philo/philo.h)                 | The provided code snippet is the header file "philo.h" for a program that simulates the dining philosophers problem. It includes necessary libraries, defines error messages and constants, declares struct types for philosophers and game data, and prototypes functions for initializing the program, starting the simulation, printing actions, and handling synchronization and resource allocation.                                                                                                                                                                                                                                                                     |
| [error.c](https://github.com/hystb/philo/blob/main/philo/error.c)                 | The provided code snippet includes functions for handling errors and displaying error messages in a project related to a dining philosophers problem simulation. The "error_alloc" function handles different error cases related to memory allocation and mutexes, freeing resources accordingly.The "error_mutex" function handles error cases related to mutexes, freeing resources.The "error_message" function prints different error messages based on the error code provided.The "ft_putstr_fd" function writes a string to a given file descriptor.Overall, these functions contribute to the error handling and error message display functionality in the project. |
| [control_death.c](https://github.com/hystb/philo/blob/main/philo/control_death.c) | This code snippet includes functions for controlling the death of philosopher threads in a dining philosopher problem simulation. It provides functionality to lock and unlock the mutexes associated with each philosopher's meal check. It also includes a death checker function that determines if a philosopher has exceeded the time allowed since their last meal. Finally, the control_death function continuously monitors the philosopher threads for deaths and stops the simulation if all philosophers have successfully eaten their required number of times or if a philosopher has died.                                                                      |
| [utils.c](https://github.com/hystb/philo/blob/main/philo/utils.c)                 | This code snippet provides several utility functions for the "philo" program. It includes functions for checking if a character is a digit, converting strings to integers, getting the current time, printing the philosopher's actions, and implementing a wait function with customizable duration.                                                                                                                                                                                                                                                                                                                                                                        |
| [Makefile](https://github.com/hystb/philo/blob/main/philo/Makefile)               | The provided code snippet is a makefile with the following core functionalities:-Compiling and linking source files to create an executable program called "philo"-Handling dependencies and object files-Cleaning up generated files using "clean" and "fclean" commands-Supporting "re" command to clean and recompile the code                                                                                                                                                                                                                                                                                                                                             |
| [init.c](https://github.com/hystb/philo/blob/main/philo/init.c)                   | The code snippet initializes the necessary data structures and variables for a simulation game involving philosophers (philo). It initializes mutex locks for forks and a writing lock. It also creates and initializes philosopher objects with their respective IDs, fork IDs, status flags, and necessary variables for the simulation. Finally, it sets up the game settings based on command line arguments.                                                                                                                                                                                                                                                             |
| [log](https://github.com/hystb/philo/blob/main/philo/log)                         | The code snippet represents a dining philosophers problem simulation. Each number represents a philosopher. They alternate between thinking, picking up forks, and eating.                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                    |
| [main.c](https://github.com/hystb/philo/blob/main/philo/main.c)                   | This code snippet is the main entry point of a program that simulates a dining philosophers problem. It initializes the game rules and handles any errors that occur. It then starts the game simulation and frees up the allocated memory before exiting.                                                                                                                                                                                                                                                                                                                                                                                                                    |
| [fork.c](https://github.com/hystb/philo/blob/main/philo/fork.c)                   | The code snippet defines functions for a dining philosopher problem where the philosophers try to pick up forks to eat. The "swap_fork" function swaps the left and right fork for odd numbered philosophers. The "give_fork" function assigns the left and right forks and their status to variables. The "nxt_step" function simulates the next step for a philosopher, including checking if they have died, printing their actions, updating the time since they last ate, and releasing the forks. The "take_fork" function marks a fork as taken by a philosopher.                                                                                                      |

</details>

---

## 🚀 Getting Started

### ✔️ Prerequisites

Before you begin, ensure that you have the following prerequisites installed:
> - `ℹ️ None`

### 📦 Installation

1. Clone the philo repository:
```sh
git clone https://github.com/hystb/philo
```

2. Change to the project directory:
```sh
cd philo
```

3. Build:
```sh
make
```

### 🎮 Using philo

```sh
./philo <nb_philo> <time_to_die> <time_to_eat> <time_to_sleep> (not mandatory)<nb_of_eat_before_stop>
```
