#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"

#include "Box2D/Box2D.h"

#include "SimpleAudioEngine.h"

#include "CGui.h"
class HelloWorld : public cocos2d::CCLayer
{
public:
	~HelloWorld();
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();  

    // there's no 'id' in cpp, so we recommand to return the exactly class pointer
    static cocos2d::CCScene* scene();
    
    // a selector callback
    void menuCloseCallback(CCObject* pSender);

    // implement the "static node()" method manually
    CREATE_FUNC(HelloWorld);

	//////////////////////////////////////////////////////////////////////////
	virtual void registerWithTouchDispatcher(void);
	//////////////////////////////////////////////////////////////////////////
	
	void draw();
private:
	CGui* m_pGUI;
};

#endif  // __HELLOWORLD_SCENE_H__