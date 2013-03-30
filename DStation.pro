#-------------------------------------------------
#
# Project created by QtCreator 2010-08-18T15:23:09
#
#-------------------------------------------------

QT       += core gui

TARGET = DStation
TEMPLATE = app

SOURCES += main.cpp\
        dstation.cpp \
    dgraphicsscene.cpp \
    aboutdialog.cpp

HEADERS  += dstation.h \
    dgraphicsscene.h \
    aboutdialog.h

FORMS    += dstation.ui \
    aboutdialog.ui


# Windows ICO
RC_FILE =       icon.rc

# This application needs patched ImageMagick 6.7.4-8 or higher. Older versions do not work as we use STL containers for Fourier transforms that were introduced
# by our request. See: http://www.imagemagick.org/discourse-server/viewtopic.php?f=2&t=17046&p=63494#p63494
#
# Configure string for ImageMagick:
# ./configure --prefix=/opt --with-quantum-depth=16 \
#      --disable-dependency-tracking --with-x=yes \
#      --x-includes=/usr/X11R6/include --x-libraries=/usr/X11R6/lib/ \
#      --without-perl --enable-hdri=yes --disable-openmp
#
# ImageMagick has to be compiled at Q16 level *** with HDRI enabled ***. OpenMP should be disabled on Mac OS X due to buggy libgomp implementation.
# When compiling ImageMagick, make sure FFTW, JPEG, TIFF and PNG libraries are installed/compiled for full functionality.
# This application has troubles running QThreads as it looks like to conflict with OpenMP. (Unconfirmed)
# Tested to work with FFTW 3.2.2
#
#-------------------------------------------------
# FAQ/Troubleshooting:
# Q: Deconvolution output is black or looks like a black-and-white corrupted image.
# A: Make sure ImageMagick is compiled with HDRI enabled.
#
# Q: DStation can't load PNG, TIFF or other images.
# A: Make sure ImageMagick is compiled with additional libraries to support those formats.
#
# Q: Deconvolution output has checkerboard pattern or corrupted image on Mac version.
# A: This is still an unresolved bug, probably an fftw issue. Use non-HDRI Wiener deconvolution. (ImageMagick still has to be compiled with HDRI!)
#-------------------------------------------------


#-------------------------------------------------
# Macintosh 64-bit version
#
# ImageMagick for Mac OSX Snow Leopard is compiled as x86_64 by default with many depending libraries pre-installed in OS, so this application has to be of the same
# architecture. You will need a Cocoa (64-bit) version of Qt Framework to compile this application on Snow Leopard. Resolved by downloading Cocoa Qt Framework and
# installing on top of the Qt SDK. Mac OS X Lion uses 64-bit by default, so nothing is required. I am using Qt 4.8.0 on Mac OS X 10.7 Lion.
#
# Notice: For 32-bit Intel and PowerPC Macs, comment out the CONFIG += x86_64 to build 32-bit application.
#-------------------------------------------------
#This is my shared libraries build environment on 24" iMac (Intel Core 2 Duo) running Mac OS X 10.7 Lion:
macx {
ICON            =  Fourier.icns
INCLUDEPATH     += /opt/include/ImageMagick
LIBS            += -L/opt/lib -lMagick++ -lMagickCore
CONFIG          += x86_64
}
#-------------------------------------------------

#-------------------------------------------------
# Windows version
#
# This one is tricky. We need to link all the libraries statically to make sure exceptions are handled correctly. For this, Qt and ImageMagick have to be compiled with
# the same MinGW compiler. First, we build a static version of Qt library. This is well described in Qt docs (http://doc.qt.nokia.com/4.6/deployment-windows.html)
# Qt 4.6.2 is the version of Qt that compiles on Windows without bugs.
# Here is the configure line used in the Qt Command Prompt: configure -release -static -qt-zlib -no-qt3support -no-phonon -no-s60
# (-no-qt3support is the QTBUG-10791 workaround)
# Warning: do not build Qt from MSYS!
# I am using gcc version 4.4.1 (TDM-2 mingw32) and Qt 4.6.2 on Windows.
#
# Next step is to build ImageMagick with the same MinGW. Other compilers (MSVC, etc) don't work due to linking problems.
# Using pre-compiled MinGW binary won't work as it does not support HDRI.
#
# Known problems building ImageMagick Q32 HDRI libraries with FFT support from scratch under MinGW:
# * fftw. Configure with --with-our-malloc16 --with-windows-f77-mangling --enabled-shared --enable-portable-binary --enable-sse2
# to avoid known Windows related problems.
# (My MSYS does not handle pthreads correctly for unknown reasons, so I have not enabled them when building fftw.)
#
# * Redifinition of type boolean in jpeglib. Edit /local/include/jconfig.h, and add before the line 24 that has typedef unsigned char boolean:
# #ifndef HAVE_BOOLEAN and #endif after that line. Edit Imagemagick_src_directory/coders/jpeg.c and add #define HAVE_BOOLEAN there at the top of includes.
#
# * libpng 1.4.x problem with undefined references. Build libpng-1.5.0 (works with 1.5.0beta45)
#
#-------------------------------------------------
#This is my current MSYS static libraries build environment on Sun Ultra 27 workstation (Intel Xeon) running Windows 7 64-bit edition:
#Linking order is important.
win32 {
INCLUDEPATH     += C:\msys\1.0\local\include\ImageMagick
LIBS            += C:\msys\1.0\local\lib\libMagick++.a
LIBS            += C:\msys\1.0\local\lib\libMagickWand.a
LIBS            += C:\msys\1.0\local\lib\libMagickCore.a
LIBS            += C:\msys\1.0\local\lib\libfftw3.dll.a
LIBS            += C:\msys\1.0\mingw\lib\gcc\mingw32\4.4.1\libgomp.a
LIBS            += C:\msys\1.0\mingw\lib\libltdl.a
LIBS            += C:\msys\1.0\local\lib\libjpeg.a
LIBS            += C:\msys\1.0\local\lib\libpng15.a
LIBS            += C:\msys\1.0\local\lib\libtiff.a
LIBS            += C:\msys\1.0\mingw\lib\libgdi32.a
LIBS            += C:\msys\1.0\mingw\lib\libpthread.a
}
#-------------------------------------------------
#-------------------------------------------------
#This is my old MSYS shared libraries build environment on Sun Ultra 27 workstation (Intel Xeon) running Windows 7 64-bit edition:
#INCLUDEPATH     += C:\msys\1.0\local\include\ImageMagick
#LIBS            += -LC:\msys\1.0\local\lib -lMagick++ -lMagickCore -lMagickWand
#-------------------------------------------------


