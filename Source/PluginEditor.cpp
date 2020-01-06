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
    setSize (450, 180);
    
    driveKnob.setSliderStyle(Slider::RotaryVerticalDrag);
    driveKnob.setTextBoxStyle(Slider::TextEntryBoxPosition::NoTextBox, true, 0, 0);
    driveKnob.setRange(1.0, 25.0);
    driveKnob.setValue(1.0);
    driveKnob.setLookAndFeel(&otherLookAndFeel);
    driveLabel.setText("Drive", dontSendNotification);
    driveLabel.setFont(Font("Calibri", "Normal", 14));
    driveLabel.setJustificationType(Justification::centred);
    driveLabel.attachToComponent(&driveKnob, false);
    addAndMakeVisible(&driveKnob);
    addAndMakeVisible(&driveLabel);
    driveKnob.addListener(this);
    
    mixKnob.setSliderStyle(Slider::RotaryVerticalDrag);
    mixKnob.setTextBoxStyle(Slider::TextEntryBoxPosition::NoTextBox, true, 0, 0);
    mixKnob.setRange(0.0, 100.0);
    mixKnob.setValue(100.0);
    mixKnob.setLookAndFeel(&otherLookAndFeel);
    mixLabel.setText("Mix", dontSendNotification);
    mixLabel.setFont(Font("Calibri", "Normal", 14));
    mixLabel.setJustificationType(Justification::centred);
    mixLabel.attachToComponent(&mixKnob, false);
    addAndMakeVisible(&mixKnob);
    addAndMakeVisible(&mixLabel);
    
    postGainKnob.setSliderStyle(Slider::RotaryVerticalDrag);
    postGainKnob.setTextBoxStyle(Slider::TextEntryBoxPosition::NoTextBox, true, 0, 0);
    postGainKnob.setRange(-1.0, 0.0);
    postGainKnob.setValue(0.0);
    postGainKnob.setLookAndFeel(&otherLookAndFeel);
    postGainLabel.setText("Post Gain", dontSendNotification);
    postGainLabel.setFont(Font("Calibri", "Normal", 14));
    postGainLabel.setJustificationType(Justification::centred);
    postGainLabel.attachToComponent(&postGainKnob, false);
    addAndMakeVisible(&postGainKnob);
    addAndMakeVisible(&postGainLabel);
}


NuclearDistortionAudioProcessorEditor::~NuclearDistortionAudioProcessorEditor() {}


void NuclearDistortionAudioProcessorEditor::sliderValueChanged(Slider* slider) {
    if (slider == &driveKnob) {
        processor.driveAmount = driveKnob.getValue();
    }
    else if (slider == &mixKnob) {
        //pass
    }
    else {
        //pass
    }
}


//==============================================================================
void NuclearDistortionAudioProcessorEditor::paint (Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    //g.fillAll (getLookAndFeel().findColour (ResizableWindow::backgroundColourId));
    
    Image background = ImageCache::getFromMemory(BinaryData::TexturedBlackBG_jpeg, BinaryData::TexturedBlackBG_jpegSize);
    g.drawImageAt(background, 0, 0);
}

void NuclearDistortionAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
    
    int border = 4;
    Rectangle<int> area = getLocalBounds();
    //auto dialArea = area.removeFromTop (area.getHeight() / 2);

    Rectangle<int> middleKnobArea = Rectangle<int>(area.getCentreX()-55, area.getCentreY()-55, 110, 110);
    driveKnob.setBounds(middleKnobArea.reduced(border));
    
    Rectangle<int> leftKnobArea = Rectangle<int>(45, area.getCentreY()-45, 90, 90);
    mixKnob.setBounds(leftKnobArea.reduced(border));
    
    Rectangle<int> rightKnobArea = Rectangle<int>(area.getCentreX()+90, area.getCentreY()-45, 90, 90);
    postGainKnob.setBounds(rightKnobArea.reduced(border));
}
