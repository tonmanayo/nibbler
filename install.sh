echo Checking if Homebrew is installed
if which -s brew > /dev/null ; then
    echo Homebrew already installed
    echo Installing dependencies
    if brew ls --versions pkg-config  > /dev/null; then
        echo pkg-config already installed
    else
        echo Installing pkg-config
        brew install pkg-config
    fi
    if brew ls --versions sdl2  > /dev/null; then
        echo SDL2 already installed
    else
        echo Installing SDL2
        brew install sdl2
    fi
    if brew ls --versions sdl2_ttf  > /dev/null; then
        echo SDL2_TTF already installed
    else
        echo Installing SDL2_TTF
        brew install sdl2_ttf
    fi
    if brew ls --versions sfml > /dev/null; then
        echo SFML already installed
    else
        echo Installing SFML
        brew install sfml
    fi
    echo Making libraries
    echo making SFMLv2 library
    cd libs/lib1-SFMLv2
    cmake .
    make
    cd ../../
    if [ -f libs/lib1-SFMLv2/libSFMLv2.so ]; then
        mv libs/lib1-SFMLv2/libSFMLv2.so .
    fi
    echo making SDL library
    cd libs/lib2-sdl
    cmake .
    make
    cd ../../
    if [ -f libs/lib2-sdl/libSDL.so ]; then
        mv libs/lib2-sdl/libSDL.so .
    fi
    echo making SFML library
    cd libs/lib3-sfml
    cmake .
    make
    cd ../../
    if [ -f libs/lib3-sfml/libSFML.so ]; then
        mv libs/lib3-sfml/libSFML.so .
    fi
else
    echo Installing Homebrew
    sh -c "$(curl -fsSL https://raw.githubusercontent.com/Tolsadus/42homebrewfix/master/install.sh)"
    echo Please open a new terminal and run "make" again.
fi