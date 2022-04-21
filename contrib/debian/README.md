
Debian
====================
This directory contains files used to package bitoreumd/bitoreum-qt
for Debian-based Linux systems. If you compile bitoreumd/bitoreum-qt yourself, there are some useful files here.

## bitoreum: URI support ##


bitoreum-qt.desktop  (Gnome / Open Desktop)
To install:

	sudo desktop-file-install bitoreum-qt.desktop
	sudo update-desktop-database

If you build yourself, you will either need to modify the paths in
the .desktop file or copy or symlink your bitoreum-qt binary to `/usr/bin`
and the `../../share/pixmaps/bitoreum128.png` to `/usr/share/pixmaps`

bitoreum-qt.protocol (KDE)

