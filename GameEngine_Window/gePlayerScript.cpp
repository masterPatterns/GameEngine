#include "gePlayerScript.h"

namespace ge
{
	PlayerScript::PlayerScript()
		: mState(PlayerScript::eState::Idle)
		, mAnimator(nullptr)
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
		if (mAnimator == nullptr)
		{
			mAnimator = GetOwner()->GetComponent<Animator>();
		}

		switch (mState)
		{
		case ge::PlayerScript::eState::Idle:
			idle();
			break;
		case ge::PlayerScript::eState::Walk:
			move();
			break;
		case ge::PlayerScript::eState::Sleep:
			break;
		case ge::PlayerScript::eState::GiveWater:
			giveWater();
			break;
		case ge::PlayerScript::eState::Attack:
			break;
		default:
			break;
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
			pos.x += speed * Time::DeltaTime();
			break;
		case 2:
			pos.x -= speed * Time::DeltaTime();
			break;
		case 3:
			pos.y += speed * Time::DeltaTime();
			break;
		case 4:
			pos.y -= speed * Time::DeltaTime();
			break;
		}

		tr->SetPos(pos);
	}
	void PlayerScript::idle()
	{
		if (Input::GetKey(eKeyCode::LButton))
		{
			mState = PlayerScript::eState::GiveWater;
			mAnimator->PlayAnimation(L"FrontGiveWater", false);

			Vector2 mousePos = Input::GetMousePosition();
		}

		if (Input::GetKey(eKeyCode::Left))
		{
			mState = PlayerScript::eState::Walk;
			mAnimator->PlayAnimation(L"LeftWalk", true);
		}
		if (Input::GetKey(eKeyCode::Right))
		{
			mState = PlayerScript::eState::Walk;
			mAnimator->PlayAnimation(L"RightWalk", true);
		}
		if (Input::GetKey(eKeyCode::Up))
		{
			mState = PlayerScript::eState::Walk;
			mAnimator->PlayAnimation(L"UpWalk", true);
		}
		if (Input::GetKey(eKeyCode::Down))
		{
			mState = PlayerScript::eState::Walk;
			mAnimator->PlayAnimation(L"DownWalk", true);
		}
	}
	void PlayerScript::move()
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

		if (Input::GetKeyUp(eKeyCode::Left) || Input::GetKeyUp(eKeyCode::Right) || Input::GetKeyUp(eKeyCode::Up) || Input::GetKeyUp(eKeyCode::Down))
		{
			mState = PlayerScript::eState::Idle;
			mAnimator->PlayAnimation(L"SitDown", false);
		}
		
	}
	void PlayerScript::giveWater()
	{
		if (mAnimator->IsComplete())
		{
			mState = eState::Idle;
			mAnimator->PlayAnimation(L"Idle", false);
		}
	}
}