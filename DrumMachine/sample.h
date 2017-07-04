//
// Created by Kilian Wutzke on 27.06.17.
//

#ifndef DRUMMACHINE_SAMPLE_H
#define DRUMMACHINE_SAMPLE_H



class sample {
public:
private:
    bool m_active;
    int m_loopLength;
    vector<int> m_playArray[32];
    bool m_playing;

};


#endif //DRUMMACHINE_SAMPLE_H
