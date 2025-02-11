//
// Created by bgriebel on 1/27/25.
//

#ifndef SHIPS_H
#define SHIPS_H
#include <cctype>
#include <string>

/*!
 * @brief Direction the ship is facing.
 */
enum Direction { UP, DOWN, LEFT, RIGHT };

/*!
 * @brief Status of the ship (Okay or Sunk).
 */
enum Status { OKAY, SUNK };

/*!
 * @brief Position of the ship, represented by ints
 */
struct Position {
    /*!
     * @brief Row of position (0-9)
     */
    int row;
    /*!
     * @brief Column of position (0-9)
     */
    int col;
    /*!
     * @brief Construct Position from integers representing the row and column.
     * @param row Integer specifying row (0-9)
     * @param col Integer specifying column (0-9)
     */
    Position(const int row, const int col) : row(row), col(col) {
    };
    /*!
     * @brief Construct Position from position String, made of two characters, the
     * first being a letter specifying the column and the second being a number specifying
     * the row.
     * @param positionSpec String of length 2 specifying the position
     */
    explicit Position(const std::string &positionSpec): Position(rowFromSpec(positionSpec), colFromSpec(positionSpec)) {
    };

private:
    static int rowFromSpec(const std::string &positionSpec) {
        return positionSpec[1];
    };

    static int colFromSpec(const std::string &positionSpec) {
        return std::toupper(positionSpec[0]) - 'A';
    };
};


/*! @brief Base class for representing different ship pieces.
 *
 */
class Ship {
    /*!
     * @brief The length of the ship, equal to number of hits to sink.
     */
    int length;
    /*!
     * @brief Number of hits taken so far by the ship
     */
    int hits;
    /*!
     * @brief Direction the ship is facing.
     */
    Direction direction;
    /*!
     * @brief Position of the start of the ship.
     */
    Position position;

public:
    /*!
     * @brief
     * @param length Length of the ship
     * @param direction Direction the ship is facing
     * @param position Position of the Ship on the board
     */
    Ship(const int length, const Direction direction, const Position position): length(length), hits(0),
        direction(direction), position(position) {
    };

    /*!
     * @brief Check if the ship has been sunk.
     * @return True if the ship has been sunk, false otherwise
     */
    [[nodiscard]] bool isSunk() const {
        return (this->hits >= this->length);
    };

    /*!
     * @brief Check whether a hit would occur at provided position.
     * @param possibleHit Position of the possible hit to check
     * @return true if the position would be a hit, and false otherwise
     */
    [[nodiscard]] bool checkHit(const Position &possibleHit) const;

    /*!
     * @brief Checks whether This overlaps another Ship.
     * @param other Other ship to check if it overlaps
     * @return True if there is an overlap, false otherwise
     */
    [[nodiscard]] bool checkOverlap(const Ship &other) const;
};


// region Specific Ships

/*!
 * @brief Represents a Carrier, a ship with length 5
 */
class Carrier : public Ship {
public:
    Carrier(const Direction direction, const Position position): Ship(5, direction, position) {
    };
};

/*!
 * @brief Represents a Battleship, a ship with length 4
 */
class Battleship : public Ship {
public:
    Battleship(const Direction direction, const Position position): Ship(4, direction, position) {
    }
};

/*!
 * @brief Represents a Destroyer, a ship with length 3
 */
class Destroyer : public Ship {
public:
    Destroyer(const Direction direction, const Position position): Ship(3, direction, position) {
    }
};

/*!
 * @brief Represents a Submarine, a ship with length 3
 */
class Submarine : public Ship {
public:
    Submarine(const Direction direction, const Position position): Ship(3, direction, position) {
    }
};

/*!
 * @brief Represents a Patrol Boat, a ship with length 2
 */
class PatrolBoat : public Ship {
public:
    PatrolBoat(const Direction direction, const Position position): Ship(2, direction, position) {
    }
};

// endregion Specific Ships

#endif //SHIPS_H
