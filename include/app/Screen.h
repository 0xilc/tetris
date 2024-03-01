#pragma once
#include "Input.h"
class Screen
{
public:
	virtual void Render() = 0;
	virtual void Update(float deltaTime) = 0;

	virtual void Enter() = 0;
	virtual void Exit() = 0;

	virtual void HandleInput() = 0;
};