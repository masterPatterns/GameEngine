#include "geGameObject.h"

namespace ge
{
	GameObject::GameObject()
		//: mX(0.0f)
		//, mY(0.0f)
		//, left(0.0f)
		//, top(0.0f)
		//, right(0.0f)
		//, bottom(0.0f)
	{
		//Initialize();
		initializeTransform();
	}
	GameObject::~GameObject()
	{
	}

	void GameObject::Initialize()
	{
		for (Component* comp : mComponents)
		{
			comp->Initialize(100, 100);
		}

		//left = 100;
		//top = 100;
		//right = 200;
		//bottom = 200;
		//for (size_t i = 0; i < 10; i++)
		//{
		//	mMissile[i].Initialize(20);
		//	mMissile[i].SetPosition(left, top);
		//	isShoot[i] = 0;
		//}
	}

	void GameObject::Update()
	{
		for (Component* comp : mComponents)
		{
			comp->Update();
		}

		/*const int speed = 200.0f;

		if (Input::GetKey(eKeyCode::Left))
		{
			mX -= speed * Time::DeltaTime();
		}

		if (Input::GetKey(eKeyCode::Right))
		{
			mX += speed * Time::DeltaTime();
		}

		if (Input::GetKey(eKeyCode::Up))
		{
			mY -= speed * Time::DeltaTime();
		}

		if (Input::GetKey(eKeyCode::Down))
		{
			mY += speed * Time::DeltaTime();
		}*/

		//if (isShoot[0] == 0) {
		//	mMissile[0].SetPosition(left + mX, top + mY);
		//}
		//else {
		//	mMissile[0].Update();
		//}

		//if (Input::GetKey(eKeyCode::Space))
		//{
		//	isShoot[0] = 1;
		//}
	}
	void GameObject::LateUpdate()
	{
		for (Component* comp : mComponents)
		{
			comp->LateUpdate();
		}
	}
	void GameObject::Render(HDC hdc)
	{
		for (Component* comp : mComponents)
		{
			comp->Render(hdc);
		}
	}

	void GameObject::initializeTransform()
	{
		AddComponent<Transform>();
		AddComponent<SpriteRenderer>();
	}

}