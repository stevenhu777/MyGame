/****************************************************************************
 Copyright (c) 2017-2018 Xiamen Yaji Software Co., Ltd.
 
 http://www.cocos2d-x.org
 
 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:
 
 The above copyright notice and this permission notice shall be included in
 all copies or substantial portions of the Software.
 
 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 THE SOFTWARE.
 ****************************************************************************/

#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"

USING_NS_CC;

Scene* HelloWorld::createScene()
{
    return HelloWorld::create();
}

// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Scene::init() )
    {
        return false;
    }

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.

    // add a "close" icon to exit the progress. it's an autorelease object
    auto closeItem = MenuItemImage::create(
                                           "CloseNormal.png",
                                           "CloseSelected.png",
                                           CC_CALLBACK_1(HelloWorld::menuCloseCallback, this));

    if (closeItem == nullptr ||
        closeItem->getContentSize().width <= 0 ||
        closeItem->getContentSize().height <= 0)
    {
        problemLoading("'CloseNormal.png' and 'CloseSelected.png'");
    }
    else
    {
        float x = origin.x + visibleSize.width - closeItem->getContentSize().width/2;
        float y = origin.y + closeItem->getContentSize().height/2;
        closeItem->setPosition(Vec2(x,y));
    }

    // create menu, it's an autorelease object
    auto menu = Menu::create(closeItem, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);

    /////////////////////////////
    // 3. add your codes below...

    // add a label shows "Hello World"
    // create and initialize a label

    auto label = Label::createWithTTF("Hello World", "fonts/Marker Felt.ttf", 24);
    if (label == nullptr)
    {
        problemLoading("'fonts/Marker Felt.ttf'");
    }
    else
    {
        // position the label on the center of the screen
        label->setPosition(Vec2(origin.x + visibleSize.width/2,
                                origin.y + visibleSize.height - label->getContentSize().height));

        // add the label as a child to this layer
        this->addChild(label, 1);
    }

    //// add "HelloWorld" splash screen"
    //auto sprite = Sprite::create("HelloWorld.png");
    //if (sprite == nullptr)
    //{
    //    problemLoading("'HelloWorld.png'");
    //}
    //else
    //{
    //    // position the sprite on the center of the screen
    //    sprite->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));

    //    // add the sprite as a child to this layer
    //    this->addChild(sprite, 0);
    //}
	//テクスチャファイル名を指定して、スプライトを作成
	/*sprite[0] = Sprite::create("sample06.png");
	this->addChild(sprite[0]);
	sprite[0]->setScale(3);
	sprite[0]->setTextureRect(Rect(0, 32, 32, 32));
	sprite[0]->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2));
	MoveBy* action1 = MoveBy::create(2.0f, Vec2(200, 100));
	sprite[0]->runAction(action1);*/
	//乱数の初期化
	//Random r=new Random();
	srand(time(nullptr));

	for (int i = 0; i < 5; i++)
	{
		sprite[i] = Sprite::create("sample06.png");
		this->addChild(sprite[i]);
		sprite[i]->setTextureRect(Rect(0, 32, 32, 32));
		sprite[i]->setScale(3);
		sprite[i]->setPosition(Vec2(100*i, visibleSize.height / 2));

		float mx, my;

		mx = (float)rand()/RAND_MAX*600;
		my = (float)rand()/RAND_MAX*600;

		MoveBy* action1 = MoveBy::create(10.0f, Vec2(mx, my));
		sprite[i]->runAction(action1);
	}

	//sprite2 = Sprite::create("sample06.png");
	//demoSprite = Sprite::create("sample09.png");


	//demoSprite->setPosition(Vec2(visibleSize.width/2, visibleSize.height/2));
	//
	////sprite->setRotation(45.0f);
	//sprite->setScale(3);
	//demoSprite->setScale(3);
	////不透明度
	//sprite->setOpacity(255);
	//demoSprite->setOpacity(0);

	////アンカーポイント　
	//sprite->setAnchorPoint(Vec2(0.5f, 0.5f));
	//demoSprite->setAnchorPoint(Vec2(0.5f, 0.5f));
	//色変更
	//sprite->setColor(Color3B(255, 0, 0));
    //左右反転
	//sprite->setFlippedX(true);
    //表示幅
	//sprite->setTextureRect(Rect(0, 32, 32, 32));
	//sprite2->setTextureRect(Rect(32, 32, 32, 32));

	////demoSprite->setTextureRect(Rect(0, 32, 32, 32));
	////方向回転
	////sprite->setRotation(180);
	////sprite->setScaleY(-1);

	////シーングラフにつなぐ
	//this->addChild(sprite);
	//this->addChild(sprite2);
	////this->addChild(demoSprite);

	////this->scheduleUpdate();
	//sprite->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2));
	//sprite2->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2));

	//sprite->setScale(3);
	//sprite2->setScale(3);

	//MoveBy* action1 = MoveBy::create(2.0f, Vec2(200, 100));
	////加速
	//EaseIn* action2 = EaseIn::create(action1, 5.0f);

	//MoveBy* action3 = MoveBy::create(2.0f, Vec2(-200, -100));
	////加速
	//EaseIn* action4 = EaseIn::create(action3, 5.0f);
	//EaseBounceIn* action2 = EaseBounceIn::create(action1);
	//ScaleBy* action1 = ScaleBy::create(1.0f, 5.0f);
	//JumpTo* action1 = JumpTo::create(1.5f, Vec2(200, 100), 500.0f, 1);
	/*ccBezierConfig conf;
	conf.controlPoint_1 = Vec2(500, 500);
	conf.controlPoint_2 = Vec2(500, 100);
	conf.endPosition = Vec2(200, 100);
	BezierTo* action1 = BezierTo::create(3.0f, conf);*/

	//*sprite->setOpacity(0);
	//FadeIn* action1 = FadeIn::create(1.0f);*/
	//sprite->runAction(action2);
	//sprite2->runAction(action2->clone());
    return true;
}



