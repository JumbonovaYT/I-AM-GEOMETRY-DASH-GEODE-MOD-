#include <Geode/Geode.hpp>
using namespace geode::prelude;
#include <Geode/modify/MenuLayer.hpp>
#include <Geode/modify/LoadingLayer.hpp>
#include <Geode/modify/MenuGameLayer.hpp>

class $modify(MyMenuLayer, MenuLayer) {
	bool init() {
		if (!MenuLayer::init()) return false;
		auto oldtitle = this->getChildByID("main-title");
		if (!oldtitle) {
			log::error("couldn't find MenuLayer>main-title");
			return true;
		}
		typeinfo_cast<cocos2d::CCSprite*>(oldtitle)->setOpacity(0);
		auto titlemenu = CCMenu::create();
		titlemenu->setID("iammusic-title-menu");
		oldtitle->addChild(titlemenu);
		titlemenu->setPosition(213, 23);
		auto title = CCMenuItemSpriteExtra::create(
			CCSprite::create("title.png"_spr),
			this,
			menu_selector(MyMenuLayer::iammusic)
		);
		title->setID("iammusic-title");
		titlemenu->addChild(title);
		return true;
	}
	
	void iammusic(CCObject*) {
		std::string randomtext = "Coming in 5 years!";
		switch(rand() % 16 + 0) {
			case 1: randomtext = "12 0CLOCK PST";
			break;			
			case 2: randomtext = "FRIDAY";
			break;			
			case 3: randomtext = "love all my supporters - it's time";
			break;			
			case 4: randomtext = "ONLY TOOK 5 YEARS";
			break;			
			case 5: randomtext = "ANY MINUTE NOW";
			break;			
			case 6: randomtext = "I AM GEOMETRY DASH";
			break;			
			case 7: randomtext = "00XO - IT'S TIME";
			break;			
			case 8: randomtext = "TONIGHT.";
			break;			
			case 9: randomtext = "TURN MY VOLUME UP";
			break;			
			case 10: randomtext = "HAVE FAITH.";
			break;
			case 11: randomtext = "I AM GEOMETRY DASH - THE GAME - FRIDAY";
			break;
			case 12: randomtext = "PREPARE";
			break;
			case 13: randomtext = "BE READY.";
			break;
			case 14: randomtext = "I AM GEOMETRY DASH OUT NOW";
			break;
			case 15: randomtext = "MARCH";
			break;
			case 16: randomtext = "DASH - DASH - DASH - DASH - DASH";
			break;
		}
		FLAlertLayer::create(
			"GEOMETRY DASH",
			randomtext,
			"Okay"
		)->show();
	}
};

class $modify(MyLoadingLayer, LoadingLayer) {
	bool init(bool p0) {
		if (!LoadingLayer::init(p0)) return false;
		auto oldtitle = this->getChildByIDRecursive("gd-logo");
		if (!oldtitle) {
			log::error("couldn't find LoadingLayer>gd-logo");
			return true;
		}
		typeinfo_cast<cocos2d::CCSprite*>(oldtitle)->setOpacity(0);
		auto searchPath = dirs::getModRuntimeDir() / Mod::get()->getID() / "resources";
		CCFileUtils::get()->addSearchPath(searchPath.string().c_str()); // thanks alpha
		auto title = CCSprite::create("title.png"_spr);
		title->setID("iammusic-title");
		oldtitle->addChild(title);
		title->setPosition({211, 30});
		return true;
	}
};
