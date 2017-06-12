echo Checking if Homebrew is installed
if which -s brew > /dev/null ; then
    echo Homebrew already installed
    echo Installing dependencies
    if brew ls --versions sdl2  > /dev/null; then
        echo SDL2 already installed
    else
        echo Installing SDL2
        brew install sdl2
    fi
    if brew ls --versions allegro  > /dev/null; then
        echo Allegro already installed
    else
        echo Installing Allegro
        brew install allegro
    fi
else
    echo Installing Homebrew
    sh -c "$(curl -fsSL https://raw.githubusercontent.com/Tolsadus/42homebrewfix/master/install.sh)"
    echo Please open a new terminal and run "make" again.
fi