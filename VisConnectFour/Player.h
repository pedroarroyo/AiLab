// File: Player.h
// Author: Pedro Arroyo
// Description: 
// A Player class encapsulates various pluggable strategies for determining game moves. 
// Usage:
// Simply invoking "DetermineMove" and passing in the game context is all that is necessary.

#ifndef VISCONNECTFOUR_PLAYER_H_
#define VISCONNECTFOUR_PLAYER_H_

//#include "GameTypes.h"
#include "Ai/Examples/ConnectFour.h"
#include <iostream>
#include <vector>

enum PlayerStrategyType
{
	kPlayerStrategyTypeHuman,
	kPlayerStrategyTypeAiEasy,
	kPlayerStrategyTypeAiDifficult,
};


class PlayerStrategy
{
public:
	PlayerStrategy(PlayerStrategyType type) : m_type(type) {}
	virtual ~PlayerStrategy() {}

	virtual void DetermineMove(const Ai::ConnectFourMove& lastMove, Ai::ConnectFourGameBoardValue player, const Ai::ConnectFourGameBoard& gameBoard, unsigned& outRow, unsigned& outColumn) = 0;

	PlayerStrategyType GetType() const { return m_type; }

private:
	PlayerStrategyType m_type;
};

class PhysicalPlayer : public PlayerStrategy
{
public:
	PhysicalPlayer() : PlayerStrategy( kPlayerStrategyTypeHuman ) {}

	// PlayerStrategy
	virtual void DetermineMove(const Ai::ConnectFourMove& lastMove, Ai::ConnectFourGameBoardValue player, const Ai::ConnectFourGameBoard& gameBoard, unsigned& outRow, unsigned& outColumn) override;
};

class AiPlayerRandom : public PlayerStrategy
{
public:
	AiPlayerRandom() : PlayerStrategy( kPlayerStrategyTypeAiEasy ) {} 

	// PlayerStrategy
	virtual void DetermineMove(const Ai::ConnectFourMove& lastMove, Ai::ConnectFourGameBoardValue player, const Ai::ConnectFourGameBoard& gameBoard, unsigned& outRow, unsigned& outColumn) override;
};

#endif