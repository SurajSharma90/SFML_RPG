#!/usr/bin/env bash

## Ensure relevant libs are installed: GL GLEW GLM SFML ...

set -e ## Exit if any command fails
set -x ## Echo commands

cd SFML_RPG ## Enter source dir

make ## Compile and link source code

./a.out ## NOTE: When starting a new game, an error regarding the vertex shader compilation failed (at least on my machine), not sure why.

