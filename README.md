*This project has been created as part of the 42 curriculum.*

# FDF - Wireframe Model

## Description
FDF is a computer graphics project aimed at simply representing a 3D landscape as a wireframe model. Within the scope of the project, coordinate points (x, y, z) in a given `.fdf` file are read, connected via line segments (edges), and the model is rendered on the screen.

The main objectives of this project are to understand the logic of graphics programming, implement line-drawing algorithms (such as Bresenham's), and learn window and event management using the MiniLibX library.

---

## Features and Rules
* **Isometric Projection:** The program is strictly required to render the created model on the screen using isometric projection.
* **MiniLibX Usage:** Utilizing the image features of the MiniLibX library is mandatory during the processes of image creation and rendering on the screen.
* **Window Management:** Window management remains smooth (no freezing occurs when switching to another window).
* **Exit Operations:** Pressing the `ESC` key or clicking the close cross (X) icon on the window frame closes the window and cleanly terminates the program, freeing all allocated memory.

---

## Instructions

### Compilation
To compile the project, simply run the following command in the terminal:
make

This process will compile your source files with `-Wall`, `-Wextra`, and `-Werror` flags, generating the executable file named `fdf`. The `clean`, `fclean`, and `re` rules can be used for cleanup operations when necessary.

### Execution
The program must take a valid map file as a parameter:
./fdf test_maps/42.fdf

Each number in the map represents a point in space:
* The horizontal position represents the abscissa (X axis).
* The vertical position represents the ordinate (Y axis).
* The value of the number represents the altitude (Z axis).

---

## Resources & AI Usage
* **Core References:** Bresenham's Line Algorithm, Isometric Projection Formulas, and MiniLibX Library Documentation.
* **AI Usage:** In this project, AI tools were utilized to reduce code repetition during the process of reading and parsing `.fdf` files, as well as to brainstorm correct and efficient algorithmic approaches (e.g., line-drawing logic). The generated content or logic was not directly copied into the project; instead, it was systematically tested, questioned, and integrated into the code following peer reviews.
