
#include "BioEnemyBoss.h"
#include "Level.h"


BioEnemyBoss::BioEnemyBoss()
{
	SetSpeed(90);
	SetMaxHitPoints(5);
	SetCollisionRadius(140);
}


void BioEnemyBoss::Update(const GameTime& gameTime)
{
	if (IsActive())
	{
		float x = sin(gameTime.GetTotalTime() /** Math::PI*/ + GetIndex());

		x *= GetSpeed() * gameTime.GetElapsedTime() * 1.4f;

		TranslatePosition(x, GetSpeed() * gameTime.GetElapsedTime());

		if (!IsOnScreen())
		{
			//std::cout << "I am gone.";
			//Deactivate();
		}
	}

	EnemyShip::Update(gameTime);
}

void BioEnemyBoss::Draw(SpriteBatch& spriteBatch)
{
	if (IsActive())
	{
		const float alpha = GetCurrentLevel()->GetAlpha();
		spriteBatch.Draw(m_pTexture, GetPosition(), Color::WHITE * alpha, m_pTexture->GetCenter());
	}
}