#!/usr/local/bin/oksh
print_date(){
		date '+%a %B %d %T'
}
print_music(){
	#	if $(killall -q -0 cmus) && [ "status playing" = $(cmus-remote -Q | head -1) ]
		if $(killall -q -0 cmus)
		then
				song=$(cmus-remote -Q | head -7 | tail -1)
				song=${song##*title}
				artist=$(cmus-remote -Q | head -5 | tail -1)
				artist=${artist##*artist}
				echo -e "$song - $artist"
		else
				mpc -f %title%\ \-\ %artist% | head -1
		fi
}
Volume(){
		volume="$(amixer get Master | tail -n1 | sed -r 's/.*\[(.*)%\].*/\1/')"
		if test "$volume" -gt 0
		then
				echo -e "${volume}🔊"
		else
				echo -e "Mute"
		fi
}
bat(){
		hash acpi || return 0
		onl="$(grep "on-line" <(acpi -V))"
		charge="$(awk '{ sum += $1 } END { print sum }' /sys/class/power_supply/BAT*/capacity)"
		if test -z "$onl"
		then
				# suspend when we close the lid
				#systemctl --user stop inhibit-lid-sleep-on-battery.service
				echo -e "${charge}"
		else
				# On mains! no need to suspend
				#systemctl --user start inhibit-lid-sleep-on-battery.service
				echo -e "${charge}"
		fi
}

while true
do
		xsetroot -name " $(print_music)  $(Volume) $(bat)% $(print_date)"
		sleep .5
done
