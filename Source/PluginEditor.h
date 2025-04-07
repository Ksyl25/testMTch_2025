/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"

//==============================================================================
/**
*/
class TestMTch_2025AudioProcessorEditor  : public juce::AudioProcessorEditor
{
public:
    TestMTch_2025AudioProcessorEditor (TestMTch_2025AudioProcessor&);
    ~TestMTch_2025AudioProcessorEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;

private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    TestMTch_2025AudioProcessor& audioProcessor;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (TestMTch_2025AudioProcessorEditor)
};
