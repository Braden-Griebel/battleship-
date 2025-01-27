#include "ships.h"

bool Ship::checkHit(Position possibleHit) {
    // Current position being examined
    int curRow = this->position.row;
    int curCol = this->position.col;
    // Iterate through the length of the ship, checking if the
    // current position matched the possible hit
    for (int i=0; i < this->length; i++) {
        // Check the current position
        if (curRow == possibleHit.row && curCol == possibleHit.col) {
            return true;
        }
        // Update the curRow and curCol based on Direction
        switch (this->direction) {
            case Direction::UP:
                ++curCol; break;
            case Direction::DOWN:
                --curCol; break;
            case Direction::LEFT:
                --curRow; break;
            case Direction::RIGHT:
                ++curRow; break;
        }
    }
    return false;
}
