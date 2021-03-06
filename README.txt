
VideoCore
(c) 2013-2014 James G Hurley

SETUP

git clone git@github.com:jamesghurley/VideoCore.git
git submodule init
git submodule update

Find an example of setting up a transform graph at 

https://github.com/jamesghurley/VideoCore/blob/master/sample

LICENSING

VideoCore library is licensed under LGPL 2.1.  I would like to make it clear 
that I explicitly give my permission for users of this library to statically link
VideoCore for the purposes of using them with iOS Apps, as long as the developer provides
an object file for download that can be relinked against a modified version of VideoCore.


=========

This is a work-in-progress library with the intention of being an audio and video manipulation
pipeline for iOS and Mac OS X.

Projects using VideoCore:

- MobCrush (www.mobcrush.com)

If you would like to be included in this list, either make a pull request or contact jamesghurley<at>gmail<dot>com

=========


e.g. Source (GLES) -> Transform (Composite) -> Transform (H.264 Encode) -> Transform (RTMP Packetize) -> Output (RTMP)

videocore/
    
    sources/
        videocore::ISource
        videocore::IAudioSource : videocore::ISource
        videocore::IVideoSource : videocore::ISource
        videocore::Watermark : videocore:IVideoSource
            iOS/
                videocore::iOS::GLESSource : videocore::IVideoSource
                videocore::iOS::CameraSource : videocore::IVideoSource
                videocore::iOS::CoreAudioSource : videocore::IAudioSource
                videocore::iOS::OpenALSource : videocore::IAudioSource
            Apple/
                videocore::Apple::MicrophoneSource : videocore::IAudioSource
            OSX/
                videocore::OSX::DisplaySource : videocore::IVideoSource
                videocore::OSX::SystemAudioSource : videocore::IAudioSource
    outputs/
        videocore::IOutput
        videocore::ITransform : videocore::IOutput
            iOS/
                videocore::iOS::H264Transform : videocore::ITransform
                videocore::iOS::AACTransform  : videocore::ITransform
            OSX/
                videocore::OSX::H264Transform : videocore::ITransform
                videocore::OSX::AACTransform  : videocore::ITransform
            RTMP/
                videocore::rtmp::H264Packetizer : videocore::ITransform
                videocore::rtmp::AACPacketizer : videocore::ITransform
                
    mixers/
        videocore::IMixer
        videocore::IAudioMixer : videocore::IMixer
        videocore::IVideoMixer : videocore::IMixer
        videocore::AudioMixer : videocore::IAudioMixer
            iOS/
                videocore::iOS::GLESVideoMixer : videocore::IVideoMixer
            OSX/
                videocore::OSX::GLVideoMixer : videocore::IVideoMixer
    
    rtmp/
        videocore::RTMPSession : videocore::IOutput
        videocore::FlvCtx
    
    stream/
        videocore::IStreamSession
        Apple/
            videocore::Apple::StreamSession : videocore::IStreamSession


============

