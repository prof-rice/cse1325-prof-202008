# Python easygui

## Use this command to install Python's easygui library in Ubuntu

    sudo apt install python3-easygui

# Zenity 

## Read the manual here

    man zenity
    https://help.gnome.org/users/zenity/3.28/ 

## Here are some copy-and-paste Zenity examples for GUI scripting in bash

    zenity --info --text "Hello, World"

    zenity --info --width=200 --height=20 --title "Build complete!" --text "make elsa"

    zenity --question --text "Are you learning gtkmm?" --no-wrap --ok-label "Yes" --cancel-label "No"

    zenity --list --column Buy --column Fruit FALSE Apple TRUE Pear FALSE Banana --radiolist

    ls -l .. | zenity --text-info --font="DejaVu Sans Mono" --height 300 --width 600 --title="Directory Listing"

    zenity --calendar

    zenity --title="Select a file" --file-selection

    zenity --entry --title "Who are you?" --text "Enter your name:"

    zenity --password --title "UTA Login" --text "Enter your password"

    secs=10; (while [ $secs -gt 0 ] ; do  secs=$(( $secs - 1 )); prog=$(( 10 * (10 - $secs) ));  printf "$prog\n# You have $secs seconds left\n"; sleep 1; done) | zenity --title "Make a Decision!" --progress
