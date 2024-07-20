#pragma once
#include "..\\GameEngine_SOURCE\\geScript.h"
#include "..\\GameEngine_SOURCE\\geGameObject.h"
#include "..\\GameEngine_SOURCE\\geInput.h"
#include "..\\GameEngine_SOURCE\\geTransform.h"
#include "..\\GameEngine_SOURCE\\geTime.h"
#include "..\\GameEngine_SOURCE\\geAnimator.h"

namespace ge
{
	class CatScript : public Script
	{
	public:
		enum class eState
		{
			SitDown,
			Walk,
			Sleep,
			LayDown,
			Attack,
		};

		enum class eDirection
		{
			Left,
			Right,
			Down,
			Up,
			End,
		};

		CatScript();
		~CatScript();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

		void PositionMove(int posiAndDire, float mSpeed);

	private:
		void sitDown();
		void move();
		void layDown();
		void PlayWalkAnimationByDirection(eDirection dir);
		void Translate(Transform* tr, float mSpeed);

	private:
		eState mState;
		class Animator* mAnimator;
		eDirection mDirection;
		float mTime;
		float mDeathTime;

	};
}