void HelloWorld::menuCloseCallback(Ref* pSender)
{
    //Close the cocos2d-x game scene and quit the application
    Director::getInstance()->end();

    /*To navigate back to native iOS screen(if present) without quitting the application  ,do not use Director::getInstance()->end() as given above,instead trigger a custom event created in RootViewController.mm as below*/

    //EventCustom customEndEvent("game_scene_close_event");
    //_eventDispatcher->dispatchEvent(&customEndEvent);


}
void HelloWorld::update(float delta) {

	//Vec2 pos = sprite->getPosition();
	//pos += Vec2(1.0f, 1.0f);
	//sprite->setPosition(pos);

	//左上を中心に回転
    /*angle += 5;
	sprite->setRotation(angle);*/


	//色を変更
	//redAlpha-= 255.0f/180;
	//if (redAlpha<5.0f)
	//{
	//	redAlpha = 0.0f;
	//}
	//blueAlpha += 255.0f / 180;
	//if (blueAlpha>250.0f)
	//{
	//	blueAlpha = 255.0f;
	//}
	//
	//sprite->setColor(Color3B(redAlpha, 0, blueAlpha));


	//クロスフェード
	/*spriteAlpha += spriteAddAlpha;
	sprite->setOpacity(spriteAlpha);

	demoSpriteAlpha += demoSpriteAddAlpha;
	demoSprite->setOpacity(demoSpriteAlpha);
	if (spriteAlpha==255||spriteAlpha==0)
	{
		spriteAddAlpha = -spriteAddAlpha;
	}
	if (demoSpriteAlpha==255|| demoSpriteAlpha == 0)
	{
		demoSpriteAddAlpha = -demoSpriteAddAlpha;
	}*/


	//左右回復

	//Vec2 pos = sprite->getPosition();
	//if (pos.x> 1280.0f - 32.0f||pos.x<32.0f)
	//{
	//	addPosition = -addPosition;
	//}
	//pos += addPosition;
	//sprite->setPosition(pos);
}
