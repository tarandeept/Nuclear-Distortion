/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
NuclearDistortionAudioProcessorEditor::NuclearDistortionAudioProcessorEditor (NuclearDistortionAudioProcessor& p)
    : AudioProcessorEditor (&p), processor (p)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize (400, 300);
    
    driveKnob.setSliderStyle(Slider::RotaryVerticalDrag);
    driveKnob.setRange(0.0, 100.0);
    driveKnob.setValue(25.0);
    driveKnob.setLookAndFeel(&otherLookAndFeel);

    addAndMakeVisible(&driveKnob);
}

NuclearDistortionAudioProcessorEditor::~NuclearDistortionAudioProcessorEditor()
{
}

//==============================================================================
void NuclearDistortionAudioProcessorEditor::paint (Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (ResizableWindow::backgroundColourId));

    g.setColour (Colours::white);
    g.setFont (Font ("Times New Roman", 20.0f, Font::italic));
    g.drawFittedText ("Nuclear Distortion!", 0, 0, getWidth(), 30, Justification::centred, 1);
}

void NuclearDistortionAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
    
    driveKnob.setBounds(100, 75, 200, 200);
}
