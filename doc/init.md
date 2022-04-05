Sample init scripts and service configuration for bitoreumd
==========================================================

Sample scripts and configuration files for systemd, Upstart and OpenRC
can be found in the contrib/init folder.

    contrib/init/bitoreumd.service:    systemd service unit configuration
    contrib/init/bitoreumd.openrc:     OpenRC compatible SysV style init script
    contrib/init/bitoreumd.openrcconf: OpenRC conf.d file
    contrib/init/bitoreumd.conf:       Upstart service configuration file
    contrib/init/bitoreumd.init:       CentOS compatible SysV style init script

Service User
---------------------------------

All three Linux startup configurations assume the existence of a "bitoreumcore" user
and group.  They must be created before attempting to use these scripts.
The OS X configuration assumes bitoreumd will be set up for the current user.

Configuration
---------------------------------

At a bare minimum, bitoreumd requires that the rpcpassword setting be set
when running as a daemon.  If the configuration file does not exist or this
setting is not set, bitoreumd will shutdown promptly after startup.

This password does not have to be remembered or typed as it is mostly used
as a fixed token that bitoreumd and client programs read from the configuration
file, however it is recommended that a strong and secure password be used
as this password is security critical to securing the wallet should the
wallet be enabled.

If bitoreumd is run with the "-server" flag (set by default), and no rpcpassword is set,
it will use a special cookie file for authentication. The cookie is generated with random
content when the daemon starts, and deleted when it exits. Read access to this file
controls who can access it through RPC.

By default the cookie is stored in the data directory, but it's location can be overridden
with the option '-rpccookiefile'.

This allows for running bitoreumd without having to do any manual configuration.

`conf`, `pid`, and `wallet` accept relative paths which are interpreted as
relative to the data directory. `wallet` *only* supports relative paths.

For an example configuration file that describes the configuration settings,
see `contrib/debian/examples/bitoreum.conf`.

Paths
---------------------------------

### Linux

All three configurations assume several paths that might need to be adjusted.

Binary:              `/usr/bin/bitoreumd`  
Configuration file:  `/etc/bitoreumcore/bitoreum.conf`  
Data directory:      `/var/lib/bitoreumd`  
PID file:            `/var/run/bitoreumd/bitoreumd.pid` (OpenRC and Upstart) or `/var/lib/bitoreumd/bitoreumd.pid` (systemd)  
Lock file:           `/var/lock/subsys/bitoreumd` (CentOS)  

The configuration file, PID directory (if applicable) and data directory
should all be owned by the bitoreumcore user and group.  It is advised for security
reasons to make the configuration file and data directory only readable by the
bitoreumcore user and group.  Access to bitoreum-cli and other bitoreumd rpc clients
can then be controlled by group membership.

### Mac OS X

Binary:              `/usr/local/bin/bitoreumd`  
Configuration file:  `~/Library/Application Support/BitoreumCore/bitoreum.conf`  
Data directory:      `~/Library/Application Support/BitoreumCore`
Lock file:           `~/Library/Application Support/BitoreumCore/.lock`

Installing Service Configuration
-----------------------------------

### systemd

Installing this .service file consists of just copying it to
/usr/lib/systemd/system directory, followed by the command
`systemctl daemon-reload` in order to update running systemd configuration.

To test, run `systemctl start bitoreumd` and to enable for system startup run
`systemctl enable bitoreumd`

### OpenRC

Rename bitoreumd.openrc to bitoreumd and drop it in /etc/init.d.  Double
check ownership and permissions and make it executable.  Test it with
`/etc/init.d/bitoreumd start` and configure it to run on startup with
`rc-update add bitoreumd`

### Upstart (for Debian/Ubuntu based distributions)

Drop bitoreumd.conf in /etc/init.  Test by running `service bitoreumd start`
it will automatically start on reboot.

NOTE: This script is incompatible with CentOS 5 and Amazon Linux 2014 as they
use old versions of Upstart and do not supply the start-stop-daemon utility.

### CentOS

Copy bitoreumd.init to /etc/init.d/bitoreumd. Test by running `service bitoreumd start`.

Using this script, you can adjust the path and flags to the bitoreumd program by
setting the BITOREUMD and FLAGS environment variables in the file
/etc/sysconfig/bitoreumd. You can also use the DAEMONOPTS environment variable here.

### Mac OS X

Copy org.bitoreum.bitoreumd.plist into ~/Library/LaunchAgents. Load the launch agent by
running `launchctl load ~/Library/LaunchAgents/org.bitoreum.bitoreumd.plist`.

This Launch Agent will cause bitoreumd to start whenever the user logs in.

NOTE: This approach is intended for those wanting to run bitoreumd as the current user.
You will need to modify org.bitoreum.bitoreumd.plist if you intend to use it as a
Launch Daemon with a dedicated bitoreumcore user.

Auto-respawn
-----------------------------------

Auto respawning is currently only configured for Upstart and systemd.
Reasonable defaults have been chosen but YMMV.
