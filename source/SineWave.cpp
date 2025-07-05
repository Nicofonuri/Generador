#include "SineWave.h"


void SineWave::prepare(double sampleRate)
{
    currentSampleRate = static_cast<float>(sampleRate);
    timeIncrement = 1.0 / currentSampleRate;
}

void SineWave::process(juce::AudioBuffer<float>& buffer)
{
    for (int channel = 0; channel < buffer.getNumChannels(); ++channel)
    {
        auto* output = buffer.getWritePointer(channel);

        for (int sample = 0; sample < buffer.getNumSamples(); ++sample)
        {
            float outSample = amplitude * std::sinf(juce::MathConstants<float>::twoPi * frequency * currentTime);
            output[sample] = outSample;
            currentTime = currentTime + timeIncrement;
        }
    }
};