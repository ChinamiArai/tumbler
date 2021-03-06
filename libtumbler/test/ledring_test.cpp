/*
 * @file ledring_test.cpp
 * @brief ledring.h の単体試験
 * @author Copyright (C) 2017 Fairy Devices Inc. http://www.fairydevices.jp/
 * @author Masato Fujino, created on: 2017/11/22 
 */

#include <iostream>
#include "tumbler/tumbler.h"
#include "tumbler/ledring.h"

int main(int argc, char** argv)
{
    using namespace tumbler;
    {
        // 青点灯
		Frame frame;
		for(int i=0;i<18;++i){
			frame.setLED(i, LED(0,0,255));
		}
		LEDRing& ring = LEDRing::getInstance();
		ring.addFrame(frame);
		ring.show(false); // 同期
    }
    {
		// R->G->B の順に点灯
		std::vector<Frame> frames(3);
		for(int i=0;i<18;++i){
			frames[0].setLED(i, LED(255,0,0));
			frames[1].setLED(i, LED(0,255,0));
			frames[2].setLED(i, LED(0,0,255));
		}
		LEDRing& ring = LEDRing::getInstance();
		ring.setFrames(frames);
		ring.setFPS(1);
		ring.show(false); // 同期
    }
    {
    	// 回転
		LEDRing& ring = LEDRing::getInstance();
		ring.clearFrames();
		LED background(0,0,100);
		for(int rot = 0; rot < 5; ++rot){ // 5 回転
			for(int i=0;i<18;++i){
				Frame frame(background);
				frame.setLED(i, LED(255,0,0));
				ring.addFrame(frame);
			}
		}
		ring.setFPS(30);
    	ring.show(false);
    }

	LEDRing& ring = LEDRing::getInstance();
	ring.reset(false); // 非同期でリセットし終了
	return 0;
}


