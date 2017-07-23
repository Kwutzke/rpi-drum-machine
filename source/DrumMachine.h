#ifndef DRUMMACHINE_DRUMMACHINE_H
#define DRUMMACHINE_DRUMMACHINE_H

#include <vector>
#include "Sample.h"
#include "AOutputController.h"
#include "RaspOutputController.h"
#include "Timer.h"

using namespace std;

namespace sample {
    const unsigned short
            SAMPLE1 = 0, SAMPLE2 = 1, SAMPLE3 = 2, SAMPLE4 = 3,
            SAMPLE5 = 4, SAMPLE6 = 5, SAMPLE7 = 6, SAMPLE8 = 7,
            NO_SAMPLE = 8;
}

namespace beat {
    const unsigned short
            BEAT1 = 0, BEAT2 = 1, BEAT3 = 2, BEAT4 = 3, BEAT5 = 4, BEAT6 = 5, BEAT7 = 6, BEAT8 = 7,
            BEAT9 = 8, BEAT10 = 9, BEAT11 = 10, BEAT12 = 11, BEAT13 = 12, BEAT14 = 13, BEAT15 = 14, BEAT16 = 15;
}

/**
 * @brief   Handles the beat loop and samples including correct timing for the give BPM,
 *          playing them at the correct beat steps and increasing and decreasing the volume.
 */
class DrumMachine {
private:
    const unsigned short MIN_BPM = 20,      ///< The lowest value the bpm can be
            MAX_BPM = 220;                  ///< The highest value the bpm can be
    const unsigned short WHOLE_BEATS = 4,   ///< The number of whole beats the loop has
            BEATS_PER_WHOLE_BEAT = 4;       ///< The number of beats one whole beat has
    const unsigned short TOTAL_BEATS = WHOLE_BEATS * BEATS_PER_WHOLE_BEAT; ///< The resulting total beats the loop has
    const unsigned long LOOP_PRECISION_NANOS = 10000;   ///< The precision with which the loop timer runs

    unsigned short bpm;             ///< BPM at which the loop runs
    unsigned short currentBeat;     ///< The number of the current beat
    unsigned short activeSample;    ///< The index of the active sample
    unsigned int beatMillis;        ///< Milliseconds that one beat lasts
    bool loopRunning;               ///< Stores whether the loop is running or not
    float volume;                   ///< The current master volume

    AOutputController &outputController;    ///< Reference to the regsitered OutputController
    Timer loop;                             ///< The loop timer
    vector<Sample> samples;                 ///< A List of all added samples

    void allocateChannels();        ///< Helper function which allocates the audio channels

    void openAudio();               ///< Initializes the audio

public:
    /**
     * Constructor
     * @param outputController the outputController the drum machine passes events to
     */
    explicit DrumMachine(AOutputController &outputController);

    /**
     * Starts the beat loop.
     */
    void startLoop();

    /**
     * Stops the beat loop.
     */
    void stopLoop();

    /**
     * Add a sample to be available for use in the drum machine. The order of adding samples determines the buttons
     * they are mapped to
     */
    void addSample(Sample);

    /**
     * Increases the volume by a given value.
     * @param value value to increase the master volume by
     */
    void increaseVolume(float value);

    /**
     * Increases the volume of the currently active sample by a given value.
     * @param value value to increase the active sample volume by
     */
    void increaseActiveSampleVolume(float value);

    /**
     * Increases the BPM by a given value.
     * @param value value to increase the bpm by
     */
    void increaseBpm(unsigned short value);

    /**
     * Toggles whether the current sample is played at a specific beat
     * @param beat the beat the sample should be toggled at
     */
    void toggleSampleAtBeat(unsigned short beat);

    // Getters and Setters
    /**
     * @return whether the loop is currently running
     */
    bool isLoopRunning();

    /**
     * Sets the BPM to a specific value
     * @param bpm the new bpm value
     */
    void setBPM(unsigned short bpm);

    /**
     * @return the current BPM
     */
    unsigned short getBPM();

    /**
     * Sets the master volume to a specific value
     * @param volume the new master volume
     */
    void setMasterVolume(float volume);

    /**
     * @return the current master volume
     */
    float getMasterVolume();

    /**
     * Sets the active sample
     * @param newActiveSample The number of the new active sample
     */
    void setActiveSample(unsigned short newActiveSample);

    /**
     * @return The number of the currently active sample
     */
    unsigned short getActiveSample();
};


#endif //DRUMMACHINE_DRUMMACHINE_H
