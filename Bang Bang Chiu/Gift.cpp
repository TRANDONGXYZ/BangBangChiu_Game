﻿#include "Gift.h"

Gift::Gift() {
	rect_.x = rect_.y = 0;												// Tọa độ xuất hiện mặc định là gốc tọa độ
	x_val_ = y_val_ = 0;												// Tốc độ di chuyển mặc định là 0 theo cả chiều dọc va chiều ngang
	rect_.w = GIFT_WIDTH;
	rect_.h = GIFT_HEIGHT;
	type_ = Gift::NONE;													// Mặc định là có kiểu POWER
	is_move_ = true;													// Mặc định được phép di chuyển
}

Gift::~Gift() {
	// Do something here
}

void Gift::handleInputAction(SDL_Event events) {
	// Do something here
}

void Gift::handleMove(const int& x_border, const int& y_border) {
	if (is_move_) {
		rect_.x -= x_val_;
		if (rect_.x < 0)
			is_move_ = false;
	}
}