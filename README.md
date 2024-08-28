# miniRT - My First Ray Tracer

<img width="1358" alt="Screen Shot 2024-08-28 at 6 39 30 PM" src="https://github.com/user-attachments/assets/a35e8a61-080f-48a6-ab70-de768d832741">

This project is an implementation of a simple ray tracer using the miniLibX library. It's capable of rendering basic 3D scenes described in .rt files.

## Compilation

This project uses a Makefile for compilation. Here are the main commands:

- `make`: Compile the mandatory part
- `make bonus`: Compile the bonus part
- `make clean`: Remove object files
- `make fclean`: Remove object files and executables
- `make re`: Recompile the project

The compilation process will create an executable named `miniRT` for the mandatory part or `miniRT_bonus` for the bonus part.

### Creating the Executable

To create the executable, follow these steps:

1. Open a terminal and navigate to the project's root directory.
2. For the mandatory part, run:
   ```
   make
   ```
   This will create the `miniRT` executable.

3. For the bonus part, run:
   ```
   make bonus
   ```
   This will create the `miniRT_bonus` executable.

4. If you want to recompile everything from scratch, you can use:
   ```
   make re
   ```
   or
   ```
   make fclean && make
   ```

After successful compilation, you should see the `miniRT` or `miniRT_bonus` executable in your project directory.

## Usage

To run the program:

```
./miniRT <scene_file.rt>
```

For the mandatory part, use the files in `data/` that start with "mandatory_".
For the bonus part, use the files that start with "bonus_".

Example:
```
./miniRT data/mandatory_model.rt
```

## Technologies Used

- C programming language
- miniLibX library for graphical rendering
- Math library for mathematical calculations
- Ray tracing algorithms for 3D rendering

## Norminette

This project follows the Norm, a programming standard used at 42 school. For more information about the Norm and the Norminette tool used to check it, please refer to the [42 Norm repository](https://github.com/42School/norminette).

## Features

- Render basic 3D shapes: spheres, planes, and cylinders
- Handle ambient and diffuse lighting
- Parse .rt scene description files
- Apply translations and rotations to objects
- Handle window management and basic user input

Bonus features (if implemented):
- Specular reflection (Phong reflection model)
- Checkerboard pattern
- Multiple colored lights
- Additional shapes (cone, hyperboloid, paraboloid)
- Bump mapping

## Note

Make sure you have the necessary libraries installed, including miniLibX and the math library, before compiling the project.