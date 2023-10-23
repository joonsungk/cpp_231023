// 2_namespace2.cpp

#include <iostream>
// namespace를 접근하는 방법 3가지

// 1) 전체 이름을 명시하는 방법
#if 0
namespace audio {
void Play() { std::cout << "Audio Play" << std::endl; }
}

int main()
{
    std::cout << "Hello, C++" << std::endl;

    audio::Play();
}
#endif

// 2) using 선언
#if 0
namespace audio {
void Play() { std::cout << "Audio Play" << std::endl; }
}

namespace video {
void Play() { std::cout << "Video Play" << std::endl; }
}

using audio::Play;
// using video::Play;

using std::cout;
using std::endl;

int main()
{
    cout << "Hello, C++" << endl;
    Play();
}
#endif

// 3) using 지시어

namespace audio {
void Play() { std::cout << "Audio Play" << std::endl; }
void Init() { }
}

using namespace std;
// std의 이름 공간 안에 있는 모든 요소를 암묵적으로 접근할 수 있습니다.

using namespace audio;

int main()
{
    std::cout << "Hello, C++" << std::endl;

    Play();
    Init();
}
