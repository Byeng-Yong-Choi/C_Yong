#include "CharMove.h"

D3DXVECTOR3 CharMove::move(std::shared_ptr<Gokussgss> Hero, std::shared_ptr<Gokussgss> Enmey)
{
	D3DXVECTOR3 HeroMove = { 0,0,0 };
	if (!Hero->Revers)
	{
		HeroMove.x=Hero->m_pos.x;

		if (Hero->m_fRect.left < -640.0f && Hero->m_pos.x < 0)
		{
			HeroMove.x = 0;
		}

		if ((Hero->m_fRect.right > 640.0f && Hero->m_pos.x > 0) || (Hero->m_fRect.right >= Enmey->m_fRect.left  && Hero->m_pos.x > 0))
		{
			if (Hero->m_fRect.bottom > Enmey->m_fRect.top)
			{
				HeroMove.x = Hero->m_pos.x;
				Hero->Revers = true;
				Enmey->Revers = false;
			}
			else
			{
				HeroMove.x = 0;
			}
		}
	}
	else
	{
		HeroMove.x = Hero->m_pos.x;

		if ((Hero->m_fRect.left < -640.0f && Hero->m_pos.x < 0) || (Hero->m_fRect.left <= Enmey->m_fRect.right  && Hero->m_pos.x < 0))
		{
			if (Hero->m_fRect.bottom > Enmey->m_fRect.top)
			{
				HeroMove.x = Hero->m_pos.x;
				Hero->Revers = false;
				Enmey->Revers = true;
			}
			else
			{
				HeroMove.x = 0;
			}
		}

		if (Hero->m_fRect.right > 640.0f && Hero->m_pos.x > 0)
		{
			HeroMove.x = 0;
		}
	}

	return HeroMove;
}

bool CharMove::CharCol()
{
	return true;
}

CharMove::CharMove()
{
	
}


CharMove::~CharMove()
{
}
