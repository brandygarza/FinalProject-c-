
#include "BioEnemyBoss.h"
#include "Level.h"


BioEnemyBoss::BioEnemyBoss()
{
	SetSpeed(90);
	SetMaxHitPoints(7);
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
			Deactivate();
		}
	}

	EnemyShip::Update(gameTime);
}

void BioEnemyBoss::Hit(const float damage)
{
	m_hitPoints -= damage;
	if (m_hitPoints > 0)
	{
		if (m_hitPoints < 10 && m_hitPoints > 4)
		{
			
		}
		return;
	}

	GameObject::Deactivate();
	GetCurrentLevel()->SpawnExplosion(this);
}

void BioEnemyBoss::Draw(SpriteBatch& spriteBatch)
{
	if (IsActive())
	{
		const float alpha = GetCurrentLevel()->GetAlpha();
		spriteBatch.Draw(m_pTexture, GetPosition(), Color::WHITE * alpha, m_pTexture->GetCenter());
	}
}