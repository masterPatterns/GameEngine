#include "gePlayerScript.h"

namespace ge
{
	PlayerScript::PlayerScript()
	{
	}
	PlayerScript::~PlayerScript()
	{
	}
	void PlayerScript::Initialize()
	{
	}
	void PlayerScript::Update()
	{
		if (Input::GetKey(eKeyCode::Left))
		{
			PositionMove(2, 200.0f);
		}

		if (Input::GetKey(eKeyCode::Right))
		{
			PositionMove(1, 200.0f);
		}

		if (Input::GetKey(eKeyCode::Up))
		{
			PositionMove(4, 200.0f);
		}

		if (Input::GetKey(eKeyCode::Down))
		{
			PositionMove(3, 200.0f);
		}
	}
	void PlayerScript::LateUpdate()
	{
	}
	void PlayerScript::Render(HDC hdc)
	{
	}

	void PlayerScript::PositionMove(int posiAndDire, float mSpeed)
	{
		float speed = mSpeed;

		Transform* tr = GetOwner()->GetComponent<Transform>();
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
}