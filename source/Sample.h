#ifndef DRUMMACHINE_SAMPLE_H
#define DRUMMACHINE_SAMPLE_H

#ifdef __APPLE__

#include "SDL2/SDL.h"
#include "SDL2_mixer/SDL_mixer.h"
#include "SDL2_image/SDL_image.h"

#else
#include "SDL2/SDL_mixer.h"
#include "SDL2/SDL.h"
#endif

#include <vector>
#include <string>
#include <thread>
#include <iostream>

using namespace std;

namespace state {
    const unsigned short PLAY = 1, MUTE = 0;
}

/**
 * @brief   A class that holds and maintains information about a sample audio file,
 *          which can be played by the Drum Machine
 *
 */

class Sample {
public:

    /**
     * Constructor
     * @param samplePath defines where to find the audio sample file
     */
    explicit Sample(const char *samplePath);

    /**
     * Checks if the sample is active for the passed beat position and if so, plays it
     * @param currentBeat the current beat position of the running loop
     */
    void playSample(int currentBeat);

    /// Plays sample, when called
    void play();

    /**
     * Activates sample at the passed beatPosition
     * @param beatPosition the beat position, where to activate the sample
     */
    void playAtBeat(unsigned int beatPosition);

    /**
     * Toggles sample state at the passed beatPosition from active to inactive or vice versa
     * @param beatPosition the beat position where to toggle the sample state
     */
    void togglePlayAtBeat(unsigned short beatPosition);

    // Getters and Setters

    ///Setter of member volume
    void setVolume(float volume);

    ///Getter of member volume
    float getVolume();

    ///Setter of member masterVolume
    void setMasterVolume(float volume);

     // Getter of member playArray
    vector<unsigned short> &getPlayArray();

private:
    //@todo extend the documentation
    Mix_Chunk *sampleFile;              ///< Pointer to
    vector<unsigned short> playArray;   ///< Vector that holds 16 zeroes or ones. One stands for an active state and zero for an inactive state
    float volume;                       ///< The volume of the sample
    //@todo extend the documentation
    float masterVolume;                 ///< The master volume of the sample

    //@todo extend the documentation
    ///Sets the mix volume
    void setMixVolume();

    ///Getter of master Volume
    float getMasterVolume();
};
#endif //DRUMMACHINE_SAMPLE_H
