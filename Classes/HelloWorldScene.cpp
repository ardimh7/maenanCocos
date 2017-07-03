#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"
#include "PluginFacebook/PluginFacebook.h"



USING_NS_CC;

Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::createWithPhysics();
    auto physicsWorld = scene->getPhysicsWorld();
    physicsWorld->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);
    physicsWorld->setGravity(Vec2(0.0f, -1));
    
    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();
    

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    auto _screenSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    
    
    /*
    {
        auto closeNormal = Sprite::create("CloseNormal.png");
        auto closeNormalPhysicsBody = PhysicsBody::createCircle(closeNormal->getBoundingBox().size.width / 2);
        closeNormal->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2 + 100));
        closeNormal->setPhysicsBody(closeNormalPhysicsBody);
        closeNormalPhysicsBody->setDynamic(true);
    
        
        
        this->addChild(closeNormal);
    }
    
    {
        auto closeNormal = Sprite::create("CloseNormal.png");
        auto closeNormalPhysicsBody = PhysicsBody::createCircle(closeNormal->getBoundingBox().size.width / 2);
        closeNormal->setPosition(Vec2(visibleSize.width / 2 + closeNormal->getBoundingBox().size.width * 2, visibleSize.height / 2 + 100));
        closeNormal->setPhysicsBody(closeNormalPhysicsBody);
        closeNormalPhysicsBody->setDynamic(true);
        
        this->addChild(closeNormal);
    }
    
    {
        auto closeNormal = Sprite::create("CloseNormal.png");
        auto closeNormalPhysicsBody = PhysicsBody::createCircle(closeNormal->getBoundingBox().size.width / 2);
        closeNormal->setPosition(Vec2(visibleSize.width / 2 + closeNormal->getBoundingBox().size.width * 4, visibleSize.height / 2 + 100));
        closeNormal->setPhysicsBody(closeNormalPhysicsBody);
        closeNormalPhysicsBody->setDynamic(true);
        
        this->addChild(closeNormal);
    }
    
    
    auto helloWorld = Sprite::create("HelloWorld.png");
    auto helloWorldPhysicsBody = PhysicsBody::createBox(helloWorld->getBoundingBox().size);
    
  
    helloWorld->setScale(0.5, 0.5);
    helloWorld->setPosition(Vec2(visibleSize.width, visibleSize.height / 2));
    
    helloWorld->setPhysicsBody(helloWorldPhysicsBody);
    helloWorldPhysicsBody->setDynamic(true);
    helloWorld->getPhysicsBody()->applyForce(Vec2(1000,1000));
    
    
    this->addChild(helloWorld);
    
    auto edgeBox = PhysicsBody::createEdgeBox(visibleSize, PHYSICSBODY_MATERIAL_DEFAULT, 3);
    auto mainNode = Node::create();
    mainNode->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
    mainNode->setPhysicsBody(edgeBox);
    
    this->addChild(mainNode);
    
    
    
    helloWorldPhysicsBody->setDynamic(false);
    
    */
    
    /*
    for (int i = 0; i < 3; i++)
    {
        visibleSizeHeightMax = _screenSize.height;
        visibleSizeHeightZero = _screenSize.height * 0;
        randomBombYPos = RandomHelper::random_int(visibleSizeHeightZero, visibleSizeHeightMax);

        
        
        mySprite = Sprite::create("CloseNormal.png");
        mySprite->setPosition(Vec2(_screenSize.width / 2, randomBombYPos));
        this->addChild(mySprite);
        
        CCLOG("%f", randomBombYPos);
    }*/
    
    /*
    closeSprite = Sprite::create("CloseNormal.png");
    closeSprite->setPosition(Vec2((_screenSize.width) - origin.x - (closeSprite->getContentSize().width), (_screenSize.height * 0) + origin.y + (closeSprite->getContentSize().height)));
    this->addChild(closeSprite);
    */
    
    
    /*
    sdkbox::PluginFacebook::requestReadPermissions({sdkbox::FB_PERM_READ_PUBLIC_PROFILE, sdkbox::FB_PERM_READ_USER_FRIENDS});
    sdkbox::PluginFacebook::requestPublishPermissions({sdkbox::FB_PERM_PUBLISH_POST});

    
    
    
    /*
    sdkbox::FBShareInfo info;
    info.type   = sdkbox::FB_LINK;
    info.link   = "http://www.arubygames.com";
    info.title  = "Test share ARUBY Games via SDKBOX";
    info.text   = "Best Game Engine";
    info.image  = "gameplayFishPuffer.png";
    sdkbox::PluginFacebook::share(info);
    */
    
    
    auto contactListener = EventListenerPhysicsContact::create();
    contactListener->onContactBegin = CC_CALLBACK_1(HelloWorld::onCollision, this);
    getEventDispatcher()->addEventListenerWithSceneGraphPriority(contactListener, this);
    
    
    
    
    auto edgeBox = PhysicsBody::createEdgeBox(_screenSize, PHYSICSBODY_MATERIAL_DEFAULT, 3);
    auto mainNode = Node::create();
    mainNode->setPosition(Vec2(_screenSize.width / 2 + origin.x, _screenSize.height / 2 + origin.y));
    mainNode->setPhysicsBody(edgeBox);
    
    this->addChild(mainNode);
    
    
    Sprite* white = Sprite::create("white.png");
    white->setScale(10);
    white->setPosition(Vec2(_screenSize.width / 2, _screenSize.height / 2));
    this->addChild(white, kAnotherTag);
    
    isPlayerWalking = false;
    
    
    playerSprite = Sprite::create("HelloWorld.png");
    playerSprite->setScale(0.5);
    playerSprite->setAnchorPoint(Vec2(0,0));
    playerSprite->setPosition(Vec2(_screenSize.width * 0.45, _screenSize.height / 2));
    playerSprite->setTag(kPlayerTag);
    
    //playerBody = PhysicsBody::createBox(playerSprite->getContentSize());
    //_setPhysicsBody(playerSprite);
    
    
    
    
    
    
    
    
    this->addChild(playerSprite);
    
    /*
    {
        fishSprite = Sprite::create("gameplayFishPuffer.png");
        fishSprite->setScale(0.5, 0.5);
        fishSprite->setPosition(Vec2(_screenSize.width * 0.5, _screenSize.height / 2));
        fishSprite->setTag(kFish1);
    
        fishBody = PhysicsBody::createBox(fishSprite->getContentSize());
        _setPhysicsBody(fishSprite);
        _fishs.pushBack(fishSprite);
    
    
        this->addChild(fishSprite);
    }
    
    
    {
        fishSprite = Sprite::create("gameplayFishPuffer.png");
        fishSprite->setScale(0.5, 0.5);
        fishSprite->setPosition(Vec2(_screenSize.width * 0.5, _screenSize.height * 0.60));
        fishSprite->setTag(kFish1);
        
        fishBody = PhysicsBody::createBox(fishSprite->getContentSize());
        _setPhysicsBody(fishSprite);
        _fishs.pushBack(fishSprite);
        
        
        this->addChild(fishSprite);
    }
    
    {
        fishSprite = Sprite::create("gameplayFishPuffer.png");
        fishSprite->setScale(0.5, 0.5);
        fishSprite->setPosition(Vec2(_screenSize.width * 0.5, _screenSize.height * 0.80));
        fishSprite->setTag(kFish1);
        
        fishBody = PhysicsBody::createBox(fishSprite->getContentSize());
        _setPhysicsBody(fishSprite);
        _fishs.pushBack(fishSprite);
        
        
        this->addChild(fishSprite);
    }
    
    
    
    {
        fishSpriteSecond = Sprite::create("gameplayFishPufferExplode.png");
        fishSpriteSecond->setScale(0.5, 0.5);
        fishSpriteSecond->setPosition(Vec2(_screenSize.width * 0.5, _screenSize.height * 0.75));
        fishSpriteSecond->setTag(kFish2);
    
        fishBodySecond = PhysicsBody::createBox(fishSpriteSecond->getContentSize());
        _setPhysicsBody(fishSpriteSecond);
        _fishs.pushBack(fishSpriteSecond);
    
    
        this->addChild(fishSpriteSecond);
    }
    
    
    {
        fishSpriteSecond = Sprite::create("gameplayFishPufferExplode.png");
        fishSpriteSecond->setScale(0.5, 0.5);
        fishSpriteSecond->setPosition(Vec2(_screenSize.width * 0.45, _screenSize.height * 0.75));
        fishSpriteSecond->setTag(kFish2);
        
        fishBodySecond = PhysicsBody::createBox(fishSpriteSecond->getContentSize());
        _setPhysicsBody(fishSpriteSecond);
        _fishs.pushBack(fishSpriteSecond);
        
        
        this->addChild(fishSpriteSecond);
    }
    
    {
        fishSpriteSecond = Sprite::create("gameplayFishPufferExplode.png");
        fishSpriteSecond->setScale(0.5, 0.5);
        fishSpriteSecond->setPosition(Vec2(_screenSize.width * 0.55, _screenSize.height * 0.75));
        fishSpriteSecond->setTag(kFish2);
        
        fishBodySecond = PhysicsBody::createBox(fishSpriteSecond->getContentSize());
        _setPhysicsBody(fishSpriteSecond);
        _fishs.pushBack(fishSpriteSecond);
        
        
        this->addChild(fishSpriteSecond);
    }
    */
    
    
    //UserDefault::getInstance()->setIntegerForKey("score", score);
    
    
    int score = UserDefault::getInstance()->getIntegerForKey("score", 0);
    
    score = 0;
    newScore = 0;
    
    label3 = Label::createWithTTF("00", "fonts/Marker Felt.ttf", 32);
    label3->setPosition( Vec2( origin.x + _screenSize.width * 0.25, origin.y + _screenSize.height * 0.5 ) );
    this->addChild( label3, 1 );

    
    this->scheduleUpdate();
    
    
    /*
    std::vector<cocos2d::Sprite*> mySprites;
     
     
    for ( int i = 0; i < 5; i++ )
    {
        closeSprite = Sprite::create("CloseNormal.png");
        closeSprite->setPosition(Vec2((_screenSize.width * 0.35) + (i * 50), _screenSize.height * 0.75));
        this->addChild(closeSprite);
        
        mySprites.push_back(closeSprite);
        
        body = PhysicsBody::createCircle(closeSprite->getContentSize().width / 2);
        //body->setContactTestBitmask(true);
        //body->setDynamic(true);
        closeSprite->setPhysicsBody(body);
        
        //CCLOG("size : %lu", mySprites.size());
    }
    
    //CCLOG("final : %lu", mySprites.size());
    
    
    
    
    
    /*
    for ( auto sprite : mySprites )
    {
        //sprite->setVisible(false);
        //sprite->getPhysicsBody()->removeAllShapes();
        sprite->removeFromParent();
    }
    
    mySprites.clear();
    
    CCLOG("after delete : %lu", mySprites.size());
    */

    /*
    mySlider = ui::Slider::create();
    mySlider->loadBarTexture("background.png");
    mySlider->loadSlidBallTextureNormal("slider.png");
    mySlider->setPosition(Vec2(_screenSize.width * 0, _screenSize.height * 0));
    mySlider->setAnchorPoint(Vec2(0,0));
    mySlider->setPercent(50);
    mySlider->addEventListener(CC_CALLBACK_2(HelloWorld::sliderEven, this));
    
    
    this->addChild(mySlider);
    */
    
    
    /*
    Rect joystickBaseDimensions;
    joystickBaseDimensions = Rect(0, 0, 160.0f, 160.0f);
    
    Point joystickBasePosition;
    joystickBasePosition = Vec2(_screenSize.width * 0.2f, _screenSize.height * 0.2f);
    
    SneakyJoystickSkinnedBase *joystickBase = new SneakyJoystickSkinnedBase();
    joystickBase->init();
    joystickBase->setPosition(joystickBasePosition);
    joystickBase->setBackgroundSprite(Sprite::create("JoyBackground.png"));
    joystickBase->setThumbSprite(Sprite::create("JoyThumb.png"));
    
    
    SneakyJoystick *aJoystick = new SneakyJoystick();
    aJoystick->initWithRect(joystickBaseDimensions);
    
    aJoystick->autorelease();
    joystickBase->setJoystick(aJoystick);
    joystickBase->setPosition(joystickBasePosition);
    
    leftJoystick = joystickBase->getJoystick();
    leftJoystick->retain();
    
    this->addChild(joystickBase);
    */
    
    
    
   
    
    
    return true;
}

