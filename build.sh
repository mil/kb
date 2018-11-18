#!/usr/bin/env bash
# to reset per jack #dfu-programmer atmega32u4 erase --force --debug 1000
#dfu-programmer atmega32u4 flash planck_rev4_calvin.hex --debug 1000
#dfu-programmer atmega32u4 reset --debug 1000


cd "$(dirname "$0")"
git submodule sync --recursive
git submodule update --init --recursive

docker build -t qmkf .
docker run -e MIDI_ENABLE=yes -e keymap=milhhkb -e subproject="" -e keyboard=hhkb --rm -v $(pwd):/qmk:rw qmkf
#MIDI_ENABLE=yes keymap=milhhkb keyboard=hhkb make
sudo dfu-programmer atmega32u4 erase
sudo dfu-programmer atmega32u4 flash hhkb_milhhkb.hex
