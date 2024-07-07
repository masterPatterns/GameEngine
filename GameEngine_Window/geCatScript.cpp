#include "geCatScript.h"

namespace ge
{
	CatScript::CatScript()
		: mState(CatScript::eState::SitDown)
		, mAnimator(nullptr)
		, mTime(0.0f)
	{
	}
	CatScript::~CatScript()
	{
	}
	void CatScript::Initialize()
	{

	}
	void CatScript::Update()
	{
		if (mAnimator == nullptr)
		{
			mAnimator = GetOwner()->GetComponent<Animator>();
		}

		switch (mState)
		{
		case ge::CatScript::eState::SitDown:
			sitDown();
			break;
		case ge::CatScript::eState::Walk:
			move();
			break;
		case ge::CatScript::eState::Sleep:
			break;
		case ge::CatScript::eState::LayDown:
			break;
		case ge::CatScript::eState::Attack:
			break;
		default:
			break;
		}
	}
	void CatScript::LateUpdate()
	{
	}
	void CatScript::Render(HDC hdc)
	{
	}

	void CatScript::PositionMove(int posiAndDire, float mSpeed)
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
	void CatScript::sitDown()
	{
		mTime += Time::DeltaTime();
		if (mTime > 1.0f)
		{
			mState = CatScript::eState::Walk;
			int direction = (rand() % 4);
			mDirection = (eDirection)direction;
			PlayWalkAnimationByDirection(mDirection);
			mTime = 0.0f;
		}
	}
	void CatScript::move()
	{
		mTime += Time::DeltaTime();
		if (mTime > 1.0f)
		{
			int isLayDown = rand() % 2;
			if (isLayDown)
			{
				mState = CatScript::eState::LayDown;
				mAnimator->PlayAnimation(L"LayDown", false);
			}
			else
			{
				mState = CatScript::eState::SitDown;
				mAnimator->PlayAnimation(L"SitDown", false);
			}
		}

		float speed = 200.0f;

		Transform* tr = GetOwner()->GetComponent<Transform>();
		Translate(tr, speed);
	}
	void CatScript::layDown()
	{

	}
	void CatScript::PlayWalkAnimationByDirection(eDirection dir)
	{
		switch (dir)
		{
		case ge::CatScript::eDirection::Left:
			mAnimator->PlayAnimation(L"LeftWalk", true);
			break;
		case ge::CatScript::eDirection::Right:
			mAnimator->PlayAnimation(L"RightWalk", true);
			break;
		case ge::CatScript::eDirection::Down:
			mAnimator->PlayAnimation(L"DownWalk", true);
			break;
		case ge::CatScript::eDirection::Up:
			mAnimator->PlayAnimation(L"UpWalk", true);
			break;
		default:
			assert(false);
			break;
		}
	}
	void CatScript::Translate(Transform* tr, float mSpeed)
	{
		float speed = mSpeed;
		Vector2 pos = tr->GetPosition();

		switch (mDirection)
		{
		case ge::CatScript::eDirection::Left:
			pos.x -= speed * Time::DeltaTime();
			break;
		case ge::CatScript::eDirection::Right:
			pos.x += speed * Time::DeltaTime();
			break;
		case ge::CatScript::eDirection::Down:
			pos.y += speed * Time::DeltaTime();
			break;
		case ge::CatScript::eDirection::Up:
			pos.y -= speed * Time::DeltaTime();
			break;
		default:
			assert(false);
			break;
		}
		tr->SetPos(pos);
	}
}