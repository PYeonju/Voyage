#pragma once
#include "Scene.h"

class TitleScene : public Scene
{
private:
	hash<string> _hasher;

public:
	virtual void Init() override;
};

