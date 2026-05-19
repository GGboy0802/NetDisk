# MediaPlayer 模块配置

# FFmpeg 和 SDL2 头文件路径
INCLUDEPATH += $$PWD/ffmpeg-4.2.2/include \
               $$PWD/SDL2-2.0.10/include

# FFmpeg 和 SDL2 链接库
LIBS += $$PWD/ffmpeg-4.2.2/lib/avcodec.lib \
        $$PWD/ffmpeg-4.2.2/lib/avdevice.lib \
        $$PWD/ffmpeg-4.2.2/lib/avfilter.lib \
        $$PWD/ffmpeg-4.2.2/lib/avformat.lib \
        $$PWD/ffmpeg-4.2.2/lib/avutil.lib \
        $$PWD/ffmpeg-4.2.2/lib/postproc.lib \
        $$PWD/ffmpeg-4.2.2/lib/swresample.lib \
        $$PWD/ffmpeg-4.2.2/lib/swscale.lib \
        $$PWD/SDL2-2.0.10/lib/x86/SDL2.lib

# OpenGL 子模块
include($$PWD/opengl/opengl.pri)
INCLUDEPATH += $$PWD/opengl/

# MediaPlayer 源文件
SOURCES += \
    $$PWD/videoplayer.cpp \
    $$PWD/PacketQueue.cpp \
    $$PWD/playerdialog.cpp

HEADERS += \
    $$PWD/videoplayer.h \
    $$PWD/PacketQueue.h \
    $$PWD/playerdialog.h

FORMS += \
    $$PWD/playerdialog.ui

# 注意：运行时需要将以下 DLL 复制到 exe 同目录：
#   ffmpeg-4.2.2/bin/*.dll  (8个)
#   SDL2-2.0.10/lib/x86/SDL2.dll  (1个)
# 首次构建后请手动复制，或运行项目根目录下的 copy_dlls.bat
