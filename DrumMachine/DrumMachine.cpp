//
// Created by fritz on 7/3/17.
//

#include <SDL2/SDL.h>
#include <chrono>
#include <iostream>
#include <boost/thread.hpp>
#include <boost/asio.hpp>
#include "DrumMachine.h"

using namespace std::chrono;
using namespace std;

DrumMachine::DrumMachine() : loopRunning(false), currentBeat(0) {
    SDL_Init(SDL_INIT_AUDIO);
    this->openAudio();
    this->allocateChannels();
    setBPM(120);

    Sample baseDrum("./audio_files/tr909_16bit/bd01.wav");
    baseDrum.preFillKickDrumArray();
    this->samples.push_back(baseDrum);

    Sample clap("./audio_files/tr909_16bit/cp01.wav");
    clap.preFillClapArray();
    this->samples.push_back(clap);

    Sample highHat("./audio_files/tr909_16bit/oh01.wav");
    highHat.preFillHighHatArray();
    this->samples.push_back(highHat);
}

long long getCurrentTimeMillis() {
    return duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
}

void DrumMachine::loop() {
    boost::asio::io_service ioService;
    boost::thread_group threadpool;

    boost::asio::io_service::work work(ioService);
    threadpool.create_thread(
            boost::bind(&boost::asio::io_service::run, &ioService)
    );
    threadpool.create_thread(
            boost::bind(&boost::asio::io_service::run, &ioService)
    );
    threadpool.create_thread(
            boost::bind(&boost::asio::io_service::run, &ioService)
    );
    threadpool.create_thread(
            boost::bind(&boost::asio::io_service::run, &ioService)
    );

    long long timeElapsed;
    long long lastTime = 0;
    while (loopRunning) {
        timeElapsed = getCurrentTimeMillis() - lastTime;

        if (timeElapsed >= sixteenthNoteMillis) {
            for (size_t i = 0; i < samples.size(); i++) {
                ioService.post(boost::bind(&Sample::playSample, &this->samples.at(i), currentBeat));
            }

            lastTime = getCurrentTimeMillis();

            currentBeat++;
            cout << currentBeat << endl ;
            if (currentBeat >= TOTAL_BEATS * TOTAL_LOOPS) {
                currentBeat = 0;
            }
        }
    }
}

void DrumMachine::startLoop() {
    loopRunning = true;
    loop();
}

void DrumMachine::stopLoop() {
    loopRunning = false;
}

void DrumMachine::setBPM(int bpm) {
    this->bpm = bpm;
    this->sixteenthNoteMillis = 60000/bpm/16;
}

int DrumMachine::getBPM() {
    return this->bpm;
}

void DrumMachine::openAudio() {
    int result = Mix_OpenAudio(44100, AUDIO_S16SYS, 2, 512);
    if (result < 0) {
        fprintf(stderr, "Unable to open audio: %s\n", SDL_GetError());
        exit(-1);
    }
}

void DrumMachine::allocateChannels() {
    int result = Mix_AllocateChannels(8);
    if (result < 0) {
        fprintf(stderr, "Unable to allocate mixing channels: %s\n", SDL_GetError());
        exit(-1);
    }
}