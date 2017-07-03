#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__
#include "SneakyButton.h"
#include "SneakyButtonSkinnedBase.h"
#include "SneakyJoystickSkinnedBase.h"

#include "cocos2d.h"
#include "ui/CocosGUI.h"

class HelloWorld : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();
    
    SneakyJoystick *leftJoystick;
    SneakyButton *jumpBtn;
    
    // a selector callback
    bool isButtonPress;
    
    
    void menuCloseCallback(cocos2d::Ref* pSender);
    int randomNumber;
    
    int visibleSizeHeightZero;
    int visibleSizeHeightMax;
    float randomBombYPos;
    
    cocos2d::ui::Slider* mySlider;
    
    void setPlayerPosition();
    float setPos;
    bool isPlayerWalking;
    
    
    int pos1;
    int pos2;
    
    
    float initialTouchPos[2];
    float currentTouchPos[2];
    bool isTouchDown;
    
    
    void _setPhysicsBody(cocos2d::Sprite* sprite);
    cocos2d::Vector<cocos2d::Sprite*> _fishs;
    
    void update(float dt);
    void sliderEven(Ref* sender, cocos2d::ui::Slider::EventType type);
    
    cocos2d::PhysicsBody* body;
    cocos2d::PhysicsBody* playerBody;
    cocos2d::Sprite* closeSprite;
    cocos2d::Sprite* playerSprite;
    
    cocos2d::PhysicsBody* fishBody;
    cocos2d::Sprite* fishSprite;
    
    cocos2d::PhysicsBody* fishBodySecond;
    cocos2d::Sprite* fishSpriteSecond;
    
    cocos2d::Label* label3;
    int score;
    int newScore;
    
    bool onCollision(cocos2d::PhysicsContact& contact);
    
    
    enum SpriteTag {
        kAnotherTag,
        kPlayerTag,
        kFish1,
        kFish2
    };
    
    
    // implement the "static create()" method manually
    CREATE_FUNC(HelloWorld);
};

#endif // __HELLOWORLD_SCENE_H__
