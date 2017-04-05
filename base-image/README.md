This is the yocto based base image for the rest of the project. Using Yocto
means extremely small base images. Also cross compiling Webkit can be tricky,
so using a Yocto recipe that takes everything into account is making this
process easier.

**Warning: The build process is extremely CPU/RAM/IO intensive and can take a
long time (hours) to complete on a personal computer. Make sure you have a lot
of free space available. On my machine it needed 32GB! Using a beefy server is
a very good idea.**

## How to build

To build this base image you'll have to checkout the submodules included in
this repo. To do this run the following commands after you clone this repo:

```bash
git submodule init
git submodule update
```

Now you're ready to go. Simply run **`./build.sh`** and it will fire up a Yocto
build. Your environment needs to have the `python` executable be a Python 2
interpreter. If you're running on a distribution which defaults to Python 3
consider using [virtualenv](https://virtualenv.pypa.io/en/stable/).

After the build is done you should see a message like the following:

```
#####################################
Created docker image: resin-wpe:raspberrypi3-669edb1
#####################################
```

You can now use push this image to your registry and use it as a base for your
project.
