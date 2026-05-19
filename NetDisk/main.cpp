

// SDL2 会将 main 宏替换为 SDL_main，必须在 #include 之前取消
// 否则 main 函数会被重定义为 SDL_main 导致链接/运行崩溃
#define SDL_MAIN_HANDLED

#include"ckernel.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    CKernel::GetInstance();


    return a.exec();
}
