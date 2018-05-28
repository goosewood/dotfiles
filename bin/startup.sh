#!/bin/sh
#sh ~/.config/polybar/start.sh
#transmission-daemon
deluged
mpd
setxkbmap -option compose:lwin
wal -i ${HOME}/.1517942744366.jpg
sleep .5
bash ${HOME}/Scripts/dwm-status.sh & disown
#sudo bash ${HOME}/Scripts/st/postmake
compton --config ${HOME}/.config/compton.conf
#tint2
# conky

