#pragma once
#include "gePlayer.h"
#include "geCat.h"
#include "gePlayerScript.h"
#include "geCameraScript.h"
#include "geCatScript.h"
#include "..\\GameEngine_SOURCE\\geScene.h"
#include "..\\GameEngine_SOURCE\\geGameObject.h"
#include "..\\GameEngine_SOURCE\\geSceneManager.h"
#include "..\\GameEngine_SOURCE\\geObject.h"
#include "..\\GameEngine_SOURCE\\geTexture.h"
#include "..\\GameEngine_SOURCE\\geResources.h"
#include "..\\GameEngine_SOURCE\\geCamera.h"
#include "..\\GameEngine_SOURCE\\geRenderer.h".
#include "..\\GameEngine_SOURCE\\geAnimator.h"

namespace ge
{
	class PlayScene : public Scene
	{
	public:
		PlayScene();
		~PlayScene();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

		void OnEnter() override;
		void OnExit() override;

	private:
		class Player* bg;
		class Player* mPlayer;
	};
}
