// 4_변수2.cpp
// 중요합니다.

struct Point {
    int x;
    int y;
};

int main()
{
    // Copy Initialization
    int n1 = 42;
    int x1[3] = { 10, 20, 30 };
    Point pt1 = { 10, 20 };

    // Direct Initialization
    int n2(42);
    int x2[3] { 10, 20, 30 };
    Point pt2 { 10, 20 };
}
