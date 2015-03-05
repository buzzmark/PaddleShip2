#include "Paddle.h"

//---------------------------------------------------------------------------
Paddle::Paddle(Ogre::String nym, Ogre::SceneManager* mgr, Simulator* sim, Ogre::SceneNode* shipNode) : GameObject(nym, mgr, sim)
{
	mShipNode = shipNode;
	rootNode->getParent()->removeChild(rootNode);
	shipNode->addChild(rootNode);
	//rootNode->setPosition(Ogre::Vector3(0.0f, 0.0f, 5.0f));

}
//---------------------------------------------------------------------------
Paddle::~Paddle(void)
{
}
//---------------------------------------------------------------------------
void Paddle::addToScene(void)
{
	geom = sceneMgr->createEntity("paddleEnt", "paddle.mesh");
	geom->setCastShadows(true);
	rootNode->attachObject(geom);
	float scale = 1.0f;
	rootNode->setScale(Ogre::Vector3(scale,scale,scale));

	mass = 1.0f; //kinematic
	shape = new btBoxShape(btVector3(4,5,1));




}
//---------------------------------------------------------------------------
void Paddle::update(void)
{
	body->setLinearVelocity( btVector3(1, 1, 0) );
	//rootNode->translate(velocity);
	//GameObject::update();
}
//---------------------------------------------------------------------------
void Paddle::injectKeyDown(const OIS::KeyEvent &arg)
{

}
//---------------------------------------------------------------------------
void Paddle::injectKeyUp(const OIS::KeyEvent &arg)
{

}
//---------------------------------------------------------------------------