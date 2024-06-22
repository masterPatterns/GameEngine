#include "geGameObject.h"

namespace ge
{
	GameObject::GameObject()
	{
		initializeTransform();
	}
	GameObject::~GameObject()
	{
	}

	void GameObject::Initialize()
	{
		for (Component* comp : mComponents)
		{
			comp->Initialize();
		}
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
	}

}