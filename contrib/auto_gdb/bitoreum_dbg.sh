#!/bin/bash
# use testnet settings,  if you need mainnet,  use ~/.bitoreumcore/bitoreumd.pid file instead
bitoreum_pid=$(<~/.bitoreumcore/testnet3/bitoreumd.pid)
sudo gdb -batch -ex "source debug.gdb" bitoreumd ${bitoreum_pid}
