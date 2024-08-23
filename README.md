# Cross-Platform Game Framework for Desktop and Nintendo 3DS

## Overview

The **Cross-Platform Game Framework** is designed for developing 2D games that run on both desktop and Nintendo 3DS platforms using a unified codebase. It simplifies the complexities of multi-platform game development by providing a consistent interface for both environments.

*Framework written in C++ using the RayLib framework and devkitPro toolchain.*

Developed by **Alexander Shemaly** in 2024.

To see an example game using this framework, see my [STARGLIDE](https://github.com/AlexShem247/starglide-3ds) game.

## Features

- **Platform Flexibility**: Supports both desktop and Nintendo 3DS with a single codebase.
- **Graphics Handling**: Draw lines, shapes, images, and text.
- **Input Management**: Handle user input across both platforms.
- **Dual-Screen Support**: Special functionality for the Nintendo 3DS's top and bottom screens.

## Installation

### Dependencies

- **For Desktop**: 
  - Requires the [raylib](https://www.raylib.com/) library for graphics handling. 
  - Note: You need to install raylib separately; it does not come with the codebase. Instructions for installation can be found on the [raylib GitHub page](https://github.com/raysan5/raylib).

- **For Nintendo 3DS**:
  - Requires [devkitPro](https://devkitpro.org/) for compiling. 
  - Follow the [devkitPro installation guide](https://devkitpro.org/wiki/Getting_Started) to set up your environment.

### Building for Desktop

1. **Clone the Repository**:
    ```bash
    git clone https://github.com/AlexShem247/desktop-3ds-game-framework.git
    ```

2. **Navigate to the Project Directory**:
    ```bash
    cd desktop-3ds-game-framework
    ```

3. **Install Dependencies**:
   - Follow the installation instructions for raylib as specified on their [GitHub page](https://github.com/raysan5/raylib).

4. **Compile the Code**:
   - Note: No makefile is included. You need to manually compile the code using your preferred method.

### Building for Nintendo 3DS

1. **Clone the Repository**:
    ```bash
    git clone https://github.com/AlexShem247/desktop-3ds-game-framework.git
    ```

2. **Navigate to the Project Directory**:
    ```bash
    cd desktop-3ds-game-framework
    ```

3. **Install Dependencies**:
   - Follow the [devkitPro installation guide](https://devkitpro.org/wiki/Getting_Started) to set up your environment.

4. **Compile the Code**:
   - Run `make` to generate a `.3dsx` file. This file can be run with the [Citra Emulator](https://citra-emulator.com/) (for testing purposes).

5. **Create a .cia File for Installation**:
   - Run `build-CIA.bat` to generate a `.cia` file. Note: This `.bat` file only works on Windows. For other operating systems, you will need to run equivalent commands manually.

6. **Modify CIA Properties**:
   - Modify properties by editing `build-CIA.bat` and files in the `assets/cia` directory.

## Switching Platforms
Changing the platform of the game can be done by commenting out one line of code:
```c++
// Define which engine to use
#define USE_DESKTOP_ENGINE // Comment out before compiling for 3DS

#ifdef USE_DESKTOP_ENGINE
    #include "desktopEngine.h"
    using EngineType = DesktopEngine;
#else
    #include "n3dsEngine.h"
    using EngineType = N3DSEngine;
#endif
```

## Documentation

For detailed documentation, including API references and advanced usage examples, please refer to the [Documentation](https://github.com/AlexShem247/desktop-3ds-game-framework/wiki) in the project’s GitHub wiki.

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.
