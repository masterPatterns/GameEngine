#include "gePlayer.h"

namespace ge
{
	void Player::Initialize()
	{
		GameObject::Initialize();
	}
	void Player::Update()
	{
		GameObject::Update();

		/*if (Input::GetKey(eKeyCode::Left))
		{
			PositionMove(1, 200.0f);
		}

		if (Input::GetKey(eKeyCode::Right))
		{
			PositionMove(2, 200.0f);
		}

		if (Input::GetKey(eKeyCode::Up))
		{
			PositionMove(3, 200.0f);
		}

		if (Input::GetKey(eKeyCode::Down))
		{
			PositionMove(4, 200.0f);
		}*/
	}
	void Player::PositionMove(int posiAndDire, float mSpeed)
	{
		float speed = mSpeed;

		Transform* tr = GameObject::GetComponent<Transform>();
		Vector2 pos = tr->GetPosition();
		switch (posiAndDire)
		{
		case 1:
			pos.x -= speed * Time::DeltaTime();
			break;
		case 2:
			pos.x += speed * Time::DeltaTime();
			break;
		case 3:
			pos.y -= speed * Time::DeltaTime();
			break;
		case 4:
			pos.y += speed * Time::DeltaTime();
			break;
		}

		tr->SetPos(pos);
	}
	void Player::AttackEffect()
	{
	}
	void Player::LateUpdate()
	{
		GameObject::LateUpdate();

		//if (Input::GetKey(eKeyCode::Right))
		//{
		//	Transform* tr = GetComponent<Transform>();
		//	Vector2 pos = tr->GetPosition();
		//	pos.x += 100.0f * Time::DeltaTime();
		//	tr->SetPos(pos);
		//}
	}
	void Player::Render(HDC hdc)
	{
		GameObject::Render(hdc);
	}
}