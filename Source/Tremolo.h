
#pragma once
#include "oscillateur.h"

class Tremolo
{
public:
	Oscillator lfo;
	float modulationDepth;

	void reset()
	{
		lfo.reset();
		lfo.amplitude = 1.0;
	}

	void setFrequency(float tremoloFreq, double sampleRate)
	{
		lfo.inc = tremoloFreq / sampleRate;
	}

	void setWaveType(WaveType waveType)
	{
		lfo.setWaveType(waveType);
	}
	

	float nextSample()
	{
		lfo.setAmplitude(modulationDepth);
		return (1 - modulationDepth) + lfo.nextSample();
	}
};