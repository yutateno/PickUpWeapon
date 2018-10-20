#include "Scene.h"

bool Scene::endFlag;
eScene Scene::scene;
int Scene::playmode;
int Scene::nowmode;

Scene::Scene()
{

}

bool Scene::GetEndFlag()
{
	return Scene::endFlag;
}

eScene Scene::GetScene()
{
	return Scene::scene;
}