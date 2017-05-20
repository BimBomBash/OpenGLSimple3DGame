#pragma once
class HealthBar
{
	
public:
	float width = 1;
	float playerHealthFloat = 1;
	float enemyHealthFloat = 1;
	HealthBar();
	~HealthBar();
	void Draw();
	void Update();
};

