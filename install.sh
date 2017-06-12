echo Installing dependencies
if brew ls --versions sdl2  > /dev/null; then
  echo SDL2 already installed
else
  echo Installing SDL2
  brew install sdl2
fi