#include "geCat.h"

namespace ge
{
	void Cat::Initialize()
	{
		GameObject::Initialize();
	}
	void Cat::Update()
	{
		GameObject::Update();
	}
	void Cat::PositionMove(int posiAndDire, float mSpeed)
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
	void Cat::LateUpdate()
	{
		GameObject::LateUpdate();
	}
	void Cat::Render(HDC hdc)
	{
		GameObject::Render(hdc);
	}
}