#include "Board.h"
#include <SDL2/SDL_image.h>
#include "Game.h"

Board::Board(std::string path)
{
    texr = IMG_LoadTexture(Game::renderer, ("../assets/" + path.substr(path.find_last_of("/") + 1)).c_str());
    SDL_Rect rect;
    rect.x = 0;
    rect.y = 0;
    SDL_QueryTexture(texr, NULL, NULL, &rect.w, &rect.h); // Query the width and height of the texture

    leftLineRect.x = 0;
    leftLineRect.y = 0;
    leftLineRect.h = rect.h;
    leftLineRect.w = 1;

    rightLineRect.x = rect.w - 1;
    rightLineRect.y = 0;
    rightLineRect.h = rect.h;
    rightLineRect.w = 1;

    topLineRect.x = 0;
    topLineRect.y = 0;
    topLineRect.h = 1;
    topLineRect.w = rect.w;

    bottomLineRect.x = 0;
    bottomLineRect.y = rect.h - 1;
    bottomLineRect.h = 1;
    bottomLineRect.w = rect.w;

    // Define goal area rectangles (adjust these values as needed for your field image)
    int goalWidth = 20; // width of the goal area
    int goalHeight = rect.h / 4; // height of the goal area
    leftGoalRect.x = 0;
    leftGoalRect.y = rect.h / 2 - goalHeight / 2;
    leftGoalRect.w = goalWidth;
    leftGoalRect.h = goalHeight;

    rightGoalRect.x = rect.w - goalWidth;
    rightGoalRect.y = rect.h / 2 - goalHeight / 2;
    rightGoalRect.w = goalWidth;
    rightGoalRect.h = goalHeight;

    // Define corner rectangles (10x10 px, adjust as needed)
    int cornerSize = 10;
    topLeftCornerRect = {0, 0, cornerSize, cornerSize};
    topRightCornerRect = {rect.w - cornerSize, 0, cornerSize, cornerSize};
    bottomLeftCornerRect = {0, rect.h - cornerSize, cornerSize, cornerSize};
    bottomRightCornerRect = {rect.w - cornerSize, rect.h - cornerSize, cornerSize, cornerSize};

}

Board::~Board()
{
}

void Board::update()
{
}

void Board::render()
{
    SDL_Rect rect;
    rect.x = 0;
    rect.y = 0;
    SDL_QueryTexture(texr, NULL, NULL, &rect.w, &rect.h); // Query the width and height of the texture
    SDL_RenderCopy(Game::renderer, texr, NULL, &rect);
}

SDL_Rect Board::getLeftLineRect()
{
    return leftLineRect;
}

SDL_Rect Board::getRightLineRect()
{
    return rightLineRect;
}

SDL_Rect Board::getTopLineRect()
{
    return topLineRect;
}

SDL_Rect Board::getBottomLineRect()
{
    return bottomLineRect;
}

SDL_Rect Board::getLeftGoalRect()
{
    return leftGoalRect;
}

SDL_Rect Board::getRightGoalRect()
{
    return rightGoalRect;
}

SDL_Rect Board::getTopLeftCornerRect() { return topLeftCornerRect; }
SDL_Rect Board::getTopRightCornerRect() { return topRightCornerRect; }
SDL_Rect Board::getBottomLeftCornerRect() { return bottomLeftCornerRect; }
SDL_Rect Board::getBottomRightCornerRect() { return bottomRightCornerRect; }