Pekka Kana 2
============

**Pekka Kana 2** (Pekka the Rooster 2) is an oldschool 2D platformer where you
control a rooster called Pekka. Your mission in Pekka Kana 2 is to save Pekka's
chicken friends from an evil crow.

**Developed and contributed**
-----------------------------

> Developer: **Janne Kivilahti** from Piste Gamez (2003)
> https://pistegamez.net/game_pk2.html
> 
> Ported to SDL by **Samuli Tuomola** (2010)
> https://github.com/stt/pk2
> 
> Translated and ported to SDL2 by **Danilo Lemos** (2016/2018)
> https://github.com/danilolc/pk2

**Game Design**
---------------

The initial source code for this project was extracted from the official
developer link [PK2Source.zip](http://pistegamez.net/PK2) and modified for
better operation on the GNU/Linux distributions.

This package contains the source codes for the game **Pekka Kana 2**, written
by Janne Kivilahti.

The game and it's code are copyrighted by Janne Kivilahti, but you can modify
and use the code freely as long as the original author is mentioned.

**Compiling**
-------------

To compile **Pekka Kana 2** into Debian GNU/Linux based distributions,
you need the **SDL2**, **SDL2_image** and **SDL2_mixer** libraries installed on
the system. To get them just run the following command on the terminal:

    # apt install libsdl2-dev libsdl2-image-dev libsdl2-mixer-dev make

Run the "make" command inside the "Pekka Kana 2" directory.

    $ make

The PK2 binary will be in "bin/" directory.

    $ ./pk2

To make the removal, within the compiled directory, execute this command:

    $ make clean

**Licenses**
------------

> **Pekka Kana 2** is distributed individually under the terms of
> the BSD-2-Clause license that can be found in the [LICENSE](LICENSE) file. 
> We encourage new contributors to distribute files under this license.

* Copyright (c) 2003 **Janne Kivilahti**
* Copyright (c) 2010 **Samuli Tuomola**
* Copyright (c) 2016-2018 **Danilo Lemos**
* Copyright (c) 2018 Individual work by Carlos Donizete Froes [a.k.a coringao]
