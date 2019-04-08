#!/usr/bin/env sh
# to reset per jack #dfu-programmer atmega32u4 erase --force --debug 1000
#dfu-programmer atmega32u4 flash planck_rev4_calvin.hex --debug 1000
#dfu-programmer atmega32u4 reset --debug 1000

cd "$(dirname "$0")"
git submodule sync --recursive
git submodule update --depth 1 --init --recursive
docker build -t qmkf .

echo "Building $1"

if [ "$1" = "hhkb" ]; then
  #docker run -e MIDI_ENABLE=yes -e keymap=milhhkb -e subproject="" -e keyboard=hhkb --rm -v $(pwd):/qmk:rw qmkf
  #MIDI_ENABLE=yes keymap=milhhkb keyboard=hhkb make
  #sudo dfu-programmer atmega32u4 erase
  #sudo dfu-programmer atmega32u4 flash hhkb_milhhkb.hex

  docker run \
    -e MIDI_ENABLE=yes \
    -e keymap=milhhkb \
    --privileged  \
    -v `pwd`:/qmk \
    -v /dev:/dev \
    qmkf make hhkb:dfu
fi

if [ "$1" = "iris" ]; then
  docker run \
    -e MIDI_ENABLE=yes \
    -e keymap=miliris_qwert  \
    --privileged  \
    -v `pwd`:/qmk \
    -v /dev:/dev \
    qmkf make iris/rev2:avrdude
fi

if [ "$1" = "atreus" ]; then
  docker run \
    -e MIDI_ENABLE=yes \
    -e keymap=milatreus \
    --privileged  \
    -v `pwd`:/qmk \
    -v /dev:/dev \
    qmkf make atreus:milatreus:avrdude
fi
