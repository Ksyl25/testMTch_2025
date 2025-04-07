/*
  ==============================================================================

    Utils.h
    Created: 27 Feb 2025 2:44:58pm
    Author:  Zord

  ==============================================================================
*/

#pragma once

template<typename T>
inline static void castParameter( juce::AudioProcessorValueTreeState&
aptvs, const juce::ParameterID& id, T& destination )
{
 destination = dynamic_cast<T>( aptvs.getParameter( id.getParamID() )
);
 jassert( destination );
}
