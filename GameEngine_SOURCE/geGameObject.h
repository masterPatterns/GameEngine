#pragma once
#include "CommonInclude.h"
#include "geInput.h"
#include "geTime.h"
#include "geMissile.h"
#include "geComponent.h"
#include "geTransform.h"
#include "geSpriteRenderer.h"

namespace ge
{
	class GameObject : public Entity
	{
	public:
		GameObject();
		virtual ~GameObject();

		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render(HDC hdc);

		template <typename T>
		T* AddComponent()
		{
			T* comp = new T();
			comp->Initialize();
			comp->SetOwner(this);

			mComponents[(UINT)comp->GetType()] = comp;
			// mComponents.push_back(comp); 

			return comp;
		}

		template <typename T>
		T* GetComponent()
		{
			T* component = nullptr;
			for (Component* comp : mComponents)
			{
				component = dynamic_cast<T*>(comp);
				if (component)
					break;
			}

			return component;
		}

	private:
		void initializeTransform();

		std::vector<Component*> mComponents;
	};
}
