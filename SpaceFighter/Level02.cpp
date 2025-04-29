

#include "Level02.h"
#include "BioEnemyBoss.h"


void Level02::LoadContent(ResourceManager& resourceManager)
{
	// Setup enemy ships
	Texture* pTexture = resourceManager.Load<Texture>("Textures\\BioEnemyBoss.png");

	const int COUNT = 22;

	double xPositions[COUNT] =
	{
		0.25, 0.2, 0.3,
		0.75, 0.8, 0.7,
		0.3, 0.25, 0.35, 0.2, 0.4,
		0.7, 0.75, 0.65, 0.8, 0.6,
		0.5, 0.4, 0.6, 0.45, 0.55, .6

	};

	double delays[COUNT] =
	{
		0.0, 0.25, 0.25,
		3.0, 0.25, 0.25,
		3.25, 0.25, 0.25, 0.25, 0.25,
		3.25, 0.25, 0.25, 0.25, 0.25,
		3.5, 0.3, 0.3, 0.3, 0.3, 0.3
	};

	float delay = 3.0; // start delay
	Vector2 position;

	for (int i = 0; i < COUNT; i++)
	{
		delay += delays[i];
		position.Set(xPositions[i] * Game::GetScreenWidth(), -pTexture->GetCenter().Y);

		BioEnemyBoss* pBoss = new BioEnemyBoss();
		pBoss->SetTexture(pTexture);
		pBoss->SetCurrentLevel(this);
		pBoss->Initialize(position, (float)delay);
		AddGameObject(pBoss);
	}

<<<<<<< HEAD
	SetBackground(resourceManager.Load<Texture>("Textures\\SpaceBackground03.png"));


=======
	// Setup background
	SetBackground(resourceManager.Load<Texture>("Textures\\SpaceBackground03.png"));

>>>>>>> 20566fe6ef2ea9c9caa7112d2cb8d58f89d11c96
	Level::LoadContent(resourceManager);
}

