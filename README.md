# Instructions to Run the Code

## Table of Contents
- [Instructions to Run the Code](#instructions-to-run-the-code)
  - [Table of Contents](#table-of-contents)
  - [Introduction](#introduction)
  - [Opening the Terminal](#opening-the-terminal)
  - [Compiling the Code](#compiling-the-code)
  - [Running Test Cases](#running-test-cases)
  - [Cleaning Up](#cleaning-up)
  - [Visualizing the Assignments](#visualizing-the-assignments)
  - [Output Image](#output-image)
  - [Conclusion](#conclusion)

## Introduction
You are not required to modify anything in the program files.  
These instructions do NOT apply for Windows. They are intended for Unix-based systems like macOS and Linux.

## Opening the Terminal
Open your terminal of preference, preferably the VSCode integrated terminal with:  
<span class="keyboard-shortcut"><kbd>Ctrl</kbd> + <kbd>J</kbd></span>

## Compiling the Code
Type `make` to compile the library and gain access to the fully compiled executable called `main`.

## Running Test Cases
We have a directory called `catalogues`, containing different sizes of test cases. You can run them by typing `./main <desired test case's relative path>`.

## Cleaning Up
Don't forget to run `make clean` after you are done using the code. Feel free to alter the `main` file and make use of our different available methods as you wish.

## Visualizing the Assignments

To visually comprehend the graphs created by your program, navigate to the `main.c` file. Ensure that, alongside `init_graph` and `destroy_graph`, the `print_dot` method is the only one not commented out. This setup is crucial for generating visual representations of your graphs.

The command `make vis` is specifically configured to visualize the graph described in the assignment. Should you wish to visualize different test cases, you can easily modify the corresponding commands in the `Makefile`. However, be mindful that graph visualization might not be as effective for very large test cases due to the limitations of the visualization tool.

## Output Image
The default `make vis` command should output this image:
<br><br>
![Visualization Output](./assets/assets.png)

## Conclusion
If you have any questions or need further assistance, please contact [alex.gabriel@edu.pucrs.br](mailto:alex.gabriel@edu.pucrs.br) or [r.sandler@edu.pucrs.br](mailto:r.sandler@edu.pucrs.br).
