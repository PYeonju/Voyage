#include "pch.h"
#include "GrandMaPrefab.h"
#include "DataManager.h"
#include "Transform.h"
#include "SphereCollider.h"
#include "MonoBehaviour.h"
#include "GameObject.h"
#include "Audio.h"
#include "Panel.h"
#include "GameProcess.h"
#include "MeshRenderer.h"
#include "NewbieEngineFunc.h"

GrandMaPrefab::GrandMaPrefab(Vector3 pos)
	: IPrefab(make_shared<GameObject>())
{
	vector<shared_ptr<GameObject>> dodoObjects = DataManager::GetInstance()->GetDataResources("Grandma");

	gameObject->SetTag(Tag::Player);
	gameObject->SetName("GrandMa");
	gameObject->AddComponent<Transform>();
	gameObject->GetComponent<Transform>()->SetLocalPosition(pos);
	gameObject->GetComponent<Transform>()->SetLocalRotation(Vector3(0.f, 180.f, 0.f));

	for (auto& gameObj : dodoObjects)
	{
		if (gameObj->GetTransform()->GetParent().lock() == nullptr)
		{
			gameObj->GetTransform()->SetParent(gameObject->GetTransform());
			gameObject->SetChild(gameObj);
		}
	}
}

GrandMaPrefab::~GrandMaPrefab()
{}