void HelloWorld::setPlayerPosition()
{
    auto _screenSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    setPos = mySlider->getPercent() / 100;
    playerSprite->setPositionX(_screenSize.width * setPos);
}

void HelloWorld::sliderEven(Ref* sender, ui::Slider::EventType type)
{
    auto _screenSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    
    
    if( type == ui::Slider::EventType::ON_PERCENTAGE_CHANGED )
    {
        setPos = (float) mySlider->getPercent() / 100;
        CCLOG("%f", setPos);
        //playerSprite->setPositionX(_screenSize.width * setPos);
        
    }
    
    if ( type == ui::Slider::EventType::ON_SLIDEBALL_DOWN) {
        CCLOG("down");
    }
    
    if ( type == ui::Slider::EventType::ON_SLIDEBALL_CANCEL) {
        CCLOG("cancel");
    }
    
    if ( type == ui::Slider::EventType::ON_SLIDEBALL_UP) {
        
        CCLOG("up");
    }
}


void HelloWorld::update(float dt)
{
    char scoreText[32];
    
    sprintf(scoreText, "%d", score);
    label3->setString(std::string(scoreText));
    auto visibleSize = Director::getInstance()->getVisibleSize();
    
    if(leftJoystick->getVelocity().x > 0)
    {
        CCLOG("right");
    }
    
    if(leftJoystick->getVelocity().x < 0)
    {
        CCLOG("left");
    }
   
}

