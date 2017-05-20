#pragma once

class MainGame
{
	float yPlayerRotation = 0;
	float yEnemyRotation = 0;
	Window * window;
	float xOldMousePosition, xNewMousePosition;
	float bulletSpeed, bulletLifeSpan;
	int elapsedTime;
	float characterColliderRadius, bullerColliderRadius;
	int maxHealth = 100;
public:
	Character *character;
	Character *enemy;
	std::vector <Bullet *> bullet;
	Stage *stage;
	HealthBar * healthBar;
	void ProcessInput();
	MainGame(Window * _window);
	~MainGame();
	void Start();
	void Update(int time);
};

