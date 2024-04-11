# Fract'ol
Fract'ol is a project developed as part of the curriculum at École 42. It's a graphical application that allows users to explore various types of fractals in real-time.

### Language : ![C language](https://img.shields.io/badge/C-00599C?style=for-the-badge&logo=c&logoColor=white)

### Overview
Fract'ol generates and displays fractal images using the GPU and provides interactive controls for users to navigate and manipulate the fractals. It supports rendering multiple types of fractals, including the Mandelbrot set, Julia set, and more.

### Features
Real-time rendering of fractal images.
Support for various types of fractals, including the Mandelbrot set, Julia set, Burning Ship, and more.
Zooming and panning functionalities to explore fractals in detail.
Customizable color schemes and rendering parameters.
Multithreaded rendering for improved performance on multi-core processors.

### Usage
#### Compilation
To compile the Fract'ol program, run the following command:

First :
go in the mini-libx and :

```shell
make
```
to create the minilibx library.

Second:
return to the project directory
```shell
make
```
Third:
```shell
make bonus
```
Now every executable are ready.

#### Execution:
To execute the program, run the following command:

```shell
./fractol [fractal_type]
```
[fractal_type] with one of the supported fractal types (e.g., mandelbrot, julia, burning_ship).

For me it's:
```shell
>$ ./fractol
Les differentes commandes sont:
Mandel
Julias
Julias X.XXX X.XXX
```

```shell
>$ ./fractol Mandel
```
This command will lauch the Mandelbrot's fractal : 
![Mandel](img/Mandel.png)
```shell
>$ ./fractol Julias
```
This command will lauch the Julias's fractal :
![Julias](img/Julias.png)

```shell
>$ ./fractol Julias 0.285 0.01
```
This command will lauch the Julias's fractal on the point : 0.285, 0.01 :
![Julias_origin](img/Julias_0.285_0.01.png)

#### Controls
* Use the arrow keys or mouse to navigate the fractal.
* Use the mouse scroll or keypad +/- keys to zoom in and out. (if it's not in bonus you just zoom in the center)
* Press ESC to exit the program.

For Julias's fractal (same as Mandelbrot's fractal but i have added one feature):
* Click on the screen to change the point and change the fractal.

#### Execution bonus
It's the same as before but now I have added the Newton fractal.

```shell
>$ ./fractol_bonus
Les differentes commandes sont:
Mandel
Julias
Julias X.XXX X.XXX
Newton
```

```shell
>$ ./fractol_bonus Mandel
```
Give the same result just like the mandatory part.
```shell
>$ ./fractol_bonus Julias
```
Give the same result just like the mandatory part.
```shell
>$ ./fractol_bonus Julias 0.285 0.01
```
Give the same result just like the mandatory part.
```shell
>$ ./fractol_bonus Newton
```
![Newton](img/Newton.png)

#### Controls bonus
The controls are the same but I have added a two features:
* Press S to switch color schemes.
* you can zoom on the position of your cursor.

### Different Julias Fractal to try: 

x      |   y    |  image
:-----:|:------:|:---------:
-0.79  | 0.15   | ![julias_one](img/Julias_-0.79_0.15.png)
-0.162 | 1.04   | ![julias_two](img/Julias_-0.162_1.04.png)
0.3    | -0.01  | ![julias_three](img/Julias_0.3_-0.01.png)
-1.476 | 0.0    | ![julias_four](img/Julias_-1.476_0.0.png)
-0.12  | -0.77  | ![julias_five](img/Julias_-0.12_-0.77.png)
0.28   | 0.008  | ![julias_six](img/Julias_0.28_0.008.png) 
