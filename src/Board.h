#include <string>
#include <SDL2/SDL_render.h>

class Board
{
public:
    Board(std::string path);
    ~Board();

    void update();
    void render();

    SDL_Rect getLeftLineRect();
    SDL_Rect getRightLineRect();
    SDL_Rect getTopLineRect();
    SDL_Rect getBottomLineRect();
    // New methods for goal areas
    SDL_Rect getLeftGoalRect();
    SDL_Rect getRightGoalRect();
    SDL_Rect getTopLeftCornerRect();
    SDL_Rect getTopRightCornerRect();
    SDL_Rect getBottomLeftCornerRect();
    SDL_Rect getBottomRightCornerRect();

private:
    SDL_Texture *texr;
    SDL_Rect leftLineRect;
    SDL_Rect rightLineRect;
    SDL_Rect topLineRect;
    SDL_Rect bottomLineRect;
    // Goal area rectangles
    SDL_Rect leftGoalRect;
    SDL_Rect rightGoalRect;
    // New corner rectangles
    SDL_Rect topLeftCornerRect;
    SDL_Rect topRightCornerRect;
    SDL_Rect bottomLeftCornerRect;
    SDL_Rect bottomRightCornerRect;

};