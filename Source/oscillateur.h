#pragma once
#include <cmath>
#include <juce_core/juce_core.h>

enum class WaveType
{
    Sine,
    Square,
    Triangle,
    Sawtooth,
    Random
};

class Oscillator
{
public:
    float inc;
    float modulo_counter;
    float amplitude;
    WaveType waveType;

    void reset()
    {
        modulo_counter = 0.0f;
    }

    void setAmplitude(float amplitude) {
        this->amplitude = amplitude;
    }

    void setWaveType(WaveType newWaveType) {
        waveType = newWaveType;
    }

    float nextSample()
    {
        float output = 0.0f;

        modulo_counter += inc;
        if (modulo_counter >= 1.0f)
            modulo_counter -= 1.0f;

        switch (waveType)
        {
        case WaveType::Sine:
            output = std::sin(juce::MathConstants<float>::twoPi * modulo_counter);
            break;
        case WaveType::Square:
            output = (modulo_counter < 0.5f) ? 1.0f : -1.0f;
            break;
        case WaveType::Triangle:
            output = 2.0f * std::abs(2.0f * (modulo_counter - std::floor(modulo_counter + 0.5f))) - 1.0f;
            break;
        case WaveType::Sawtooth:
            output = 2.0f * (modulo_counter - std::floor(modulo_counter + 0.5f));
            break;
        case WaveType::Random:
            output = juce::Random::getSystemRandom().nextFloat() * 2.0f - 1.0f;
            break;
        }

        return output * amplitude;
    }
};
