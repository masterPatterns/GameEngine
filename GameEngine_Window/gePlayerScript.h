#pragma once
#include "..\\GameEngine_SOURCE\\geScript.h"
#include "..\\GameEngine_SOURCE\\geGameObject.h"
#include "..\\GameEngine_SOURCE\\geInput.h"
#include "..\\GameEngine_SOURCE\\geTransform.h"
#include "..\\GameEngine_SOURCE\\geTime.h"
#include "..\\GameEngine_SOURCE\\geAnimator.h"

namespace ge
{
	class PlayerScript : public Script
	{
	public:
		enum class eState
		{
			Idle,
			Walk,
			Sleep,
			GiveWater,
			Attack,
		};


		PlayerScript();
		~PlayerScript();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

		void PositionMove(int posiAndDire, float mSpeed);

	private:
		void idle();
		void move();
		void giveWater();

	private:
		eState mState;
		class Animator* mAnimator;

		//void (*StartEvent)();
		//void (*CompleteEvent)();
		//void (*EndEvent)();


	};
}
