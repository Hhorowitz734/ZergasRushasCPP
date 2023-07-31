#include "/opt/homebrew/Cellar/raylib/4.5.0/include/raylib.h"
#include <iostream>
#include <unistd.h> 
#include <cstdlib>
#include <ctime>
#include <cmath>

//Compile code with g++ zergrush.cpp -o zergrush -I/opt/homebrew/Cellar/raylib/4.5.0/include -L/opt/homebrew/Cellar/raylib/4.5.0/lib -lraylib -framework CoreVideo -framework IOKit -framework Cocoa -framework GLUT -framework OpenGL
//Run with ./zergrush

class Player {
    public:
        int xpos = GetScreenWidth() / 2;
        int ypos = GetScreenHeight() / 2;
        int width = 4;
        int height = 4;
        int speed = 5;
        int bullet_speed = 5;
        int hp = 100;
        Color PLAYERWHITE = {255, 255, 255, 255};
        Color ERASEBLACK = {0, 0, 0, 255};

    
    void draw(){
        DrawRectangle(xpos, ypos, width, height, PLAYERWHITE);
    }

    void erase(double oldxpos, double oldypos){
            DrawCircle(oldxpos, oldypos, 17, ERASEBLACK);
        }
    
    void move(char direction){

        erase(xpos, ypos);

        switch (direction) {
            case 'u':
                this->ypos -= speed; 
                break;
            case 'd':
                this->ypos += speed; 
                break;
            case 'l':
                this->xpos -= speed; 
                break;
            case 'r':
                this->xpos += speed; 
                break;
            default:
                // Handle invalid direction
                break;
        }
    }

};


int main(){

    //Colors for the game
    const Color BGBLACK = {0, 0, 0, 255};

    // Initialize the window and set the frame rate
    const int screenWidth = 800;
    const int screenHeight = 600;
    InitWindow(screenWidth, screenHeight, "Zergas Rushas");
    SetTargetFPS(60);
    ClearBackground(BGBLACK);

    //Initializes player
    Player player;



    // Main game loop
    while (!WindowShouldClose())
    {

        if (IsKeyPressed(KEY_SPACE)) {
            CloseWindow(); // Close the window when space bar is pressed
        }

        //Handles player movement
        if (IsKeyDown(KEY_W) || IsKeyDown(KEY_UP)) {
            player.move('u');
        } 
        if (IsKeyDown(KEY_S) || IsKeyDown(KEY_DOWN)) {
            player.move('d');
        }
        if (IsKeyDown(KEY_A) || IsKeyDown(KEY_LEFT)) {
            player.move('l');
        }
        if (IsKeyDown(KEY_D) || IsKeyDown(KEY_RIGHT)) {
            player.move('r');
        }


        

        // Clear the screen and draw a circle in the center
        BeginDrawing();
        player.draw();
        EndDrawing();
    }


    return 0;
}