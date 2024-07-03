#include "gePlayScene.h"

namespace ge
{
	PlayScene::PlayScene()
		: bg{}
	{
	}
	PlayScene::~PlayScene()
	{
	}
	void PlayScene::Initialize()
	{
		// main camera
		GameObject* camera = object::Instantiate<GameObject>(enums::eLayerType::None);
		Camera* cameraComp = camera->AddComponent<Camera>();
		renderer::mainCamera = cameraComp;

		camera->AddComponent<PlayerScript>();

		//bg = object::Instantiate<Player>(enums::eLayerType::Background, Vector2(100.0f, 100.0f));
		bg = object::Instantiate<Player>(enums::eLayerType::Background);
		SpriteRenderer* sr = bg->AddComponent<SpriteRenderer>();
		sr->SetName(L"SR");
		//bg->AddComponent<PlayerScript>();

		graphcis::Texture* bgtex = Resources::Find<graphcis::Texture>(L"BG");
		sr->SetTexture(bgtex);
		
		Scene::Initialize();
	}
	void PlayScene::Update()
	{
		Scene::Update();
	}
	void PlayScene::LateUpdate()
	{
		Scene::LateUpdate();

		if (Input::GetKeyDown(eKeyCode::N))
		{
			SceneManager::LoadScene(L"EndScene");
		}
	}
	void PlayScene::Render(HDC hdc)
	{
		Scene::Render(hdc);
		wchar_t str[50] = L"Play Scene";
		TextOut(hdc, 0, 30, str, 10);
	}

	void PlayScene::OnEnter()
	{
	}
	void PlayScene::OnExit()
	{
		//Transform* tr = bg->GetComponent<Transform>();
		//tr->SetPos(Vector2(0, 0));
	}

}
