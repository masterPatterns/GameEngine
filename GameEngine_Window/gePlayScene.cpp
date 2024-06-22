#include "gePlayScene.h"

namespace ge
{
	PlayScene::PlayScene()
	{
	}
	PlayScene::~PlayScene()
	{
	}
	void PlayScene::Initialize()
	{
		//bg = new Player();
		//Transform* tr = bg->AddComponent<Transform>();
		//tr->SetPos(Vector2(0, 0));
		//tr->SetName(L"TR");

		//SpriteRenderer* sr = bg->AddComponent<SpriteRenderer>();
		//sr->SetName(L"SR");
		//sr->ImageLoad(L"K:\\workspace\\test\\GameEngine\\Resources\\CloudOcean.png");

		//AddGameObject(bg, enums::eLayerType::Background);

		bg = object::Instantiate<Player>(enums::eLayerType::Background, Vector2(100.0f, 100.0f));
		SpriteRenderer* sr = bg->AddComponent<SpriteRenderer>();
		sr->SetName(L"SR");
		sr->ImageLoad(L"K:\\workspace\\test\\GameEngine\\Resources\\CloudOcean.png");
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
