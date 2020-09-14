﻿#include"HPObject.h"

HP hp;
HP hp_boss;
SDL_Surface * hp_border;
SDL_Surface* hp_border_boss;


const int X_POS_HP_BORDER_BOSS = SCREEN_WIDTH - 350;					// X CỦA THANH MÁU BOSS
const int X_POS_HP_BOSS = SCREEN_WIDTH - 344;						    // X CỦA THANH MÁU BOSS
const int Y_POS_HP_BOSS = Y_POS_HP_MAIN;								// Y CUA THANH MAU BOSS

unsigned int die_num = 0;												// biến đếm số lần main trúng đạn
unsigned int die_num_boss = 0;

int DAME_OF_MAIN = 1;
const int LIFE_OF_THREAT = DAME_OF_MAIN * 2;							// mau cua threat

HP::HP() {
	rect_.x = 0;
	rect_.y = 0;
	rect_.w = LIFE;
	_number = 0;
	_number_boss = 0;
	_number_threat = 0;
}

HP::~HP(){}

void HP::addPos(const int& pos) {
	_pos_list.push_back(pos);
}

void HP::addPos_boss(const int& pos) {
	_pos_list_boss.push_back(pos);
}

//void HP::addPos_threat(const int& pos) {
//	_pos_list_threat.push_back(pos);
//}

void HP::render(SDL_Surface* des) {
	if (_number == _pos_list.size()) {
		for (int i = 0; i < _pos_list.size(); i ++) {
			rect_.x = _pos_list.at(i);
			showObject(des);
		}
	}
}

void HP::render_boss(SDL_Surface* des) {
	if (_number_boss == _pos_list_boss.size()) {
		for (int i = 0; i < _pos_list_boss.size(); i++) {
			rect_.x = _pos_list_boss.at(i);
			showObject(des);
		}
	}
}

//void HP::render_threat(SDL_Surface* des) {
//	if (_number_threat == _pos_list_threat.size()) {
//		for (int i = 0; i < _pos_list_threat.size(); i++) {
//			rect_.x = _pos_list_threat.at(i);
//			showObject(des);
//		}
//	}
//}

void HP::init() {
	loadImgObject("HP.png");
	_number = LIFE;
	if (_pos_list.size() > 0) _pos_list.clear();

	int count = X_POS_HP_MAIN + 60; // CÁI NÀY NÓ CÓ Ý NGHĨA SẼ PUSH_BACK TỪNG VỊ TRÍ MÀ MỖI CỘT MÁU NHỎ SẼ XUẤT HIỆN SAU ĐÓ TẠO THÀNH 1 THANH MÁU TO
	for (int i = 0; i < LIFE; i ++) {
		addPos(count);
		count += 2;
	}
}

void HP::init_BOSS() {
	loadImgObject("HP_boss.png");
	_number_boss = LIFE_BOSS;
	if (_pos_list_boss.size() > 0) _pos_list_boss.clear();

	int count = X_POS_HP_BOSS + LIFE_BOSS * 2; // CÁI NÀY NÓ CÓ Ý NGHĨA SẼ PUSH_BACK TỪNG VỊ TRÍ MÀ MỖI CỘT MÁU NHỎ SẼ XUẤT HIỆN SAU ĐÓ TẠO THÀNH 1 THANH MÁU TO
	for (int i = 0; i < LIFE_BOSS; i++) {
		addPos_boss(count);
		count -= 2;
	}
}

//void HP::init_threat() {
//	loadImgObject("HP_threat.png");
//	_number_threat = LIFE_BOSS;
//	if (_pos_list_threat.size() > 0) _pos_list_threat.clear();
//
//	int count = 0; // CÁI NÀY NÓ CÓ Ý NGHĨA SẼ PUSH_BACK TỪNG VỊ TRÍ MÀ MỖI CỘT MÁU NHỎ SẼ XUẤT HIỆN SAU ĐÓ TẠO THÀNH 1 THANH MÁU TO
//	for (int i = 0; i < LIFE_OF_THREAT; i++) {
//		addPos_threat(count);
//		count += 2;
//	}
//}

//void HP::load_border(SDL_Surface* des) {
//	loadImg("HP_border.png");
//	rect_.x = 0;
//	rect_.y = 0;
//	show(des);
//}

void HP::decreaseHP(){
	_number--;
	if (_pos_list.size() >= 0) _pos_list.pop_back();
}

void HP::decreaseHP_BOSS() {
	_number_boss--;
	if (_pos_list_boss.size() >= 0) _pos_list_boss.pop_back();
}


//void HP::decreaseHP_threat() {
//	_number_threat--;
//	if (_pos_list_threat.size() >= 0) _pos_list_threat.pop_back();
//}






//-------------------------------------------------------------------------------//


void HpFunc::prepareHpMain()
{
	hp.init();
	hp.setRect(X_POS_HP_MAIN, Y_POS_HP_MAIN);
}

void HpFunc::prepareHpBoss()
{
	hp_boss.init_BOSS();
	hp_boss.setRect(X_POS_HP_BOSS, Y_POS_HP_BOSS + 1);

}



bool HpFunc::prepareMainHpBorder()
{
	hp_border = SDLCommonFunc::loadImage("HP_border.png");
	if (hp_border == NULL)
		return 0;
	return true;
}



bool HpFunc::prepareBossHpBorder()
{
	hp_border_boss = SDLCommonFunc::loadImage("HP_border_boss.png");
	if (hp_border_boss == NULL)
		return false;
	return true;
}

