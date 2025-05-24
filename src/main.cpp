#include <Geode/Geode.hpp>
#include <Geode/modify/MenuLayer.hpp>
#include <Geode/modify/LoadingLayer.hpp>
using namespace geode::prelude;

class $modify(MyMenuLayer, MenuLayer) {
	static void onModify(auto& self) {
		(void) self.setHookPriorityAfterPost("MenuLayer::init", "flingus.geometry_pride");
	}

	bool init() {
		if (!MenuLayer::init()) return false;
		auto oldtitle = this->getChildByID("main-title");

		if (!oldtitle || !oldtitle->isVisible()) { // make a button in the bottom-menu instead of making a title if there is no title
			auto btmmenu = this->getChildByID("bottom-menu");
			if (!btmmenu) return true;

			auto newbtnspr = CircleButtonSprite::create(
				CCSprite::create("btn.png"_spr),
				CircleBaseColor::Green,
				CircleBaseSize::MediumAlt
			);
			auto newbtn = CCMenuItemSpriteExtra::create(
				newbtnspr,
				this,
				menu_selector(MyMenuLayer::iammusic)
			);
			newbtn->setID("iammusic-btn"_spr);
			btmmenu->addChild(newbtn);
			btmmenu->updateLayout();
		} else {
			typeinfo_cast<CCSprite*>(oldtitle)->setOpacity(0);

			auto titlemenu = CCMenu::create();
			titlemenu->setID("iammusic-title-menu"_spr);
			oldtitle->addChild(titlemenu);
			titlemenu->setPosition({215, 30});

			auto title = CCMenuItemSpriteExtra::create(
				CCSprite::create("title.png"_spr),
				this,
				menu_selector(MyMenuLayer::iammusic)
			);
			title->setID("iammusic-title"_spr);
			titlemenu->addChild(title);
		}
		return true;
	}
	
	void iammusic(CCObject*) {
		std::string rngtxt = "Coming in 5 years!";
		switch(rand() % 20) { // i never see "SEEYUH" when its at 19 so its at 20, probably just me being unlucky
			case 1: rngtxt = "12 0CLOCK PST";
			break;
			case 2: rngtxt = "FRIDAY";
			break;
			case 3: rngtxt = "love all my supporters - it's time";
			break;
			case 4: rngtxt = "ONLY TOOK 5 YEARS";
			break;
			case 5: rngtxt = "ANY MINUTE NOW";
			break;
			case 6: rngtxt = "I AM GEOMETRY DASH";
			break;
			case 7: rngtxt = "00XO - IT'S TIME";
			break;
			case 8: rngtxt = "TONIGHT.";
			break;
			case 9: rngtxt = "TURN MY VOLUME UP";
			break;
			case 10: rngtxt = "HAVE FAITH.";
			break;
			case 11: rngtxt = "I AM GEOMETRY DASH - THE GAME - FRIDAY";
			break;
			case 12: rngtxt = "PREPARE";
			break;
			case 13: rngtxt = "BE READY.";
			break;
			case 14: rngtxt = "I AM GEOMETRY DASH OUT NOW";
			break;
			case 15: rngtxt = "MARCH";
			break;
			case 16: rngtxt = "DASH - DASH - DASH - DASH - DASH";
			break;
			case 17: rngtxt = "SWAMP IZZO";
			break;
			case 18: rngtxt = "FWAEH";
			break;
			case 19: rngtxt = "SEEYUH";
		}
		FLAlertLayer::create(
			"GEOMETRY DASH",
			rngtxt,
			"Okay"
		)->show();
	}
};

class $modify(MyLoadingLayer, LoadingLayer) {
	bool init(bool p0) {
		if (!LoadingLayer::init(p0)) return false;
		auto oldtitle = this->getChildByIDRecursive("gd-logo");
		if (!oldtitle) return true;
		typeinfo_cast<CCSprite*>(oldtitle)->setOpacity(0);
		
		auto searchPath = dirs::getModRuntimeDir() / Mod::get()->getID() / "resources";
		CCFileUtils::get()->addSearchPath(searchPath.string().c_str()); // thanks alpha

		auto title = CCSprite::create("title.png"_spr);
		title->setID("iammusic-title"_spr);
		oldtitle->addChild(title);
		title->setPosition({215, 30});
		return true;
	}
};
