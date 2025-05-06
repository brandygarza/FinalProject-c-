
#include "BioEnemyBoss.h"
#include "Level.h"


BioEnemyBoss::BioEnemyBoss()
{
	SetSpeed(50);
	SetMaxHitPoints(15);
	SetCollisionRadius(20);
}


void BioEnemyBoss::Update(const GameTime& gameTime)
{
	if (IsActive())
	{
		float x = sin(gameTime.GetTotalTime() * Math::PI + GetIndex());

		x *= GetSpeed() * gameTime.GetElapsedTime() * 1.4f;

		TranslatePosition(x, GetSpeed() * gameTime.GetElapsedTime());

		if (!IsOnScreen()) Deactivate();
	}

	EnemyShip::Update(gameTime);
}

void BioEnemyBoss::Hit(const float damage)
{
	Ship::Hit(damage);
}


void BioEnemyBoss::Draw(SpriteBatch& spriteBatch)
{
	if (IsActive())
	{
		const float alpha = GetCurrentLevel()->GetAlpha();
		spriteBatch.Draw(m_pTexture, GetPosition(), Color::WHITE * alpha, m_pTexture->GetCenter(), Vector2::ONE, Math::PI, 1);
	}
}