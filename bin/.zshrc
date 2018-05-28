# Lines configured by zsh-newuser-install
HISTFILE=~/.histfile
HISTSIZE=1000
SAVEHIST=1000
setopt appendhistory autocd
unsetopt beep nomatch
bindkey -v
# End of lines configured by zsh-newuser-install
# The following lines were added by compinstall
zstyle :compinstall filename '/home/void/.zshrc'

autoload -Uz compinit
compinit
# End of lines added by compinstall

# -------------------------------
# Alias'
# -------------------------------

alias ls="ls --color=auto"
alias ll="ls --color -lh"
alias q='exit'
alias d-c='deluge-console'
alias U='sudo xbps-install -Su'
alias m2="xrandr --output VGA1 --auto --left-of LVDS1"
alias I='sudo xbps-install -S'
alias R="R -q"
alias shot="bash ~/Scripts/shot"
alias tr='transmission-remote'
alias cls="clear"
alias c="clear"
alias ka='killall'
alias r='ranger'
alias py="python3"
#alias vtop="vtop -t wal"
alias v="nvim"
alias brc="nvim ~/.bashrc"
alias zrc="nvim ~/.zshrc"
alias vrc="nvim ~/.config/nvim/init.vim"
alias gtd="./Scripts/gtd/gtd"
alias tether="bash ~/Scripts/tether/tetherScript"
#alias neofetch="bash ~/Scripts/neofetch"
alias killme="echo Type: 
echo sudo init 0"

# -----------------------------
# Settings
# -----------------------------

# Change Icon
PS1='[%~] Δ '