bool HelloWorld::onCollision(PhysicsContact& contact)
{
    auto nodeA = contact.getShapeA()->getBody()->getNode();
    auto nodeB = contact.getShapeB()->getBody()->getNode();
    
    CCLOG("true collision");
    CCLOG("nodeA tag : %d", nodeA->getTag());
    CCLOG("nodeB tag : %d", nodeB->getTag());
    
    if ((nodeA->getTag() == 1 && nodeB->getTag() == 0)) {
        CCLOG("collide with fish 1");
    }
    
    if ((nodeA->getTag() == 2 && nodeB->getTag() == 0)) {
        CCLOG("collide with fish 2");
    }
    
    if(nodeA->getTag() != 0 && nodeB->getTag() != 0){
        CCLOG("fish to fish collide");
    }
    
    if((nodeA->getTag() == kFish1 && nodeB->getTag() == kPlayerTag) || (nodeB->getTag() == kFish1 && nodeA->getTag() == kPlayerTag)){
        CCLOG("player collide with fish 1");
        score += 5;
        CCLOG("%i", score);
        nodeA->removeFromParent();
        //this->removeChild(nodeA);
    }
    
    if((nodeA->getTag() == kFish2 && nodeB->getTag() == kPlayerTag) || (nodeB->getTag() == kFish2 && nodeA->getTag() == kPlayerTag)){
        CCLOG("player collide with fish 2");
        score += 10;
        nodeA->removeFromParent();
        CCLOG("%i", score);
        //_fishs.eraseObject(fishSpriteSecond);
        //fishSpriteSecond->removeFromParent();
    }
    
    /*
    if(nodeA->getTag() == kPlayerTag && nodeB->getTag() == kFish1){
        CCLOG("accident");
        nodeB->removeFromParent();
        score += 10;
    }
    
    if(nodeA->getTag() == kPlayerTag && nodeB->getTag() == kFish2){
        CCLOG("accident");
        nodeB->removeFromParent();
        score += 10;
    }
     */
    
    return true;
}

void HelloWorld::_setPhysicsBody(Sprite* sprite)
{
    auto body = PhysicsBody::createCircle(sprite->getContentSize().width / 2);
    body->setContactTestBitmask(true);
    body->setDynamic(true);
    sprite->setPhysicsBody(body);
}



void HelloWorld::menuCloseCallback(Ref* pSender)
{
    //Close the cocos2d-x game scene and quit the application
    Director::getInstance()->end();

    #if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
    
    /*To navigate back to native iOS screen(if present) without quitting the application  ,do not use Director::getInstance()->end() and exit(0) as given above,instead trigger a custom event created in RootViewController.mm as below*/
    
    //EventCustom customEndEvent("game_scene_close_event");
    //_eventDispatcher->dispatchEvent(&customEndEvent);
    
    
}
