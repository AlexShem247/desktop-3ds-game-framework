#include <iostream>
#include <vector>
#include <string>

#include "shapes.h"

// Define which engine to use
// #define USE_DESKTOP_ENGINE

#ifdef USE_DESKTOP_ENGINE
    #include "desktopEngine.h"
    using EngineType = DesktopEngine;
#else
    #include "n3dsEngine.h"
    using EngineType = N3DSEngine;
#endif

using namespace std;


int main() {
    EngineType gameEngine("Game Name");

    // Load resources
    int img = gameEngine.loadImage("assets/images/image.png");
    int arialFont = gameEngine.loadFont("assets/fonts/Arial.ttf");

    while (gameEngine.gameIsRunning()) {
        double width = gameEngine.getScreenWidth();
        double height = gameEngine.getScreenHeight();
        
        // Calculate vertical line offset
        gameEngine.scanInput();
        
        vector<Key> keysPressed = gameEngine.getReleasedKeys();
        if (contains(keysPressed, START_KEY)) {
            gameEngine.terminateGame();
            break;
        }

        // Start drawing
        gameEngine.startDrawing();
        gameEngine.clearBackground(COLOR_RED);

        // Draw shapes
        gameEngine.drawLine({width * 0.1, height * 0.1}, {width * 0.15, height * 0.2},
            COLOR_WHITE);
        gameEngine.drawTriangle({width * 0.2, height * 0.2}, {width * 0.3, height * 0.1}, 
            {width * 0.4, height * 0.2}, COLOR_WHITE);
        gameEngine.drawRect({width * 0.5, height * 0.5}, 100, 50, COLOR_WHITE);

        // Draw image
        gameEngine.drawImage(img, {0.1 * width, 0.3 * height}, 0.4 * width, 0.5 * height);

        // Draw text
        gameEngine.drawText(arialFont, "Hello World!", {width * 0.7, height * 0.2},
        true, 24, 1.0, COLOR_WHITE);

        gameEngine.endDrawing();

        // Draw on bottom screen
        gameEngine.startDrawingLowerScreen();
        gameEngine.clearBackground(COLOR_BLACK);

        gameEngine.drawText(arialFont, "Press START to close", {160, height * 0.2},
        true, 18, 1.0, COLOR_WHITE);

        gameEngine.endDrawingLowerScreen();
    }
    
    gameEngine.freeResources();
        
    return 0;
}
