/*
 
 Video Core
 Copyright (C) 2014 James G. Hurley
 
 This library is free software; you can redistribute it and/or
 modify it under the terms of the GNU Lesser General Public
 License as published by the Free Software Foundation; either
 version 2.1 of the License, or (at your option) any later version.
 
 This library is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 Lesser General Public License for more details.
 
 You should have received a copy of the GNU Lesser General Public
 License along with this library; if not, write to the Free Software
 Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301
 USA
 
 */
#ifndef videocore_IVideoMixer_hpp
#define videocore_IVideoMixer_hpp

#include <videocore/mixers/IMixer.hpp>

namespace videocore
{
    struct SourceProperties {
        
        // [0..1] range
        float x, y;
        float width, height;
        
        bool blends;
        
    } ;
    
    typedef enum {
        kLayerGame,
        kLayerCamera,
        kLayerLogo,
        VideoLayer_Count
    } VideoLayer_t;
    
    enum {
        kVideoMetadataLayer,
        kVideoMetadataSource
    };
    
    typedef MetaData<'vide', VideoLayer_t, std::weak_ptr<ISource> > VideoBufferMetadata;
    
    class IVideoMixer : public IMixer
    {
    public:
        virtual ~IVideoMixer() {};
        
        virtual void setSourceProperties(std::weak_ptr<ISource> source, SourceProperties properties) = 0;
    };
}

#endif
