Import("env")

import subprocess

# my_flags = env.ParseFlags(env['BUILD_FLAGS'])
# defines = {k: v for (k, v) in my_flags.get("CPPDEFINES")}
# print defines

description = subprocess.Popen(
    [
        "git",
        "describe",
        "--always"],
    stdout=subprocess.PIPE).stdout.read().strip().replace(
    ".",
    "_")

env.Replace(PROGNAME="firmware-%s" % description)
