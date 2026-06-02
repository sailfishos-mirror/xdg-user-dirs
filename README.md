# xdg-user-dirs

xdg-user-dirs is a tool to help manage "well known" user directories like the desktop folder and the music folder.
It also handles localization (i.e. translation) of the filenames.

The way it works is that xdg-user-dirs-update is run very early in the login phase. This program reads a configuration file,
and a set of default directories. It then creates localized versions of these directories in the user's home directory and
sets up a config file in `$XDG_CONFIG_HOME/user-dirs.dirs` (`XDG_CONFIG_HOME` defaults to `~/.config`) that applications can
read to find these directories.

The `xdg-user-dir` command can be used to query a single directory from scripts or applications:
```bash
xdg-user-dir DOWNLOAD
```


## Settings

Sysadmins can configure things by editing `/etc/xdg/user-dirs.conf`.
There are only two settings: you can disable the whole thing, and you can specify the charset encoding used for filenames.
Sysadmins can also set or change the default directories and their initial values in `/etc/xdg/user-dirs.defaults`.

The well-known directory names are: `DESKTOP`, `DOCUMENTS`, `DOWNLOAD`, `MUSIC`, `PICTURES`, `PROJECTS`, `PUBLICSHARE`,
`TEMPLATES`, and `VIDEOS`.

`$XDG_CONFIG_HOME/user-dirs.dirs` specifies the current set of directories for the user. This file is in a shell format, so it's easy
to access from a shell script. This file can also be modified by users (manually or via applications) to change the directories used.
Note: To disable a directory, point it to the homedir.

Here is a shell script example of how to find the desktop and the download directory:
```bash
test -f ${XDG_CONFIG_HOME:-~/.config}/user-dirs.dirs && source ${XDG_CONFIG_HOME:-~/.config}/user-dirs.dirs
echo ${XDG_DESKTOP_DIR:-$HOME/Desktop}
echo ${XDG_DOWNLOAD_DIR:-$HOME}
```

For application code, desktop environments integrate this via their own APIs - for example `g_get_user_special_dir()` in GLib,
or `QStandardPaths` in Qt.


## Building

xdg-user-dirs uses [Meson](https://mesonbuild.com/):

```bash
meson setup build
meson compile -C build
meson install -C build
```


## Translations

Translations of xdg-user-dirs are handled by the [translation project](https://translationproject.org/).
All translations should go through there.

## Code

The Git module for this code is [gitlab.freedesktop.org/xdg/xdg-user-dirs](https://gitlab.freedesktop.org/xdg/xdg-user-dirs).

## More Information

See info at [freedesktop.org/wiki/Software/xdg-user-dirs](https://freedesktop.org/wiki/Software/xdg-user-dirs).
