/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "PluginProcessor.h"

//==============================================================================

class OtherLookAndFeel : public LookAndFeel_V4
{
public:
    OtherLookAndFeel() {
        setColour(Slider::thumbColourId, Colours::red);
    }
    
    
    void drawRotarySlider (Graphics& g, int x, int y, int width, int height, float sliderPos,
                       const float rotaryStartAngle, const float rotaryEndAngle, Slider& slider) override
    {
        float radius = jmin(width/2, height/2) - 4.0f;
        float centreX = width/2 + x;
        float centreY = height/2 + y;
        float rx = centreX - radius;
        float ry = centreY - radius;
        float rw = radius * 2.0f;
        float angle = rotaryStartAngle + sliderPos * (rotaryEndAngle - rotaryStartAngle);
        
        g.setColour(Colours::mintcream);
        g.fillEllipse(rx, ry, rw, rw);
        g.setColour(Colours::darkgrey);
        g.drawEllipse(rx, ry, rw, rw, 1.0f);
        
        Path p;
        float pointerLength = radius/2;
        float pointerThickness = 3.0f;
        p.addRectangle(-pointerThickness/2, -radius, pointerThickness, pointerLength);
        p.applyTransform(AffineTransform::rotation(angle).translated(centreX, centreY));
        
        g.setColour(Colours::black);
        g.fillPath(p);
    }
    
};



class NuclearDistortionAudioProcessorEditor  : public AudioProcessorEditor, private Slider::Listener
{
public:
    NuclearDistortionAudioProcessorEditor (NuclearDistortionAudioProcessor&);
    ~NuclearDistortionAudioProcessorEditor();

    //==============================================================================
    void paint (Graphics&) override;
    void resized() override;

private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    NuclearDistortionAudioProcessor& processor;
    OtherLookAndFeel otherLookAndFeel;
    
    void sliderValueChanged(Slider* slider) override;
    
    Slider driveKnob;
    Label driveLabel;
    
    Slider mixKnob;
    Label mixLabel;
    
    Slider postGainKnob;
    Label postGainLabel;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (NuclearDistortionAudioProcessorEditor)
};
