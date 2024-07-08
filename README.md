
# cub3d

## Overview

cub3d is a graphic design project inspired by the classic Wolfenstein 3D game, aimed at exploring ray-casting techniques using the miniLibX library. The objective is to create an immersive first-person perspective inside a maze environment.

## Features

-   Implement ray-casting to simulate 3D graphics in real-time.
-   Display textured walls with varying textures based on orientation.
-   Navigate the maze using keyboard controls (WASD) and look around (arrow keys).
-   Customize floor and ceiling colors for visual aesthetics.
-   Read scene configuration from a `.cub` file specifying textures and map layout.

## Installation

1.  **Clone the repository**:    `git clone https://github.com/mbrettsc/cub3d.git
   && cd cub3d` 
    
2.  **Build the project**:    `make` 
    

## Usage
`./cub3D path_to_your_map.cub` 

## Dependencies

-   `gcc` (or any compatible C compiler)
-   `make` build automation tool
-   `miniLibX` library for graphical rendering

## Scene File Format

The `.cub` scene file must include:

-   Texture paths for North, South, East, and West walls (`NO`, `SO`, `WE`, `EA`).
-   Floor and ceiling colors (`F` and `C`).
-   Map layout consisting of characters: `0` (empty space), `1` (wall), `N/S/E/W` (player start position).
