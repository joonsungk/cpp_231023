// 2_namespace.cpp
#include <iostream>

// 1. C에서는 이름 충돌 해결을 위한 언어적인 기능이 제공되지 않습니다.
//  => 다른 이름을 약속합니다.
#if 0
// audio.c
void AudioInit() { }

// video.c
void VideoInit() { }
#endif

// 2. C++에서는 이름 충돌의 문제를 해결하기 위한 namespace 문법을 제공합니다.
// 3. C++은 표준에서 제공하는 모든 기능을 std의 이름 공간을 통해 제공합니다.
// 4. namespace를 사용하면, 프로그램의 각 요소를 관련된 요소끼리 그룹화 할 수 있습니다.

// audio.cpp
namespace audio {
void Init() { std::cout << "Audio Init" << std::endl; }
}

// video.cpp
namespace video {
void Init() { std::cout << "Video Init" << std::endl; }

namespace mp3 {
    void Play() { }
}

namespace mp4 {
    void Play() { }
}

}

int main()
{
    audio::Init();
    video::Init();

    video::mp3::Play();
    video::mp4::Play();
}
