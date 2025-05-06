# Raylib Pong

A pong game I wrote to practice C++ and Raylib, but it has some "annoying" features: the enemy paddle randomly changes its y position to the y position of the ball, comes closer to the center of the screen and changes size.

The entire game is in the file `new_project.cpp`.

https://github.com/user-attachments/assets/18aebb51-b200-4565-9ffa-3fb2dbde22c9

### Compiling
The repository contains a Visual Studio Code workspace (tested on version 1.81.1)

After installing Raylib 5.5 [https://raysan5.itch.io/raylib] open the `main.code-workspace` in Visual Studio Code and run the Build Task (keyboard shortcut F5).


### Features
* Entire game in one .cpp file
* Moving paddles
* User input with up and down arrows
* Ball and paddle collisions
* Ball bouncing off screen edges and paddles
* Scoring when the ball moves outside the sides of the screen
* Resetting ball position after scoring
* Randomized enemy paddle behavior
