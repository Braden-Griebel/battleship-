#include "ships.h"


bool Ship::checkHit(const Position& possibleHit) const {
    // Current position being examined
    int curRow = this->position.row;
    int curCol = this->position.col;
    // Iterate through the length of the ship, checking if the
    // current position matched the possible hit
    // There are ways for this to be optimized, but this is easy and fast enough
    for (int i=0; i < this->length; i++) {
        // Check the current position
        if (curRow == possibleHit.row && curCol == possibleHit.col) {
            return true;
        }
        // Update the curRow and curCol based on Direction
        switch (this->direction) {
            case Direction::UP:
                ++curRow; break;
            case Direction::DOWN:
                --curRow; break;
            case Direction::LEFT:
                --curCol; break;
            case Direction::RIGHT:
                ++curCol; break;
        }
    }
    // If no positions overlap, it is not a hit
    return false;
}


bool Ship::checkOverlap(const Ship& other) const {
    int otherRow = other.position.row;
    int otherCol = other.position.col;
    Direction otherDirection = other.direction;
    for (int i=0; i < other.length; i++) {
        // Check if the current position is overlapping self
        if (this->checkHit(Position {otherRow, otherCol})) {
            return true;
        }
        // update the otherRow and otherCol based on direction
        switch (otherDirection) {
            case Direction::UP:
                ++otherRow; break;
            case Direction::DOWN:
                --otherRow; break;
            case Direction::LEFT:
                --otherCol; break;
            case Direction::RIGHT:
                ++otherCol; break;
        }
    }
    // If none of the positions of the other ship "hit", there is no overlap
    return false;
}