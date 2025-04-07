/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "Oscillateur.h"
#include "Tremolo.h"
namespace ParameterID
{
        #define PARAMETER_ID(str) const juce::ParameterID str(#str, 1);

        PARAMETER_ID(mainOscFreq)
        PARAMETER_ID(mainOscAmp)
        PARAMETER_ID(tremFreq)
        PARAMETER_ID(tremDepth)
        PARAMETER_ID(waveType) // Ajout du paramètre pour le type d'onde

       #undef PARAMETER_ID
}

//==============================================================================
/**
*/
class TestMTch_2025AudioProcessor  : public juce::AudioProcessor , private juce::ValueTree::Listener
{
public:
    //==============================================================================
    TestMTch_2025AudioProcessor();
    ~TestMTch_2025AudioProcessor() override;

    //==============================================================================
    void prepareToPlay (double sampleRate, int samplesPerBlock) override;
    void releaseResources() override;

   #ifndef JucePlugin_PreferredChannelConfigurations
    bool isBusesLayoutSupported (const BusesLayout& layouts) const override;
   #endif

    void processBlock (juce::AudioBuffer<float>&, juce::MidiBuffer&) override;

    //==============================================================================
    juce::AudioProcessorEditor* createEditor() override;
    bool hasEditor() const override;

    //==============================================================================
    const juce::String getName() const override;

    bool acceptsMidi() const override;
    bool producesMidi() const override;
    bool isMidiEffect() const override;
    double getTailLengthSeconds() const override;

    //==============================================================================
    int getNumPrograms() override;
    int getCurrentProgram() override;
    void setCurrentProgram (int index) override;
    const juce::String getProgramName (int index) override;
    void changeProgramName (int index, const juce::String& newName) override;

    //==============================================================================
    void getStateInformation (juce::MemoryBlock& destData) override;
    void setStateInformation (const void* data, int sizeInBytes) override;


    juce::AudioProcessorValueTreeState aptvs{ *this, nullptr, "Parameters", createParameterLayout()};
    void valueTreePropertyChanged(juce::ValueTree&, const juce::Identifier&) override ;
    juce::AudioParameterChoice* waveTypeParam; // Ajout du paramètre


private:
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (TestMTch_2025AudioProcessor)

    juce::AudioProcessorValueTreeState::ParameterLayout createParameterLayout();

    float freq = 441.f;
    double sampleRate;
    float phaseOffset = 0.0f;
    int sampleIndex = 0;

    float mod_freq = 2.0f;
    float mod_amp = 0.75f;

    Oscillator Main_osc;
	Tremolo trem;

	juce::AudioParameterFloat* mainOscFreqParam; //was float freq = 441.f
    juce::AudioParameterFloat* mainOscAmpParam; //was set to 0.5
	juce::AudioParameterFloat* modFreqParam; // floar mod_Freq = 0.5f
	juce::AudioParameterFloat* modDepthParam; // float mod_Depth = 0.75f
	std::atomic<bool> parametersChanged{ false }; 

};
